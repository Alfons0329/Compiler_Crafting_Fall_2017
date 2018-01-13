; test4
.class public test4
.super java/lang/Object

.field public static _sc Ljava/util/Scanner;
 
;main start
.method public static main([Ljava/lang/String;)V
.limit stack 128 ; up to 128items can be pushed
.limit locals 128 ; up to 64 varibles can be pushed


sipush 1
istore 1
Lbegin_1:
iload 1
sipush 10
isub
iflt Ltrue_1
iconst_0
goto Lfalse_1
Ltrue_1:
iconst_1
Lfalse_1:
ifeq Lexit_1

sipush 1
istore 2
Lbegin_2:
iload 2
sipush 10
isub
iflt Ltrue_2
iconst_0
goto Lfalse_2
Ltrue_2:
iconst_1
Lfalse_2:
ifeq Lexit_2
getstatic java/lang/System/out Ljava/io/PrintStream;
iload 1
iload 2
imul
invokevirtual java/io/PrintStream/print(I)V

getstatic java/lang/System/out Ljava/io/PrintStream;
ldc "\n"
invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V

iload 2
sipush 1
iadd
istore 2
goto Lbegin_2
Lexit_2:

iload 1
sipush 1
iadd
istore 1
goto Lbegin_1
Lexit_1:

return
.end method
