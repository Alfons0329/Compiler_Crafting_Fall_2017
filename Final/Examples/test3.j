; test3.j 
.class public test3 
.super java/lang/Object 
.field public static _sc Ljava/util/Scanner; 

.method public static main([Ljava/lang/String;)V 
	.limit stack 100 
	.limit locals 100 
	new java/util/Scanner 
	dup 
	getstatic java/lang/System/in Ljava/io/InputStream; 
	invokespecial java/util/Scanner/<init>(Ljava/io/InputStream;)V 
	putstatic test3/_sc Ljava/util/Scanner; 
	ldc 19 
	istore 1 
	; invoke java.util.Scanner.nextXXX() 
	getstatic test3/_sc Ljava/util/Scanner; 
	invokevirtual java/util/Scanner/nextInt()I 
	istore 2 
	iload 2 
	ldc 100 
	isub 
	ifgt Ltrue_0 
	iconst_0 
	goto Lfalse_0 
Ltrue_0: 
	iconst_1 
Lfalse_0: 
	ifeq Lelse_1 
	getstatic java/lang/System/out Ljava/io/PrintStream; 
	ldc "b > 100\n" 
	invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V 
	goto Lexit_1 
Lelse_1: 
	iload 2 
	ldc 20 
	isub 
	iflt Ltrue_2 
	iconst_0 
	goto Lfalse_2 
Ltrue_2: 
	iconst_1 
Lfalse_2: 
	ifeq Lelse_3 
	getstatic java/lang/System/out Ljava/io/PrintStream; 
	ldc "b < 20\n" 
	invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V 
	goto Lexit_3 
Lelse_3: 
	getstatic java/lang/System/out Ljava/io/PrintStream; 
	ldc "bbb \n" 
	invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V 
Lexit_3: 
Lexit_1: 
	return 
.end method 
