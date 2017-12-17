//Data structure without the memory adjusment lololol
#ifndef _SYMBOLTABLE_
#define _SYMBOLTABLE_
#include <bits/stdc++.h>
#define pb push_back
#define SYMBOL_TABLE_MAX_SIZE 1000
#define SUB_ENTRY_SIZE 100
#define BUF_SIZE 50
using namespace std;
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
//global varaible declaration for HW4 semantic analysis
extern int is_proc_call;
extern string program_name;
extern vector<string> assign_check_buf;
extern vector<string> funct_param_buf;
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
//operation data structures
//function prototype declaration for HW3 symbol table implementation
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
//function prototype declaration for HW4 semantic analysis
int program_name_checking(string,string,int);
int op_assign_checking(string );
void dumpallsymbol();
void allsymbol_table_error_detection();
void procedure_call_checking();
//operations
string find_type(string);
string find_kind(string);
string assignop(string,string,string,string);
void addop();
#endif
