1: /**
2:  * test.p: simple P language example
3:  */
4: //&T-
5: test;
6: 
7: var a: integer;		// global variable
8: 
9: foo( a, b: integer ): integer;
10: begin
11: 	return a*b;
12: end
13: end foo
14: 
15: // main block
16: begin
17: 
18: 	print foo(2*4,3);
19: 
20: end
21: end test

|--------------------------------|
|  There is no syntactic error!  |
|--------------------------------|
