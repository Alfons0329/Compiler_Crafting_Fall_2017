#ifndef _GENCODE_H_
#define _GENCODE_H_

extern int linenum;
extern FILE* outfp;
extern int scope;
extern int hasRead;
extern struct SymTable *symbolTable;	// main symbol table
extern char fileName[256];
//instruction stack
struct instr_stk
{
    char
    int top
};
struct loop_stk
{
	int stk[100];
	int top;
};
struct cond_stk
{
	int stk[100];
	int top;
};
//operand stack user size to maintain
//start and end of program
void prog_start();
void prog_end();

//load and save
void load_expr();
void save_expr();


#endif
