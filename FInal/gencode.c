#include "gencode.h"
void prog_start(char* name_in)
{
    loop_stk.top=-1;
    fprintf(outfp, "; %s\n",pname);
    fprintf(outfp, ".class public %s\n",pname);
    fprintf(outfp, ".super java/lang/Object\n\n");
    fprintf(outfp, ".field public static _sc Ljava/util/Scanner;\n ");
}
void prog_end()
{
    fprintf(outfp, "return\n");
    fprintf(outfp, ".end method\n");
}
