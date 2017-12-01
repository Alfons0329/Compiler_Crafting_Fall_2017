1: /**
2:  * expr1.p: expression
3:  */
4: //&T-
5: expr1;
6: 
7: 
8: begin
9: 
10:         var a, b: integer;
11:         a := 2;
12:         b:= 3;
13: 
14:         print 1+2*(3+4);
15: 
16:         if a*3+1 <> b*4 mod 123 then
17:                 print "test";
18:         end if
19: 
20: end
21: end expr1

|--------------------------------|
|  There is no syntactic error!  |
|--------------------------------|
