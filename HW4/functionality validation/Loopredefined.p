// Loopredefined

//&T-
//&D-

Loopredefined;
begin
    var i: string;
    var ii: string;
/* local var of for loop redeclaration */
    for i:=1 to 10 do
    begin
        var i: string;          // error
        for ii:=1 to 10 do
        begin
            for iii:=1 to 10 do
            begin
                for i:=1 to 10 do   //error
                begin
                end
                end do
            end
            end do
        end
        end do
    end
    end do

/* Nested for redeclaration*/
    for i:=1 to 10 do
    begin
        var i: 12 ;    // error
        var a : "100";
        for i:=1 to 10 do    // error
        begin
            for i:=1 to 10 do //error
            end do
        end
        end do
        begin
            var i:real;     // error
        end
    end
    end do


    for ii:=1 to 10 do
    begin
        var i: string;
        var ii : false; // error
        var i : false; // error
        for i:=1 to 10 do
        begin
            begin
            for i:=1 to 10 do       //error
            begin
                for i:=1 to 10 do   //error
                begin
                end
                end do
            end
            end do
            end
        end
        end do
    end
    end do
end
end Loopredefined
