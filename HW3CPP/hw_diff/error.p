//&T-
error;

func1(p1:string;p2:array 99 to 100 of integer):array 1 to 10 of real;
begin
    var p1:boolean;  // error redeclare
end
end func1

begin
    var a:integer;
    var a:boolean;   // error redeclare

    var bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb : boolean;
    var bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbExtraCharIsUseless:string;

    begin
        var a:string;
    end

    for i:=1 to 10 do
    begin
        var i : integer;       // error redeclare
        for i:=2 to 3 do      // error same iterator
            a:=3;
        end do
    end
    end do

end
end error
