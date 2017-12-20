# Introduction to Compiler Design Project4 Report 0416324 An-Fong Hwu

## Part of the parser.y I have modified to make it interact with my symbol_table.c and symbol_table.h
* Use $$ $1....9 to passing the synthesized and inheritance attribute in the AST, Abstract Syntax Tree in parsing
```
%union
{
    char* parsed_string;
}
```
## How I implement the symbol table

* Use the following data structure to implementing the symbol table and type checking.
1.
The first is sub_entry and it is used to store the element in symbol table, the structure is 2D vector, inshort
the row in the vector represents the current scope_depth of the program and the column represents each element
in that scope_depth.
For instance, suppose I want to access the i-th element in scope_depth S then the data will be mysymbol_table[S][i]
2.
Second struct is used to store the iterator for type checking such as the loop_iterator cannot be redeclared in the
loop and the like.
3.
Thired is the parameter, which mainly implemented in the project this time since we have to ehcke the parameter for both
of their dimension ,length and the type (or say the hardest part, the array type checking)
```
struct sub_entry //the real entry for inserting the value to symbol table
{
    string name;
    string kind;
    string level_str;
    string type;
    vector<int> arr_dim;
    vector<string> funct_attri;
    bool is_arr_decl,is_funct_decl;
};
extern vector<vector <sub_entry> > mysymbol_table;
struct loop_iterator //loop oterator checking
{
    string iter_name;
    int iter_level;
};
extern vector <loop_iterator> myiter_table;
//operation data structures
//data structure for parameter processing starts here
struct param_struct //
{
    int param_dim;
    string param_name;
};
```
* Make yylval available in lex scanner to prevent the null char pointer corruption (segfault) in parser since
such mechanism can passed the required value and information from scanner to parser.
Such as, where yylval can be passed into yacc parser and return the token OP_ADD
```
"+"				{ tokenChar('+');yylval.str=strdup(yytext); return OP_ADD; }
```
* Modular functions coding style for better future implementation of intermediate code generating.
```
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
void procedure_call_checking();
//operations type ckecking
string find_type(string);
string find_kind(string);
string arr_convert_to_scalar_checking(string,string); //for checking the correctness of two array
string assignop(string,string,string,string);
string relop(string,string,string,string);
string addop(string,string,string,string,string);
string mulop(string,string,string,string,string);
string boolop(string,string,string,string);
string simple(string); //for checking the simple statement
string condition(string,string); //for checking the conditional statement
string has_scalar(string,int,string);
void perfect();
```
