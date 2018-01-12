#include "gencode.h"
void instr_stk_init()
{
    instr_stk_size = 0;
    for(int i=0;i<INSTR_STK_SIZE;i++)
    {
        memset(instr_stk[i].buf, 0, sizeof(instr_stk[i].buf));
    }
}
void push_instr(char* instr_in)
{
	instr_stk.top++;
	instr_stk[instr_stk.top] = instr_in;
}
void output_instr_stk()
{
	for(int i=0;i<instr_stk.size;i++)
    {

    }
}
void prog_start(char* name_in)
{
    loop_stk.top=-1;
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
            snprintf(instr_buf, sizeof(instr_buf), "iload %d\n", lookup->attribute->var_no);
        }
        else
        {
            find_entry = lookupSymbol(symbolTable, expr->varRef->id, scope, __FALSE);//or check the symbol table
            if(find_entry) //find a symbol to be referenced
            {
                if(lookup->category==VARIABLE_t && lookup->scope==0) //reference is the global_var
                {
                    switch(expr->pType->type)
                    {
						case INTEGER_t:
							snprintf(instr_buf,sizeof(instr_buf), "getstatic %s/%s I\n",fileName,lookup->name);
							break;
						case REAL_t:
							snprintf(instr_buf,sizeof(instr_buf), "getstatic %s/%s F\n",fileName,lookup->name);
							break;
						case BOOLEAN_t:
							snprintf(instr_buf,sizeof(instr_buf), "getstatic %s/%s Z\n",fileName,lookup->name);
							break;
                        default:
                            break;
					}
                }
                else if((lookup->category==VARIABLE_t ||lookup->category==PARAMETER_t)&& lookup->scope!=0)
				{
					switch(expr->pType->type)
					{
						case INTEGER_t:
							snprintf(instr_buf,sizeof(instr_buf), "iload %d\n",lookup->attribute->var_no);
							break;
						case REAL_t:
							snprintf(instr_buf,sizeof(instr_buf), "fload %d\n",lookup->attribute->var_no);
							break;
						case BOOLEAN_t:
							snprintf(instr_buf,sizeof(instr_buf), "iload %d\n",lookup->attribute->var_no);
							break;
					}
				}
                else if(lookup->category==CONSTANT_t) //reference is the const variable
				{
					switch(expr->pType->type)
					{
						case INTEGER_t:
							snprintf(instr_buf,sizeof(instr_buf), "sipush %d\n",lookup->attribute->constVal->value.integerVal);
							break;
						case REAL_t:
							snprintf(instr_buf,sizeof(instr_buf), "ldc %lf\n",lookup->attribute->constVal->value.realVal);
							break;
						case BOOLEAN_t:
							snprintf(instr_buf,sizeof(instr_buf), "iconst_%d\n",lookup->attribute->constVal->value.booleanVal);
							break;
					}
				}
            }
        }
    }
}
void asn_expr()
{

}
