/**
 * Introduction to Compiler Design by Prof. Yi Ping You
 * Prjoect 2 main function
 */
#include <stdio.h>
#include <stdlib.h>
#include <string>
extern int yyparse();	/* declared by yacc */
extern FILE* yyin;	/* declared by lex */
std::string program_name;
int  main( int argc, char **argv )
{
	if( argc != 2 ) {
		fprintf(  stdout,  "Usage:  ./parser  [filename]\n"  );
		exit(0);
	}

	FILE *fp = fopen( argv[1], "r" );
	program_name = argv[1];
	if( fp == NULL )  {
		fprintf( stdout, "Open  file  error\n" );
		exit(-1);
	}

	yyin = fp;
	yyparse();
	exit(0);
}
