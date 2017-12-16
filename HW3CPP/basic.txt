1: //&T-
2: basic;
3: 
4: // scaler type
5: var a,b,c : integer;
<Error> found in Line 6: symbol c is redeclared
6: var c : boolean;
7: var d : string;
8: var r : real;
9: 
10: //array type
11: var e,ee : array 1 to 10 of integer;
12: var f : array 1 to 5 of array 1 to 5 of array 100 to 101 of integer;
13: 
14: //Constant
15: var g,gg : 10;
16: var h : "Gimme Gimme Gimme!!";
17: var i : true;
18: var j : 2.56;
19: var k : 111.111E-3;
20: var l : 0777;    // note octal
21: 
22: fun();
23: begin
==============================================================================================================
Name                             Kind       Level      Type             Attribute  
--------------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------------
24: end
25: end fun
26: 
27: fun2( a,b:integer; c:string ): integer;
28: begin
==============================================================================================================
Name                             Kind       Level      Type             Attribute  
--------------------------------------------------------------------------------------------------------------
a                                parameter  1(local)   integer          
b                                parameter  1(local)   integer          
c                                parameter  1(local)   string           
--------------------------------------------------------------------------------------------------------------
29: end
30: end fun2
31: 
32: fun3( a:array 1 to 10 of boolean ) : array 11 to 20 of real;
33: begin
==============================================================================================================
Name                             Kind       Level      Type             Attribute  
--------------------------------------------------------------------------------------------------------------
a                                parameter  1(local)   boolean [10]     
--------------------------------------------------------------------------------------------------------------
34: end
35: end fun3
36: 
37: //&D-
38: begin
39:     var noDump: string;
40: end
41: //&D+
==============================================================================================================
Name                             Kind       Level      Type             Attribute  
--------------------------------------------------------------------------------------------------------------
basic                            program    0(global)  void             
a                                variable   0(global)  integer          
b                                variable   0(global)  integer          
c                                variable   0(global)  integer          
d                                variable   0(global)  string           
r                                variable   0(global)  real             
e                                variable   0(global)  integer [10]     
ee                               variable   0(global)  integer [10]     
f                                variable   0(global)  integer [5][5][2]
g                                constant   0(global)  integer          10
gg                               constant   0(global)  integer          10
h                                constant   0(global)  string           "Gimme Gimme Gimme!!"
i                                constant   0(global)  boolean          true
j                                constant   0(global)  real             2.560000
k                                constant   0(global)  real             0.111111
l                                constant   0(global)  integer          511
fun                              function   0(global)  void             
fun2                             function   0(global)  integer          integer, integer, string
fun3                             function   0(global)  real [10]        boolean [10]
--------------------------------------------------------------------------------------------------------------
42: end basic
