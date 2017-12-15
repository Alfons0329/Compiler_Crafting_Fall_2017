/*Data structure without the memory adjusment lololol*/
#include <bits/stdc++.h>
#define pb push_back
#define SYMBOL_TABLE_MAX_SIZE 1000
#define SUB_ENTRY_SIZE 100
#define BUF_SIZE 50
//some global variables that needed in the parsing procedure
string tmpstr;
string const_buf;
vector<string> id_list_buf; //for multiple ID
vector<string> funct_attri_buf; //for concatenating the function attribute
//0 not constant, 1 int 2 -int  3 float 4 -float 5 scientific 6 -scientific 7 string 8 bool 9 OCTAL 10 -OCTAL
extern char *yytext;
extern char arr_buf[BUF_SIZE];
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
    char iterator_name[ITER_NAME_SIZE];
    int iterator_level;
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
    global_sub_entry_cnt=0;
    global_pre_sub_entry_cnt=0;
    sub_entry_cnt=0;
    pre_sub_entry_cnt=0;
    iterator_cnt=0;
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
        one_subentry.name = id_list_buf[i];
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
    printf("\n");
    for(int i=0;i<SUB_ENTRY_SIZE;i++)
    {
        if(mysymbol_table[scope_depth].mysub_entry[i].name[0]==0)
            continue;

        if(mysymbol_table[scope_depth].mysub_entry[i].name[33]!=0)
        {
            for(int j=0;j<32;j++)
            {
                printf("%c",mysymbol_table[scope_depth].mysub_entry[i].name[j]==0?32:mysymbol_table[scope_depth].mysub_entry[i].name[j]); //cool method lolol
            }
            printf(" ");
        }
        else
        {
            printf("%-33s",mysymbol_table[scope_depth].mysub_entry[i].name);
        }
        if(mysymbol_table[scope_depth].mysub_entry[i].kind)
            printf("%-11s",mysymbol_table[scope_depth].mysub_entry[i].kind);

        printf("%-11s",mysymbol_table[scope_depth].mysub_entry[i].level_str);
        if(mysymbol_table[scope_depth].mysub_entry[i].is_array_decl)
        {
            printf("%-17s",mysymbol_table[scope_depth].mysub_entry[i].array_type_buf);
        }
        else if(mysymbol_table[scope_depth].mysub_entry[i].is_funct_decl)
        {
            printf("%-17s",mysymbol_table[scope_depth].mysub_entry[i].funct_type_buf[0]==0?"void":mysymbol_table[scope_depth].mysub_entry[i].funct_type_buf);
        }
        else
        {
            printf("%-17s",mysymbol_table[scope_depth].mysub_entry[i].type);
        }
        for(int j=0;j<ATTRI_BUF_SIZE;)
        {
            if(mysymbol_table[scope_depth].mysub_entry[i].attri_type_buf[j]==0)
                break;
            else if(mysymbol_table[scope_depth].mysub_entry[i].attri_type_buf[j]==','&&mysymbol_table[scope_depth].mysub_entry[i].attri_type_buf[j+1]==0)
                break;
            else if(mysymbol_table[scope_depth].mysub_entry[i].attri_type_buf[j]==' '&&mysymbol_table[scope_depth].mysub_entry[i].attri_type_buf[j+1]==',')
            {
                j+=2;
                if(mysymbol_table[scope_depth].mysub_entry[i].attri_type_buf[j]==0)
                    break;
                else
                    printf(", ");
                //printf("This is type2 printf ");
            }
            else
            {
                printf("%c",mysymbol_table[scope_depth].mysub_entry[i].attri_type_buf[j]);
                j++;
            }
        }
        printf("\n");
    }
    for(int i=0;i< 110;i++)
        printf("-");
    printf("\n");
}
int  error_detection() //no hashing, just naive solution
{
    char error_msg[200];
    char redeclared_var[100];
    memset(error_msg,0,sizeof(error_msg));
    memset(redeclared_var,0,sizeof(redeclared_var));
    int redeclared_index=0,is_error=0,is_parsed=0,pre_redeclared_index=0,is_final_error=0;
    //loop iterator-loop iterator detection
    for(int i=0;i<ITERATOR_TABLE_SIZE;i++)
    {
        for(int j=i+1;j<ITERATOR_TABLE_SIZE;j++)
        {
            if(!strncmp(myiter_table[i].iterator_name,myiter_table[j].iterator_name,32)&&
            (myiter_table[j].iterator_level>myiter_table[i].iterator_level))
            {
                //printf("Found iter same with iter!!\n");
                for(;myiter_table[i].iterator_name[pre_redeclared_index]!=0&&pre_redeclared_index<33;)
                {

                    //printf("push name %c\n",myiter_table[i].iterator_name[pre_redeclared_index]);
                    redeclared_var[redeclared_index]=myiter_table[i].iterator_name[pre_redeclared_index];
                    pre_redeclared_index+=1;
                    redeclared_index+=1;
                    //printf("same at i %d redeclared_index %d\n",i,redeclared_index);
                }
                redeclared_var[redeclared_index]=',';
                redeclared_index+=1;
                pre_redeclared_index=0;
                is_error=1;
                break;
            }

        }
    }
    if(is_error)
    {
        for(int i=0;redeclared_var[i]!=0;)
        {
            memset(error_msg,0,sizeof(error_msg));
            strcat(error_msg,"symbol ");

            for(int j=i,cnt=0;redeclared_var[j]!=',';j++,cnt++) //cnt for substring parsing index
            {
                error_msg[cnt+7]=redeclared_var[j];  //parse the redeclaration ID string
                i=j;
                is_parsed=1; //error messgae parsed successfully
            }
            i+=1;
            if(redeclared_var[i]==0)
                break;
            strcat(error_msg," is redeclared");
            if(is_parsed)
                printf("<Error> found in Line %d: %s\n", linenum, error_msg);

            is_parsed=0;
        }
        is_error=0;
	is_final_error=1;
    }
    //variable-iterator detection
    redeclared_index=0,is_error=0,is_parsed=0,pre_redeclared_index=0;
    memset(error_msg,0,sizeof(error_msg));
    memset(redeclared_var,0,sizeof(redeclared_var));
    for(int i=0;i<SUB_ENTRY_SIZE;i++)
    {
        if(mysymbol_table[scope_depth].mysub_entry[i].name[0]==0)
            continue;
        for(int j=0;j<ITERATOR_TABLE_SIZE;j++)
        {
            if(!strncmp(mysymbol_table[scope_depth].mysub_entry[i].name,myiter_table[j].iterator_name,32)&&
            scope_depth==myiter_table[j].iterator_level)
            {

                for(;mysymbol_table[scope_depth].mysub_entry[i].name[pre_redeclared_index]!=0&&pre_redeclared_index<33;)
                {
                    //printf("Found iter same with variable!! name is %s\n",mysymbol_table[scope_depth].mysub_entry[i].name);
                    //printf("push name %c\n",mysymbol_table[scope_depth].mysub_entry[i].name[pre_redeclared_index]);
                    redeclared_var[redeclared_index]=mysymbol_table[scope_depth].mysub_entry[i].name[pre_redeclared_index];
                    pre_redeclared_index+=1;
                    redeclared_index+=1;
                    //printf("same at i %d redeclared_index %d\n",i,redeclared_index);
                }
                mysymbol_table[scope_depth].mysub_entry[i].name[0]=0;//mark the error table as not print
                redeclared_var[redeclared_index]=',';
                redeclared_index+=1;
                pre_redeclared_index=0;
                is_error=1;
                break;
            }
        }
    }
    if(is_error)
    {
        //printf("Error with iter-variable \n");
        for(int i=0;redeclared_var[i]!=0;)
        {
            memset(error_msg,0,sizeof(error_msg));
            strcat(error_msg,"symbol ");
            for(int j=i,cnt=0;redeclared_var[j]!=',';j++,cnt++) //cnt for substring parsing index
            {
                error_msg[cnt+7]=redeclared_var[j];  //parse the redeclaration ID string
                i=j;
                is_parsed=1; //error messgae parsed successfully
            }
            i+=1;
            if(redeclared_var[i]==0)
                break;
            strcat(error_msg," is redeclared");
            if(is_parsed)
                printf("<Error> found in Line %d: %s\n", linenum, error_msg);

            is_parsed=0;
        }
        is_error=0;
	is_final_error=1;
    }
    //variable-variable detection
    redeclared_index=0,is_error=0,is_parsed=0,pre_redeclared_index=0;
    memset(error_msg,0,sizeof(error_msg));
    memset(redeclared_var,0,sizeof(redeclared_var));
    for(int i=0;i<SUB_ENTRY_SIZE;i++)
    {
        //printf("\ni now %dname first %s ",i,mysymbol_table[scope_depth].mysub_entry[i].name);
        if(mysymbol_table[scope_depth].mysub_entry[i].name[0]==0)
            continue;
        for(int j=i+1;j<SUB_ENTRY_SIZE;j++)
        {
            //printf("j now %dand %s \n",j,mysymbol_table[scope_depth].mysub_entry[j].name);
            if(!strncmp(mysymbol_table[scope_depth].mysub_entry[i].name,mysymbol_table[scope_depth].mysub_entry[j].name,32))
            {
                //printf("Found same variable and variable \n");
                mysymbol_table[scope_depth].mysub_entry[j].name[0]=0;//mark the error table as not print
                for(;mysymbol_table[scope_depth].mysub_entry[i].name[pre_redeclared_index]!=0&&pre_redeclared_index<33;)
                {

                    //printf("push name %c\n",mysymbol_table[scope_depth].mysub_entry[i].name[pre_redeclared_index]);
                    redeclared_var[redeclared_index]=mysymbol_table[scope_depth].mysub_entry[i].name[pre_redeclared_index];
                    pre_redeclared_index+=1;
                    redeclared_index+=1;
                    //printf("same at i %d redeclared_index %d\n",i,redeclared_index);
                }
                redeclared_var[redeclared_index]=',';
                redeclared_index+=1;
                pre_redeclared_index=0;
                is_error=1;
                break;
            }
        }
    }
    if(is_error)
    {
        for(int i=0;redeclared_var[i]!=0;)
        {
            memset(error_msg,0,sizeof(error_msg));
            strcat(error_msg,"symbol ");

            for(int j=i,cnt=0;redeclared_var[j]!=',';j++,cnt++) //cnt for substring parsing index
            {
                error_msg[cnt+7]=redeclared_var[j];  //parse the redeclaration ID string
                i=j;
                is_parsed=1; //error messgae parsed successfully
            }
            i+=1;
            if(redeclared_var[i]==0)
                break;
            strcat(error_msg," is redeclared");
            if(is_parsed)
                printf("<Error> found in Line %d: %s\n", linenum, error_msg);

            is_parsed=0;
        }
        is_error=0;
	is_final_error=1;
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
void assign_constant_type(int scope_depth,int index)
{
    switch(const_type)
    {

        case 1 ... 2:
        {
            strcpy(mysymbol_table[scope_depth].mysub_entry[index].type,"integer ");
            break;
        }
        case 3 ... 4:
        {
            strcpy(mysymbol_table[scope_depth].mysub_entry[index].type,"real ");
            break;
        }
        case 5 ... 6:
        {
            strcpy(mysymbol_table[scope_depth].mysub_entry[index].type,"real ");
            break;
        }
        case 7:
        {
            strcpy(mysymbol_table[scope_depth].mysub_entry[index].type,"string ");
            break;
        }
        case 8:
        {
            strcpy(mysymbol_table[scope_depth].mysub_entry[index].type,"boolean ");
            break;
        }
        case 9 ... 10:
        {
            strcpy(mysymbol_table[scope_depth].mysub_entry[index].type,"integer ");
            break;
        }
    }
    strcpy(mysymbol_table[scope_depth].mysub_entry[index].attri_type_buf,const_buf);
}
void assign_scalar_type(char* type_in)
{
    //printf("type in %s FUNCTION OR NOTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTTT %d\n",type_in,is_function);
    //printf("(In dump function)Scope depth %d, pre_sub_entry_cnt %d sub_entry_cnt %d global_pre_sub_entry_cnt %d global_sub_entry_cnt %d\n",scope_depth,pre_sub_entry_cnt,sub_entry_cnt,global_pre_sub_entry_cnt,global_sub_entry_cnt);
    if(scope_depth==0)
    {
        if(is_function)
        {
            //printf("TYPE IN LOOP %s \n\n",type_in);
            for(int i=global_pre_sub_entry_cnt;i<global_sub_entry_cnt;i++)
            {
                strcat(mysymbol_table[scope_depth].mysub_entry[i].funct_type_buf,type_in);
            }
        }
        else
        {
            for(int i=global_pre_sub_entry_cnt;i<global_sub_entry_cnt;i++)
            {
                strcat(mysymbol_table[scope_depth].mysub_entry[i].array_type_buf,type_in);
            }
        }

    }
    else
    {
        for(int i=pre_sub_entry_cnt;i<sub_entry_cnt;i++)
        {
            strcat(mysymbol_table[scope_depth].mysub_entry[i].array_type_buf,type_in);
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
        if(myiter_table[i].iterator_name[0]==0)
            break;
        printf("%s and depth %d\n",myiter_table[i].iterator_name,myiter_table[i].iterator_level);
    }
    printf("---------ITERATOR TABLE --------\n");*/
}
