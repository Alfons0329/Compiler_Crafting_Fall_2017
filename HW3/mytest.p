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
        var c,b,multiarrref:integer;
        b := 12 ;
        c := a[a and b] ;
        multiarrref := a[1][2][a and b][2*4+66605][3 mod 465] ;
        c := amodb ; //this is an identifier
        // simple statement
        a := 1.0 - (-5);
        b := 2.3E-1;
        multiarrref := 3456789 mod( 2- (-1) )*b[2*2*2*2*2*2];
        // compound statement
        begin
                var c: boolean;
                c := a<b;
                a := a - b + c + d;
                a := 123445555;
        end
        a:=a+b+c+d+e*6*7*8*9+12;
        if a*b>c and e then
        end if
        //a := b := c; if comment this one, parse error here
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
        a:=4*5*6;
        //tricky test case
        b:=a-b;
        b:=a--b;

        // function invocation statement
        echo();
        callfunctionwithsomearguments(a, b, a[1][2][a and b][2*4+66605][3 mod 465], a mod b,c and z,1.123456,(a[1][3+4]));
end
end statement
