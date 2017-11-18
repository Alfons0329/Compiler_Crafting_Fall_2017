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
%token PLUS MINUS MULTIPLY DIVIDE MOD
// logical operators
%token LESS LESSEQUAL LESSGREATER GREATEREQUAL GREATER EQUAL AND OR NOT
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
/*2 Program Units */
/*2.1 Program */
program	: programname SEMICOLON programbody END IDENT
		;

programname	: identifier
		;

programbody : var_const_decl | func_decl | compound_statement
		;
/*2.2 Function*/
func_decl : IDENT BRACELEFT arg_lists BRACERIGHT COLON func_type compound_statement KWEND IDENT
		;

arg_lists : identifier_list | epsilon
		;

identifier_list : identifier_list | IDENT COMMA
		;

func_type : INTEGER SEMICOLON |
			OCTAL SEMICOLON |
			FLOAT SEMICOLON |
			SCIENTIFIC SEMICOLON |
			KWBOOLEAN SEMICOLON |
			KWSTRING SEMICOLON |
			epsilon SEMICOLON
		;

data_decl :
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
