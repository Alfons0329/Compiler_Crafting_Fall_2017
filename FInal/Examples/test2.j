; test2.j 
.class public test2 
.super java/lang/Object 
.field public static _sc Ljava/util/Scanner; 
.field public static a I 
.field public static b Z 
.field public static c F 
.field public static d F 
.field public static e F 

.method public static main([Ljava/lang/String;)V 
	.limit stack 100 
	.limit locals 100 
	new java/util/Scanner 
	dup 
	getstatic java/lang/System/in Ljava/io/InputStream; 
	invokespecial java/util/Scanner/<init>(Ljava/io/InputStream;)V 
	putstatic test2/_sc Ljava/util/Scanner; 
	ldc 3 
	istore 1 
	ldc 1.230000 
	fstore 6 
	ldc 1.230000 
	ldc 3 
	i2f 
	fmul 
	fstore 6 
	getstatic java/lang/System/out Ljava/io/PrintStream; 
	fload 6 
	invokevirtual java/io/PrintStream/print(F)V 
	getstatic java/lang/System/out Ljava/io/PrintStream; 
	ldc "\n" 
	invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V 
	ldc 3 
	ldc 1.230000 
	fstore 7 
	i2f 
	fload 7 
	fdiv 
	fstore 6 
	getstatic java/lang/System/out Ljava/io/PrintStream; 
	fload 6 
	invokevirtual java/io/PrintStream/print(F)V 
	getstatic java/lang/System/out Ljava/io/PrintStream; 
	ldc "\n" 
	invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V 
	ldc 1 
	ldc 100 
	iadd 
	i2f 
	fstore 6 
	getstatic java/lang/System/out Ljava/io/PrintStream; 
	fload 6 
	invokevirtual java/io/PrintStream/print(F)V 
	getstatic java/lang/System/out Ljava/io/PrintStream; 
	ldc "\n" 
	invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V 
	ldc 100 
	ldc 17 
	irem 
	istore 5 
	getstatic java/lang/System/out Ljava/io/PrintStream; 
	iload 5 
	invokevirtual java/io/PrintStream/print(I)V 
	getstatic java/lang/System/out Ljava/io/PrintStream; 
	ldc "\n" 
	invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V 
	ldc 1.230000 
	ldc 3 
	i2f 
	fsub 
	fstore 6 
	getstatic java/lang/System/out Ljava/io/PrintStream; 
	fload 6 
	invokevirtual java/io/PrintStream/print(F)V 
	getstatic java/lang/System/out Ljava/io/PrintStream; 
	ldc "\n" 
	invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V 
	getstatic java/lang/System/out Ljava/io/PrintStream; 
	ldc 100 
	ldc 20 
	iadd 
	ldc 3.140000 
	fstore 7 
	i2f 
	fload 7 
	fmul 
	ldc 2 
	i2f 
	fdiv 
	invokevirtual java/io/PrintStream/print(F)V 
	getstatic java/lang/System/out Ljava/io/PrintStream; 
	ldc "\n" 
	invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V 
	return 
.end method 
