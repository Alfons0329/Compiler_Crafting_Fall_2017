/**
 * Introduction to Compiler Design by Prof. Yi Ping You
 * Prjoect 3 main function
  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "header.h"
#include "symtab.h"

extern int yydebug;	/* declared by yacc */

extern int yyparse();	/* declared by yacc */
extern FILE* yyin;	/* declared by lex */

extern struct SymTable *symbolTable;
extern struct PType *funcReturn;
extern char fileName[256];
FILE *outfp;

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

	// parse argv[1] and setup fileName
	const char* slashPos = strrchr(argv[1], '/');
	size_t fileNameLength;
	if( slashPos )
		strcpy(fileName, slashPos+1);
	else
		strcpy(fileName, argv[1]);
	fileNameLength = strlen(fileName);


	if( fileName[fileNameLength-2] != '.' || fileName[fileNameLength-1] != 'p' ) {
		fprintf( stdout, "input file: %s \tshould be [fileName].p \n", fileName );
		exit(-1);
	}
	fileName[fileNameLength-2] = '\0';

    char outputFN[64];
    snprintf(outputFN,sizeof(outputFN),"%s.j",fileName);

	outfp = fopen(outputFN,"w");

	yyin = fp;

	// initial symbol table
	symbolTable = (struct SymTable *)malloc(sizeof(struct SymTable));
	initSymTab( symbolTable );

	// initial function return recoder

	yydebug = 0;

	yyparse();	/* primary procedure of parser */
	fclose(outfp);
	exit(0);
}

