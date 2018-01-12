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
	if(type->type == INTEGER_t)
    {
		fprintf(outfp, ".field public static %s %s\n",name_in,"I");
	}
	else if(type->type == BOOLEAN_t)
    {
		fprintf(outfp, ".field public static %s %s\n",name_in,"Z");
	}
	else if(type->type == REAL_t)
    {
		fprintf(outfp, ".field public static %s %s\n",name_in,"F");
	}
}
