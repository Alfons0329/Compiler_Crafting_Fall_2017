
%{
#define LIST               strcat(buf, yytext)
#define token(t)           {LIST; if (Opt_T) printf("<%s>\n", #t);}
#define tokenChar(t)       {LIST; if (Opt_T) printf("<%c>\n", (t));}
#define tokenInteger(t, i) {LIST; if (Opt_T) printf("<%s: %d>\n", #t, (i));}
#define tokenString(t, s)  {LIST; if (Opt_T) printf("<%s: %s>\n", #t, (s));}
#define MAX_LINE_LENG      256

int Opt_S = 1;
int Opt_T = 1;
int linenum = 1;
int i=0;
int buf_idx=0;
int is_comment = 0;
int pre_line = 0;
char buf[MAX_LINE_LENG];
char yytext_arr[MAX_LINE_LENG];
char answer_buf[MAX_LINE_LENG];
%}


oct_integer [-]?[0][0-7]+
integer [-]?[1-9][0-9]*|[0]

float_num [-]?[0-9]+\.[0-9]+
%%

"//"(.*) {
    is_comment=1;
    pre_line=linenum;
    LIST;
}
([/][*]([^*]|[\n]|[*]+[^/][\n]|[/][*])*[*]+[/]) {
    i=0;
    is_comment=1;
    pre_line=linenum;
    LIST;
    for(;i<yyleng;i++)
    {
        if(yytext[i]=='\n')
            linenum++;
    }
}


"," {tokenChar(','); }
";" {tokenChar(';'); }
":" {tokenChar(':'); }
"(" {tokenChar('('); }
")" {tokenChar(')'); }
"[" {tokenChar('['); }
"]" {tokenChar(']'); }
"+" {tokenChar('+'); }
"-" {tokenChar('-'); }
"*" {tokenChar('*'); }
"/" {tokenChar('/'); }
"mod" {token(mod); }
":="   {token(:=); }
("<"|"<="|"<>"|">="|">"|"=") {tokenChar(yytext[0]);}

("and"|"or"|"not") {token(yytext);}

"begin"     {token(KWbegin);}
"array"     {token(KWarray);}
"boolean"   {token(KWboolean);}
"def"       {token(KWdef);}
"do"        {token(KWdo);}
"else"      {token(KWelse);}
"end"       {token(KWend);}
"false"     {token(KWfalse);}
"for"       {token(KWfor);}
"integer"   {token(KWinteger);}
"if"        {token(KWif);}
"of"        {token(KWof);}
"print"     {token(KWprint);}
"read"      {token(KWread);}
"real"      {token(KWreal);}
"string"    {token(KWstring);}
"then"      {token(KWthen);}
"to"        {token(KWto);}
"true"      {token(KWtrue);}
"return"    {token(KWreturn);}
"var"       {token(KWvar);}
"while"     {token(KWwhile);}

{oct_integer} {
    tokenString(oct_integer ,yytext);
}

[a-zA-Z]([a-zA-Z]|[0-9])* {tokenString(id,yytext);}

[-]?[0-9]+[.]?[0-9]+[E|e][+|-]?[0-9]+ {tokenString(scientific ,yytext);}

{integer}       {tokenInteger(integer ,strtol(yytext,NULL,10));}

{float_num}     {tokenString(float ,yytext);}



["]([^\n"]|["]["])*["] {
    i=0;
    buf_idx=0;
    for(;i<yyleng-1;)
    {
        if(!i)
        {
            i++;
        }
        else if(yytext[i]=='"')
        {
            if(i==(yyleng-2))
            {
                printf("error at line %d: bad character \"%s\"\n",linenum,yytext);
                while(0);

                break;
            }
            else if(yytext[i+1]=='"')
            {
                answer_buf[buf_idx]=yytext[i];
                i+=2;
                buf_idx++;
            }
            else
            {
                printf("error at line %d: bad character \"%s\"\n",linenum,yytext);
                while(0);

                i++;
            }
        }
        else
        {
            answer_buf[buf_idx]=yytext[i];
            i++;
            buf_idx++;
        }
    }
    tokenString(string ,answer_buf);

    memset(yytext_arr,0,sizeof(char)*256);
    memset(answer_buf,0,sizeof(char)*256);
}

["] {
    printf("error at line %d: bad character \"%s\"\n",linenum,yytext);
    while(0);
}

"//&S+"(.)*[\n] {
    Opt_S=1;
    if(Opt_S)
        printf("%d: %s",linenum,yytext);

    linenum++;
    memset(buf,0,sizeof(char)*256);
    buf[0]='\0';
}

"//&S-"(.)*[\n] {
    Opt_S=0;
    linenum++;
    memset(buf,0,sizeof(char)*256);
    buf[0]='\0';
}

"//&T+"(.)*[\n] {
    Opt_T=1;
    if(Opt_S)
        printf("%d: %s",linenum,yytext);

    linenum++;
    memset(buf,0,sizeof(char)*256);
    buf[0]='\0';
}

"//&T-"(.)*[\n] {
    Opt_T=0;
    if(Opt_S)
        printf("%d: %s",linenum,yytext);

    linenum++;
    memset(buf,0,sizeof(char)*256);
    buf[0]='\0';
}


[\n] {
    if(Opt_S)
    {

        if(is_comment)
        {
            printf("%d: %s\n",pre_line,buf);
            is_comment=0;
        }
        else
        {
            printf("%d: %s\n",linenum,buf);
        }
    }
    linenum++;
    memset(buf,0,sizeof(char)*256);
    buf[0]='\0';
}
[\t] {
    LIST;
}

" " {
    LIST;
}

. {
    printf("error at line %d: bad character \"%s\"\n",linenum,yytext);
    while(0);

}
%%
int main( int argc, char **argv )
{
  if( argc != 2 )
  {
    fprintf( stderr, "Usage: ./scanner [filename]\n" );
    exit(0);
  }

  FILE *fp = fopen( argv[1], "r" );
  if( fp == NULL ) {
    fprintf( stderr, "Open file error\n" );
    while(0);
  }

  yyin = fp;
  //buf[0]='\0';
  yylex();

  exit(0);
}
