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
/*C++ working*/
extern "C" int yylex(void);
extern FILE *yyin;		/* declared by lex */
extern char *yytext;	/* declared by lex */
extern char *buf;	/* declared in lex.l */
extern int Opt_D; /* declared in lex.l */
extern int linenum;	/* declared in lex.l */
int yyerror(const char*);

/*some global variables that needed in the parsing procedure*/
char arr_buf[BUF_SIZE];
char reverse_arr_buf[BUF_SIZE];
string const_buf;
string const_type_str;
string funct_name;
string array_type_str;
vector<string> id_list_buf; /**/
vector<string> funct_attri_buf;
/*global variables for HW4*/
vector<string> assign_check_buf;
#line 32 "parser.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union
{
    char* str;
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 62 "y.tab.c"

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
   13,   15,    0,   14,   16,   16,   19,   19,   20,    1,
    1,   21,    1,    4,    4,    5,    5,    5,    5,    5,
    5,    5,    5,    5,   17,   17,   22,   22,   23,   25,
   26,   27,    2,   24,   24,   28,   28,    6,    7,    7,
    3,    3,    8,    8,    9,    9,    9,    9,   29,   10,
   30,   30,   30,   30,   30,   30,   30,   37,   39,   18,
   38,   38,   40,   40,   41,   31,   31,   31,   36,   32,
   32,   33,   44,   34,   35,   43,   43,   45,   45,   42,
   42,   46,   46,   47,   47,   48,   48,   50,   50,   50,
   50,   50,   50,   49,   49,   51,   51,   52,   52,   53,
   53,   53,   12,   12,   12,   12,   12,   12,   12,   11,
   11,   54,
};
static const YYINT yylen[] = {                            2,
    0,    0,    7,    3,    1,    0,    2,    1,    0,    6,
    5,    0,    6,    1,    1,    1,    2,    1,    2,    1,
    2,    1,    1,    1,    1,    0,    2,    1,    0,    0,
    0,    0,   13,    1,    0,    3,    1,    3,    3,    1,
    2,    0,    1,    1,    1,    1,    1,    1,    0,    7,
    1,    1,    1,    1,    1,    1,    1,    0,    0,    6,
    1,    0,    2,    1,    0,    5,    3,    3,    5,    8,
    6,    6,    0,   11,    3,    1,    0,    3,    1,    3,
    1,    3,    1,    2,    1,    3,    1,    1,    1,    1,
    1,    1,    1,    3,    1,    1,    1,    3,    1,    1,
    1,    1,    1,    2,    3,    4,    4,    5,    1,    1,
    2,    3,
};
static const YYINT yydefred[] = {                         0,
    1,    0,    0,    2,    0,    0,    8,    0,    0,    0,
   40,    0,    0,   29,   28,    0,    0,    7,    0,    0,
    3,    0,   58,    4,   27,   39,   49,   47,   24,   45,
   46,   48,   23,   15,   14,   18,   20,   22,    0,   16,
   12,    9,    0,    0,    0,    0,   19,   21,   17,    0,
    0,   11,   37,    0,    0,    0,    0,    0,   13,   10,
    0,   30,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   51,   64,   52,   53,   54,   55,   56,   57,   59,
    0,    0,   38,   43,   44,    0,   36,   73,    0,    0,
    0,    0,  109,    0,   99,    0,    0,   83,   85,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  111,    0,
   63,    0,    0,    0,    0,    0,    0,    0,    0,   84,
    0,    0,    0,    0,   96,   97,   90,   93,   92,   88,
   91,   89,    0,    0,  100,  101,  102,    0,   67,   68,
   75,    0,    0,    0,    0,    0,    0,   60,    0,   41,
   31,    0,    0,    0,    0,  105,    0,    0,   82,    0,
    0,   98,    0,    0,    0,  112,    0,   50,    0,    0,
  107,    0,  106,    0,    0,    0,   69,    0,   66,    0,
    0,  108,    0,   71,   72,   32,    0,    0,    0,    0,
   70,   33,    0,    0,   74,
};
static const YYINT yydgoto[] = {                          2,
    7,   15,  114,   40,   93,   53,   54,   83,   84,   85,
   94,   95,    3,    8,    5,    9,   16,   72,   10,   51,
   50,   17,   22,   55,   86,  169,  189,   56,   46,   73,
   74,   75,   76,   77,   78,   79,   45,   80,  110,   81,
  108,  143,  144,  115,  145,   97,   98,   99,  100,  133,
  134,  101,  138,  109,
};
static const YYINT yysindex[] = {                      -262,
    0,    0, -280,    0, -257, -211,    0, -181, -195, -257,
    0, -269, -174,    0,    0, -164, -195,    0, -162,   46,
    0, -188,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0, -136,    0,
    0,    0, -176, -211, -257, -168,    0,    0,    0, -166,
 -131,    0,    0, -172, -197, -121,   88, -154,    0,    0,
 -185,    0, -211, -149,    1,    1,    1,    1,    1, -120,
 -123,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   88, -168,    0,    0,    0, -117,    0,    0, -118, -103,
    1,    1,    0, -123,    0, -260,  -91,    0,    0,   77,
 -247, -259, -239, -229, -250,    1,    1,  -88,    0,  -53,
    0,  -60, -185,  -93,  -79,    1,  -90,    1, -123,    0,
 -279,   88,    1,    1,    0,    0,    0,    0,    0,    0,
    0,    0,   15,   15,    0,    0,    0,   15,    0,    0,
    0,   88,  -86,  -87,  -81, -282,    1,    0, -185,    0,
    0, -168,  -84,    1, -271,    0, -129,  -91,    0, -144,
 -247,    0,  -49,  -73,    1,    0, -227,    0, -164,  -40,
    0,  -67,    0,   88,  -29,  -22,    0,  -86,    0,  -23,
 -168,    0,  -19,    0,    0,    0,  -20,  -11,  -34,   88,
    0,    0,   -5,  -14,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0, -243,    0,    0,    0,    2, -147,
    0,    0,    0,    0,    0,    0,    4,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  -37,   73,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  -36,    3,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0, -277,
  -26,    0,    0,    0,    0,    0,    0,    0,    0,    0,
 -124,    0,    0,    0,    0,  -33,    0,    0, -196,    0,
    0,    0,    0, -137,    0,    0, -134,    0,    0, -251,
  -70,    0,    0,    0,    0,  -31,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  -31, -196,    0,  -99,    0,
    0,  -89,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    3, -224,    0,  -18,    0,    0,    0,    0,    0,
    0,    0,    0,  -31,    0,    0,    0,  -28,    0, -240,
  -43,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    3,    0,    0,    0, -221,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    3,
    0,    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
  261,  258,    0,  -38,  268,  226,  284,  -95,  272,  273,
  -55,  164,    0,    0,    0,  262,    0,  -16,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  225,
    0,    0,    0,    0,    0,    0,    0, -113,    0,    0,
    0,  -62, -104,    0,    0,  185,  -54,    0,  176,    0,
    0,  177,    0,    0,
};
#define YYTABLESIZE 373
static const YYINT yytable[] = {                         24,
   49,   71,   96,  102,  103,  104,  105,   58,  157,   87,
  142,  153,  110,  122,    6,  123,    1,  150,  123,    6,
   86,    4,   87,  166,  156,   71,  123,  110,  163,  121,
   19,   20,  173,   86,  119,    6,  120,  123,  123,  135,
  136,  137,  139,  112,  146,   87,   87,  123,   87,  172,
   87,   49,   87,  168,   87,  155,   86,   86,  123,   86,
  183,   86,  140,   86,  110,   86,   71,   11,  123,  159,
  123,   27,  141,   28,  179,   79,  193,  110,   78,   79,
   30,   13,   78,   14,  167,   31,   71,   32,  110,  110,
  110,  110,  110,   23,  110,  110,  110,  110,  110,  110,
  110,  110,  178,  110,   21,  110,   62,  110,  110,  110,
    5,   34,   35,  170,   44,    5,   26,    5,   71,    5,
   82,    5,    5,  103,    5,   52,   81,   19,   61,   88,
    5,    5,  174,  175,   71,   59,  103,   61,   61,   81,
  125,  126,  187,   34,   35,   47,   48,  103,  103,  103,
  103,  103,  180,  103,  103,  103,  103,  103,  103,  103,
  103,  104,  103,   81,  103,   81,  103,   81,  103,   81,
   60,   81,   62,   62,  104,  117,   34,   35,   47,   48,
   63,  107,  106,  113,  116,  104,  104,  104,  104,  104,
   95,  104,  104,  104,  104,  104,  104,  104,  104,  118,
  104,  147,  104,   95,  104,  124,  104,  149,  151,  148,
  152,  123,  154,  176,   95,   95,  164,   94,  165,  171,
   95,   95,   95,   95,   95,   95,   95,   95,  177,   95,
   94,   95,   80,   95,  181,   95,  182,  184,  185,  186,
  190,   94,   94,  188,  192,   80,  195,   94,   94,   94,
   94,   94,   94,   94,   94,  191,   94,  194,   94,   26,
   94,   25,   94,   65,   29,   62,   35,   34,   42,   80,
   18,   80,   77,   80,   25,   80,   33,   80,   29,   89,
   34,   35,   36,   37,   38,   76,   90,   41,   87,   12,
   33,   42,   43,   89,   34,   35,   36,   37,   38,   91,
   90,  162,   27,   92,   28,  111,   57,  158,  160,   29,
  161,   30,    0,    0,    0,    0,   31,   92,   32,    0,
    0,   33,    0,    0,    0,   34,   35,   36,   37,   38,
    6,   39,    0,    0,    0,    6,    0,    6,    0,    6,
    0,    6,    6,    0,    6,   23,    0,    0,    0,    0,
    6,    6,   64,    0,   65,    0,   66,   67,    0,   68,
    0,  125,  126,    0,    0,   69,   70,  127,  128,  129,
  130,  131,  132,
};
static const YYINT yycheck[] = {                         16,
   39,   57,   65,   66,   67,   68,   69,   46,  122,  261,
  261,  116,  290,  274,  258,  298,  279,  113,  298,  277,
  261,  302,  274,  306,  304,   81,  298,  305,  142,   92,
  300,  301,  304,  274,   90,  279,   91,  298,  298,  287,
  288,  289,  302,   82,  107,  297,  298,  298,  300,  154,
  302,   90,  304,  149,  306,  118,  297,  298,  298,  300,
  174,  302,  302,  304,  261,  306,  122,  279,  298,  124,
  298,  257,  302,  259,  302,  300,  190,  274,  300,  304,
  266,  263,  304,  279,  147,  271,  142,  273,  285,  286,
  287,  288,  289,  258,  291,  292,  293,  294,  295,  296,
  297,  298,  165,  300,  279,  302,  304,  304,  305,  306,
  258,  280,  281,  152,  303,  263,  279,  265,  174,  267,
  275,  269,  270,  261,  272,  302,  261,  300,  301,  279,
  278,  279,  262,  263,  190,  302,  274,  262,  263,  274,
  285,  286,  181,  280,  281,  282,  283,  285,  286,  287,
  288,  289,  169,  291,  292,  293,  294,  295,  296,  297,
  298,  261,  300,  298,  302,  300,  304,  302,  306,  304,
  302,  306,  262,  263,  274,  279,  280,  281,  282,  283,
  302,  305,  303,  301,  303,  285,  286,  287,  288,  289,
  261,  291,  292,  293,  294,  295,  296,  297,  298,  303,
  300,  290,  302,  274,  304,  297,  306,  268,  302,  263,
  290,  298,  303,  263,  285,  286,  304,  261,  300,  304,
  291,  292,  293,  294,  295,  296,  297,  298,  302,  300,
  274,  302,  261,  304,  275,  306,  304,  267,  261,  263,
  261,  285,  286,  263,  279,  274,  261,  291,  292,  293,
  294,  295,  296,  297,  298,  267,  300,  263,  302,  258,
  304,  258,  306,  290,  264,  263,  304,  304,  302,  298,
   10,  300,  304,  302,   17,  304,  276,  306,  264,  279,
  280,  281,  282,  283,  284,  304,  286,   20,   63,    6,
  276,   20,   20,  279,  280,  281,  282,  283,  284,  299,
  286,  138,  257,  303,  259,   81,   45,  123,  133,  264,
  134,  266,   -1,   -1,   -1,   -1,  271,  303,  273,   -1,
   -1,  276,   -1,   -1,   -1,  280,  281,  282,  283,  284,
  258,  286,   -1,   -1,   -1,  263,   -1,  265,   -1,  267,
   -1,  269,  270,   -1,  272,  258,   -1,   -1,   -1,   -1,
  278,  279,  265,   -1,  267,   -1,  269,  270,   -1,  272,
   -1,  285,  286,   -1,   -1,  278,  279,  291,  292,  293,
  294,  295,  296,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 1
#endif
#define YYMAXTOKEN 306
#define YYUNDFTOKEN 363
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
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
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
"$$12 :",
"simple_stmt : var_ref $$12 OP_ASSIGN boolean_expr MK_SEMICOLON",
"simple_stmt : PRINT boolean_expr MK_SEMICOLON",
"simple_stmt : READ boolean_expr MK_SEMICOLON",
"proc_call_stmt : ID MK_LPAREN opt_boolean_expr_list MK_RPAREN MK_SEMICOLON",
"cond_stmt : IF boolean_expr THEN opt_stmt_list ELSE opt_stmt_list END IF",
"cond_stmt : IF boolean_expr THEN opt_stmt_list END IF",
"while_stmt : WHILE boolean_expr DO opt_stmt_list END DO",
"$$13 :",
"for_stmt : FOR ID $$13 OP_ASSIGN int_const TO int_const DO opt_stmt_list END DO",
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
#line 443 "parser.y"

int yyerror(const char *msg )
{
    const char* tmp = msg;
    fprintf( stderr, "\n|--------------------------------------------------------------------------\n" );
	fprintf( stderr, "| Error found in Line #%d: %s\n", linenum, buf );
	fprintf( stderr, "|\n" );
	fprintf( stderr, "| Unmatched token: %s\n", yytext );
	fprintf( stderr, "|--------------------------------------------------------------------------\n" );
	exit(-1);
}
#line 526 "y.tab.c"

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
#line 48 "parser.y"
	{
					symbol_table_init();
					id_list_buf.pb(yytext);
					funct_attri_buf.clear();
                    program_name_checking(program_name,yytext,0);
				}
break;
case 2:
#line 55 "parser.y"
	{
					inserting_symbol_table(id_list_buf,"program","void",funct_attri_buf);
					id_list_buf.clear();
				}
break;
case 3:
#line 61 "parser.y"
	{
					error_detection();
                    program_name_checking(program_name,yytext,1);
					dumpsymbol();
					pop_symbol_table();
			  	}
break;
case 9:
#line 82 "parser.y"
	{
				funct_attri_buf.clear(); /*normal variable does not have attribute, so just let the size be zero*/
				inserting_symbol_table(id_list_buf,"variable",yystack.l_mark[0].str,funct_attri_buf);
				id_list_buf.clear();
				error_detection();
			}
break;
case 11:
#line 90 "parser.y"
	{
                funct_attri_buf.clear(); /*normal variable does not have attribute, so just let the size be zero*/
				array_dimension_parser();
                array_type_str=yystack.l_mark[-1].str;
                array_type_str+=" ";
                array_type_str+=reverse_arr_buf;
				inserting_symbol_table(id_list_buf,"variable",array_type_str,funct_attri_buf);
				id_list_buf.clear();
				error_detection();
				memset(arr_buf,0,sizeof(arr_buf));/*update it for next segment*/
				is_arr=0;
			}
break;
case 12:
#line 103 "parser.y"
	{
				funct_attri_buf.pb(const_buf); /*normal variable does not have attribute, so just let the size be zero*/
				inserting_symbol_table(id_list_buf,"constant",const_type_str,funct_attri_buf);
				id_list_buf.clear();
				error_detection();
                funct_attri_buf.clear();
			}
break;
case 14:
#line 113 "parser.y"
	{yyval.str=yytext; const_type=1;}
break;
case 15:
#line 114 "parser.y"
	{yyval.str=yytext; const_type=9;}
break;
case 16:
#line 117 "parser.y"
	{yyval.str=yytext; const_type=(const_type==1)?1:9; const_type_str="integer ";parse_constant();}
break;
case 17:
#line 118 "parser.y"
	{yyval.str=yytext; const_type=(const_type==1)?2:10; const_type_str="integer ";parse_constant();}
break;
case 18:
#line 119 "parser.y"
	{yyval.str=yytext; const_type=3; const_type_str="real ";parse_constant();}
break;
case 19:
#line 120 "parser.y"
	{yyval.str=yytext; const_type=4; const_type_str="real ";parse_constant();}
break;
case 20:
#line 121 "parser.y"
	{yyval.str=yytext; const_type=5; const_type_str="real ";parse_constant();}
break;
case 21:
#line 122 "parser.y"
	{yyval.str=yytext; const_type=6; const_type_str="real ";parse_constant();}
break;
case 22:
#line 123 "parser.y"
	{yyval.str=yytext; const_type=7; const_type_str="string ";parse_constant();}
break;
case 23:
#line 124 "parser.y"
	{yyval.str=yytext; const_type=8; const_type_str="boolean ";parse_constant();}
break;
case 24:
#line 125 "parser.y"
	{yyval.str=yytext; const_type=8; const_type_str="boolean ";parse_constant();}
break;
case 29:
#line 137 "parser.y"
	{
                    funct_name = yytext;
                    scope_depth++;
				}
break;
case 30:
#line 142 "parser.y"
	{
					is_funct=1;
					scope_depth--;
				}
break;
case 31:
#line 147 "parser.y"
	{
                    id_list_buf.pb(funct_name);
                    funct_name.clear();
                    if(is_arr)
					{
						array_dimension_parser();
						/*here we push_back the funct_attri_buf inorder to match the attributes of function*/
						funct_attri_buf.clear(); /*primitive initialization*/
						for(unsigned int i=0;i<mysymbol_table[1].size();i++) /*search the parameter for function attribute*/
						{
							if((mysymbol_table[1][i].kind=="parameter")&&(mysymbol_table[1][i].name[0]!=0))
							{
                                funct_attri_buf.pb(mysymbol_table[1][i].type);
							}
						}
                        array_type_str=yystack.l_mark[-1].str;
                        array_type_str+=" ";
                        array_type_str+=reverse_arr_buf;
						inserting_symbol_table(id_list_buf,"function",array_type_str,funct_attri_buf);
                        memset(arr_buf,0,sizeof(arr_buf));/*update it for next segment*/
					}
					else
					{
						/*here we push_back the funct_attri_buf inorder to match the attributes of function*/
						funct_attri_buf.clear(); /*primitive initialization*/
						for(unsigned int i=0;i<mysymbol_table[1].size();i++) /*search the parameter for function attribute*/
						{
							if((mysymbol_table[1][i].kind=="parameter")&&(mysymbol_table[1][i].name[0]!=0))
							{
                                funct_attri_buf.pb(mysymbol_table[1][i].type);
							}
						}
                        if(yystack.l_mark[-1].str==NULL) /*prevent logic null string error*/
                        {
                            inserting_symbol_table(id_list_buf,"function","void",funct_attri_buf);
                        }
                        else
                        {
                            inserting_symbol_table(id_list_buf,"function",yystack.l_mark[-1].str,funct_attri_buf);
                        }

					}
                    id_list_buf.clear();
                    funct_attri_buf.clear();
                    error_detection();
					is_arr=0;
				}
break;
case 32:
#line 196 "parser.y"
	{
					is_funct=0;
				}
break;
case 38:
#line 211 "parser.y"
	{
				funct_attri_buf.clear();
				if(is_arr)
				{
                    if(error_detection()==0)
					{
						array_dimension_parser();
                        array_type_str=yystack.l_mark[0].str;
                        array_type_str+=" ";
                        array_type_str+=reverse_arr_buf;
						inserting_symbol_table(id_list_buf,"parameter",array_type_str,funct_attri_buf);
                        memset(arr_buf,0,sizeof(arr_buf));/*update it for next segment*/
					}
				}
				else
				{
					if(error_detection()==0)
					{
						inserting_symbol_table(id_list_buf,"parameter",yystack.l_mark[0].str,funct_attri_buf);
					}
				}
                id_list_buf.clear();
				is_arr=0;
			}
break;
case 39:
#line 238 "parser.y"
	{
                id_list_buf.pb(yytext);
			}
break;
case 40:
#line 242 "parser.y"
	{
				id_list_buf.pb(yytext);
			}
break;
case 41:
#line 247 "parser.y"
	{yyval.str=yystack.l_mark[0].str;}
break;
case 43:
#line 251 "parser.y"
	{yyval.str=yystack.l_mark[0].str;}
break;
case 44:
#line 252 "parser.y"
	{yyval.str=yystack.l_mark[0].str;}
break;
case 45:
#line 256 "parser.y"
	{
                char* synth = (char* )"integer";/*suppose this is not implemented, IOS CONVERSION ERROR WILL BE THROWN*/
                yyval.str=synth;
			}
break;
case 46:
#line 261 "parser.y"
	{
                char* synth = (char* )"real";/*suppose this is not implemented, IOS CONVERSION ERROR WILL BE THROWN*/
                yyval.str=synth;
			}
break;
case 47:
#line 266 "parser.y"
	{
                char* synth = (char* )"boolean";/*suppose this is not implemented, IOS CONVERSION ERROR WILL BE THROWN*/
                yyval.str=synth;
			}
break;
case 48:
#line 271 "parser.y"
	{
                char* synth = (char* )"string";/*suppose this is not implemented, IOS CONVERSION ERROR WILL BE THROWN*/
                yyval.str=synth;
			}
break;
case 49:
#line 278 "parser.y"
	{
				is_arr=1;
			}
break;
case 50:
#line 282 "parser.y"
	{
                yyval.str=yystack.l_mark[0].str;
                int delta=atol(yystack.l_mark[-2].str)-atol(yystack.l_mark[-4].str)+1;
				char tmp[10];
				sprintf(tmp,"%d",delta);
				strcat(arr_buf,tmp);
				strcat(arr_buf,",");
			}
break;
case 58:
#line 302 "parser.y"
	{
					scope_depth++;
				}
break;
case 59:
#line 307 "parser.y"
	{
                    dumpsymbol();
                    pop_symbol_table();
				}
break;
case 65:
#line 323 "parser.y"
	{
                /*cout<<"VAR REF GET "<<$1<<endl;*/
                assign_check_buf.pb(yystack.l_mark[0].str);
                simple_stmt_checking();
            }
break;
case 66:
#line 329 "parser.y"
	{
                assign_check_buf.clear();
            }
break;
case 73:
#line 353 "parser.y"
	{
					inserting_iter_table(yytext,scope_depth+1);
					error_detection();
					is_loop=1;
				}
break;
case 74:
#line 361 "parser.y"
	{
					is_loop=0;
				}
break;
case 103:
#line 418 "parser.y"
	{yyval.str=yystack.l_mark[0].str;}
break;
case 104:
#line 419 "parser.y"
	{yyval.str=yystack.l_mark[0].str;}
break;
case 110:
#line 429 "parser.y"
	{
                if(yystack.l_mark[0].str==NULL)
                {
                    cout<<"VAR RED Nullptr"<<endl;
                }
                yyval.str=yystack.l_mark[0].str;
            }
break;
#line 1056 "y.tab.c"
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
