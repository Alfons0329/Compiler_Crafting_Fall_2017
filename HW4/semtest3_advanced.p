//&S-
//&T-
//&D-
/**
 * semtest3.p : check array type properties 
 */
semtest3;
var c : integer;
var k : integer;
var p : 123;

fun( a : array 1 to 5 of integer ) : array 1 to 5 of integer; // return type of function cannot be array type -> this is not a valid function declaration -> we don't insert fun to symbol table
begin
    var i : integer;
    i := 1;
    while i <= 5 do
        a[i] := i*i;
    end do
    
    return a;
end
end fun


fun2( a : array 1 to 5 of integer ): integer; // valid function declaration -> func2 will be inserted to symbol table
begin
    var i : integer;
    i := 1;
    while i <= 5 do
        a[i] := i*i;
    end do
    
    return a;        // error, return an array
end
end fun2

// main program
begin
   
    var a : array 1 to 10 of integer;                // 1D integer array , size=10
    var b, result : array 1 to 5 of integer;         // 1D integer array , size=5
    var c : array 1 to 5 of array 1 to 5 of integer; // 2D integer array , size=5*5
    var aa : integer;
	var cc : real;
    var bb,cc : boolean;             //error redeclare
    var h,i: array 1 to 8 of string; //my test
    var zr: array 1 to 8 of integer;
    var twodim: array 1 to 8 of array 1 to 7 of integer; //mytest
    //&S+
	if a >= b then                        // error a , b should be integer/real               
	    dd := aa;                         // error not declared
	    c := aa;                          // error array can not be assign
	else
	    p := aa;                          // error const cannot be assign
	    k := aa;                          // correct k is global variable
	end if
	 
    cc := aa;                         // correct integer assign to real
	aa := cc;                         // error, real assign to integer 
	
    aa := zr[2] * zr[3];              // correct integer * integer 
    aa := zr[2][3] + twodim[2][3];    // error, error dimension of zr
	
    result := fun(b);        // error, LHS=int[5] RHS=?
    result := fun2(a);       // error, parameter type inconsistent
    result := fun2(c);       // error, parameter type inconsistent
    result := fun2(c[2]);    // error, LHS=int[5] RHS=int
    result[2] := fun2(c[2]); // ok
    c[3][2] := fun2(b);      // ok
    c := b;                  // error ,LHS=2D RHS=1D
	
    return a;                // error ,cannot return in main
end
end semtest3
