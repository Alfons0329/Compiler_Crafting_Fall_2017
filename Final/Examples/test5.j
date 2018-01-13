; test5.j 
.class public test5 
.super java/lang/Object 
.field public static _sc Ljava/util/Scanner; 

.method public static fun()V 
.limit stack 100 
.limit locals 100 
	return 
.end method 

.method public static fun2()F 
.limit stack 100 
.limit locals 100 
	ldc 10.000000
	freturn 
.end method 

.method public static fun3(II)I 
.limit stack 100 
.limit locals 100 
	iload 0 
	iload 1 
	iadd 
	ireturn 
	ireturn 
.end method 

.method public static main([Ljava/lang/String;)V 
	.limit stack 100 
	.limit locals 100 
	new java/util/Scanner 
	dup 
	getstatic java/lang/System/in Ljava/io/InputStream; 
	invokespecial java/util/Scanner/<init>(Ljava/io/InputStream;)V 
	putstatic test5/_sc Ljava/util/Scanner; 
	getstatic java/lang/System/out Ljava/io/PrintStream; 
	ldc 1 
	ldc 3 
	imul 
	ldc 201 
	ldc 17 
	idiv 
	invokestatic test5/fun3(II)I 
	ineg 
	invokevirtual java/io/PrintStream/print(I)V 
	getstatic java/lang/System/out Ljava/io/PrintStream; 
	ldc "\n" 
	invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V 
	getstatic java/lang/System/out Ljava/io/PrintStream; 
	invokestatic test5/fun2()F 
	fneg 
	invokevirtual java/io/PrintStream/print(F)V 
	getstatic java/lang/System/out Ljava/io/PrintStream; 
	ldc "\n" 
	invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V 
	getstatic java/lang/System/out Ljava/io/PrintStream; 
	ldc 101 
	ldc 2 
	invokestatic test5/fun3(II)I 
	invokestatic test5/fun2()F 
	fneg 
	fstore 1 
	i2f 
	fload 1 
	fmul 
	invokevirtual java/io/PrintStream/print(F)V 
	getstatic java/lang/System/out Ljava/io/PrintStream; 
	ldc "\n" 
	invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V 
	return 
.end method 
