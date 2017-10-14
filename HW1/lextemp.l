%{
#define LIST MAX_LINE_LENG strcat ( buf , yytext )
#define token ( t ) { LIST ; if ( Opt_T ) printf ( " <%s> \n " , # t );}
#define tokenChar ( t )  { LIST ; if ( Opt_T ) printf ( " <%c> \n " , ( t ));}
#define tokenInteger (t , i ) { LIST ; if ( Opt_T ) printf ( " <%s : %d> \n " , #t , ( i ));}
#define tokenString (t , s ) { LIST ; if ( Opt_T ) printf ( " <%s : %s> \n " , #t , ( s ));}
#define MAX_LINE_LENG 256
int Opt_S = 1;
int Opt_T = 1;
int linenum = 1;
char buf[MAX_LINE_LENG];
buf[0]='\0';

oct_integer [-]?[0][1-9]*
integer [-]?[1-9][0-9]*

float_num [+-]?[0-9]+\.[0-9]+

%}

%%
"," {tokenChar(','); strcat(buf,yytext);}
";" {tokenChar(';'); strcat(buf,yytext);}
":" {tokenChar(':'); strcat(buf,yytext);}
"(" {tokenChar('('); strcat(buf,yytext);}
")" {tokenChar(')'); strcat(buf,yytext);}
"[" {tokenChar('['); strcat(buf,yytext);}
"]" {tokenChar(']'); strcat(buf,yytext);}
"+" {tokenChar('+'); strcat(buf,yytext);}
"-" {tokenChar('-'); strcat(buf,yytext);}
"*" {tokenChar('*'); strcat(buf,yytext);}
"/" {tokenChar('/'); strcat(buf,yytext);}
"mod" {token("mod"); strcat(buf,yytext);}
":="   {token(":="); strcat(buf,yytext);}
("<"|"<="|"<>"|">="|">"|"=") {token(yytext);strcat(buf,yytext);}
("and"|"or"|"not"){token(yytext);strcat(buf,yytext);}

"begin"     {token(KWbegin);strcat(buf,yytext);}
"array"     {token(KWarray);strcat(buf,yytext);}
"boolean"   {token(KWboolean);strcat(buf,yytext);}
"def"       {token(KWdef);strcat(buf,yytext);}
"do"        {token(KWdo);strcat(buf,yytext);}
"else"      {token(KWelse);strcat(buf,yytext);}
"end"       {token(KWend);strcat(buf,yytext);}
"false"     {token(KWfalse);strcat(buf,yytext);}
"for"       {token(KWfor);strcat(buf,yytext);}
"integer"   {token(KWinteger);strcat(buf,yytext);}
"if"        {token(KWif);strcat(buf,yytext);}
"of"        {token(KWof);strcat(buf,yytext);}
"print"     {token(KWprint);strcat(buf,yytext);}
"read"      {token(KWread);strcat(buf,yytext);}
"real"      {token(KWreal);strcat(buf,yytext);}
"string"    {token(KWstring);strcat(buf,yytext);}
"then"      {token(KWthen);strcat(buf,yytext);}
"to"        {token(KWto);strcat(buf,yytext);}
"true"      {token(KWtrue);strcat(buf,yytext);}
"return"    {token(KWreturn);strcat(buf,yytext);}
"var"       {token(KWvar);strcat(buf,yytext);}
"while"     {token(KWwhile);strcat(buf,yytext);}

[a-zA-Z_][a-zA-Z_0-9]* {tokenString(id,yytext);strcat(buf,yytext);}

{oct_integer}   {tokenInteger("oct_integer",strtol(yytext,NULL));strcat(buf,yytext);}
{integer}       {tokenInteger("integer",strtol(yytext,NULL));strcat(buf,yytext);}

{float_num}     {token(strtof(yytext,NULL));strcat(buf,yytext);}

[-]?({integer}|{float_num})'E'[+-]?({integer}) {token("scientific: ",yytext);strcat(buf,yytext);}

\"(.)*\"
{
    strcat(buf,yytext);
    char yytext_arr[]= yytext;
    char answer_buf[256]={0};
    for(int i=0,buf_idx=0;i<yyleng-1;)
    {
        if(!i)
        {
            i++;
        }
        else if(yytext_arr[i]=='"')
        {
            if(i==(yleng-2))
            {
                printf("error at line %d: bad character \"%s\"\n",linenum,yytext);
                exit(EXIT_FAILURE);
            }
            else if(yytext_arr[i+1]=='"')
            {
                answer_buf[buf_idx]=yytext_arr[i];
                i+=2;
                buf_idx++;
            }
        }
        else
        {
            answer_buf[buf_idx]=yytext_arr[i];
            i++;
            buf_idx++;
        }
    }
}

" " ;

"//&S+" {Opt_S=1;}

"//&S-" {Opt_S=0;}

"//&T+" {Opt_T=1;}

"//&T-" {Opt_T=0;}


\/\/(.)*
{
    strcat(buf,yytext);
}

\/\*(.|[\n])*\*\/
{
    strcat(buf,yytext);
    char yytext_arr[]= yytext;
    for(int i=0;i<yyleng;i++)
    {
        if(yytext_arr[i]=='\n')
            linenum++;
    }
}

[\n]
{
    printf("%d %s \n",linenum,buf);
    linenum++;
    memset(buf,0,sizeof(char)*256);
    buf[0]='\0';
}

.
{
    printf("error at line %d: bad character \"%s\"\n",linenum,yytext);
    exit(EXIT_FAILURE);
}
%%

int main ( int argc , char ** argv )
{
    if(argc!=2)
    {
        fprintf( stderr , " Usage : ./ scanner [ filename ] \n " );
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
