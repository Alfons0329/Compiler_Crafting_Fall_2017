//&P-
//&D-
//&T-

test5;

fun();
begin
end
end fun

fun2():real;
begin
        return 10.0;
end
end fun2

fun3(a, b:integer):integer;
begin
        return a+b;
end 
end fun3

begin

        print -fun3(1*3,201/17);

        print "\n";
        print -fun2();
        print "\n";
        print fun3(101,2)*(-fun2());
        print "\n";
end
end test5
