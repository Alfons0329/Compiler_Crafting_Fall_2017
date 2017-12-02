#include "symbol_table.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void symbol_table_init()
{
    for(int i=0;i<SYMBOL_TABLE_MAX_SIZE;i++)
    {
        for(int j=0;j<SUB_ENTRY_SIZE;j++)
        {
            memset(mysymbol_table[i].mysub_entry[j].attri_type_buf,0,sizeof(mysymbol_table[i].mysub_entry[j].attri_type_buf));
            memset(mysymbol_table[i].mysub_entry[j].array_type_buf,0,sizeof(mysymbol_table[i].mysub_entry[j].array_type_buf));
            memset(mysymbol_table[i].mysub_entry[j].param_type_buf,0,sizeof(mysymbol_table[i].mysub_entry[j].param_type_buf));
            mysymbol_table[i].mysub_entry[j].is_array_decl=false;
        }
    }
    scope_depth=0;
    sub_entry_cnt=0;
    pre_sub_entry_cnt=0;
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
    }
    printf("\n");
    printf("%-33s%-11s%-11s%-17s%-11s\n","Name","Kind","Level","Type","Attribute");
    printf("\n");
    for(int i=0;i<SUB_ENTRY_SIZE;i++)
    {
        printf("%-33s",mysymbol_table[scope_depth].mysub_entry[i].name);
        printf("%-11s",mysymbol_table[scope_depth].mysub_entry[i].kind);
        printf("%-10s",mysymbol_table[scope_depth].mysub_entry[i].level_str);
        printf("%-17s",(mysymbol_table[scope_depth].mysub_entry[i].is_array_decl)?mysymbol_table[scope_depth].mysub_entry[i].array_type_buf:mysymbol_table[scope_depth].mysub_entry[i].type);
        printf("%-11s",mysymbol_table[scope_depth].mysub_entry[i].attri_type_buf);
        printf("\n");
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
            if(mysymbol_table[scope_depth].mysub_entry[i].name==mysymbol_table[scope_depth].mysub_entry[j].name)
            {
                strcat(error_msg,mysymbol_table[scope_depth].mysub_entry[i].name);
                strcat(error_msg,"' is redeclared");
                printf("<Error> found in Line %d: %s\n", linenum, error_msg);
            }
        }
    }
}
