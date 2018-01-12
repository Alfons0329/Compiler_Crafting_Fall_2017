#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>

#ifndef _GENCODE_H_
#define _GENCODE_H_
#define INSTR_STK_SIZE 10000
#define STK_SIZE 100
#define BUF_SIZE 256
extern int linenum;
extern FILE* outfp;
extern int scope;
extern int hasRead;
extern struct SymTable *symbolTable;	// main symbol table
extern char fileName[BUF_SIZE];
int instr_stk_size;
int label_cnt;
//instruction stack if multiple insructions to be added
//instrbuf for temporary store the instruction
struct instr_stk
{
    char buf[BUF_SIZE*4];
};
instr_stk instr_stk[INSTR_STK_SIZE]
char instr_buf[BUF_SIZE];
struct loop_stk
{
	int stk[STK_SIZE];
	int top;
};
struct cond_stk
{
	int stk[STK_SIZE];
	int top;
};
//operand stack user size to maintain
//start and end of program
void prog_start();
void prog_end();

//method
void method(char*, int, char*, char*);
//ref(say load) the value and assign (say save)
void ref_expr(struct expr_sem* );
void asn_expr(struct expr_sem* ,struct expr_sem* );
//append more instruction of negative value
void negative(struct expr_sem*);
//vars global and others
void global_var(char* ,struct PType*);
void funct_end(char* name_in);
//group of instructions to be generated
void output_instr_stk();



#endif
