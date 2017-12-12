# Intro. to Compiler Design Project3 Report 0416324 An-Fong Hwu

## Part of the parser.y I have modified to make it interact with my symbol_table.c and symbol_table.h
* Use $$ $1....9 to passing the synthesized and inheritance attribute in the AST, Abstract Syntax Tree in parsing
* ```
%union
{
    char* parsed_string;
}
 ```
Use the aforementioned  %union method to specifically define the type of parsed things, in order to prevent the
bas pointer usage such as ```char* = int``` which sometimes causes the memory issues like segmentation fault and the like.

For each of the parsed nonterminals, use %type<parsed_string> to defined what type it should be assigned after parsed successfully in
CFG and using the %token <parsed_string>to  assign for type of terminal

## How I implement the symbol table
* Data structure
Mainly a static rather than a dynamic memory management (define-like size definition for flexibility)
1.Use struct of struct to implement the double-layered data structure which resembles vector<vector<class> >
where it is specifically defined as follows.
Use char array rather than char pointer to prevent the dangling pointer problem.
```
struct sub_entry //the real entry for inserting the value (to be more specifically, the scope)
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
```
2.
Use another struct o struct to store the loop_iterator for error_detection in for loop of error redeclaration of
variable-variable, variable-iterator and iterator-iterator.
```
struct loop_iterator
{
    char iterator_name[ITER_NAME_SIZE];
    int iterator_level;
};
struct loop_iterator myiter_table[ITERATOR_TABLE_SIZE];
```
* Modular functions coding style for better future implementation of intermediate code generating.
```
void symbol_table_init(); //memset all the symbol to 0 value
void pop_symbol_table(); //pop the symbol table out when leaving the scope, or compound_stmt
void dumpsymbol(); //dumpsymbol
int  error_detection(); //no hashing, just naive solution, checking whether there are redeclaration of certain variables and
turn their flag off when printing (pseudo-deletion method)
void parse_constant(); //parse the constant to store the value of certain constant
void assign_scalar_type(char* );
void assign_constant_type(int, int);
void array_dimension_parser(); //parse the dimension of array correctly
void radix_converter(); //radix_converter for OCT-->DEC
void scientific_converter(); //Convert %e to %d
```
