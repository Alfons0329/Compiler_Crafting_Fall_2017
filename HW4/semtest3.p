//&S-
//&T-
//&D-
/**
 * semtest3.p : check array type properties 
 */
semtest3;

fun( a : array 1 to 5 of integer ) : array 1 to 5 of integer;
begin
    var i : integer;
    i := 1;
    while i <= 5 do
        a[i] := i*i;
    end do
    
    return a;        // ok, return 1D integer array
end
end fun


fun2( a : array 1 to 5 of integer ): array 1 to 5 of integer;
begin
    var i : integer;
    i := 1;
    while i <= 5 do
        a[i] := i*i;
    end do
    
    return a[2];        // error, return scalar
end
end fun2

// main program
begin

    var a : array 1 to 10 of integer;                // 1D integer array , size=10
    var b, result : array 1 to 5 of integer;         // 1D integer array , size=5
    var c : array 1 to 5 of array 1 to 5 of integer; // 2D integer array , size=5*5

    result := fun(b);    // ok
    result := fun(a);    // error, parameter type inconsistent
    result := fun(c);    // error, parameter type inconsistent
    result := fun(c[2]); // ok
    c[3] := fun(b);      // ok
    c := fun(b);         // error ,LHS=2D RHS return 1D

end
end semtest3
