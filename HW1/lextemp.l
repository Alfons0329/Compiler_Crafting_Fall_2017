%{
#define LIST MAX_LINE_LENG strcat ( buf , yytext )
#define token ( t ) { LIST ; if ( Opt_T ) printf ( " <%s>\ n " , # t );}
#define tokenChar ( t )  { LIST ; if ( Opt_T ) printf ( " <%c>\ n " , ( t ));}
#define tokenInteger (t , i ) { LIST ; if ( Opt_T ) printf ( " <%s : %d>\ n " , #t , ( i ));}
#define tokenString (t , s ) { LIST ; if ( Opt_T ) printf ( " <%s : %s>\ n " , #t , ( s ));}
#define MAX_LINE_LENG 256
int Opt_S = 1;
int Opt_T = 1;
int linenum = 1;
char buf [ MAX_LINE_LENG ];

oct_integer [0][1-9]*
integer [1-9][0-9]*

float_num [0-9]+'.'[0-9]+

%}
%%
',' {tokenChar(',');}
';' {tokenChar(';');}
':' {tokenChar(':');}
'(' {tokenChar('(');}
')' {tokenChar(')');}
'[' {tokenChar('[');}
']' {tokenChar(']');}

'+' {tokenChar('+');}
'-' {tokenChar('-');}
'*' {tokenChar('*');}
'/' {tokenChar('/');}
"mod" {token(yytext);}
":=" {token(":=");}
("<"|"<="|"<>"|">="|">"|"=") {token(yytext);}
("and"|"or"|"not"){token(yytext);}

"begin" {token(KWbegin); printf("%d: begin\n",linenum);}
"array" {token(KWarray); printf("%d: array\n",linenum);}
"boolean" {token(KWboolean); printf("%d: boolean\n",linenum);}
"def" {token(KWdef); printf("%d: def\n",linenum);}
"do" {token(KWdo); printf("%d: do\n",linenum);}
"else" {token(KWelse); printf("%d: else\n",linenum);}
"end" {token(KWend); printf("%d: end\n",linenum);}
"false" {token(KWfalse); printf("%d: false\n",linenum);}
"for" {token(KWfor); printf("%d: for\n",linenum);}
"integer" {token(KWinteger); printf("%d: integer\n",linenum);}
"if" {token(KWif); printf("%d: if\n",linenum);}
"of" {token(KWof); printf("%d: of\n",linenum);}
"print" {token(KWprint); printf("%d: print\n",linenum);}
"read" {token(KWread); printf("%d: read\n",linenum);}
"real" {token(KWreal); printf("%d: real\n",linenum);}
"string" {token(KWstring); printf("%d: string\n",linenum);}
"then" {token(KWthen); printf("%d: then\n",linenum);}
"to" {token(KWto); printf("%d: to\n",linenum);}
"true" {token(KWtrue); printf("%d: true\n",linenum);}
"return" {token(KWreturn); printf("%d: return\n",linenum);}
"var" {token(KWvar); printf("%d: var\n",linenum);}
"while" {token(KWwhile); printf("%d: while\n",linenum);}

[a-zA-Z_][a-zA-Z_0-9]* {tokenString(id,yytext);}

{oct_integer} {tokenInteger("oct_integer",strtol(yytext,NULL));}
{integer} {tokenInteger("integer",strtol(yytext,NULL));}

{float_num} {token(strtof(yytext,NULL))}

[+-]?({integer}|{float_num})'E'('+'|'-')?({integer})

'"'(.)*'"'
{
    char yytext_arr[]= yytext
    char answer_buf[10000]={0};
    for(int i=0,buf_idx=0;i<yyleng-1;)
    {
        if(!i)
        {
            i++;
        }
        else if(yytext_arr[i]=='"'&&yytext_arr[i+1]=='"')
        {
            answer_buf[buf_idx]=yytext_arr[i];
            i+=2;
            buf_idx++;
        }
        else
        {
            answer_buf[buf_idx]=yytext_arr[i];
            i++;
            buf_idx++;
        }
    }
}
%%
int main ( int argc , char ** argv )
{
    if ( argc != 2 )
    {
        fprintf ( stderr , " Usage : ./ scanner [ filename ]\ n " );
        exit (0);
    }
    FILE * fp = fopen ( argv [1] , " r " );
    if ( fp == NULL )
    {
        fprintf ( stderr , " Open file error \ n " );
        exit ( -1);
    }
    yyin = fp ;
    yylex ();
    exit (0);
}
