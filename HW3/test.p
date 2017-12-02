test;
//&T-
// no global declaration(s)

func( a: integer ; b: array 1 to 2 of array 2 to 4 of real ): boolean;
begin
        var c: "hello world!";
        begin
                var d: real;
                return (b[1][4] >= 1.0);
        end
end
end func

begin
        var a: integer;
        begin
                var a: boolean; // outer 'a' has been hidden in this scope
        end
end
end test
