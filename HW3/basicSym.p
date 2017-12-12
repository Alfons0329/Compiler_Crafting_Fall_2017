/**
 * basic_sym.p : basic symbol table info. dump check
 * You should pass this pattern
 */
//&T-
basicSym;


var aaa : integer;
var bbb : boolean;
var ccc : string;
var rrr : real;
var ddd : array 1 to 10 of integer;
var eee : array 1 to 5 of array 1 to 5 of boolean;
var ttt : array 2 to 3 of array 5 to 10 of array 1 to 5 of real;
var fff : 123;
var ggg : true;
var hhh : "hello\n";
var iii : 2.86;

var f : array 1 to 5 of array 1 to 5 of integer;
var ee : array 1 to 10 of boolean;
var ff : array 1 to 5 of array 1 to 5 of boolean;
var rr : array 3 to 5 of array 5 to 7 of real;
var g : 10;
var h : "bye~";
var i : true;
var k : 2.56;

// function without param and return type
fun();
begin

end 
end fun

// function with param, no return type
fun2( a,b:integer );
begin

end
end fun2

// function with param and return type

fun4( a,b,c:boolean ) : boolean;
begin
    return false;
end
end fun4

// main program
begin
var a,b : integer;
var c : boolean;
var d : string;
var r : real;
var e : array 1 to 10 of integer;
end
end basicSym

