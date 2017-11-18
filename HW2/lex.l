/**
 * Introduction to Compiler Design by Prof. Yi Ping You
 * Project 1 Sample
 */

%{

#include <string.h>

#define LIST strcat( buf, yytext )
#define token(t) { LIST; if (Opt_T) printf("<%s>\n", #t );}
#define tokenChar(t) { LIST; if (Opt_T) printf("<%c>\n", t );}
#define tokenInteger(t, i) { LIST; if (Opt_T) printf("<%s: %d>\n", t, i); }
#define tokenOctInteger(t, i) { LIST; if (Opt_T) printf("<%s: %s>\n", t, i); }
#define tokenFloat(t, i) { LIST; if (Opt_T) printf("<%s: %s>\n", t, i ); }
#define tokenScientific(t, s) { LIST; if ( Opt_T ) printf("<%s: %s>\n", t, s); }
#define tokenString(t, s) { LIST; if (Opt_T) printf("<%s: %s>\n", t, s); }


#define  MAX_LINE_LENG  256

int Opt_S = 1;				/* list source code option */
int Opt_T = 1;				/* list token option */
int linenum = 1;			/* line number */
char buf[MAX_LINE_LENG];		/* source code line buffer */
char strContent[MAX_LINE_LENG];		/* string buffer */

void setPseudoComment( const char * );	/* pseudo comment option switch */
%}

whitespace [ \t]+
letter [A-Za-z]
digit [0-9]
integer 0|[1-9][0-9]*
octal 0[0-7]+
fraction 0|[0-9]*
float {integer}"."{fraction}
scientific ({integer}|{float}|{octal})[Ee][+-]?({integer}|{octal})
identifier ({letter})({letter}|{digit})*

 /* exclusive start conditions */
%x COMMENT
%x COMMENT_CPP

%%

","				{ tokenChar(','); return COMMA}
";"				{ tokenChar(';'); return SEMICOLON}
":"				{ tokenChar(':'); return COLON}
")"				{ tokenChar(')'); return BRACELEFT}
"("				{ tokenChar('('); return BRACERIGHT}
"["				{ tokenChar('['); return BRACELEFT}
"]"				{ tokenChar(']'); return BRACKETRIGHT}

"+"				{ tokenChar('+'); return PLUS}
"-"				{ tokenChar('-'); return MINUS}
"*"				{ tokenChar('*'); return MULTIPLY}
"/"				{ tokenChar('/'); return DIVIDE}
"mod"			{ token(mod); return MOD}
":="			{ token(:=); return ASSIGN}
"<"				{ tokenChar('<'); return LESS}
"<="			{ token(<=); return LESSEQUAL}
"<>"			{ token(<>); return LESSGREATER}
">="			{ token(>=); return GREATEREQUAL}
">"				{ tokenChar('>'); return GREATER}
"="				{ tokenChar('='); return EQUAL}
"and"			{ token(and); return AND}
"or"			{ token(or); return OR}
"not"			{ token(not); return NOT}

"array"			{ token(KWarray); return KWARRAY}
"begin"			{ token(KWbegin); return KWBEGIN}
"boolean"		{ token(KWboolean); return KWBOOLEAN}
"def"			{ token(KWdef); return KWDEF}
"do"			{ token(KWdo); return KWDO}
"else"			{ token(KWelse); return KWELSE}
"end"			{ token(KWend); return KWEND}
"false"			{ token(KWfalse); return KWFALSE}
"for"			{ token(KWfor); return KWFOR}
"integer"		{ token(KWinteger); return KWINTEGER}
"if"			{ token(KWif); return KWIF}
"of"			{ token(KWof); return KWOF}
"print"			{ token(KWprint); return KWPRINT}
"read"			{ token(KWread); return KWREAD}
"real"			{ token(KWreal); return KWREAL}
"string"		{ token(KWstring); return KWSTRING}
"then"			{ token(KWthen); return KWTHEN}
"to"			{ token(KWto); return KWTO}
"true"			{ token(KWtrue); return KWTRUE}
"return"		{ token(KWreturn); return KWRETURN}
"var"			{ token(KWvar); return KWVAR}
"while"			{ token(KWwhile); return KWWHILE}

{octal} { tokenOctInteger("oct_integer",yytext); return OCTAL}
{identifier}			{ tokenString("id",yytext); return IDENT}
{integer}			{ tokenInteger("integer",atoi(yytext)); return INTEGER}
{float}				{ tokenFloat("float",yytext); return FLOAT}
{scientific}			{ tokenScientific("scientific", yytext); return SCIENTIFIC}

\"((\"\")|[^\"\n])*\"	{
				LIST;
				if (Opt_T){
					size_t wrt_idx = 0;
					size_t rd_idx = 1;
					int quote = 0;
					while( yytext[rd_idx] ){
						if( yytext[rd_idx] == '\"' ){
							if( quote )
								strContent[wrt_idx++] = '\"';
							quote = ~quote;
						}
						else
							strContent[wrt_idx++] = yytext[rd_idx];
						rd_idx++;
					}
					strContent[wrt_idx] = '\0';
					printf("<%s: %s>\n", "string", strContent);
				}
				return STRING
			}

"//&"[A-Z][+-][^\n]*		{ /* pseudo comment */
				  LIST;
				  setPseudoComment( yytext );
				}
"//"				{ /* C++ stype comment */
				  LIST;
				  BEGIN COMMENT_CPP;
				}

<COMMENT_CPP>[^\n]+		{
				  LIST;
				}

<COMMENT_CPP>"\n"		{
				  LIST;
				  if( Opt_S )
				  	printf("%d: %s",  linenum,  buf);
				  linenum++;
				  buf[0] = '\0';
				  BEGIN INITIAL;
				}

"/*"				{ /* C-style comment */
				  LIST;
				  BEGIN COMMENT;
				}
<COMMENT>"*/"			{
				  LIST;
				  BEGIN INITIAL;
				}
<COMMENT>"\n"			{
				  LIST;
				  if  (Opt_S)
				  	printf("%d: %s",  linenum,  buf);
				  linenum++;
				  buf[0] = '\0';
				}
<COMMENT>.			{
				  LIST;
				}

{whitespace}			{
				  LIST;
				}

\n 				{
				  LIST;
				  if  (Opt_S)
				  	printf("%d: %s",  linenum,  buf);
				  linenum++;
				  buf[0] = '\0';
		   		}

.				{
				  /* error */
				  printf("error at line %d: bad character \"%s\"\n", linenum, yytext );
				  exit(-1);
				}

%%

void setPseudoComment( const char *text )
{
	/* format : //&[A-Z][+-] */
	switch( text[3] ) {
	 case 'S':
		if( text[4] == '+' )
			Opt_S = 1;
		else if( text[4] == '-' )
			Opt_S = 0;
		break;
	 case 'T':
		if( text[4] == '+' )
			Opt_T = 1;
		else if( text[4] == '-' )
			Opt_T = 0;
	 	break;
	 default:
	 	break;
	}

}
