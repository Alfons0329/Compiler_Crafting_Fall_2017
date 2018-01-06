/**
 * Introduction to Compiler Design by Prof. Yi Ping You
 * Prjoect 4 main function
  */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "header.h"
#include "symtab.h"

extern FILE *yyin;    /* declared by lex */
extern int yydebug;   /* declared by yacc */
extern int yyparse(); /* declared by yacc */

extern struct SymTable *symbolTable; /* declared in parser.y */
extern struct PType *funcReturn;     /* declared in parser.y */
extern char fileName[256];           /* declared in parser.y */

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        fprintf(stdout, "Usage:  ./parser  [filename]\n");
        exit(0);
    }

    FILE *fp = fopen(argv[1], "r");

    if (fp == NULL)
    {
        fprintf(stdout, "Open  file  error\n");
        exit(-1);
    }

    // parse argv[1] and setup fileName
    const char *slashPos = strrchr(argv[1], '/');
    size_t fileNameLength;
    if (slashPos)
        strcpy(fileName, slashPos + 1);
    else
        strcpy(fileName, argv[1]);
    fileNameLength = strlen(fileName);

    // check filename extension of input file is '.p'
    if (fileName[fileNameLength - 2] != '.' || fileName[fileNameLength - 1] != 'p')
    {
        fprintf(stdout, "input file: %s should be [fileName].p\n", fileName);
        exit(-1);
    }
    fileName[fileNameLength - 2] = '\0';

    yyin = fp;

    // initialize symbol table
    symbolTable = (struct SymTable *)malloc(sizeof(struct SymTable));
    initSymTab(symbolTable);

    yyparse();
    exit(0);
}
