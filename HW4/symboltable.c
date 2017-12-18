#include "symboltable.h"
#include <algorithm>
using namespace std;
//function mplementation
int scope_depth;
int is_arr;
int is_funct;
int is_loop;
int const_type;
vector <vector <sub_entry> > mysymbol_table;
vector <vector <sub_entry> > allsymbol_table;
vector <loop_iterator> myiter_table;
void symbol_table_init()
{
    mysymbol_table.resize(SYMBOL_TABLE_MAX_SIZE);
    allsymbol_table.resize(SYMBOL_TABLE_MAX_SIZE);
    scope_depth = 0;
    is_arr = 0;
    is_funct = 0;
    is_loop = 0;
    const_type = 0;
    is_proc_call = 0;
    arr_dim_cnt = 0;
}
void inserting_symbol_table(vector<string> id_list_buf, string kind_in, string type_in, vector<string> funct_attri_buf)
{
    for(unsigned int i=0;i<id_list_buf.size();i++)
    {
        sub_entry one_subentry;
        if(id_list_buf[i].length()>32)
        {
            one_subentry.name = id_list_buf[i].substr(0,32);
        }
        else
        {
            one_subentry.name = id_list_buf[i];
        }
        one_subentry.kind = kind_in;
        if(type_in==";")
            type_in = "void";


        one_subentry.type = type_in;
        if(is_arr) //moreover, assign the arr_dim
        {
            one_subentry.arr_dim = arr_dim_buf;
        }
        else
        {
            one_subentry.arr_dim.resize(0);
        }
        string scope_depth_str = to_string(scope_depth);
        if(scope_depth)
        {
            scope_depth_str+="(local)";
        }
        else
        {
            scope_depth_str+="(global)";
        }
        one_subentry.level_str = scope_depth_str;
        if(funct_attri_buf.size())
        {
            one_subentry.funct_attri = funct_attri_buf;
        }
        mysymbol_table[scope_depth].pb(one_subentry);
        allsymbol_table[scope_depth].pb(one_subentry);
    }
}
void inserting_iter_table(string iter_name_in,int iter_level_in)
{
    loop_iterator one_iter_table;
    one_iter_table.iter_name = iter_name_in;
    one_iter_table.iter_level = iter_level_in;
    myiter_table.pb(one_iter_table);
}
void pop_symbol_table()
{
    mysymbol_table[scope_depth].clear();//pop the table at that table, easliy pop
    scope_depth=(scope_depth==0)?0:scope_depth-1; //shirnk the level
    // myiter_table.clear(); //clean the iterator table NO DONT DO THIS! SHOULD BE CLEAN THE ITERATOR OF CURRENT DEPTH RATHER THAN all
    // cout<<"POP symboltable scope_depth "<<scope_depth<<endl;
    for(unsigned int i=0;i<myiter_table.size();i++)
    {
        if(myiter_table[i].iter_level == scope_depth+1)
        {
            myiter_table.erase(myiter_table.begin()+i);
        }
    }
}
void dumpsymbol()
{
    //printf("(In dump function)Scope depth %d, pre_sub_entry_cnt %d sub_entry_cnt %d global_pre_sub_entry_cnt %d global_sub_entry_cnt %d\n",scope_depth,pre_sub_entry_cnt,sub_entry_cnt,global_pre_sub_entry_cnt,global_sub_entry_cnt);
    if(!Opt_D)
        return;

    for(unsigned int i=0;i<110;i++)
    {
        printf("=");
    }
    printf("\n");
    printf("%-33s%-11s%-11s%-17s%-11s\n","Name","Kind","Level","Type","Attribute");
    for(unsigned int i=0;i<110;i++)
    {
        printf("-");
    }
    printf("\n");
    for(unsigned int i=0;i<mysymbol_table[scope_depth].size();i++)
    {
        if(mysymbol_table[scope_depth][i].name[0]==0)
            continue;

        printf("%-33s",mysymbol_table[scope_depth][i].name.c_str()); //safety first
        printf("%-11s",mysymbol_table[scope_depth][i].kind.c_str());
        printf("%-11s",mysymbol_table[scope_depth][i].level_str.c_str());
        printf("%-17s",mysymbol_table[scope_depth][i].type.c_str());
        for(unsigned int j=0;j<mysymbol_table[scope_depth][i].funct_attri.size();j++)
        {
            cout<<mysymbol_table[scope_depth][i].funct_attri[j];
            if(j!=mysymbol_table[scope_depth][i].funct_attri.size()-1)
            {
                cout<<", ";
            }
        }
        printf("\n");

    }
    for(unsigned int i=0;i< 110;i++)
        printf("-");
    printf("\n");
}
int error_detection() //no hashing, just naive solution
{
    //iterator-iterator checking------------------------------------------------------------------------------------//
    // dumpiterator();
    // cout<<"Error detection current scope depth "<<scope_depth<<endl;
    vector<string> redeclared_var;
    string error_msg;
    bool is_error=0, is_final_error=0;
    for(unsigned int i=0;i<myiter_table.size();i++)
    {
        if((myiter_table[i].iter_name==myiter_table.back().iter_name)&&(myiter_table.back().iter_level>myiter_table[i].iter_level))
        {
            redeclared_var.pb(myiter_table[i].iter_name);
            is_error=1;
            is_final_error=1;
            break;
        }
    }
    if(is_error)
    {
        for(unsigned int i=0;i<redeclared_var.size();i++)
        {
            error_msg=": symbol '";
            error_msg+=redeclared_var[i];
            error_msg+="' is redeclared";
            cout<<"<Error> found in Line "<<linenum<<error_msg<<endl;
            error_msg.clear();
        }
    }
    //iterator-variable checking------------------------------------------------------------------------------------//
    redeclared_var.clear();
    is_error=0;
    for(unsigned int i=0;i<mysymbol_table[scope_depth].size();i++)
    {
        if(mysymbol_table[scope_depth][i].name[0]==0)
            continue;
        for(unsigned int j=0;j<myiter_table.size();j++)
        {
            if((mysymbol_table[scope_depth][i].name==myiter_table[j].iter_name)&&(scope_depth==myiter_table[j].iter_level))
            {
                redeclared_var.pb(mysymbol_table[scope_depth][i].name);
                is_error=1;
                is_final_error=1;
                mysymbol_table[scope_depth][i].name[0]=0; //turn off the variable which confilicts with the iterator
            }
        }
    }
    if(is_error)
    {
        for(unsigned int i=0;i<redeclared_var.size();i++)
        {
            error_msg=": symbol '";
            error_msg+=redeclared_var[i];
            error_msg+="' is redeclared";
            cout<<"<Error> found in Line "<<linenum<<error_msg<<endl;
            error_msg.clear();
        }
    }
    //variable-variable checking------------------------------------------------------------------------------------//
    redeclared_var.clear();
    is_error=0;
    for(unsigned int i=0;i<mysymbol_table[scope_depth].size();i++)
    {
        if(mysymbol_table[scope_depth][i].name[0]==0)
            continue;
        for(unsigned int j=i+1;j<mysymbol_table[scope_depth].size();j++)
        {
            if((mysymbol_table[scope_depth][i].name==mysymbol_table[scope_depth][j].name)&&(mysymbol_table[scope_depth][i].level_str==mysymbol_table[scope_depth][j].level_str))
            {
                redeclared_var.pb(mysymbol_table[scope_depth][i].name);
                is_error=1;
                is_final_error=1;
                mysymbol_table[scope_depth][j].name[0]=0; //turn off the variable which confilicts with the iterator
            }
        }
    }
    if(is_error)
    {
        for(unsigned int i=0;i<redeclared_var.size();i++)
        {
            error_msg=": symbol '";
            error_msg+=redeclared_var[i];
            error_msg+="' is redeclared";
            cout<<"<Error> found in Line "<<linenum<<error_msg<<endl;
            error_msg.clear();
        }
    }
    return is_final_error;
}
void radix_converter(char* octal_in)
{
    int decimal_number = 0, remainder;
    int count = 0;
    int octal_number=atoi(octal_in);
    while(octal_number > 0)
    {
        remainder = octal_number % 10;
        decimal_number = decimal_number + remainder * pow(8, count);
        octal_number = octal_number / 10;
        count++;
    }
    const_buf+=to_string(decimal_number);
}
void scientific_converter(char* scientific_in)
{
    float float_converted=atof(scientific_in);
    char tmp[20];
    memset(tmp,0,sizeof(tmp));
    sprintf(tmp,"%f",float_converted);
    const_buf+=tmp;
}
void parse_constant()
{
    const_buf.clear();
    const_buf="";
    switch(const_type)
    {
        case 1:
        {
            const_buf+=yytext;
            break;
        }
        case 2:
        {
            const_buf+="-";
            const_buf+=yytext;
            break;
        }
        case 3:
        {
            const_buf+=yytext;
            break;
        }
        case 4:
        {
            const_buf+="-";
            const_buf+=yytext;
            break;
        }
        case 5:
        {
            scientific_converter(yytext);
            break;
        }
        case 6:
        {
            const_buf+="-";
            scientific_converter(yytext);
            break;
        }
        case 7:
        {
            const_buf+=yytext;
            break;
        }
        case 8:
        {
            const_buf+=yytext;
            break;
        }
        case 9:
        {
            radix_converter(yytext);
            break;
        }
        case 10:
        {
            const_buf+="-";
            radix_converter(yytext);
            break;
        }
    }

}
void array_dimension_parser()
{
    memset(reverse_arr_buf,0,sizeof(reverse_arr_buf));
    int comma_pos=0,reverse_pos=0,quit_parsing_arr_size=0;
    for(int i=49;i>=0;)
    {
        if(arr_buf[i]==',')
        {
            for(int k=i-1;;k--)
            {

                if(arr_buf[k]==',')
                {
                    comma_pos=k;
                    break;
                }
                else if(k==0)
                {
                    comma_pos=-1; //headtype
                    quit_parsing_arr_size=1;
                    break;
                }
            }
            reverse_arr_buf[reverse_pos]='[';
            reverse_pos++;
            for(int j=comma_pos+1;arr_buf[j]!=',';)
            {
                reverse_arr_buf[reverse_pos]=arr_buf[j];
                reverse_pos++;
                j++;
            }
            reverse_arr_buf[reverse_pos]=']';
            reverse_pos++;
            i=comma_pos+1;
        }
        if(quit_parsing_arr_size)
            break;
        else
            i--;
    }
}
void dumpiterator()
{
    printf("---------ITERATOR TABLE --------\n");
    for(unsigned int i=0;i<myiter_table.size();i++)
    {
        if(myiter_table[i].iter_name[0]==0)
            break;
        cout<<myiter_table[i].iter_name<<" and level "<<myiter_table[i].iter_level<<endl;
    }
    printf("---------ITERATOR ENDDD --------\n");
}
int program_name_checking(string program_name_in,string parsed_name,int situation)
{
    int is_error=0;
    if(!situation)
    {
        if(program_name_in!=parsed_name)
        {
            cout<<"<Error> found in Line "<<linenum<<": program end ID inconsist with the file name"<<endl;
            is_error=1;
        }
    }
    else
    {
        if(program_name_in!=mysymbol_table[0][0].name)
        {
            cout<<"<Error> found in Line "<<linenum<<": program end ID inconsist with the file name"<<endl;
            is_error=1;
        }
        if(parsed_name!=mysymbol_table[0][0].name)
        {
            cout<<"<Error> found in Line "<<linenum<<": program end ID inconsist with the beginning ID"<<endl;
            is_error=1;
        }
    }
    return is_error;
}
void procedure_call_checking()
{
    string funct_name = funct_param_buf[0];
    //check if parameter count consistent
    cout<<"Check function name "<<funct_name<<endl;
    for(int i=0;i<funct_param_buf.size();i++)
    {
        cout<<funct_param_buf[i]<<" ";
    }
    cout<<endl;
    for(unsigned int i=0;i<mysymbol_table[0].size();i++)
    {
        if(mysymbol_table[0][i].name == funct_name
        && mysymbol_table[0][i].kind == "function")
        {
            if(funct_param_buf.size()-1!=mysymbol_table[0][i].funct_attri.size())
            {
                cout<<"<Error> found in Line: "<<linenum<<" parameter number inconsistent"<<endl;
                break;
            }
        }
    }
    //check if parameter type consistent
    for(unsigned int i=0;i<mysymbol_table[0].size();i++)
    {
        if(mysymbol_table[0][i].name == funct_name
        && mysymbol_table[0][i].kind == "function")
        {
            for(unsigned int param_idx=0;param_idx<mysymbol_table[0][i].funct_attri.size();param_idx++)
            {
                if(funct_param_buf[param_idx+1]!=mysymbol_table[0][i].funct_attri[param_idx])
                {
                    /*cout<<"funct attri "<<i<<" and paramidx "<<param_idx<<" "
                    <<mysymbol_table[0][i].funct_attri[param_idx]<<"r"<<" with "<<funct_param_buf[param_idx+1]<<"s"<<endl;*/
                    cout<<"<Error> found in Line: "<<linenum<<" parameter type inconsistent"<<endl;
                    return;
                }
            }
        }
    }

}
string find_type(string name_in)
{
    //dumpsymbol();
    for(unsigned int i=0;i<=scope_depth;i++)
    {
        for(unsigned int j=0;j<mysymbol_table[i].size();j++)
        {
            if(mysymbol_table[i][j].name==name_in)
            {
                return mysymbol_table[i][j].type;
            }
        }
    }
    return "none";
}
string find_kind(string name_in)
{
    //dumpsymbol();
    for(unsigned int i=0;i<=scope_depth;i++)
    {
        for(unsigned int j=0;j<mysymbol_table[i].size();j++)
        {
            if(mysymbol_table[i][j].name==name_in)
            {
                return mysymbol_table[i][j].kind;
            }
        }
    }
    return "none";
}
string arr_convert_to_scalar_checking(string LHS_type,string RHS_type)
{
    size_t LHS_arr_dim=count(LHS_type.begin(),LHS_type.end(),'[');
    size_t RHS_arr_dim=count(RHS_type.begin(),RHS_type.end(),'[');
    // cout<<"Line:"<<linenum<<"LHS Array dimension "<<LHS_arr_dim<<" RHS Array dimension "<<RHS_arr_dim<<" Total dimension "<<arr_dim_cnt<<endl;
    //ends here
    string check_LHS_arr;
    if(arr_dim_cnt!=LHS_arr_dim+RHS_arr_dim)
    {
        cout<<"<Error> found in Line: "<<linenum<<" Array reference does not converted to scalar type successfully "<<endl;
        return "error";
    }
    else if(LHS_arr_dim && RHS_arr_dim) //array case by case which has been converted to scalar type successfully, checking whether their type matches
    {
        //find the type name before [] characters and take the substr out
        size_t find5=LHS_type.find("[");
        check_LHS_arr=LHS_type.substr(0,find5-1);
        cout<<"Array has been converted to scalar type :"<<check_LHS_arr<<"QQ"<<endl;
        size_t arr_correct=RHS_type.find(check_LHS_arr);
        if(arr_correct==string::npos)
        {
            cout<<"<Error> found in Line: "<<linenum<<" Assign operation LHS_type and RHS_type inconsistent "<<endl;
            return "error";
        }
        else
        {
            return check_LHS_arr;
        }
    }
    return check_LHS_arr;
}
string assignop(string LHS_type,string RHS_type,string LHS_name, string RHS_name)
{
    cout<<"\n\nAssignop at Line:"<<linenum<<" LHS_type "<<LHS_type<<" RHS_type "<<RHS_type<<endl;
    if(find_kind(LHS_name)=="constant")
    {
        cout<<"<Error> found in Line: "<<linenum<<" constant '"<<LHS_name<<"'cannot be assigned"<<endl;
        return "error";
    }
    if(LHS_type!=RHS_type)
    {
        //special judge for judging the array_type checking the consistency of their dimension
        if(arr_convert_to_scalar_checking(LHS_type,RHS_type)=="error")
        {
            return "error";
        }
        /*if((LHS_arr_dim!=RHS_arr_dim) && LHS_arr_dim && RHS_arr_dim)
        {
            cout<<"<Error> found in Line: "<<linenum<<" Assign operation LHS Array dimension  RHS Array dimension inconsistent "<<endl;
            return "error";
        }*/
        size_t find1=LHS_type.find(RHS_type); //find right in left ex: left string[10] right string is allowed
        size_t find2=RHS_type.find(LHS_type); //find left in right ex: left integer right integer [10] is allowed
        size_t find3=LHS_type.find("real"); //the only allowed conversion is this one
        size_t find4=RHS_type.find("integer"); //the only allowed conversion is this one
        if(!(find3!=string::npos && find4!=string::npos)) //LHS is not real and RHS is not integer
        {
            if(find1==string::npos && find2==string::npos) //LHS does not have the same type
            {
                cout<<"<Error> found in Line: "<<linenum<<" Assign operation LHS_type and RHS_type inconsistent "<<endl;
                return "error";
            }
        }

    }
    return RHS_type;
}
string relop(string LHS_type,string RHS_type,string LHS_name, string RHS_name)
{
    // cout<<"Relop at Line:"<<linenum<<" LHS_type "<<LHS_type<<" RHS_type "<<RHS_type<<endl;

    //if array type since it comes with dimention, so use string find to check if
    size_t find1=LHS_type.find("integer");
    size_t find2=RHS_type.find("real");
    size_t find3=LHS_type.find("real");
    size_t find4=RHS_type.find("integer");
    /*cout<<"FIND 1 "<<find1
        <<"FIND 2 "<<find2
        <<"FIND 3 "<<find3
        <<"FIND 4 "<<find4<<endl;*/
    //check if array has been converted to scalar first and whether their type matches or not
    if(arr_convert_to_scalar_checking(LHS_type,RHS_type)=="error")
    {
        return "error";
    }
    if(find1!=string::npos && find4!=string::npos)
    {
        return "boolean";
    }
    else if(find2!=string::npos && find3!=string::npos)
    {
        return "boolean";
    }
    else if(!(find1!=string::npos && find2!=string::npos)) //LHS RHS diff types expected to be either int real or real int
    {
        if(!(find3!=string::npos && find4!=string::npos)) //LHS RHS Is neither real nor integer
        {
            cout<<"<Error> found in Line: "<<linenum<<" Relational operation LHS_type and RHS_type should be either real or integer type"<<endl;
            return "error";
        }
    }
    return "boolean";
}
string addop(string LHS_type,string RHS_type,string LHS_name, string RHS_name,string oper)
{
    //still chekc the array type first
    cout<<"Addop at Line:"<<linenum<<" LHS_type "<<LHS_type<<" RHS_type "<<RHS_type<<endl;
    size_t find1=LHS_type.find("integer");
    size_t find2=RHS_type.find("real");
    size_t find3=LHS_type.find("real");
    size_t find4=RHS_type.find("integer");
    if(arr_convert_to_scalar_checking(LHS_type,RHS_type)=="error")
    {
        return "error";
    }
    if(oper=="+") //add, operator overloading works for striong type
    {
        size_t LHS_str=LHS_type.find("string");
        size_t RHS_str=LHS_type.find("string");
        if(LHS_str!=string::npos && RHS_str!=string::npos) //LHS RHS if both be the string, then + operator fits the case
        {
            return "string";
        }
        else if(LHS_type.find("integer")!=string::npos && RHS_type.find("integer")!=string::npos)
        {
            return "integer";
        }
        else if(LHS_type.find("real")!=string::npos && RHS_type.find("real")!=string::npos) //LHS is real RHS is integer
        {
            return "real";
        }
        else if(find1!=string::npos && find2!=string::npos) //LHS is integer RHS is real
        {
            return "real";
        }
        else if(find3!=string::npos && find4!=string::npos) //LHS is real RHS is integer
        {
            return "real";
        }
        else if(!(find1!=string::npos && find2!=string::npos)) //LHS RHS diff types expected to be either int real or real int
        {
            if(!(find3!=string::npos && find4!=string::npos)) //LHS RHS Is neither real nor integer
            {
                cout<<"<Error> found in Line: "<<linenum<<" Add operation LHS_type and RHS_type should be either real or integer type"<<endl;
                return "error";
            }
        }
    }
    else
    {
        if(LHS_type.find("integer") && RHS_type.find("integer"))
        {
            return "integer";
        }
        else if(LHS_type.find("real") && RHS_type.find("real")) //LHS is real RHS is integer
        {
            return "real";
        }
        else if(find1!=string::npos && find2!=string::npos) //LHS is integer RHS is real
        {
            return "real";
        }
        else if(find3!=string::npos && find4!=string::npos) //LHS is real RHS is integer
        {
            return "real";
        }
        else if(!(find1!=string::npos && find2!=string::npos)) //LHS RHS diff types expected to be either int real or real int
        {
            if(!(find3!=string::npos && find4!=string::npos)) //LHS RHS Is neither real nor integer
            {
                cout<<"<Error> found in Line: "<<linenum<<" Add operation LHS_type and RHS_type should be either real or integer type"<<endl;
                return "error";
            }
        }
    }
}
/*
void dumpallsymbol()
{
    printf("\n%-110s\n","-------------------ALL SYMBOL TABLE---------------------------------------------------------------------------");
    for(unsigned int i=0;i<110;i++)
    {
        printf("=");
    }
    printf("\n");
    printf("%-33s%-11s%-11s%-17s%-11s\n","Name","Kind","Level","Type","Attribute");
    for(unsigned int i=0;i<110;i++)
    {
        printf("-");
    }
    printf("\n");
    for(unsigned int all_scope_index=0;all_scope_index<SYMBOL_TABLE_MAX_SIZE;all_scope_index++)
    {
        if(allsymbol_table[all_scope_index].size()==0)
            continue;

        for(unsigned int i=0;i<allsymbol_table[all_scope_index].size();i++)
        {
            printf("%-33s",allsymbol_table[all_scope_index][i].name.c_str()); //safety first
            printf("%-11s",allsymbol_table[all_scope_index][i].kind.c_str());
            printf("%-11s",allsymbol_table[all_scope_index][i].level_str.c_str());
            printf("%-17s",allsymbol_table[all_scope_index][i].type.c_str());
            for(unsigned int j=0;j<allsymbol_table[all_scope_index][i].funct_attri.size();j++)
            {
                cout<<allsymbol_table[all_scope_index][i].funct_attri[j];
                if(j!=allsymbol_table[all_scope_index][i].funct_attri.size()-1)
                {
                    cout<<", ";
                }
            }
            printf("\n");
        }
    }
    for(unsigned int i=0;i< 110;i++)
        printf("-");
    printf("\n");
}
void allsymbol_table_error_detection()
{
    for(unsigned int i=0;i<allsymbol_table[scope_depth].size();i++)
    {
        for(unsigned int j=i+1;j<allsymbol_table[scope_depth].size();j++)
        {
            if((allsymbol_table[scope_depth][i].name==allsymbol_table[scope_depth][j].name)
            &&(allsymbol_table[scope_depth][j].kind!="parameter")&&((allsymbol_table[scope_depth][i].kind!="parameter")))
            {
                allsymbol_table[scope_depth].erase(allsymbol_table[scope_depth].begin()+j);
            }
        }
    }
}
*/
