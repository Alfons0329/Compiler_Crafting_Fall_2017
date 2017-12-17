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
vector<string> funct_param_buf;
int is_proc_call;
#line 34 "parser.y"
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
#line 64 "y.tab.c"

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
   38,   38,   40,   40,   41,   31,   31,   31,   43,   36,
   32,   32,   33,   45,   34,   35,   44,   44,   46,   46,
   42,   42,   47,   47,   48,   48,   49,   49,   51,   51,
   51,   51,   51,   51,   50,   50,   52,   52,   53,   53,
   54,   54,   54,   12,   12,   12,   12,   55,   12,   12,
   12,   11,   11,   56,
};
static const YYINT yylen[] = {                            2,
    0,    0,    7,    3,    1,    0,    2,    1,    0,    6,
    5,    0,    6,    1,    1,    1,    2,    1,    2,    1,
    2,    1,    1,    1,    1,    0,    2,    1,    0,    0,
    0,    0,   13,    1,    0,    3,    1,    3,    3,    1,
    2,    0,    1,    1,    1,    1,    1,    1,    0,    7,
    1,    1,    1,    1,    1,    1,    1,    0,    0,    6,
    1,    0,    2,    1,    0,    5,    3,    3,    0,    6,
    8,    6,    6,    0,   11,    3,    1,    0,    3,    1,
    3,    1,    3,    1,    2,    1,    3,    1,    1,    1,
    1,    1,    1,    1,    3,    1,    1,    1,    3,    1,
    1,    1,    1,    1,    2,    3,    4,    0,    5,    5,
    1,    1,    2,    3,
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
    0,    0,   38,   43,   44,    0,   36,   74,    0,    0,
    0,    0,  111,    0,  100,    0,    0,   84,   86,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  113,    0,
   63,    0,    0,    0,    0,    0,    0,    0,    0,   85,
    0,    0,    0,    0,   97,   98,   91,   94,   93,   89,
   92,   90,    0,    0,  101,  102,  103,    0,   67,   68,
   76,    0,    0,    0,    0,   60,    0,   41,   31,    0,
    0,    0,    0,  106,    0,    0,   83,    0,    0,   99,
    0,    0,    0,    0,  114,    0,   50,    0,    0,    0,
    0,  107,    0,    0,    0,    0,    0,   66,    0,    0,
  109,  110,    0,   72,   73,   70,    0,   32,    0,    0,
    0,    0,   71,   33,    0,    0,   75,
};
static const YYINT yydgoto[] = {                          2,
    7,   15,  114,   40,   93,   53,   54,   83,   84,   85,
   94,   95,    3,    8,    5,    9,   16,   72,   10,   51,
   50,   17,   22,   55,   86,  168,  191,   56,   46,   73,
   74,   75,   76,   77,   78,   79,   45,   80,  110,   81,
  108,  162,  106,  163,  115,  164,   97,   98,   99,  100,
  133,  134,  101,  138,  116,  109,
};
static const YYINT yysindex[] = {                      -252,
    0,    0, -262,    0, -234, -213,    0, -194, -195, -234,
    0, -166, -193,    0,    0, -165, -195,    0, -177,   63,
    0, -199,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0, -102,    0,
    0,    0, -186, -213, -234, -137,    0,    0,    0, -180,
 -173,    0,    0,  -93, -163, -164,  105, -112,    0,    0,
 -146,    0, -213, -133,   20,   20,   20,   20,   20,    0,
 -140,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  105, -137,    0,    0,    0, -131,    0,    0,    0, -267,
   20,   20,    0, -140,    0, -257, -125,    0,    0,   94,
 -105, -260, -230, -227, -250, -127,   20,  -91,    0,  -58,
    0,  -67, -146,  -72,  -77,  -75,  -69,   20, -140,    0,
 -276,  105,   20,   20,    0,    0,    0,    0,    0,    0,
    0,    0,   29,   29,    0,    0,    0,   29,    0,    0,
    0,  105,   20, -236,   20,    0, -146,    0,    0, -137,
   20,   20, -273,    0,  -53, -125,    0,  -74, -105,    0,
  -21,  -51,  -59,  -52,    0, -217,    0, -165,  -18,  -43,
  -41,    0,  105,   -2,    5,  -35,   20,    0,    6, -137,
    0,    0,    9,    0,    0,    0,  -51,    0,    7,    8,
   -6,  105,    0,    0,   11,   25,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0, -240,    0,    0,    0,   30, -139,
    0,    0,    0,    0,    0,    0,   32,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  -12,   90,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  -10,   34,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0, -271,
   17,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  -26,    0,    0,    0,    0,   -7,    0,    0, -197,    0,
    0,    0,    0, -100,    0,    0, -241,    0,    0, -251,
  -42,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0, -138,    0,  -71,    0,
    0,  -24,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   34,   10,    0,    0,    0,    0,    0,    0,    0,
   10,   10,    0,    0,    0, -129,    0, -224,  -15,    0,
    0, -190,    0,   12,    0,    0,    0,    0,    0,    0,
    0,    0,   34,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0, -183,    0,    0,    0,
    0,   34,    0,    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
  288,  300,    0,  -38,  298,  258,  318,  -89,  305,  306,
  -55,  190,    0,    0,    0,  285,    0,  -16,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  250,
    0,    0,    0,    0,    0,    0,    0, -113,    0,    0,
    0,  -62,    0,   89,    0,    0,  210,  -70,    0,  202,
    0,    0,  203,    0,    0,    0,
};
#define YYTABLESIZE 390
static const YYINT yytable[] = {                         24,
   49,   71,   96,  102,  103,  104,  105,   58,  155,   88,
  142,  117,   34,   35,   47,   48,  122,    6,  112,   82,
  120,  123,   88,  148,  123,   71,    1,  154,  161,  121,
  172,   69,   82,  112,  119,  118,   87,  123,    6,    4,
  123,  139,    6,  112,  144,   88,   88,  123,   88,   87,
   88,   49,   88,  157,   88,  153,   82,  167,   82,  183,
   82,  123,   82,  112,   82,   11,   71,  123,   13,  165,
  123,  140,   87,   87,  141,   87,  112,   87,  195,   87,
  123,   87,  166,   14,  178,   21,   71,  112,  112,  112,
  112,  112,   23,  112,  112,  112,  112,  112,  112,  112,
  112,   26,  112,   44,  112,  108,  112,  112,  112,   80,
   27,  169,   28,   80,  187,   52,   79,   71,    5,   30,
   79,   59,  112,    5,   31,    5,   32,    5,   60,    5,
    5,   81,    5,   19,   20,  112,   71,   63,    5,    5,
   62,  189,   34,   35,   81,   88,  112,  112,  112,  112,
  112,  179,  112,  112,  112,  112,  112,  112,  112,  112,
  104,  112,   82,  112,  107,  112,  112,  112,   81,  113,
   81,  124,   81,  104,   81,  143,   81,   34,   35,   47,
   48,  135,  136,  137,  104,  104,  104,  104,  104,  105,
  104,  104,  104,  104,  104,  104,  104,  104,  145,  104,
  147,  104,  105,  104,  146,  104,   19,   61,  173,  174,
  125,  126,  150,  105,  105,  105,  105,  105,   96,  105,
  105,  105,  105,  105,  105,  105,  105,  151,  105,  149,
  105,   96,  105,  152,  105,   61,   61,   62,   62,  170,
  171,  175,   96,   96,  176,   95,  123,  177,   96,   96,
   96,   96,   96,   96,   96,   96,  180,   96,   95,   96,
  181,   96,  182,   96,  184,  185,  186,  192,  188,   95,
   95,  190,  194,  196,  193,   95,   95,   95,   95,   95,
   95,   95,   95,   29,   95,  197,   95,   26,   95,   25,
   95,   35,   29,   34,   42,   33,   62,   18,   89,   34,
   35,   36,   37,   38,   33,   90,   65,   89,   34,   35,
   36,   37,   38,   78,   90,   77,   25,   41,   91,   27,
   87,   28,   92,   12,   42,   43,   29,  160,   30,   57,
  111,   92,  156,   31,  158,   32,  159,    0,   33,    0,
    0,    0,   34,   35,   36,   37,   38,    6,   39,    0,
    0,    0,    6,    0,    6,    0,    6,    0,    6,    6,
    0,    6,   23,    0,    0,    0,    0,    6,    6,   64,
    0,   65,    0,   66,   67,    0,   68,    0,  125,  126,
    0,    0,   69,   70,  127,  128,  129,  130,  131,  132,
};
static const YYINT yycheck[] = {                         16,
   39,   57,   65,   66,   67,   68,   69,   46,  122,  261,
  261,  279,  280,  281,  282,  283,  274,  258,  290,  261,
   91,  298,  274,  113,  298,   81,  279,  304,  142,   92,
  304,  303,  274,  305,   90,  303,  261,  298,  279,  302,
  298,  302,  277,   82,  107,  297,  298,  298,  300,  274,
  302,   90,  304,  124,  306,  118,  298,  147,  300,  173,
  302,  298,  304,  261,  306,  279,  122,  298,  263,  306,
  298,  302,  297,  298,  302,  300,  274,  302,  192,  304,
  298,  306,  145,  279,  302,  279,  142,  285,  286,  287,
  288,  289,  258,  291,  292,  293,  294,  295,  296,  297,
  298,  279,  300,  303,  302,  303,  304,  305,  306,  300,
  257,  150,  259,  304,  177,  302,  300,  173,  258,  266,
  304,  302,  261,  263,  271,  265,  273,  267,  302,  269,
  270,  261,  272,  300,  301,  274,  192,  302,  278,  279,
  304,  180,  280,  281,  274,  279,  285,  286,  287,  288,
  289,  168,  291,  292,  293,  294,  295,  296,  297,  298,
  261,  300,  275,  302,  305,  304,  305,  306,  298,  301,
  300,  297,  302,  274,  304,  303,  306,  280,  281,  282,
  283,  287,  288,  289,  285,  286,  287,  288,  289,  261,
  291,  292,  293,  294,  295,  296,  297,  298,  290,  300,
  268,  302,  274,  304,  263,  306,  300,  301,  262,  263,
  285,  286,  290,  285,  286,  287,  288,  289,  261,  291,
  292,  293,  294,  295,  296,  297,  298,  303,  300,  302,
  302,  274,  304,  303,  306,  262,  263,  262,  263,  151,
  152,  263,  285,  286,  304,  261,  298,  300,  291,  292,
  293,  294,  295,  296,  297,  298,  275,  300,  274,  302,
  304,  304,  304,  306,  267,  261,  302,  261,  263,  285,
  286,  263,  279,  263,  267,  291,  292,  293,  294,  295,
  296,  297,  298,  264,  300,  261,  302,  258,  304,  258,
  306,  304,  264,  304,  302,  276,  263,   10,  279,  280,
  281,  282,  283,  284,  276,  286,  290,  279,  280,  281,
  282,  283,  284,  304,  286,  304,   17,   20,  299,  257,
   63,  259,  303,    6,   20,   20,  264,  138,  266,   45,
   81,  303,  123,  271,  133,  273,  134,   -1,  276,   -1,
   -1,   -1,  280,  281,  282,  283,  284,  258,  286,   -1,
   -1,   -1,  263,   -1,  265,   -1,  267,   -1,  269,  270,
   -1,  272,  258,   -1,   -1,   -1,   -1,  278,  279,  265,
   -1,  267,   -1,  269,  270,   -1,  272,   -1,  285,  286,
   -1,   -1,  278,  279,  291,  292,  293,  294,  295,  296,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 1
#endif
#define YYMAXTOKEN 306
#define YYUNDFTOKEN 365
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
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"illegal-symbol",
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
"$$13 :",
"proc_call_stmt : ID $$13 MK_LPAREN opt_boolean_expr_list MK_RPAREN MK_SEMICOLON",
"cond_stmt : IF boolean_expr THEN opt_stmt_list ELSE opt_stmt_list END IF",
"cond_stmt : IF boolean_expr THEN opt_stmt_list END IF",
"while_stmt : WHILE boolean_expr DO opt_stmt_list END DO",
"$$14 :",
"for_stmt : FOR ID $$14 OP_ASSIGN int_const TO int_const DO opt_stmt_list END DO",
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
"$$15 :",
"factor : ID $$15 MK_LPAREN opt_boolean_expr_list MK_RPAREN",
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
#line 459 "parser.y"

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
#line 533 "y.tab.c"

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
#line 50 "parser.y"
	{
					symbol_table_init();
					id_list_buf.pb(yytext);
					funct_attri_buf.clear();
                    program_name_checking(program_name,yytext,0);
				}
break;
case 2:
#line 57 "parser.y"
	{
					inserting_symbol_table(id_list_buf,"program","void",funct_attri_buf);
					id_list_buf.clear();
				}
break;
case 3:
#line 63 "parser.y"
	{
					error_detection();
                    program_name_checking(program_name,yytext,1);
					dumpsymbol();
					pop_symbol_table();
			  	}
break;
case 9:
#line 84 "parser.y"
	{
				funct_attri_buf.clear(); /*normal variable does not have attribute, so just let the size be zero*/
				inserting_symbol_table(id_list_buf,"variable",yystack.l_mark[0].str,funct_attri_buf);
				id_list_buf.clear();
				error_detection();
			}
break;
case 11:
#line 92 "parser.y"
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
#line 105 "parser.y"
	{
				funct_attri_buf.pb(const_buf); /*normal variable does not have attribute, so just let the size be zero*/
				inserting_symbol_table(id_list_buf,"constant",const_type_str,funct_attri_buf);
				id_list_buf.clear();
				error_detection();
                funct_attri_buf.clear();
			}
break;
case 14:
#line 115 "parser.y"
	{yyval.str=yytext; const_type=1;}
break;
case 15:
#line 116 "parser.y"
	{yyval.str=yytext; const_type=9;}
break;
case 16:
#line 119 "parser.y"
	{yyval.str=yytext; const_type=(const_type==1)?1:9; const_type_str="integer ";parse_constant();}
break;
case 17:
#line 120 "parser.y"
	{yyval.str=yytext; const_type=(const_type==1)?2:10; const_type_str="integer ";parse_constant();}
break;
case 18:
#line 121 "parser.y"
	{yyval.str=yytext; const_type=3; const_type_str="real ";parse_constant();}
break;
case 19:
#line 122 "parser.y"
	{yyval.str=yytext; const_type=4; const_type_str="real ";parse_constant();}
break;
case 20:
#line 123 "parser.y"
	{yyval.str=yytext; const_type=5; const_type_str="real ";parse_constant();}
break;
case 21:
#line 124 "parser.y"
	{yyval.str=yytext; const_type=6; const_type_str="real ";parse_constant();}
break;
case 22:
#line 125 "parser.y"
	{yyval.str=yytext; const_type=7; const_type_str="string ";parse_constant();}
break;
case 23:
#line 126 "parser.y"
	{yyval.str=yytext; const_type=8; const_type_str="boolean ";parse_constant();}
break;
case 24:
#line 127 "parser.y"
	{yyval.str=yytext; const_type=8; const_type_str="boolean ";parse_constant();}
break;
case 29:
#line 139 "parser.y"
	{
                    funct_name = yytext;
                    scope_depth++;
				}
break;
case 30:
#line 144 "parser.y"
	{
					is_funct=1;
					scope_depth--;
				}
break;
case 31:
#line 149 "parser.y"
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
#line 198 "parser.y"
	{
					is_funct=0;
				}
break;
case 38:
#line 213 "parser.y"
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
#line 240 "parser.y"
	{
                id_list_buf.pb(yytext);
			}
break;
case 40:
#line 244 "parser.y"
	{
				id_list_buf.pb(yytext);
			}
break;
case 41:
#line 249 "parser.y"
	{yyval.str=yystack.l_mark[0].str;}
break;
case 43:
#line 253 "parser.y"
	{yyval.str=yystack.l_mark[0].str;}
break;
case 44:
#line 254 "parser.y"
	{yyval.str=yystack.l_mark[0].str;}
break;
case 45:
#line 258 "parser.y"
	{
                char* synth = (char* )"integer";/*suppose this is not implemented, IOS CONVERSION ERROR WILL BE THROWN*/
                yyval.str=synth;
			}
break;
case 46:
#line 263 "parser.y"
	{
                char* synth = (char* )"real";/*suppose this is not implemented, IOS CONVERSION ERROR WILL BE THROWN*/
                yyval.str=synth;
			}
break;
case 47:
#line 268 "parser.y"
	{
                char* synth = (char* )"boolean";/*suppose this is not implemented, IOS CONVERSION ERROR WILL BE THROWN*/
                yyval.str=synth;
			}
break;
case 48:
#line 273 "parser.y"
	{
                char* synth = (char* )"string";/*suppose this is not implemented, IOS CONVERSION ERROR WILL BE THROWN*/
                yyval.str=synth;
			}
break;
case 49:
#line 280 "parser.y"
	{
				is_arr=1;
			}
break;
case 50:
#line 284 "parser.y"
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
#line 304 "parser.y"
	{
					scope_depth++;
				}
break;
case 59:
#line 309 "parser.y"
	{
                    dumpsymbol();
                    pop_symbol_table();
				}
break;
case 65:
#line 325 "parser.y"
	{
                assign_check_buf.pb(yystack.l_mark[0].str);
                simple_stmt_checking();
            }
break;
case 66:
#line 330 "parser.y"
	{
                assign_check_buf.clear();
            }
break;
case 69:
#line 339 "parser.y"
	{
                funct_param_buf.pb(yystack.l_mark[0].str);
                is_proc_call=1;
                cout<<"procedure call "<<endl;
            }
break;
case 70:
#line 345 "parser.y"
	{
                is_proc_call=0;
                cout<<"procedure call END   "<<endl;
            }
break;
case 74:
#line 365 "parser.y"
	{
					inserting_iter_table(yytext,scope_depth+1);
					error_detection();
					is_loop=1;
				}
break;
case 75:
#line 373 "parser.y"
	{
					is_loop=0;
				}
break;
case 104:
#line 430 "parser.y"
	{yyval.str=yystack.l_mark[0].str;}
break;
case 105:
#line 431 "parser.y"
	{yyval.str=yystack.l_mark[0].str;}
break;
case 108:
#line 435 "parser.y"
	{
                cout<<"NEW PROCEDURE CALL"<<endl;
            }
break;
case 112:
#line 445 "parser.y"
	{
                yyval.str=yystack.l_mark[0].str;
                if(is_proc_call)
                {
                    cout<<"IS PROCEDUIRE CALL PARAM "<<yystack.l_mark[0].str<<endl;
                }
            }
break;
#line 1083 "y.tab.c"
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
