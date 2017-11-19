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
func(a:integer):array 1 to 5 of integer;  //this should be correct
begin
     return a;
end
end func

begin
        var L2darray: array 1 to 5 of array 1 to 3 of integer; //should be correct
        var a, b: real;
        var i, k: integer;


        var a:array 1 to 5 of integer;  //these four statements should be correct
        var c,b:integer;
        b := 12 ;
        c := a[a and b] ;

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
