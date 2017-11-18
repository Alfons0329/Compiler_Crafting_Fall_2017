
|--------------------------------------------------------------------------
| Error found in Line #16:         var
|
| Unmatched token: var
|--------------------------------------------------------------------------
1: /**
2:  * err2.p: error case 2
3:  *
4:  * Description: local variable declaration after statement(s), at line 16
5:  */
6: //&T-
7: 
8: err2;
9: 
10: var globalA: integer;
11: 
12: begin
13: 
14:         globalA := 123;
15: 
