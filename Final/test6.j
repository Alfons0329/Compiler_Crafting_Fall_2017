; test6
.class public test6
.super java/lang/Object

.field public static _sc Ljava/util/Scanner;
 
;main start
.method public static main([Ljava/lang/String;)V
.limit stack 128 ; up to 128items can be pushed
.limit locals 128 ; up to 64 varibles can be pushed

sipush 1
istore 1
ldc 2.200000
fstore 2
iload 1
i2f
fload 2
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
