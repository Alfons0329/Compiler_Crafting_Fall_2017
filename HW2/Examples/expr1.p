/**
 * expr1.p: expression
 */
//&T-
expr1;


begin

        var a, b: integer;
        a := 2;
        b:= 3;

        print 1+2*(3+4);

        if a*3+1 <> b*4 mod 123 then
                print "test";
        end if

end
end expr1
