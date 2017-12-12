//&S-
//&T-
//&D-
/**
 * semtest4.p: test for type coercion
 */
semtest4;

begin
        var i1, i2: integer;
        var r1, r2: real;
        var s1, s2: string;
        var b1, b2: boolean;

        r1 := i1+i2;    // ok, LHS=real, RHS=integer
        r2 := r1+i2;    // ok, r1+i2 ---> real

        s1 := s2+"123"; // ok
        b1 := i1+i2;    // error, LHS=boolean, RHS=integer

        i1 := i2-r1;    // error, RHS=real, cannot convert into integer implicitly

end
end semtest4
