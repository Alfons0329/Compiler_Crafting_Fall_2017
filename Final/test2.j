; test2
.class public test2
.super java/lang/Object

.field public static _sc Ljava/util/Scanner;
 .field public static a I
.field public static b Z
.field public static c F
.field public static d F
.field public static e F

;main start
.method public static main([Ljava/lang/String;)V
.limit stack 128 ; up to 128items can be pushed
.limit locals 128 ; up to 64 varibles can be pushed

sipush 3
istore 1
ldc 1.230000
fstore 6
ldc 1.230000
sipush 3
i2f
fmul
fstore 6
getstatic java/lang/System/out Ljava/io/PrintStream;
fload 6
invokevirtual java/io/PrintStream/print(F)V

getstatic java/lang/System/out Ljava/io/PrintStream;
ldc "\n"
invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V

sipush 3
ldc 1.230000
fdiv
fstore 6
getstatic java/lang/System/out Ljava/io/PrintStream;
fload 6
invokevirtual java/io/PrintStream/print(F)V

getstatic java/lang/System/out Ljava/io/PrintStream;
ldc "\n"
invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V

sipush 1
sipush 100
iadd
i2f
fstore 6
getstatic java/lang/System/out Ljava/io/PrintStream;
fload 6
invokevirtual java/io/PrintStream/print(F)V

getstatic java/lang/System/out Ljava/io/PrintStream;
ldc "\n"
invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V

sipush 100
sipush 17
irem
istore 5
getstatic java/lang/System/out Ljava/io/PrintStream;
iload 5
invokevirtual java/io/PrintStream/print(I)V

getstatic java/lang/System/out Ljava/io/PrintStream;
ldc "\n"
invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V

ldc 1.230000
sipush 3
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
sipush 100
sipush 20
iadd
ldc 3.140000
fmul
sipush 2
i2f
fdiv
invokevirtual java/io/PrintStream/print(F)V

getstatic java/lang/System/out Ljava/io/PrintStream;
ldc "\n"
invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V

return
.end method
