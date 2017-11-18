/**
 * Introduction to Compiler Design by Prof. Yi Ping You
 * Project 1 Sample
 */

%{
#include "y.tab.h"
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

<INITIAL>","				{ tokenChar(','); return COMMA; }
<INITIAL>";"				{ tokenChar(';'); return SEMICOLON; }
<INITIAL>":"				{ tokenChar(':'); return COLON; }
<INITIAL>"("				{ tokenChar('('); return BRACELEFT; }
<INITIAL>")"				{ tokenChar(')'); return BRACERIGHT; }
<INITIAL>"]"				{ tokenChar(']'); return BRACKETLEFT; }
<INITIAL>"["				{ tokenChar('['); return BRACKETRIGHT; }

<INITIAL>"+"				{ tokenChar('+'); return PLUS; }
<INITIAL>"-"				{ tokenChar('-'); return MINUS; }
<INITIAL>"*"				{ tokenChar('*'); return MULTIPLY; }
<INITIAL>"/"				{ tokenChar('/'); return DIVIDE; }
<INITIAL>"mod"			{ token(mod); return MOD; }
<INITIAL>":="			{ token(:=); return ASSIGN; }
<INITIAL>"<"				{ tokenChar('<'); return LESS; }
<INITIAL>"<="			{ token(<=); return LESSEQUAL; }
<INITIAL>"<>"			{ token(<>); return LESSGREATER; }
<INITIAL>">="			{ token(>=); return GREATEREQUAL; }
<INITIAL>">"				{ tokenChar('>'); return GREATER; }
<INITIAL>"="				{ tokenChar('='); return EQUAL; }
<INITIAL>"and"			{ token(and); return AND; }
<INITIAL>"or"			{ token(or); return OR; }
<INITIAL>"not"			{ token(not); return NOT; }

<INITIAL>"array"			{ token(KWarray); return KWARRAY; }
<INITIAL>"begin"			{ token(KWbegin); return KWBEGIN; }
<INITIAL>"boolean"		{ token(KWboolean); return KWBOOLEAN; }
<INITIAL>"def"			{ token(KWdef); return KWDEF; }
<INITIAL>"do"			{ token(KWdo); return KWDO; }
<INITIAL>"else"			{ token(KWelse); return KWELSE; }
<INITIAL>"end"			{ token(KWend); return KWEND; }
<INITIAL>"false"			{ token(KWfalse); return KWFALSE; }
<INITIAL>"for"			{ token(KWfor); return KWFOR; }
<INITIAL>"integer"		{ token(KWinteger); return KWINTEGER; }
<INITIAL>"if"			{ token(KWif); return KWIF; }
<INITIAL>"of"			{ token(KWof); return KWOF; }
<INITIAL>"print"			{ token(KWprint); return KWPRINT; }
<INITIAL>"read"			{ token(KWread); return KWREAD; }
<INITIAL>"real"			{ token(KWreal); return KWREAL; }
<INITIAL>"string"		{ token(KWstring); return KWSTRING; }
<INITIAL>"then"			{ token(KWthen); return KWTHEN; }
<INITIAL>"to"			{ token(KWto); return KWTO; }
<INITIAL>"true"			{ token(KWtrue); return KWTRUE; }
<INITIAL>"return"		{ token(KWreturn); return KWRETURN; }
<INITIAL>"var"			{ token(KWvar); return KWVAR; }
<INITIAL>"while"			{ token(KWwhile); return KWWHILE; }

<INITIAL>{octal} { tokenOctInteger("oct_integer",yytext); return OCTAL; }
<INITIAL>{identifier}			{ tokenString("id",yytext); return IDENT; }
<INITIAL>{integer}			{ tokenInteger("integer",atoi(yytext)); return INTEGER; }
<INITIAL>{float}				{ tokenFloat("float",yytext); return REAL; }
<INITIAL>{scientific}			{ tokenScientific("scientific", yytext); return REAL; }

<STRING>\"((\"\")|[^\"\n])*\"	{
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
				return STRING;
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
