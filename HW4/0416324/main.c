/**
 * Introduction to Compiler Design by Prof. Yi Ping You
 * Prjoect 2 main function
 */
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
using namespace std;
extern int yyparse();	/* declared by yacc */
extern FILE* yyin;	/* declared by lex */
string program_name;
int  main( int argc, char **argv )
{
	if( argc != 2 ) {
		fprintf(  stdout,  "Usage:  ./parser  [filename]\n"  );
		exit(0);
	}

	FILE *fp = fopen( argv[1], "r" );
	program_name = argv[1];
	program_name = program_name.substr(0,program_name.length()-2);
	cout<<"File name "<<program_name<<endl<<endl;
	if( fp == NULL )  {
		fprintf( stdout, "Open  file  error\n" );
		exit(-1);
	}

	yyin = fp;
	yyparse();
	exit(0);
}
