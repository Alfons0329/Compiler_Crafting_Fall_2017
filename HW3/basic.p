//&T-
basic;

// scaler type
var a,b,c : integer;
var c : boolean;
var d : string;
var r : real;

//array type
var e,ee : array 1 to 10 of integer;
var f : array 1 to 5 of array 1 to 5 of array 100 to 101 of integer;

//Constant
var g,gg : 10;
var a : "Gimme Gimme Gimme!!";
var a : true;
var a : 2.56;
var a : 111.111E-3;


fun();
begin
end
end fun

fun( a,b:integer; c:string ): integer;
begin
end
end fun

fun2( a:array 1 to 10 of boolean ) : array 11 to 20 of real;
begin
    var fun2 : 123456 ;//infucntion
end
end fun2

fun3( a,b:integer; c:string ): integer;
begin
end
end fun3

//&D-
begin
    var noDump: string;
end
//&D+
end basic
