; test3
.class public test3
.super java/lang/Object

.field public static _sc Ljava/util/Scanner;
 
;main start
.method public static main([Ljava/lang/String;)V
.limit stack 128 ; up to 128items can be pushed
.limit locals 128 ; up to 64 varibles can be pushed

sipush 19
istore 1
new java/util/Scanner
dup
getstatic java/lang/System/in Ljava/io/InputStream;
invokespecial java/util/Scanner/<init>(Ljava/io/InputStream;)V
putstatic test3/_sc Ljava/util/Scanner;

getstatic test3/_sc Ljava/util/Scanner;
invokevirtual java/util/Scanner/nextInt()I
iload 2
istore 2

iload 2
sipush 100
isub
ifgt Ltrue_1
iconst_0
goto Lfalse_1
Ltrue_1:
iconst_1
Lfalse_1:
ifeq Lfalse_2
getstatic java/lang/System/out Ljava/io/PrintStream;
ldc "b > 100\n"
invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V

goto Lcondexit_2
Lfalse_2:
iload 2
sipush 20
isub
iflt Ltrue_3
iconst_0
goto Lfalse_3
Ltrue_3:
iconst_1
Lfalse_3:
ifeq Lfalse_4
getstatic java/lang/System/out Ljava/io/PrintStream;
ldc "b < 20\n"
invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V

goto Lcondexit_4
Lfalse_4:
getstatic java/lang/System/out Ljava/io/PrintStream;
ldc "bbb \n"
invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V

Lcondexit_4:
Lcondexit_0:
return
.end method
