// Redefined
//&T-
//&D-
Redefined;


var a, b: integer;
var i : integer;
var i : string;		// error, var i redeclared

func( aa, bb : integer ) : integer ;
begin
    var aa : boolean;       // error, var aa redeclared as parameter
    var b : string;         // ok, in nested scope
    var b: string;          // error, var b redeclared
end
end func

func();
begin
end
end func

// main program
begin

    var a, b, c: integer;      // ok, in nested scope
    var a : integer;          // error
    var c : integer;          // error
    var ii: integer;
    var aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabbb : string;
    var aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaccc : string;  // error, variable redefine
    begin
        var a: 100;
        var a : "100";    // error
        var a : true;    // error
        begin
            var xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxoooooo : string;
            var xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxz : string;  // error, variable redefine
        end
    end

    while ii < 10 do
        begin    
            var a : boolean;    // ok, in nested scope
            var a : string;     // error, var a redeclared
            var c : 1.1;   
            var c: 01010;    // error
            var c,c: 7777;    // error
            var c: false;    // error
        end
    end do
    
end
end Redefined

