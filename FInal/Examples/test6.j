; test6.j 
.class public test6 
.super java/lang/Object 
.field public static _sc Ljava/util/Scanner; 

.method public static main([Ljava/lang/String;)V 
	.limit stack 100 
	.limit locals 100 
	new java/util/Scanner 
	dup 
	getstatic java/lang/System/in Ljava/io/InputStream; 
	invokespecial java/util/Scanner/<init>(Ljava/io/InputStream;)V 
	putstatic test6/_sc Ljava/util/Scanner; 
	ldc 1 
	istore 1 
	ldc 2.200000 
	fstore 2 
	iload 1 
	fload 2 
	fstore 4 
	i2f 
	fload 4 
	fadd 
	fstore 3 
	getstatic java/lang/System/out Ljava/io/PrintStream; 
	fload 3 
	invokevirtual java/io/PrintStream/print(F)V 
	getstatic java/lang/System/out Ljava/io/PrintStream; 
	ldc "\n" 
	invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V 
	return 
.end method 
