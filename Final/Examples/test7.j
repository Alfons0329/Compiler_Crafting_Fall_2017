; test7.j 
.class public test7 
.super java/lang/Object 
.field public static _sc Ljava/util/Scanner; 

.method public static main([Ljava/lang/String;)V 
	.limit stack 100 
	.limit locals 100 
	new java/util/Scanner 
	dup 
	getstatic java/lang/System/in Ljava/io/InputStream; 
	invokespecial java/util/Scanner/<init>(Ljava/io/InputStream;)V 
	putstatic test7/_sc Ljava/util/Scanner; 
	return 
.end method 
