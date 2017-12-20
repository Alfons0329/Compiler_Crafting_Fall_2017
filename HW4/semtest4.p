
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

        if i1  then     //error what in conditional should be the boolean type
            i1 := 3;
        else
            i1 := 4;
        end if

        if b2  then     //correct
            i1 := 3;
        else
            i1 := 4;
        end if

        if r2 > 2.0  then    //correct
            i1 := 3;
        else
            i1 := 4;
        end if

        while i2    //error what in conditional should be the boolean type
        do
            i2 := 4;
        end do

        while b2    //correct
        do
            i2 := 4;
        end do

        while i1 > 2.0   //correct
        do
            i2 := 4;
        end do


end
end semtest4
