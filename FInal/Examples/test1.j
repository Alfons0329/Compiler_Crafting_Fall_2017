; test1.j 
.class public test1 
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
	putstatic test1/_sc Ljava/util/Scanner; 
	iconst_1 
	istore 6 
	iconst_0 
	istore 6 
	ldc 1234567 
	istore 1 
	ldc 2.860000 
	fstore 7 
	getstatic java/lang/System/out Ljava/io/PrintStream; 
	iload 1 
	invokevirtual java/io/PrintStream/print(I)V 
	getstatic java/lang/System/out Ljava/io/PrintStream; 
	ldc "\n" 
	invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V 
	getstatic java/lang/System/out Ljava/io/PrintStream; 
	iload 6 
	invokevirtual java/io/PrintStream/print(Z)V 
	getstatic java/lang/System/out Ljava/io/PrintStream; 
	ldc "\n" 
	invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V 
	getstatic java/lang/System/out Ljava/io/PrintStream; 
	fload 7 
	invokevirtual java/io/PrintStream/print(F)V 
	getstatic java/lang/System/out Ljava/io/PrintStream; 
	ldc "\n" 
	invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V 
	getstatic java/lang/System/out Ljava/io/PrintStream; 
	ldc "hello world!" 
	invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V 
	getstatic java/lang/System/out Ljava/io/PrintStream; 
	ldc "\n" 
	invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V 
	return 
.end method 
