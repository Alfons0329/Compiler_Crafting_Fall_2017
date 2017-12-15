/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20140715

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "parser.y"
/**
 * Introduction to Compiler Design by Prof. Yi Ping You
 * Project 2 YACC sample
 */
#include <bits/stdc++.h>
#include "symboltable.h"
#define pb push_back
#define BUF_SIZE 50
extern FILE *yyin;		/* declared by lex */
extern char *yytext;	/* declared by lex */
extern char *buf;	/* declared in lex.l */
extern int yylex(void);
extern int Opt_D; /* declared in lex.l */
extern int linenum;	/* declared in lex.l */
int yyerror(char* );
/*some global variables that needed in the parsing procedure*/
char arr_buf[BUF_SIZE];
char reverse_arr_buf[BUF_SIZE];
string const_buf;
string const_type_str;
vector<string> id_list_buf; /**/
vector<string> funct_attri_buf;
#line 26 "parser.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union
{
    char* parsed_string;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 56 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define ARRAY 257
#define BEG 258
#define BOOLEAN 259
#define DEF 260
#define DO 261
#define ELSE 262
#define END 263
#define FALSE 264
#define FOR 265
#define INTEGER 266
#define IF 267
#define OF 268
#define PRINT 269
#define READ 270
#define REAL 271
#define RETURN 272
#define STRING 273
#define THEN 274
#define TO 275
#define TRUE 276
#define VAR 277
#define WHILE 278
#define ID 279
#define OCTAL_CONST 280
#define INT_CONST 281
#define FLOAT_CONST 282
#define SCIENTIFIC 283
#define STR_CONST 284
#define OP_ADD 285
#define OP_SUB 286
#define OP_MUL 287
#define OP_DIV 288
#define OP_MOD 289
#define OP_ASSIGN 290
#define OP_EQ 291
#define OP_NE 292
#define OP_GT 293
#define OP_LT 294
#define OP_GE 295
#define OP_LE 296
#define OP_AND 297
#define OP_OR 298
#define OP_NOT 299
#define MK_COMMA 300
#define MK_COLON 301
#define MK_SEMICOLON 302
#define MK_LPAREN 303
#define MK_RPAREN 304
#define MK_LB 305
#define MK_RB 306
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
   11,   13,    0,   12,   14,   14,   17,   17,   18,    1,
    1,   19,    1,    4,    4,    5,    5,    5,    5,    5,
    5,    5,    5,    5,   15,   15,   20,   20,   21,   23,
   24,   25,    2,   22,   22,   26,   26,    6,    7,    7,
    3,    3,    8,    8,    9,    9,    9,    9,   27,   10,
   28,   28,   28,   28,   28,   28,   28,   35,   37,   16,
   36,   36,   38,   38,   29,   29,   29,   34,   30,   30,
   31,   42,   32,   33,   41,   41,   43,   43,   40,   40,
   44,   44,   45,   45,   46,   46,   48,   48,   48,   48,
   48,   48,   47,   47,   49,   49,   50,   50,   51,   51,
   51,   52,   52,   52,   52,   52,   52,   52,   39,   39,
   53,
};
static const YYINT yylen[] = {                            2,
    0,    0,    7,    3,    1,    0,    2,    1,    0,    6,
    5,    0,    6,    1,    1,    1,    2,    1,    2,    1,
    2,    1,    1,    1,    1,    0,    2,    1,    0,    0,
    0,    0,   13,    1,    0,    3,    1,    3,    3,    1,
    2,    0,    1,    1,    1,    1,    1,    1,    0,    7,
    1,    1,    1,    1,    1,    1,    1,    0,    0,    6,
    1,    0,    2,    1,    4,    3,    3,    5,    8,    6,
    6,    0,   11,    3,    1,    0,    3,    1,    3,    1,
    3,    1,    2,    1,    3,    1,    1,    1,    1,    1,
    1,    1,    3,    1,    1,    1,    3,    1,    1,    1,
    1,    1,    2,    3,    4,    4,    5,    1,    1,    2,
    3,
};
static const YYINT yydefred[] = {                         0,
    1,    0,    0,    2,    0,    0,    8,    0,    0,    0,
   40,    0,    0,   29,   28,    0,    0,    7,    0,    0,
    3,    0,   58,    4,   27,   39,   49,   47,   24,   45,
   46,   48,   23,   15,   14,   18,   20,   22,    0,   16,
   12,    9,    0,    0,    0,    0,   19,   21,   17,    0,
    0,   11,   37,    0,    0,    0,    0,    0,   13,   10,
    0,   30,    0,    0,    0,    0,    0,    0,    0,    0,
   51,   64,   52,   53,   54,   55,   56,   57,   59,    0,
    0,    0,   38,   43,   44,    0,   36,   72,    0,    0,
    0,    0,  108,    0,    0,    0,   82,   84,    0,    0,
   98,    0,    0,    0,    0,    0,    0,   63,    0,    0,
  110,    0,    0,    0,    0,    0,    0,    0,    0,   83,
    0,    0,    0,    0,   95,   96,   89,   92,   91,   87,
   90,   88,    0,    0,   99,  100,  101,    0,   66,   67,
   74,    0,    0,    0,    0,   60,    0,    0,    0,   41,
   31,    0,    0,    0,    0,  104,    0,    0,   81,    0,
    0,   97,    0,    0,    0,   65,  111,   50,    0,    0,
  106,    0,  105,    0,    0,    0,   68,    0,    0,    0,
  107,    0,   70,   71,   32,    0,    0,    0,    0,   69,
   33,    0,    0,   73,
};
static const YYINT yydgoto[] = {                          2,
    7,   15,  114,   40,   93,   53,   54,   83,   84,   85,
    3,    8,    5,    9,   16,   71,   10,   51,   50,   17,
   22,   55,   86,  169,  188,   56,   46,   72,   73,   74,
   75,   76,   77,   78,   45,   79,  107,   80,   94,  143,
  144,  115,  145,   96,   97,   98,   99,  133,  134,  100,
  138,  101,  111,
};
static const YYINT yysindex[] = {                      -265,
    0,    0, -279,    0, -251, -239,    0, -185, -161, -251,
    0, -258, -154,    0,    0, -156, -161,    0, -141,   47,
    0, -163,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0, -136,    0,
    0,    0, -150, -239, -251, -221,    0,    0,    0, -145,
 -128,    0,    0, -196, -121, -126,   89, -127,    0,    0,
 -158,    0, -239,  -94,    2,    2,    2,    2,    2, -116,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   89,
 -269, -221,    0,    0,    0, -110,    0,    0, -109, -264,
    2,    2,    0, -112, -243,  -88,    0,    0,   78, -177,
    0, -245, -244, -218, -248,    2,  -60,    0,    2,    2,
    0,  -57, -158,  -90,  -77,    2,  -89,    2, -112,    0,
 -271,   89,    2,    2,    0,    0,    0,    0,    0,    0,
    0,    0,   16,   16,    0,    0,    0,   16,    0,    0,
    0,   89,  -83,  -86,  -70,    0, -213, -274, -158,    0,
    0, -221,  -68,    2, -270,    0, -146,  -88,    0, -135,
 -177,    0,  -25,  -81,    2,    0,    0,    0, -156,  -36,
    0,  -64,    0,   89,  -26,  -19,    0,  -83,  -18, -221,
    0,  -14,    0,    0,    0,  -10,  -13,  -22,   89,    0,
    0,   -4,   -8,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0, -238,    0,    0,    0,    3, -172,
    0,    0,    0,    0,    0,    0,    5,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  -39,   74,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  -37,    6,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0, -268,
    0,    0,    0,    0,    0,    0,    0,    0,    0, -108,
    0,    0,    0,    0,    0,  -34,    0,    0, -223,    0,
    0,    0,    0, -165,    0, -118,    0,    0,  -54,  -96,
    0,    0,    0,    0,    0,  -32,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  -32, -223,    0, -125,    0,
    0, -104,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    6, -212,    0,  -30,    0,    0,    0,    0,    0,
    0,    0,    0,  -32,    0,    0,    0,  -27,    0,  -42,
  -69,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    6,    0,    0,    0, -210,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    6,    0,
    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
  260,  259,    0,  -38,  267,  226,  284, -103,  271,  273,
    0,    0,    0,  249,    0,  -16,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  223,    0,    0,
    0,    0,    0,    0,    0, -113,    0,    0,  -55,  -62,
 -105,    0,    0,  184,  -79,    0,  175,    0,    0,  176,
    0,  171,    0,
};
#define YYTABLESIZE 374
static const YYINT yytable[] = {                         24,
   49,   81,   95,  102,  103,  104,  105,   58,  157,  150,
  153,  120,  142,    1,  117,   34,   35,   47,   48,    6,
  109,  109,    4,  123,   81,    6,  123,  123,  163,  121,
  122,  167,  156,  173,  119,  110,  109,  109,  118,   11,
    6,   19,   20,  112,  159,  168,  147,  148,  172,  123,
  109,   49,  123,  123,  123,  155,  139,  140,   34,   35,
  182,  109,  109,  109,  109,  109,   81,  109,  109,  109,
  109,  109,  109,  109,  109,  192,  109,   13,  109,  123,
  109,  109,  109,  141,  123,    5,   81,   78,  166,   77,
    5,   78,    5,   77,    5,  102,    5,    5,   27,    5,
   28,   23,  178,   19,   61,    5,    5,   30,  102,  135,
  136,  137,   31,  170,   32,  174,  175,   14,   81,  102,
  102,  102,  102,  102,   21,  102,  102,  102,  102,  102,
  102,  102,  102,   81,  102,  103,  102,   26,  102,   44,
  102,  186,   80,   34,   35,   47,   48,   82,  103,  125,
  126,   52,  179,   61,   61,   80,   59,   62,   62,  103,
  103,  103,  103,  103,   94,  103,  103,  103,  103,  103,
  103,  103,  103,   60,  103,   63,  103,   94,  103,   80,
  103,   80,   62,   80,   88,   80,  106,   80,   94,   94,
  113,   93,  110,  116,   94,   94,   94,   94,   94,   94,
   94,   94,  146,   94,   93,   94,   86,   94,  124,   94,
  149,  151,  152,  154,  123,   93,   93,  164,   85,   86,
  177,   93,   93,   93,   93,   93,   93,   93,   93,  165,
   93,   85,   93,   79,   93,  171,   93,  176,  180,  181,
  183,  184,   86,   86,  185,   86,   79,   86,  187,   86,
  189,   86,  194,  190,   85,   85,  191,   85,  193,   85,
   26,   85,   25,   85,   35,   29,   34,   42,   62,   18,
   79,   76,   79,   75,   79,   25,   79,   33,   79,   29,
   89,   34,   35,   36,   37,   38,   41,   90,   87,   12,
   42,   33,   43,   57,   89,   34,   35,   36,   37,   38,
   91,   90,  108,   27,   92,   28,  158,  160,  162,  161,
   29,    0,   30,    0,    0,    0,    0,   31,   92,   32,
    0,    0,   33,    0,    0,    0,   34,   35,   36,   37,
   38,    6,   39,    0,    0,    0,    6,    0,    6,    0,
    6,    0,    6,    6,    0,    6,   23,    0,    0,    0,
    0,    6,    6,   64,    0,   65,    0,   66,   67,    0,
   68,    0,  125,  126,    0,    0,   69,   70,  127,  128,
  129,  130,  131,  132,
};
static const YYINT yycheck[] = {                         16,
   39,   57,   65,   66,   67,   68,   69,   46,  122,  113,
  116,   91,  261,  279,  279,  280,  281,  282,  283,  258,
  290,  290,  302,  298,   80,  277,  298,  298,  142,   92,
  274,  306,  304,  304,   90,  305,  305,  261,  303,  279,
  279,  300,  301,   82,  124,  149,  109,  110,  154,  298,
  274,   90,  298,  298,  298,  118,  302,  302,  280,  281,
  174,  285,  286,  287,  288,  289,  122,  291,  292,  293,
  294,  295,  296,  297,  298,  189,  300,  263,  302,  298,
  304,  305,  306,  302,  298,  258,  142,  300,  302,  300,
  263,  304,  265,  304,  267,  261,  269,  270,  257,  272,
  259,  258,  165,  300,  301,  278,  279,  266,  274,  287,
  288,  289,  271,  152,  273,  262,  263,  279,  174,  285,
  286,  287,  288,  289,  279,  291,  292,  293,  294,  295,
  296,  297,  298,  189,  300,  261,  302,  279,  304,  303,
  306,  180,  261,  280,  281,  282,  283,  275,  274,  285,
  286,  302,  169,  262,  263,  274,  302,  262,  263,  285,
  286,  287,  288,  289,  261,  291,  292,  293,  294,  295,
  296,  297,  298,  302,  300,  302,  302,  274,  304,  298,
  306,  300,  304,  302,  279,  304,  303,  306,  285,  286,
  301,  261,  305,  303,  291,  292,  293,  294,  295,  296,
  297,  298,  263,  300,  274,  302,  261,  304,  297,  306,
  268,  302,  290,  303,  298,  285,  286,  304,  261,  274,
  302,  291,  292,  293,  294,  295,  296,  297,  298,  300,
  300,  274,  302,  261,  304,  304,  306,  263,  275,  304,
  267,  261,  297,  298,  263,  300,  274,  302,  263,  304,
  261,  306,  261,  267,  297,  298,  279,  300,  263,  302,
  258,  304,  258,  306,  304,  264,  304,  302,  263,   10,
  298,  304,  300,  304,  302,   17,  304,  276,  306,  264,
  279,  280,  281,  282,  283,  284,   20,  286,   63,    6,
   20,  276,   20,   45,  279,  280,  281,  282,  283,  284,
  299,  286,   80,  257,  303,  259,  123,  133,  138,  134,
  264,   -1,  266,   -1,   -1,   -1,   -1,  271,  303,  273,
   -1,   -1,  276,   -1,   -1,   -1,  280,  281,  282,  283,
  284,  258,  286,   -1,   -1,   -1,  263,   -1,  265,   -1,
  267,   -1,  269,  270,   -1,  272,  258,   -1,   -1,   -1,
   -1,  278,  279,  265,   -1,  267,   -1,  269,  270,   -1,
  272,   -1,  285,  286,   -1,   -1,  278,  279,  291,  292,
  293,  294,  295,  296,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 1
#endif
#define YYMAXTOKEN 306
#define YYUNDFTOKEN 362
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"ARRAY","BEG","BOOLEAN","DEF",
"DO","ELSE","END","FALSE","FOR","INTEGER","IF","OF","PRINT","READ","REAL",
"RETURN","STRING","THEN","TO","TRUE","VAR","WHILE","ID","OCTAL_CONST",
"INT_CONST","FLOAT_CONST","SCIENTIFIC","STR_CONST","OP_ADD","OP_SUB","OP_MUL",
"OP_DIV","OP_MOD","OP_ASSIGN","OP_EQ","OP_NE","OP_GT","OP_LT","OP_GE","OP_LE",
"OP_AND","OP_OR","OP_NOT","MK_COMMA","MK_COLON","MK_SEMICOLON","MK_LPAREN",
"MK_RPAREN","MK_LB","MK_RB",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : program",
"$$1 :",
"$$2 :",
"program : ID $$1 MK_SEMICOLON $$2 program_body END ID",
"program_body : opt_decl_list opt_func_decl_list compound_stmt",
"opt_decl_list : decl_list",
"opt_decl_list :",
"decl_list : decl_list decl",
"decl_list : decl",
"$$3 :",
"decl : VAR id_list MK_COLON scalar_type $$3 MK_SEMICOLON",
"decl : VAR id_list MK_COLON array_type MK_SEMICOLON",
"$$4 :",
"decl : VAR id_list MK_COLON literal_const $$4 MK_SEMICOLON",
"int_const : INT_CONST",
"int_const : OCTAL_CONST",
"literal_const : int_const",
"literal_const : OP_SUB int_const",
"literal_const : FLOAT_CONST",
"literal_const : OP_SUB FLOAT_CONST",
"literal_const : SCIENTIFIC",
"literal_const : OP_SUB SCIENTIFIC",
"literal_const : STR_CONST",
"literal_const : TRUE",
"literal_const : FALSE",
"opt_func_decl_list : func_decl_list",
"opt_func_decl_list :",
"func_decl_list : func_decl_list func_decl",
"func_decl_list : func_decl",
"$$5 :",
"$$6 :",
"$$7 :",
"$$8 :",
"func_decl : ID $$5 MK_LPAREN opt_param_list MK_RPAREN $$6 opt_type MK_SEMICOLON $$7 compound_stmt END $$8 ID",
"opt_param_list : param_list",
"opt_param_list :",
"param_list : param_list MK_SEMICOLON param",
"param_list : param",
"param : id_list MK_COLON type",
"id_list : id_list MK_COMMA ID",
"id_list : ID",
"opt_type : MK_COLON type",
"opt_type :",
"type : scalar_type",
"type : array_type",
"scalar_type : INTEGER",
"scalar_type : REAL",
"scalar_type : BOOLEAN",
"scalar_type : STRING",
"$$9 :",
"array_type : ARRAY $$9 int_const TO int_const OF type",
"stmt : compound_stmt",
"stmt : simple_stmt",
"stmt : cond_stmt",
"stmt : while_stmt",
"stmt : for_stmt",
"stmt : return_stmt",
"stmt : proc_call_stmt",
"$$10 :",
"$$11 :",
"compound_stmt : BEG $$10 opt_decl_list opt_stmt_list $$11 END",
"opt_stmt_list : stmt_list",
"opt_stmt_list :",
"stmt_list : stmt_list stmt",
"stmt_list : stmt",
"simple_stmt : var_ref OP_ASSIGN boolean_expr MK_SEMICOLON",
"simple_stmt : PRINT boolean_expr MK_SEMICOLON",
"simple_stmt : READ boolean_expr MK_SEMICOLON",
"proc_call_stmt : ID MK_LPAREN opt_boolean_expr_list MK_RPAREN MK_SEMICOLON",
"cond_stmt : IF boolean_expr THEN opt_stmt_list ELSE opt_stmt_list END IF",
"cond_stmt : IF boolean_expr THEN opt_stmt_list END IF",
"while_stmt : WHILE boolean_expr DO opt_stmt_list END DO",
"$$12 :",
"for_stmt : FOR ID $$12 OP_ASSIGN int_const TO int_const DO opt_stmt_list END DO",
"return_stmt : RETURN boolean_expr MK_SEMICOLON",
"opt_boolean_expr_list : boolean_expr_list",
"opt_boolean_expr_list :",
"boolean_expr_list : boolean_expr_list MK_COMMA boolean_expr",
"boolean_expr_list : boolean_expr",
"boolean_expr : boolean_expr OP_OR boolean_term",
"boolean_expr : boolean_term",
"boolean_term : boolean_term OP_AND boolean_factor",
"boolean_term : boolean_factor",
"boolean_factor : OP_NOT boolean_factor",
"boolean_factor : relop_expr",
"relop_expr : expr rel_op expr",
"relop_expr : expr",
"rel_op : OP_LT",
"rel_op : OP_LE",
"rel_op : OP_EQ",
"rel_op : OP_GE",
"rel_op : OP_GT",
"rel_op : OP_NE",
"expr : expr add_op term",
"expr : term",
"add_op : OP_ADD",
"add_op : OP_SUB",
"term : term mul_op factor",
"term : factor",
"mul_op : OP_MUL",
"mul_op : OP_DIV",
"mul_op : OP_MOD",
"factor : var_ref",
"factor : OP_SUB var_ref",
"factor : MK_LPAREN boolean_expr MK_RPAREN",
"factor : OP_SUB MK_LPAREN boolean_expr MK_RPAREN",
"factor : ID MK_LPAREN opt_boolean_expr_list MK_RPAREN",
"factor : OP_SUB ID MK_LPAREN opt_boolean_expr_list MK_RPAREN",
"factor : literal_const",
"var_ref : ID",
"var_ref : var_ref dim",
"dim : MK_LB boolean_expr MK_RB",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 417 "parser.y"

int yyerror( char *msg )
{
	(void) msg;
	fprintf( stderr, "\n|--------------------------------------------------------------------------\n" );
	fprintf( stderr, "| Error found in Line #%d: %s\n", linenum, buf );
	fprintf( stderr, "|\n" );
	fprintf( stderr, "| Unmatched token: %s\n", yytext );
	fprintf( stderr, "|--------------------------------------------------------------------------\n" );
	exit(-1);
}
#line 519 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    YYERROR_CALL("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 41 "parser.y"
	{
					symbol_table_init();
					id_list_buf.pb(yytext);
					funct_attri_buf.resize(0);
				}
break;
case 2:
#line 47 "parser.y"
	{
					inserting_symbol_table(id_list_buf,"program","void",funct_attri_buf);
					id_list_buf.clear();
				}
break;
case 3:
#line 53 "parser.y"
	{
					error_detection();
					dumpsymbol();
					pop_symbol_table();
			  	}
break;
case 9:
#line 73 "parser.y"
	{
				funct_attri_buf.resize(0); /*normal variable does not have attribute, so just let the size be zero*/
				inserting_symbol_table(id_list_buf,"variable",yystack.l_mark[0].parsed_string,funct_attri_buf);
				id_list_buf.clear();
				error_detection();
			}
break;
case 11:
#line 81 "parser.y"
	{
				funct_attri_buf.resize(0); /*normal variable does not have attribute, so just let the size be zero*/
				array_dimension_parser();
				inserting_symbol_table(id_list_buf,"variable",reverse_arr_buf,funct_attri_buf);
				id_list_buf.clear();
				error_detection();
				memset(arr_buf,0,sizeof(arr_buf));/*update it for next segment*/
				is_arr=0;
			}
break;
case 12:
#line 91 "parser.y"
	{
				funct_attri_buf.pb(const_buf); /*normal variable does not have attribute, so just let the size be zero*/
				inserting_symbol_table(id_list_buf,"constant",const_type_str,funct_attri_buf);
				id_list_buf.clear();
				error_detection();
			}
break;
case 14:
#line 100 "parser.y"
	{yyval.parsed_string=yytext; const_type=1;}
break;
case 15:
#line 101 "parser.y"
	{yyval.parsed_string=yytext; const_type=9;}
break;
case 16:
#line 104 "parser.y"
	{yyval.parsed_string=yytext; const_type=(const_type==1)?1:9; const_type_str="integer ";parse_constant();}
break;
case 17:
#line 105 "parser.y"
	{yyval.parsed_string=yytext; const_type=(const_type==1)?2:10; const_type_str="integer ";parse_constant();}
break;
case 18:
#line 106 "parser.y"
	{yyval.parsed_string=yytext; const_type=3; const_type_str="real ";parse_constant();}
break;
case 19:
#line 107 "parser.y"
	{yyval.parsed_string=yytext; const_type=4; const_type_str="real ";parse_constant();}
break;
case 20:
#line 108 "parser.y"
	{yyval.parsed_string=yytext; const_type=5; const_type_str="real ";parse_constant();}
break;
case 21:
#line 109 "parser.y"
	{yyval.parsed_string=yytext; const_type=6; const_type_str="real ";parse_constant();}
break;
case 22:
#line 110 "parser.y"
	{yyval.parsed_string=yytext; const_type=7; const_type_str="string ";parse_constant();}
break;
case 23:
#line 111 "parser.y"
	{yyval.parsed_string=yytext; const_type=8; const_type_str="boolean ";parse_constant();}
break;
case 24:
#line 112 "parser.y"
	{yyval.parsed_string=yytext; const_type=8; const_type_str="boolean ";parse_constant();}
break;
case 29:
#line 124 "parser.y"
	{
					id_list_buf.pb(yytext);
                    error_detection();
					scope_depth++;
				}
break;
case 30:
#line 130 "parser.y"
	{
					is_funct=1;
					scope_depth--;
				}
break;
case 31:
#line 135 "parser.y"
	{
					if(is_arr)
					{
						array_dimension_parser();
						/*here we push_back the funct_attri_buf inorder to match the attributes of function*/
						funct_attri_buf.resize(0); /*primitive initialization*/
						for(int i=0;i<mysymbol_table[1].size();i++) /*search the parameter for function attribute*/
						{
							if((mysymbol_table[1][i].kind=="parameter")&&(mysymbol_table[1][i].name[0]!=0))
							{
								funct_attri_buf.pb(mysymbol_table[1][i].type+",");
							}
						}
						inserting_symbol_table(id_list_buf,"function",reverse_arr_buf,funct_attri_buf);
					}
					else
					{
						/*here we push_back the funct_attri_buf inorder to match the attributes of function*/
						funct_attri_buf.resize(0); /*primitive initialization*/
						for(int i=0;i<mysymbol_table[1].size();i++) /*search the parameter for function attribute*/
						{
							if((mysymbol_table[1][i].kind=="parameter")&&(mysymbol_table[1][i].name[0]!=0))
							{
								funct_attri_buf.pb(mysymbol_table[1][i].type+",");
							}
						}
						inserting_symbol_table(id_list_buf,"function",yystack.l_mark[-1].parsed_string,funct_attri_buf);
					}
					is_arr=0;
				}
break;
case 32:
#line 167 "parser.y"
	{
					is_funct=0;
				}
break;
case 38:
#line 182 "parser.y"
	{
				funct_attri_buf.resize(0);
				if(is_arr)
				{
					array_dimension_parser();
					if(error_detection()==0)
					{
						funct_attri_buf.resize(0);
						array_dimension_parser();
						inserting_symbol_table(id_list_buf,"parameter",reverse_arr_buf,funct_attri_buf);
						id_list_buf.clear();
					}
				}
				else
				{
					if(error_detection()==0)
					{
						inserting_symbol_table(id_list_buf,"parameter",yystack.l_mark[0].parsed_string,funct_attri_buf);
						id_list_buf.clear();
					}
				}
				is_arr=0;
			}
break;
case 39:
#line 208 "parser.y"
	{
				/* tmpstr.clear(); */
				/* strcpy(tmpstr,yytext); */
				id_list_buf.pb(yytext);
				/* $$=yytext; */
			}
break;
case 40:
#line 215 "parser.y"
	{
				/* tmpstr.clear(); */
				/* strcpy(tmpstr,yytext); */
				id_list_buf.pb(yytext);
				/* $$=yytext; */
			}
break;
case 41:
#line 223 "parser.y"
	{yyval.parsed_string=yystack.l_mark[0].parsed_string;}
break;
case 43:
#line 227 "parser.y"
	{yyval.parsed_string=yystack.l_mark[0].parsed_string;}
break;
case 44:
#line 228 "parser.y"
	{yyval.parsed_string=yystack.l_mark[0].parsed_string;}
break;
case 45:
#line 232 "parser.y"
	{
				yyval.parsed_string="integer ";
			}
break;
case 46:
#line 236 "parser.y"
	{
				yyval.parsed_string="real ";
			}
break;
case 47:
#line 240 "parser.y"
	{
				yyval.parsed_string="boolean ";
			}
break;
case 48:
#line 244 "parser.y"
	{
				yyval.parsed_string="string ";
			}
break;
case 49:
#line 250 "parser.y"
	{
				is_arr=1;
			}
break;
case 50:
#line 254 "parser.y"
	{
				int delta=atol(yystack.l_mark[-2].parsed_string)-atol(yystack.l_mark[-4].parsed_string)+1;
				char tmp[10];
				sprintf(tmp,"%d",delta);
				strcat(arr_buf,tmp);
				strcat(arr_buf,",");
			}
break;
case 58:
#line 273 "parser.y"
	{
					if(scope_depth==0&&is_funct)
					{
						scope_depth++;
					}
					else
					{
						scope_depth++;
					}
				}
break;
case 59:
#line 285 "parser.y"
	{
					/*printf("23->");}*/
					/*printf("compound_stmt end\n");*/
					/*printf("Scope depth %d, pre_sub_entry_cnt %d sub_entry_cnt %d \n",scope_depth,pre_sub_entry_cnt,sub_entry_cnt);*/
					if(is_funct&&scope_depth>1) /*prevernt double popping*/
					{
						dumpsymbol();
						pop_symbol_table();
					}
					else if(!is_loop)/*if(!is_funct) *//*normal like*/
					{
						dumpsymbol();
						pop_symbol_table();
					}
				}
break;
case 72:
#line 334 "parser.y"
	{
					inserting_iter_table(yytext,scope_depth+1);
					error_detection();
					/*dumpiterator();*/
					is_loop=1;
				}
break;
case 73:
#line 343 "parser.y"
	{
					is_loop=0;
				}
break;
#line 1014 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                yys = yyname[YYTRANSLATE(yychar)];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
