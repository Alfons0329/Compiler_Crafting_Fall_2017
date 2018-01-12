#ifndef _GENCODE_H_
#define _GENCODE_H_

extern int linenum;
extern FILE* outfp;
extern int scope;
extern int hasRead;
extern struct SymTable *symbolTable;	// main symbol table
extern char fileName[256];
//instruction stack if multiple insructions to be added
//instrbuf for temporary store the instruction
struct instr_stk
{
    char buf[1024];
    int top;
};
char instr_buf[256];
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

//method
void method(char*, int, char*, char*);
//ref(say load) the value and assign (say save)
void ref_expr(struct expr_sem* expr);
void asn_expr(struct expr_sem* expr,struct expr_sem* RHS);
//vars global and others
void global_var(char* ,struct PType*);
void funct_end(char* name_in);
//group of instructions to be generated
void expr_instr();



#endif
