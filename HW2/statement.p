/**
 * statement.p: examples for each statement
 */
//&T-
statement;

echo();
begin
        var s: string;
        read s;         // simple statement
        print s;        // simple statement
end
end echo

funny(): boolean;
begin
        return 1<>1;    // return statement
end 
end funny


begin

        var a, b: real;
        var i, k: integer;

        // simple statement
        a := 1.0;
        b := 2.3E-1;

        // compound statement
        begin
                var c: boolean;
                c := a < b;
        end
        
        // condition statement
        if a > b then
                print " a > b \n";
        else
                print " a <= b \n";
        end if

        // while statement
        i := 1;
        while i <= 10 do
                print i*i;
                print "\n";
        end do

        // for statement
        for k := 10 to 20 do 
                print k*3;
                print "\n";
        end do

        // function invocation statement 
        echo();

end
end statement
