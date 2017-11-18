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

// mathematical operators
%left PLUS MINUS MULTIPLY DIVIDE MOD

//assign, which is right associative
%right ASSIGN

// logical operators
%left LESS LESSEQUAL LESSGREATER GREATEREQUAL GREATER EQUAL AND OR NOT

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

programname	: identifier
		;

programbody : var_const_decl | func_decl | compound_statement
		;
/*Function*/
func_decl : IDENT BRACELEFT arg_lists BRACERIGHT COLON func_type SEMICOLON compound_statement KWEND IDENT
		;

arg_lists : identifier_list | epsilon
		;

identifier_list : identifier_list | IDENT COMMA
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
				KWVAR identifier_list COLON literal_constant
		;

var_decl : 	KWVAR IDENT COLON var_type SEMICOLON
		;

array_decl :	KWVAR identifier_list COLON array_dimension_decl SEMICOLON
		;

array_dimension_decl :	array_dimension_decl OF |
						KWARRAY INTEGER KWTO INTEGER
		;
/*2.3 Statements in program*/
statement_list : 	compound_statement |
					simple_statement |
					conditional_statement |
					while_statement |
					for_statement |
					return_statement |
					function_invocation_statement |
		;
/*2.3.1 compound_statement*/
compound_statement : KWBEGIN var_const_decl statement_list KWEND
		;

var_const_decl :	var_decl |
					const_decl
		;


const_decl :
		;

var_type : 	KWOCTAL |
			KWINTEGER |
			KWREAL |
			KWBOOLEAN
		;
/*2.3.2 simple statement*/
simple_statement : 	variable_reference COLON EQUAL expression_list |
					KWPRINT variable_reference SEMICOLON |
					KWPRINT expression_list SEMICOLON |
					KWREAD variable_reference SEMICOLON
		;
array_reference	: 	epsilon |/*terminate array reference*/
					BRACKETLEFT expression BRACKETRIGHT array_reference
		;

variable_reference	: 	IDENT |
					 	IDENT BRACKETLEFT expression BRACKETRIGHT array_reference
		;

expression :
				literal_constant_list |
				variable_reference |
				function_invocation_statement
				MINUS BRACELEFT expression BRACERIGHT |
				expression MULTIPLY expression |
				expression DIVIDE expression |
				expression MOD expression |
				expression PLUS expression |
				expression MINUS expression |
				expression LESS expression |
				expression LESSEQUAL expression |
				expression EQUAL expression |
				expression GREATEREQUAL expression |
				expression GREATER expression |
				expression LESSGREATER expression |
				NOT expression |
				expression AND  expression |
				expression OR expression
		;

function_invocation_statement :	IDENT BRACELEFT expression_list BRACKETRIGHT

expression_list : 	expression_list COMMA |
					expression

identifier :
		;
epsilon : ; /*epsilon does nothing*/
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
