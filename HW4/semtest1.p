//&S-
//&T-
//&D-
/**
 *  semtest1.p :
 *
 *  There is no syntax error, but exists some semantic errors.
 *  You must indicate all of the semantic errors.
 *
 */
semtest1;

var a : 10;       // a is integer constant
var b : 10.635;
var dr : real;
fun( a,b : integer ) : integer;
begin
    if a >= b then
        return a*3;
    else
        return b*3;
    end if
end
end fun

fun2();
begin
    print "message\n";
end
end fun2

// main program
begin

    var aa : integer;
    var bb,cc : boolean;
    var h,i: array 1 to 8 of string; //my test
    var zr: array 1 to 8 of integer;
    var twodim: array 1 to 8 of array 1 to 7 of integer; //mytest
    //&S+

    zr := twodim;      //error array dimension error, also , whole array cannot be assigned
    twodim := zr;      //error array dimension error, also , whole array cannot be assigned

    aa := twodim[2][4]; //correct
    twodim[7][3] := aa; //correct
    twodim[7] := aa;    //incorrect not a scalar type
    twodim := zr;       //incorrect not a scalar type
    zr[8] := twodim[4][7]; //correct
    zr[8] := twodim[4];  //incorrect not a scalar type
    zr[8] := twodim;    //incorrect not a scalar type
    h[4] := zr[5];      //array in same dimension but different type error

    a := 5;            // error, constant cannot be assigned
    aa := fun(1,2);    // ok
    fun(1,2);          // ok
    aa := fun(a,a);    // ok
    aa := h[4];        // error string array cannot assign to integer
    h[4] := aa;        // still an error like line54
    dr := aa;          // ok assign integer to real , type coercion
    aa := dr;          // wrong assign real to integer, invalid type coercion
    dr := zr[7];       // ok assign integer to real , type coercion
    zr[7] := dr;       // wrong assign real to integer, invalid type coercion
    aa := zr[3];       // correct a LHS RHS same type
    zr[3] := aa;       // correct a LHS RHS same type
    aa := fun(a);      // error, parameter number inconsistent
    aa := fun(bb,cc);  // error, parameter type inconsistent
    bb := fun2();      // error, fun2() has no return type
    bb := fun(5,6);    // error, return type inconsistent
    fun2();            // ok
    //&S-
end
end semtest1
