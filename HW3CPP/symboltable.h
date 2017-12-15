/*Data structure without the memory adjusment lololol*/
#ifndef _SYMBOLTABLE_H_
#define _SYMBOLTABLE_H_
#include <bits/stdc++.h>
#define pb push_back
#define SYMBOL_TABLE_MAX_SIZE 1000
#define SUB_ENTRY_SIZE 100
#define BUF_SIZE 50
using namespace std;
extern "C"
{
    int yyerror(const char *msg);
    extern int yylex(void);
}
//global varaible declaration
extern char *yytext;
extern char arr_buf[BUF_SIZE];
extern char reverse_arr_buf[BUF_SIZE];
extern int linenum;		/* declared in lex.l */
extern int Opt_D;
extern int scope_depth;
extern int is_arr;
extern int is_funct;
extern int is_loop;
extern int const_type;
extern string const_buf;
extern string const_type_str;
extern vector<string> id_list_buf; //for multiple ID
extern vector<string> funct_attri_buf; //for concatenating the function attribute
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
//symbol table data structure declaration
struct sub_entry //the real entry for inserting the value
{
    string name;
    string kind;
    string level_str;
    string type;
    vector<string> funct_attri;
    bool is_arr_decl,is_funct_decl;
};
extern vector<vector <sub_entry> > mysymbol_table;
struct loop_iterator
{
    string iter_name;
    int iter_level;
};
extern vector <loop_iterator> myiter_table;
//function prototype declaration
void symbol_table_init();
void inserting_symbol_table(vector<string> , string , string , vector<string> );
void inserting_iter_table(string ,int );
void pop_symbol_table();
void dumpsymbol();
int error_detection(); //no hashing, just naive solution
void parse_constant();
void array_dimension_parser();
void radix_converter(char* );
void scientific_converter(char* );
void dumpiterator();
#endif
