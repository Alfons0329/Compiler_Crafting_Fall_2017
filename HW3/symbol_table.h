/*Data structure without the memory adjusment lololol*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SYMBOL_TABLE_MAX_SIZE 10000
#define SUB_ENTRY_SIZE 20
#define ARRAY_BUF_SIZE 100
#define PARAM_BUF_SIZE 100
#define ATTRI_BUF_SIZE 100
int scope_depth;
int sub_entry_cnt;
int pre_sub_entry_cnt;
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
    char* name;
    char* kind;
    char* level_str;
    char* type;
    char attri_type_buf[ATTRI_BUF_SIZE];
    char array_type_buf[ARRAY_BUF_SIZE];
    char param_type_buf[PARAM_BUF_SIZE];
    int level;
    bool is_array_decl;
}
struct symbol_table_entry
{
    struct sub_entry mysub_entry[SUB_ENTRY_SIZE];
}

extern struct symbol_table mysymbol_table[SYMBOL_TABLE_MAX_SIZE];
void symbol_table_init()
{
    /*for(int i=0;i<SYMBOL_TABLE_MAX_SIZE;i++)
    {
        memset(mysymbol_table[i].name,0,sizeof(mysymbol_table.name));
        memset(mysymbol_table[i].kind,0,sizeof(mysymbol_table.kind));
        memset(mysymbol_table[i].level_str,0,sizeof(mysymbol_table.level_str));
        memset(mysymbol_table[i].type,0,sizeof(mysymbol_table.type));
        memset(mysymbol_table[i].attribute,0,sizeof(mysymbol_table.attribute));
        mysymbol_table[i].level=0;
    }*/
    scope_depth=0;
    sub_entry_cnt=0;
    pre_sub_entry_cnt=0;
}
void push_symbol_table(symbol_table_entry sen,int scope_depth)
{
    symbol_table_entry[scope_depth]=sen;
}
void pop_symbol_table()
{
    scope_depth=(scope_depth==0)?0:scope_depth-1;
}
void dumpsymbol()
{
    if(!Opt_D)
        return;

    int i,j;
    for(i=0;i<110;i++)
    {
        printf("=");
        printf("\n");
        printf("%-33s%-11s%-11s%-17s%-11s\n","Name","Kind","Level","Type","Attribute");
        for(i=0;i<stack_size;i++)
        {
            for(j=0;j<110;j++)
            {
                printf("-");
                printf("\n");
                {
                    printf("%-33s",) ;
                    printf("%-11s",);
                    printf("%d%-10s",);
                    printf("%-17s",);
                    printf("%-11s",);
                    printf("\n");
                }
            }
        }
    }
    for(i=0;i< 110;i++)
        printf("-");
    printf("\n");
}
void error_detection() //no hashing, just naive solution
{
    char error_msg[100];
    strcat(error_msg,"symbol '");
    for(int i=0;i<SUB_ENTRY_SIZE;i++)
    {
        for(int j=i+1;j<SUB_ENTRY_SIZE;j++)
        {
            if(mysymbol_table[scope_depth].sub_entry[i].name==mysymbol_table[scope_depth].sub_entry[j].name)
            {
                strcat(error_msg,mysymbol_table[scope_depth].sub_entry[i].name);
                strcat(error_msg,"' is redeclared");
                printf("<Error> found in Line %d: %s\n", linenum, error_msg);
            }
        }
    }
}
