/**
 * err2.p: error case 2
 *
 * Description: local variable declaration after statement(s), at line 16
 */
//&T-

err2;

var globalA: integer;

begin

        globalA := 123;

        var b: integer;

        b := globalA*globalA;

end
end err2
