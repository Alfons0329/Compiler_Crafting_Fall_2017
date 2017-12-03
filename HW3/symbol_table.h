/*Data structure without the memory adjusment lololol*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#define SYMBOL_TABLE_MAX_SIZE 10000
#define SUB_ENTRY_SIZE 20
#define ITERATOR_TABLE_SIZE 50
#define ITER_NAME_SIZE 32
#define NAME_SIZE 40
#define TYPE_SIZE 40
#define LEVEL_STR_SIZE 20
#define FUNCT_BUF_SIZE 100
#define ATTRI_BUF_SIZE 100
#define ARRAY_BUF_SIZE 100
#define PARAM_BUF_SIZE 100
extern char *yytext;
extern char arr_buf[50];
extern char reverse_arr_buf[50];
extern char const_buf[50];
extern char funct_type_buf_parser[50];
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
    char name[NAME_SIZE];
    char kind[11];
    char level_str[LEVEL_STR_SIZE];
    char type[17];
    char funct_type_buf[FUNCT_BUF_SIZE];
    char attri_type_buf[ATTRI_BUF_SIZE];
    char array_type_buf[ARRAY_BUF_SIZE];
    char param_type_buf[PARAM_BUF_SIZE];
    int level;
    bool is_array_decl,is_funct_decl,is_iterator;
};
struct symbol_table_entry
{
    struct sub_entry mysub_entry[SUB_ENTRY_SIZE];
};
struct symbol_table_entry mysymbol_table[SYMBOL_TABLE_MAX_SIZE];
struct loop_iterator
{
    char iterator_name[ITER_NAME_SIZE];
    int iterator_level;
};
struct loop_iterator myiter_table[ITERATOR_TABLE_SIZE];
void symbol_table_init();
void pop_symbol_table();
void dumpsymbol();
void error_detection(); //no hashing, just naive solution
void parse_constant();
void assign_scalar_type(char* );
void array_dimension_parser();
void radix_converter();
void scientific_converter();
void dumpiterator();
