#include "gencode.h"
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
        struct SymNode* find_entry = lookupLoopVar(symbolTable,expr->varRef->id);//find the loop variable first
        if(find_entry)
        {
            snprintf(instr_buf, sizeof(instr_buf), "iload %d\n",lookup->attribute->var_no);
        }
        else
        {
            find_entry = lookupSymbol()//or check the symbol table
        }
    }
}
void asn_expr()
{

}
