//&S-
//&T-
//&D-
/**
 * semtest2.p
 */
semtest2;

// main program
begin
    var a, b, c : integer;
    var d, e, f : boolean;
    var g, h, i : string;

    b := 100;
    c := 25;
    a := b+c*c mod 17;            // ok
    a := b >= c*4;                // error, LHS=integer RHS=boolean
    e := b >= c*4;                // ok
    print a <> 11 ;               // ok
   
    e := false;
    f := true;
    d := e and f;                 // ok 
    d := true or false;           // ok
    d := a+b mod c;               // error, LHS=boolean RHS=integer
   
    g := "hello ";
    h := "world\n";
    i := g;                       // ok
    i := g+h;                     // ok, string concatenation
    i := g*h;                     // error, we cannot perform multiplication on string type

end
end semtest2
