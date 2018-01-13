; test4
.class public test4
.super java/lang/Object

.field public static _sc Ljava/util/Scanner;
 
;main start
.method public static main([Ljava/lang/String;)V
.limit stack 128 ; up to 128items can be pushed
.limit locals 128 ; up to 64 varibles can be pushed

getstatic java/lang/System/out Ljava/io/PrintStream;
iload 1
iload 2
imul
invokevirtual java/io/PrintStream/print(I)V

getstatic java/lang/System/out Ljava/io/PrintStream;
ldc "\n"
invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V

return
.end method
