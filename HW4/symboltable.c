#include "symboltable.h"
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
        one_subentry.type = type_in;
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

    // dumpallsymbol();
}
int error_detection() //no hashing, just naive solution
{
    //iterator-iterator checking------------------------------------------------------------------------------------//
    // dumpiterator();
    cout<<"Error detection current scope depth "<<scope_depth<<endl;
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
    allsymbol_table_error_detection();
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
void simple_stmt_checking()
{
    int is_error=0;
    if(assign_check_buf.size()==1) //check if LHS is the constant, which cannot be assigned
    {
        //search the current symbol table
        for(unsigned int i=0;i<mysymbol_table[scope_depth].size();i++)
        {
            if(assign_check_buf[0]==mysymbol_table[scope_depth][i].name
            && mysymbol_table[scope_depth][i].kind=="constant")
            {
                is_error=1;
            }
        }
        //search the global variables
        for(unsigned int i=0;i<mysymbol_table[0].size();i++)
        {
            if(assign_check_buf[0]==mysymbol_table[0][i].name
            && mysymbol_table[0][i].kind=="constant")
            {
                is_error=1;
            }
        }
        string constant_name=assign_check_buf[0];
        if(is_error)
        {
            cout<<"<Error> found in Line "<<linenum<<": constant '"<<constant_name<<"' cannot be assigned"<<endl;
        }
    }
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
                    cout<<"funct attri "<<i<<" and paramidx "<<param_idx<<" "
                    <<mysymbol_table[0][i].funct_attri[param_idx]<<"r"<<" with "<<funct_param_buf[param_idx+1]<<"s"<<endl;
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
