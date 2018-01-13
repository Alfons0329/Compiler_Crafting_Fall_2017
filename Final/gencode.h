#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "header.h"
#include "symtab.h"
#ifndef _GENCODE_H_
#define _GENCODE_H_
#define INSTR_STACK_SIZE 10000
#define stack_SIZE 100
#define BUF_SIZE 256
extern int linenum;
extern FILE* ofptr;
extern int scope;
extern int is_read;
extern struct SymTable *symbolTable;	// main symbol table
extern char fileName[BUF_SIZE];
char instr_buf[BUF_SIZE]; //instruction buffer for temporarily store the instruction
int cur_instr_stk_size; //current instruction stack size
int label_cnt; //label for depth
//instruction stack if multiple insructions to be fprintf
struct one_instr_stack
{
    char buf[BUF_SIZE*4];
};
struct one_instr_stack instr_stack[INSTR_STACK_SIZE];
struct one_loop_stack
{
	int stack[stack_SIZE];
	int top;
};
struct one_loop_stack loop_stack;
//operand stack user size to maintain
//group of instructions to be generated
//start and end of program
//for loop
//append more instruction of negative value
//void negative(struct expr_sem* expr);

void init_all()
{
    label_cnt=0;
    cur_instr_stk_size=0;
    for(int i=0;i<INSTR_STACK_SIZE;i++)
    {
        memset(instr_stack[i].buf, 0, sizeof(instr_stack[i].buf));
    }
}
void push_instr(char* instr_in)
{
    printf("Push instruction %s \n",instr_in);
	strcpy(instr_stack[cur_instr_stk_size].buf,instr_in);
    cur_instr_stk_size++;
}
void output_instr_stack()
{
    printf("Lets output! size is %d\n",cur_instr_stk_size);
    for(int i=0;i<cur_instr_stk_size;i++)
    {
        printf("%s \n",instr_stack[i].buf);
    }
    for(int i=0;i<cur_instr_stk_size;i++)
    {
        fprintf(ofptr,"%s",instr_stack[i].buf);
        memset(instr_stack[i].buf, 0, sizeof(instr_stack[i].buf));
    }
    cur_instr_stk_size=0;
}
void prog_start(char* name_in)
{
    loop_stack.top=-1; //start from 0 so use -1 is ok
    fprintf(ofptr, "; %s\n",name_in);
    fprintf(ofptr, ".class public %s\n",name_in);
    fprintf(ofptr, ".super java/lang/Object\n\n");
    fprintf(ofptr, ".field public static _sc Ljava/util/Scanner;\n ");
}
void prog_end()
{
    fprintf(ofptr, "return\n");
    fprintf(ofptr, ".end method\n");
}
//method
void method(char* name_in, int stack_lim, char* param, char* ret)
{
    fprintf(ofptr, "\n;main start\n");
    fprintf(ofptr, ".method public static %s(%s)%s\n",name_in,param,ret);
    fprintf(ofptr, ".limit stack %d ; up to %ditems can be pushed\n",stack_lim,stack_lim);
    fprintf(ofptr, ".limit locals 128 ; up to 64 varibles can be pushed\n\n");
}
void corecion(struct expr_sem* LHS_type,struct expr_sem* RHS_type)
{
    if(LHS_type->pType->type==INTEGER_t && RHS_type->pType->type == REAL_t)
    {
        push_instr("i2f\n");
    }
}
//vars global and others
void global_var(char* name_in, struct PType* type_in)
{
    printf("global_var \n");
    if(type_in->type == INTEGER_t)
    {
		fprintf(ofptr, ".field public static %s %s\n",name_in,"I");
	}
	else if(type_in->type == BOOLEAN_t)
    {
		fprintf(ofptr, ".field public static %s %s\n",name_in,"Z");
	}
	else if(type_in->type == REAL_t)
    {
		fprintf(ofptr, ".field public static %s %s\n",name_in,"F");
	}
}
//ref(say load) the value and assign (say save)
void ref_expr(struct expr_sem* expr)
{
    if(expr==NULL)
    {
        return; //return if nothing
    }
    else if(expr->varRef) //is var ref type expression
    {
        struct SymNode* find_entry = lookupLoopVar(symbolTable, expr->varRef->id);//find the loop variable first
        if(find_entry)
        {
            snprintf(instr_buf, sizeof(instr_buf), "iload %d\n", find_entry->attribute->var_no);
        }
        else
        {
            printf("Noot loop var reference \n");
            find_entry = lookupSymbol(symbolTable, expr->varRef->id, scope, __FALSE);//or check the symbol table
            if(find_entry) //find a symbol to be referenced
            {
                if(find_entry->category==VARIABLE_t && find_entry->scope==0) //reference is the global_var
                {
                    switch(expr->pType->type)
                    {
						case INTEGER_t:
							snprintf(instr_buf,sizeof(instr_buf), "getstatic %s/%s I\n",fileName,find_entry->name);
							break;
						case REAL_t:
							snprintf(instr_buf,sizeof(instr_buf), "getstatic %s/%s F\n",fileName,find_entry->name);
							break;
						case BOOLEAN_t:
							snprintf(instr_buf,sizeof(instr_buf), "getstatic %s/%s Z\n",fileName,find_entry->name);
							break;
                        default:
                            break;
					}
                }
                else if((find_entry->category==VARIABLE_t ||find_entry->category==PARAMETER_t)&& find_entry->scope!=0) //local type
				{
					switch(expr->pType->type)
					{
						case INTEGER_t:
							snprintf(instr_buf,sizeof(instr_buf), "iload %d\n",find_entry->attribute->var_no);
							break;
						case REAL_t:
							snprintf(instr_buf,sizeof(instr_buf), "fload %d\n",find_entry->attribute->var_no);
							break;
						case BOOLEAN_t:
							snprintf(instr_buf,sizeof(instr_buf), "iload %d\n",find_entry->attribute->var_no);
							break;
                        default:
                            break;
					}
				}
                else if(find_entry->category==CONSTANT_t) //reference is the const variable
				{
					switch(expr->pType->type)
					{
						case INTEGER_t:
							snprintf(instr_buf,sizeof(instr_buf), "sipush %d\n",find_entry->attribute->constVal->value.integerVal);
							break;
						case REAL_t:
							snprintf(instr_buf,sizeof(instr_buf), "ldc %lf\n",find_entry->attribute->constVal->value.realVal);
							break;
						case BOOLEAN_t:
							snprintf(instr_buf,sizeof(instr_buf), "iconst_%d\n",find_entry->attribute->constVal->value.booleanVal);
							break;
                        default:
                            break;
					}
				}
            }
        }
        push_instr(instr_buf);
        memset(instr_buf,0,sizeof(instr_buf));
    }
}
void asn_expr(struct expr_sem* expr,struct expr_sem* RHS)
{
    if(expr==NULL)
    {
        return;
    }
    else if(expr->varRef)
    {
        printf("Assign instruction \n");
        struct SymNode* find_entry = lookupSymbol(symbolTable,expr->varRef->id,scope,__FALSE);//find the loop variable first
        if(find_entry)
        {
            if(find_entry->category==VARIABLE_t && find_entry->scope!=0)
            { //varible but not global
				switch(expr->pType->type)
                {
					case INTEGER_t:
						snprintf(instr_buf,sizeof(instr_buf), "istore %d\n",find_entry->attribute->var_no);
						break;
					case REAL_t:
						if(RHS && RHS->pType->type==INTEGER_t)
                        {
							snprintf(instr_buf,sizeof(instr_buf), "i2f\nfstore %d\n",find_entry->attribute->var_no);
						}
                        else
                        {
							snprintf(instr_buf,sizeof(instr_buf), "fstore %d\n",find_entry->attribute->var_no);
						}
						break;
					case BOOLEAN_t:
						snprintf(instr_buf,sizeof(instr_buf), "istore %d\n",find_entry->attribute->var_no);
						break;
                    default:
                        break;
				}
			}
			else if(find_entry->category==VARIABLE_t && find_entry->scope==0)
            {
				switch(expr->pType->type)
                {
					case INTEGER_t:
						snprintf(instr_buf,sizeof(instr_buf), "putstatic %s/%s I\n",fileName,find_entry->name);
						break;
					case REAL_t:
						if(RHS && RHS->pType->type==INTEGER_t)
                        {
							snprintf(instr_buf,sizeof(instr_buf), "i2f\nputstatic %s/%s F\n",fileName,find_entry->name);
						}
                        else
                        {
							snprintf(instr_buf,sizeof(instr_buf), "putstatic %s/%s F\n",fileName,find_entry->name);
						}
						break;
					case BOOLEAN_t:
						snprintf(instr_buf,sizeof(instr_buf), "putstatic %s/%s Z\n",fileName,find_entry->name);
						break;
                    default:
                        break;
				}
			}
        }
        printf("Instr buf for assign %s\n",instr_buf);
        push_instr(instr_buf);
        memset(instr_buf,0,sizeof(instr_buf));
    }
}
void for_loop(char* iter, int loop_begin, int loop_end)
{
    loop_stack.top++; //depth inner by 1
    label_cnt++; //label cnt is used for the while or loop depth
    struct SymNode* loop_ptr;
    loop_ptr = lookupLoopVar(symbolTable, iter);
    if(loop_ptr)
    {
        snprintf(instr_buf,sizeof(instr_buf),"iload %d\nsipush 1\niadd\nistore %d\ngoto Lbegin_%d\nLexit_%d:\n\n"\
        ,loop_ptr->attribute->var_no,loop_ptr->attribute->var_no,loop_stack.stack[loop_stack.top],loop_stack.stack[loop_stack.top]);
        push_instr(instr_buf);
        memset(instr_buf,0,sizeof(instr_buf));
        output_instr_stack();
    }
    loop_stack.top--;
}
void for_loop_end(char* iter)
{
    loop_stack.top++;
    struct SymNode* loop_ptr;
    loop_ptr = lookupLoopVar(symbolTable, iter); //find again
    if(loop_ptr)
    {
        snprintf(instr_buf,sizeof(instr_buf),"iload %d\nsipush 1\niadd\nistore %d\ngoto Lbegin_%d\nLexit_%d:\n\n"\
        ,loop_ptr->attribute->var_no,loop_ptr->attribute->var_no,loop_stack.stack[loop_stack.top],loop_stack.stack[loop_stack.top]);
        push_instr(instr_buf);
        memset(instr_buf,0,sizeof(instr_buf));
        output_instr_stack();
    }
    loop_stack.top--;
}

void negative(struct expr_sem* expr)
{
    if(expr->pType->type==INTEGER_t)
    {
		push_instr("ineg\n");
	}
    else if(expr->pType->type==REAL_t)
    {
		push_instr("fneg\n");
	}
}

void print_stdout_init()
{
	snprintf(instr_buf,sizeof(instr_buf), "getstatic java/lang/System/out Ljava/io/PrintStream;\n");
	push_instr(instr_buf);
	memset(instr_buf,0,sizeof(instr_buf));
}
void print_stdout(struct expr_sem* expr)
{
	switch(expr->pType->type)
    {
		case STRING_t:
			fprintf(ofptr, "invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V\n");
			break;
		case INTEGER_t:
			fprintf(ofptr, "invokevirtual java/io/PrintStream/print(I)V\n");
			break;
		case REAL_t:
			fprintf(ofptr, "invokevirtual java/io/PrintStream/print(F)V\n");
			break;
		case BOOLEAN_t:
			fprintf(ofptr, "invokevirtual java/io/PrintStream/print(Z)V\n");
			break;
        default:
            break;
	}
	fprintf(ofptr, "\n");

}
void read_stdin_init()
{
    if(!is_read)
    {
		fprintf(ofptr, "new java/util/Scanner\n");
		fprintf(ofptr, "dup\n");
		fprintf(ofptr, "getstatic java/lang/System/in Ljava/io/InputStream;\n");
		fprintf(ofptr, "invokespecial java/util/Scanner/<init>(Ljava/io/InputStream;)V\n");
		fprintf(ofptr, "putstatic %s/_sc Ljava/util/Scanner;\n",fileName);
		fprintf(ofptr, "\n");
		is_read=1;
    }
}
void read_stdin(struct expr_sem* expr)
{
    fprintf(ofptr, "getstatic %s/_sc Ljava/util/Scanner;\n",fileName);
	if(expr->varRef)
    {
		struct SymNode* find_entry= lookupSymbol(symbolTable,expr->varRef->id,scope,__FALSE);
		if(find_entry->category==VARIABLE_t && find_entry->scope!=0)
        {
			switch(expr->pType->type)
            {
				case INTEGER_t:
					fprintf(ofptr, "invokevirtual java/util/Scanner/nextInt()I\n");
					break;
				case REAL_t:
					fprintf(ofptr, "invokevirtual java/util/Scanner/nextFloat()F\n");
					break;
				case BOOLEAN_t:
					fprintf(ofptr, "invokevirtual java/util/Scanner/nextBoolean()Z\n");
					break;
                default:
                    break;
			}
		}
        else if(find_entry->category==VARIABLE_t && find_entry->scope==0)
        {
			switch(expr->pType->type){
				case INTEGER_t:
					fprintf(ofptr, "invokevirtual java/util/Scanner/nextInt()I\n");
					break;
				case REAL_t:
					fprintf(ofptr, "invokevirtual java/util/Scanner/nextFloat()F\n");
					break;
				case BOOLEAN_t:
					fprintf(ofptr, "invokevirtual java/util/Scanner/nextBoolean()Z\n");
					break;
                default:
                    break;
			}
		}
		asn_expr(expr,NULL); //sace what i read
		output_instr_stack();
	}
	fprintf(ofptr, "\n");
}
void load_const_stk(struct ConstAttr* constattr)
{
	if(constattr->category==STRING_t){
		snprintf(instr_buf,sizeof(instr_buf), "ldc \"%s\"\n",constattr->value.stringVal);
	}
	else if(constattr->category==INTEGER_t){
		snprintf(instr_buf,sizeof(instr_buf), "sipush %d\n",constattr->value.integerVal);
	}
	else if(constattr->category==REAL_t){
		snprintf(instr_buf,sizeof(instr_buf), "ldc %lf\n",constattr->value.realVal);
	}
	else if(constattr->category==BOOLEAN_t){
		snprintf(instr_buf,sizeof(instr_buf), "iconst_%d\n",constattr->value.booleanVal);
	}
	push_instr(instr_buf);
	memset(instr_buf,0,sizeof(instr_buf));
}
#endif
