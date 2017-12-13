/**
 * Introduction to Compiler Design by Prof. Yi Ping You
 * Prjoect 2 main function
 */

#include <stdio.h>
#include <stdlib.h>
#include "symbol_table.h"
using namespace std;
extern void symbol_table_init();
extern int yyparse();	/* declared by yacc */
extern int param_or_decl;
extern int is_array;
extern FILE* yyin;	/* declared by lex */


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
	//0 no 1 yes
	symbol_table_init();
	yyparse();
	exit(0);
}
