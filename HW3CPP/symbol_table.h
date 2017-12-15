/*Data structure without the memory adjusment lololol*/
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define SYMBOL_TABLE_MAX_SIZE 1000
#define SUB_ENTRY_SIZE 100
#define BUF_SIZE 50
std::ios_base::sync_with_stdio
//some global variables that needed in the parsing procedure
string tmpstr;
string const_buf;
string const_type_str;
vector<string> id_list_buf; //for multiple ID
vector<string> funct_attri_buf; //for concatenating the function attribute
//0 not constant, 1 int 2 -int  3 float 4 -float 5 scientific 6 -scientific 7 string 8 bool 9 OCTAL 10 -OCTAL
extern char *yytext;
extern char arr_buf[BUF_SIZE];
char arr_buf[BUF_SIZE];
char reverse_arr_buf[BUF_SIZE];
char funct_type_buf_parser[BUF_SIZE];
char funct_attri_buf[BUF_SIZE];
extern int linenum;		/* declared in lex.l */
extern int Opt_D;
int scope_depth;
int global_pre_sub_entry_cnt;
int global_sub_entry_cnt;
int sub_entry_cnt;
int pre_sub_entry_cnt;
int iterator_cnt;
int is_function;
int is_array;
int is_loop;
int const_type;
/*###############################################################################################################
Implementation abstract;
Use symbol table entry for each symebol table main try and the sub entry
for situation like
a parameter 1(local) integer   the first parsed all put into the subentry of symbol table entry
b parameter 1(local) real [2][3] the second parsed all put into the subentry of symbol table entry
c constant  1(local) string "hello world!" the third parsed all put into the subentry of symbol table entry

Detail for every declarations
1.For some of the decl_list, once the scalar_type has reached, marked all that sub_entry to be the same types
e.g. var i, k : integer
that is mysymbol_table[scope_depth].mysymbol_table[:sub_entry_cnt]=type and they have thier own name, but all count as variable
2.
var i, k : integer from pre_sub_entry_cnt=0 to sub_entry_cnt 2 (exclude 2)
var j, m, n ,p : real from pre_sub_entry_cnt=2 to sub_entry_cnt 6(exclude6)
that is once a var is redeclared, the pre_sub_entry_cnt<---->sub_entry_cnt symbolizes how many var ID in this segment to be parsed in one line
3.
func_decl
4.
If it is an array type, say b:array 1 to 2 of array 2 to 4 of real
than after parsing the array token. mark the array boolean to be true and after reach the end of scalar type
strcat all the type in same buf
###############################################################################################################*/
struct sub_entry //the real entry for inserting the value
{
    string name;
    string kind;
    string level_str;
    string type_buf;
    vector<string> funct_attri;
    bool is_array_decl,is_funct_decl;
};
vector<vector <sub_entry> > mysymbol_table;
struct loop_iterator
{
    string iter_name;
    int iter_level;
};
vector <loop_iterator> myiter_table;
void symbol_table_init();
void pop_symbol_table();
void dumpsymbol();
int  error_detection(); //no hashing, just naive solution
void parse_constant();
void assign_scalar_type(char* );
void assign_constant_type(int, int);
void array_dimension_parser();
void radix_converter();
void scientific_converter();
void dumpiterator();
/*
Implementation Here
*/
void symbol_table_init()
{
    mysymbol_table.resize(SYMBOL_TABLE_MAX_SIZE);
    scope_depth=0;
    is_array = 0;
    is_function=0;
    is_loop=0;
    const_type=0;
}
void inserting_symbol_table(vector<string> id_list_buf, string kind_in, string type_in, vector<string> funct_attri_buf)
{
    for(int i=0;i<id_list_buf.size();i++)
    {
        mysub_entry one_subentry;
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
        if(funct_attri_buf.size())
        {
            one_subentry.funct_attri = funct_attri_buf;
        }
        mysymbol_table[scope_depth].pb(one_subentry);
    }
}
void inserting_iter_table(string iter_name_in,int iter_level_in)
{
    myiter_table one_iter_table;
    one_iter_table.iter_name = iter_name_in;
    one_iter_table.iter_level = iter_level_in;
    myiter_table.pb(one_iter_table);
}
void pop_symbol_table()
{
    mysymbol_table[scope_depth].clear();//pop the table at that table, easliy pop
    scope_depth=(scope_depth==0)?0:scope_depth-1; //shirnk the level
    myiter_table.clear(); //clean the iterator table
}
void dumpsymbol()
{
    //printf("(In dump function)Scope depth %d, pre_sub_entry_cnt %d sub_entry_cnt %d global_pre_sub_entry_cnt %d global_sub_entry_cnt %d\n",scope_depth,pre_sub_entry_cnt,sub_entry_cnt,global_pre_sub_entry_cnt,global_sub_entry_cnt);
    if(!Opt_D)
        return;

    for(int i=0;i<110;i++)
    {
        printf("=");
    }
    printf("\n");
    printf("%-33s%-11s%-11s%-17s%-11s\n","Name","Kind","Level","Type","Attribute");
    for(int i=0;i<110;i++)
    {
        printf("-");
    }

    for(int i=0;i< 110;i++)
        printf("-");
    printf("\n");
}
int error_detection() //no hashing, just naive solution
{
    //iterator-iterator checking------------------------------------------------------------------------------------//
    vector<string> redeclared_var;
    string error_msg;
    bool is_error=0, is_final_error=0;
    for(int i=0;i<myiter_table.size();i++)
    {
        for(int j=0;j<myiter_table.size();j++)
        {
            if((myiter_table[i].iter_name==myiter_table[j].iter_name)&&(myiter_table[j].iter_level>myiter_table[i].iter_level))
            {
                redeclared_var.pb(myiter_table[i].iter_name);
                is_error=1;
                is_final_error=1;
            }
        }
    }
    if(is_error)
    {
        for(int i=0;i<redeclared_var.size();i++)
        {
            error_msg=" symbol ";
            error_msg+=redeclared_var[i];
            error_msg+=" is redeclared"
            cout<<"<Error> found in Line "<<linenum<<error_msg<<endl;
            error_msg.clear();
        }
    }
    //iterator-variable checking------------------------------------------------------------------------------------//
    redeclared_var.clear();
    is_error=0;
    for(int i=0;i<mysymbol_table[scope_depth].size();i++)
    {
        if(mysymbol_table[scope_depth][i].name[0]==0)
            continue;
        for(int j=0;j<myiter_table.size();j++)
        {
            if((myiter_table[i].iter_name==myiter_table[j].iter_name)&&(myiter_table[j].iter_level>myiter_table[i].iter_level))
            {
                redeclared_var.pb(myiter_table[i].iter_name);
                is_error=1;
                is_final_error=1;
                mysymbol_table[scope_depth][i].name[0]=0; //turn off the variable which confilicts with the iterator
            }
        }
    }
    if(is_error)
    {
        for(int i=0;i<redeclared_var.size();i++)
        {
            error_msg=" symbol ";
            error_msg+=redeclared_var[i];
            error_msg+=" is redeclared"
            cout<<"<Error> found in Line "<<linenum<<error_msg<<endl;
            error_msg.clear();
        }
    }
    //variable-variable checking------------------------------------------------------------------------------------//
    redeclared_var.clear();
    is_error=0;
    for(int i=0;i<mysymbol_table[scope_depth].size();i++)
    {
        for(int j=0;j<mysymbol_table[scope_depth].size();j++)
        {
            if(mysymbol_table[scope_depth][i].name==mysymbol_table[scope_depth][j].name)
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
        for(int i=0;i<redeclared_var.size();i++)
        {
            error_msg=" symbol ";
            error_msg+=redeclared_var[i];
            error_msg+=" is redeclared"
            cout<<"<Error> found in Line "<<linenum<<error_msg<<endl;
            error_msg.clear();
        }
    }
    return is_final_error;
}

void parse_constant()
{
    char convert_tmp[20];
    memset(const_buf,0,sizeof(const_buf));
    memset(convert_tmp,0,sizeof(convert_tmp));
    float float_tmp=0.0f;
    switch(const_type)
    {
        case 1:
        {
            strcpy(const_buf,yytext);
            break;
        }
        case 2:
        {
            strcat(const_buf,"-");
            strcat(const_buf,yytext);
            break;
        }
        case 3:
        {

            float_tmp=atof(yytext);
            sprintf(convert_tmp,"%f",float_tmp);
            strcat(const_buf,convert_tmp);
            break;
        }
        case 4:
        {
            strcat(const_buf,"-");
            float_tmp=atof(yytext);
            sprintf(convert_tmp,"%f",float_tmp);
            strcat(const_buf,convert_tmp);
            break;
        }
        case 5:
        {
            scientific_converter(yytext);
            break;
        }
        case 6:
        {
            strcat(const_buf,"-");
            scientific_converter(yytext);
            break;
        }
        case 7:
        {
            strcat(const_buf,yytext);
            break;
        }
        case 8:
        {
            strcat(const_buf,yytext);
            break;
        }
        case 9:
        {
            radix_converter(yytext);
            break;
        }
        case 10:
        {
            strcat(const_buf,"-");
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
void radix_converter(char* octal_in)
{
    int decimal_number = 0, remainder;

    int count = 0;
    int octal_number=atoi(octal_in);
    char tmp[20];
    while(octal_number > 0)
    {
        remainder = octal_number % 10;
        decimal_number = decimal_number + remainder * pow(8, count);
        octal_number = octal_number / 10;
        count++;
    }
    memset(tmp,0,sizeof(tmp));
    sprintf(tmp,"%d",decimal_number);
    strcat(const_buf,tmp);
}
void scientific_converter(char* scientific_in)
{
    float float_converted=atof(scientific_in);
    char tmp[20];
    memset(tmp,0,sizeof(tmp));
    sprintf(tmp,"%f",float_converted);
    strcat(const_buf,tmp);
}
void dumpiterator()
{
    /*printf("---------ITERATOR TABLE --------\n");
    for(int i=0;i<ITERATOR_TABLE_SIZE;i++)
    {
            if(myiter_table[i].iter_name[0]==0)
            break;
        printf("%s and depth %d\n",myiter_table[i].iter_name,myiter_table[i].iter_level);
    }
    printf("---------ITERATOR TABLE --------\n");*/
}
