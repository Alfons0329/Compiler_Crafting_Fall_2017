#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "gencode.h"
#include "header.h"
#include "symtab.h"
void init_all()
{
    label_cnt=0;
}
void instr_stk_init()
{
    instr_stk_size=0;
    for(int i=0;i<INSTR_STK_SIZE;i++)
    {
        memset(instr_stk[i].buf, 0, sizeof(instr_stk[i].buf));
    }
}
void push_instr(char* instr_in)
{
	instr_stk_size++;
	instr_stk[instr_stk_size] = strdup(instr_in);
}
void output_instr_stk()
{
	for(int i=0;i<instr_stk_size;i++)
    {
        fprintf(ofptr,"%s",instr_stk[i].buf);
    }
    instr_stk_size=0;
}
void prog_start(char* name_in)
{
    loop_stk.top=-1; //start from 0 so use -1 is ok
    fprintf(outfp, "; %s\n",name_in);
    fprintf(outfp, ".class public %s\n",name_in);
    fprintf(outfp, ".super java/lang/Object\n\n");
    fprintf(outfp, ".field public static _sc Ljava/util/Scanner;\n ");
}
void prog_end()
{
    fprintf(outfp, "return\n");
    fprintf(outfp, ".end method\n");
}

void method(char* name_in, int stk_lim, char* param, char* ret)
{
    fprintf(outfp, "\n;main start\n");
    fprintf(outfp, ".method public static %s(%s)%s\n",name,para,ret);
    fprintf(outfp, ".limit stack %d ; up to %ditems can be pushed\n",stack_lim,stack_lim);
    fprintf(outfp, ".limit locals 128 ; up to 64 varibles can be pushed\n\n");
}
void global_var(char* name_in, struct PType* type_in)
{
	if(type_in->type == INTEGER_t)
    {
		fprintf(outfp, ".field public static %s %s\n",name_in,"I");
	}
	else if(type_in->type == BOOLEAN_t)
    {
		fprintf(outfp, ".field public static %s %s\n",name_in,"Z");
	}
	else if(type_in->type == REAL_t)
    {
		fprintf(outfp, ".field public static %s %s\n",name_in,"F");
	}
}
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
    }
}
void asn_expr(struct expr_sem* expr,struct expr_sem* RHS)
{
    if(expr->varRef)
    {
        struct SymNode* find_entry = find_entryLoopVar(symbolTable, expr->varRef->id);//find the loop variable first
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
        //clean the buffer for next assign
        push_instr(instr_buf);
        memset(instr_buf,0,sizeof(instr_buf));
    }
}
void for_loop(char* iter, int loop_begin, int loop_end)
{
    loop_stk.top++; //depth inner by 1
    label_cnt++; //label cnt is used for the while or loop depth
    struct SymNode* loop_ptr;
    loop_ptr = lookupLoopVar(symbolTable, iter);
    if(loop_ptr)
    {
        snprintf(instr_buf,sizeof(instr_buf),"iload %d\nsipush 1\niadd\nistore %d\ngoto Lbegin_%d\nLexit_%d:\n\n"\
        ,ptr->attribute->var_no,ptr->attribute->var_no,loop_stk.stack[loop_stk.top],loop_stk.stack[loop_stk.top]);
        push_instr(instr_buf);
        memset(instr_buf,0,sizeof(instr_buf));
        output_instr_stk();
    }
    loop_stk.top--;
}
void for_loop_end(char* iter)
{
    loop_stk.top++;
    struct SymNode* loop_ptr;
    loop_ptr = lookupLoopVar(symbolTable, iter); //find again
    if(loop_ptr)
    {
        snprintf(instr_buf,sizeof(instr_buf),"iload %d\nsipush 1\niadd\nistore %d\ngoto Lbegin_%d\nLexit_%d:\n\n"\
        ,ptr->attribute->var_no,ptr->attribute->var_no,loop_stk.stack[loop_stk.top],loop_stk.stack[loop_stk.top]);
        push_instr(instr_buf);
        memset(instr_buf,0,sizeof(instr_buf));
        output_instr_stk();
    }
    loop_stk.top--;
}
void coercion(struct expr_sem* LHS_type, struct expr_sem* RHS_type)
{
    if(LHS_type->pType->type==INTEGER_t && RHS_type->pType->type == REAL_t)
    {
		push_instr("i2f\n");
	}
}
void negative(struct expr_sem* expr)
{
    if(expr->pType->type==INTEGER_t)
    {
		push_instr("ineg\n");
	}else if(expr->pType->type==REAL_t)
    {
		push_instr("fneg\n");
	}
}
