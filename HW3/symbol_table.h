/*Data structure without the memory adjusment lololol*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SYMBOL_TABLE_MAX_SIZE 10000
#define SUB_ENTRY_SIZE 20
int scope_depth;
int sub_entry_cnt;
/*###############################################################################################################
Implementation abstract;
Use symbol table entry for each symebol table main try and the sub entry
for situation like
a parameter 1(local) integer   the first parsed all put into the subentry of symbol table entry
b parameter 1(local) real [2][3] the second parsed all put into the subentry of symbol table entry
c constant  1(local) string "hello world!" the third parsed all put into the subentry of symbol table entry

###############################################################################################################*/
struct sub_entry //the real entry for inserting the value
{
    char* name;
    char* kind;
    char* level_str;
    char* type;
    char* attribute;
    int level;
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
    sub_entry_cnt;
}
void push_symbol_table(symbol_table_entry sen,int scope_depth)
{
    symbol_table_entry[scope_depth]=sen;
}
void pop_symbol_table()
{
    stack_size=(stack_size==0)?0:stack_size-1;
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
