/*
 * advance_sym.p : Advanced symbol table info. dump check
 * You should pass this pattern
 */
//&T-
advanceSym;
var a,b : integer;
var c : boolean;
var d : string;
var r : string;
var e : array 1 to 10 of integer;
var f : array 1 to 5 of array 1 to 5 of integer;
var ee : array 1 to 10 of boolean;
var ff : array 1 to 5 of array 1 to 5 of boolean;
var gg : array 100 to 199 of real;
var g : 123;
var h : "bye~";
var i : true;
var k : 678E-2;

// function without param and return type
fun();
begin

end
end fun

// function with param, no return type
fun2( a,b: array 1 to 10 of array 1 to 5 of integer ; c:boolean );
begin
    var d : integer;
    var e : boolean;

    begin
        var a,b,c : string;
        var d : array 1 to 5 of integer;
    end
end
end fun2


// main program
begin
    var aaa, i : integer;
    var bbb : boolean;

    while i < 100 do
    begin
        var sum : integer;
        sum := i*i;
        print sum;
    end
    end do

    for it:=10 to 111 do
    begin
        var a : string;
        begin
            var a : integer;
            begin
                var a : real;
            end
        end
    end
    end do

end
end advanceSym
