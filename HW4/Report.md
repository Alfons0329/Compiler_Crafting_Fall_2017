# Introduction to Compiler Design Project4 Report 0416324 An-Fong Hwu

## Part of the parser.y I have modified to make it interact with my symbol_table.c and symbol_table.h
* Use $$ $1....9 to passing the synthesized and inheritance attribute in the AST, Abstract Syntax Tree in parsing
* ```
%union
{
    char* parsed_string;
}
 ```
* Use the following data structure to implementing the symbol table and type checking
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
