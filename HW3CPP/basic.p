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
var h : "Gimme Gimme Gimme!!";
var i : true;
var j : 2.56;
var k : 111.111E-3;
var l : 0777;    // note octal

fun();
begin
end
end fun

fun2( a,b:integer; c:string ): integer;
begin
end
end fun2

fun3( a:array 1 to 10 of boolean ) : array 11 to 20 of real;
begin
end
end fun3

//&D-
begin
    var noDump: string;
end
//&D+
end basic
