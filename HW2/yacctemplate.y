%{
#include <stdio.h>
#include <stdlib.h>

extern int linenum;             /* declared in lex.l */
extern FILE *yyin;              /* declared by lex */
extern char *yytext;            /* declared by lex */
extern char buf[256];           /* declared in lex.l */
%}
// symbols
%token COMMA SEMICOLON COLON BRACELEFT BRACERIGHT BRACKETLEFT BRACKETRIGHT

//assign, which is right associative

// mathematical operators
%right ASSIGN
%left LESS LESSEQUAL LESSGREATER GREATEREQUAL GREATER EQUAL
%left PLUS MINUS
%left MULTIPLY DIVIDE MOD
%left NOT
%left AND OR
%nonassoc UNARY_NEGATIVE

// logical operators


// KW
%token KWARRAY KWBEGIN KWBOOLEAN KWDEF KWDO KWELSE KWEND KWFALSSE KWFOR KWINTEGER
%token KWIF KWOF KWPRINT KWREAD KWREAL KWSTRING KWTHEN KWTO KWTRUE KWRETURN KWVAR KWWHILE

//mathematical numbers
%token OCTAL INTEGER FLOAT SCIENTIFIC

//identifier
%token IDENT

//others
%token STRING

%%
/*use non-capital for non terminal and capital for terminal*/
/*2.1  Program Units */
/*Program */
program	: programname SEMICOLON programbody END IDENT
		;

programname	: IDENT
		;

programbody : var_const_decl_list | func_decl_list | compound_statement //these list should be zero or more
		;

var_const_decl_list : var_const_decl_list var_const_decl | var_const_decl | epsilon //epsilon for terminate//cfg for zero or more like S->Sa | a | epsilon
 		;

var_const_decl :	var_decl |
					const_decl
		;

func_decl_list : func_decl_list func_decl | func_decl | epsilon
 		;

/*Function*/
func_decl : IDENT BRACELEFT arg_lists BRACERIGHT COLON func_type SEMICOLON compound_statement KWEND IDENT
		;

arg_lists : identifier_list | epsilon //zero or more formal arguments is fine
		;

identifier_list : identifier_list IDENT COMMA | IDENT COMMA //identifier list for expanding more and more
		;

func_type : KWINTEGER |
			KWREAL |
			KWBOOLEAN |
			KWSTRING |
			epsilon
		;
/*2.2 Data Types and Declarations */
data_decl :  	var_decl |
				array_decl |
				const_decl
		;

var_decl : 	KWVAR IDENT COLON var_type SEMICOLON
		;

var_type : 	KWOCTAL |
			KWINTEGER |
			KWREAL |
			KWBOOLEAN
		;

array_decl : KWVAR identifier_list KWARRAY array_dimension_decl SEMICOLON
		;

array_dimension_decl :	array_dimension_decl OF |
						KWARRAY INTEGER KWTO INTEGER
		;

const_decl : KWVAR identifier_list COLON literal_constant_list SEMICOLON
		;

literal_constant_list :	INTEGER |
						REAL |
						STRING |
						KWTRUE |
						KWFALSE
		;

/*2.3 Statements in program are listed below */
statement_list :	statement_list statement | statement | epsilon
		;

statement : 		compound_statement |
					simple_statement |
					conditional_statement |
					while_statement |
					for_statement |
					return_statement |
					function_invocation_statement |
		;
/*2.3.1 compound_statement*/
compound_statement : KWBEGIN var_const_decl_list statement_list KWEND
		;

/*2.3.2 simple statement*/
simple_statement : 	variable_reference COLON EQUAL expression_list |
					KWPRINT variable_reference SEMICOLON |
					KWPRINT expression SEMICOLON |
					KWREAD variable_reference SEMICOLON
		;

variable_reference	: 	IDENT |
					 	IDENT BRACKETLEFT integer_expression BRACKETRIGHT array_reference
		;

array_reference	: 	epsilon |//terminate array reference
					BRACKETLEFT expression BRACKETRIGHT array_reference
		;

expression :	MINUS BRACELEFT expression BRACERIGHT %prec UNARY_NEGATIVE | //unary expression gets highest priority
				literal_constant_list | //required for mathematical operation with constant
				variable_reference | //required for mathematical operation with variable
				function_invocation_statement //required for mathematical operation with function
				expression MULTIPLY expression |
				expression DIVIDE expression |
				expression MOD expression |
				expression PLUS expression |
				expression MINUS expression |
				boolean_expression |
				NOT expression |
				expression AND  expression |
				expression OR expression
		;

boolean_expression :	expression LESS expression |
						expression LESSEQUAL expression |
						expression EQUAL expression |
						expression GREATEREQUAL expression |
						expression GREATER expression |
						expression LESSGREATER expression |
		;

function_invocation_statement :	IDENT BRACELEFT expression_list BRACKETRIGHT
		;

expression_list : 	expression_list COMMA | expression | epsilon //in order to terminate
		;

/*2.3.3 Conditional statements*/
conditional_statement :	KWIF boolean_expression KWTHEN statement_list KWELSE statement_list KWEND KWIF |
						KWIF boolean_expression KWTHEN statement_list KWEND KWIF
		;

/*2.3.4 while statements*/
while_statement : KWWHILE boolean_expression KWDO statement_list KWEND KWDO
		;

for_statement : KWFOR identifier COLON EQUAL INTEGER KWTO INTEGER KWDO statement_list KWEND KWDO
		;

return_statement KWRETURN expression
		;

epsilon :  /*epsilon does nothing*/
		;
%%

int yyerror( char *msg ) /*parsing error goes here*/
{
    fprintf( stderr, "\n|--------------------------------------------------------------------------\n" );
	fprintf( stderr, "| Error found in Line #%d: %s\n", linenum, buf );
	fprintf( stderr, "|\n" );
	fprintf( stderr, "| Unmatched token: %s\n", yytext );
    fprintf( stderr, "|--------------------------------------------------------------------------\n" );
    exit(-1);
}

int  main( int argc, char **argv )
{
	if( argc != 2 ) {
		fprintf(  stdout,  "Usage:  ./parser  [filename]\n"  );
		exit(0);
	}

	FILE *fp = fopen( argv[1], "r" );

	if( fp == NULL )  {
		fprintf( stdout, "Open  file  error\n" );
		exit(-1);
	}

	yyin = fp;
	yyparse();

	fprintf( stdout, "\n" );
	fprintf( stdout, "|--------------------------------|\n" );
	fprintf( stdout, "|  There is no syntactic error!  |\n" );
	fprintf( stdout, "|--------------------------------|\n" );
	exit(0);
}
