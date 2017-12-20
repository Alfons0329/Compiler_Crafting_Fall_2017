//&S-
//&T-
//&D-
/**
 * semtest5.p: test for program name
 */
test;
foo(): integer;
begin
    var a: array 1 to 3 of array 1 to 3 of integer;
    var b: array 1 to 5 of array 1 to 3 of integer;
    var i, j: integer;
    var k : boolean;
    a[1][1] := i; // legal
    i := a[1][1] + j; // legal
    a[1][1] := b[1][2]; // legal
    a := b; // illegal array arithmetic
    a[1] := b[2]; // illegal: array arithmetic
    return k; // legal: ‘a[1][1]’ is a scalar type, but ‘a’ is an array type.
end
end foo
begin
    foo();
end
end ttest
