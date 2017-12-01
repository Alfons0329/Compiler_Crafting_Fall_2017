/**
 * test.p: simple P language example
 */
//&T-
test;

var a: integer;		// global variable

foo( a, b: integer ): integer;
begin
	return a*b;
end
end foo

// main block
begin

	print foo(2*4,3);

end
end test
