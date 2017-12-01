1: /**
2:  * statement.p: examples for each statement
3:  */
4: //&T-
5: statement;
6: 
7: echo();
8: begin
9:         var s: string;
10:         read s;         // simple statement
11:         print s;        // simple statement
12: end
13: end echo
14: 
15: funny(): boolean;
16: begin
17:         return 1<>1;    // return statement
18: end 
19: end funny
20: 
21: 
22: begin
23: 
24:         var a, b: real;
25:         var i, k: integer;
26: 
27:         // simple statement
28:         a := 1.0;
29:         b := 2.3E-1;
30: 
31:         // compound statement
32:         begin
33:                 var c: boolean;
34:                 c := a < b;
35:         end
36:         
37:         // condition statement
38:         if a > b then
39:                 print " a > b \n";
40:         else
41:                 print " a <= b \n";
42:         end if
43: 
44:         // while statement
45:         i := 1;
46:         while i <= 10 do
47:                 print i*i;
48:                 print "\n";
49:         end do
50: 
51:         // for statement
52:         for k := 10 to 20 do 
53:                 print k*3;
54:                 print "\n";
55:         end do
56: 
57:         // function invocation statement 
58:         echo();
59: 
60: end
61: end statement

|--------------------------------|
|  There is no syntactic error!  |
|--------------------------------|
