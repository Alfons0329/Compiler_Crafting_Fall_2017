1: //&T-
2: error;
3: 
4: func1(p1:string;p2:array 99 to 100 of integer):array 1 to 10 of real;
5: begin
<Error> found in Line 6: symbol p1 is redeclared
6:     var p1:boolean;  // error redeclare
==============================================================================================================
Name                             Kind       Level      Type             Attribute  
--------------------------------------------------------------------------------------------------------------
p1                               parameter  1(local)   string           
p2                               parameter  1(local)   integer [2]      
--------------------------------------------------------------------------------------------------------------
7: end
8: end func1
9: 
10: begin
11:     var a:integer;
<Error> found in Line 12: symbol a is redeclared
12:     var a:boolean;   // error redeclare
13: 
14:     var bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb : boolean;
<Error> found in Line 15: symbol bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb is redeclared
15:     var bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbExtraCharIsUseless:string;
16: 
17:     begin
18:         var a:string;
==============================================================================================================
Name                             Kind       Level      Type             Attribute  
--------------------------------------------------------------------------------------------------------------
a                                variable   2(local)   string           
--------------------------------------------------------------------------------------------------------------
19:     end
20: 
21:     for i:=1 to 10 do
22:     begin
<Error> found in Line 23: symbol i is redeclared
23:         var i : integer;       // error redeclare
<Error> found in Line 24: symbol i is redeclared
24:         for i:=2 to 3 do      // error same iterator
25:             a:=3;
26:         end do
==============================================================================================================
Name                             Kind       Level      Type             Attribute  
--------------------------------------------------------------------------------------------------------------
--------------------------------------------------------------------------------------------------------------
27:     end
28:     end do
29: 
==============================================================================================================
Name                             Kind       Level      Type             Attribute  
--------------------------------------------------------------------------------------------------------------
a                                variable   1(local)   integer          
bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb variable   1(local)   boolean          
--------------------------------------------------------------------------------------------------------------
30: end
==============================================================================================================
Name                             Kind       Level      Type             Attribute  
--------------------------------------------------------------------------------------------------------------
error                            program    0(global)  void             
func1                            function   0(global)  real [10]        string, integer [2]
--------------------------------------------------------------------------------------------------------------
31: end error
