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
extern int yylex(void);
extern int Opt_D; /* declared in lex.l */
extern int linenum;	/* declared in lex.l */
int yyerror(const char*);
/*some global variables that needed in the parsing procedure*/
char arr_buf[BUF_SIZE];
char reverse_arr_buf[BUF_SIZE];
string const_buf;
string const_type_str;
vector<string> id_list_buf; /**/
vector<string> funct_attri_buf;
#line 46 "y.tab.c"

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

#define ID 257
#define MK_SEMICOLON 258
#define END 259
#define VAR 260
#define MK_COLON 261
#define INT_CONST 262
#define OCTAL_CONST 263
#define OP_SUB 264
#define FLOAT_CONST 265
#define SCIENTIFIC 266
#define STR_CONST 267
#define TRUE 268
#define FALSE 269
#define MK_LPAREN 270
#define MK_RPAREN 271
#define MK_COMMA 272
#define INTEGER 273
#define REAL 274
#define BOOLEAN 275
#define STRING 276
#define ARRAY 277
#define TO 278
#define OF 279
#define BEG 280
#define OP_ASSIGN 281
#define PRINT 282
#define READ 283
#define IF 284
#define THEN 285
#define ELSE 286
#define WHILE 287
#define DO 288
#define FOR 289
#define RETURN 290
#define OP_OR 291
#define OP_AND 292
#define OP_NOT 293
#define OP_LT 294
#define OP_LE 295
#define OP_EQ 296
#define OP_GE 297
#define OP_GT 298
#define OP_NE 299
#define OP_ADD 300
#define OP_MUL 301
#define OP_DIV 302
#define OP_MOD 303
#define MK_LB 304
#define MK_RB 305
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
    3,    0,   58,    4,   27,   14,   15,    0,   18,   20,
   22,   23,   24,   45,   46,   47,   48,   49,   16,   12,
    9,    0,   39,    0,    0,   19,   21,   17,    0,    0,
    0,   11,   37,    0,    0,    0,    0,    0,   13,   10,
    0,   30,    0,    0,    0,    0,    0,    0,    0,    0,
   51,   64,   52,   53,   54,   55,   56,   57,   59,    0,
    0,    0,   38,   43,   44,    0,   36,    0,    0,    0,
    0,    0,  108,    0,    0,    0,   82,   84,    0,    0,
   98,    0,    0,    0,   72,    0,    0,   63,    0,    0,
  110,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   83,   66,    0,    0,   96,   87,   88,   89,
   90,   91,   92,   95,    0,    0,   99,  100,  101,    0,
   67,    0,    0,    0,   74,   60,    0,    0,    0,   41,
   31,    0,    0,    0,    0,    0,  104,    0,   81,    0,
    0,   97,    0,    0,    0,   65,  111,   50,    0,   68,
    0,  106,    0,  105,    0,    0,    0,    0,    0,  107,
   70,    0,   71,    0,   32,    0,    0,    0,   69,    0,
   33,    0,    0,   73,
};
static const YYINT yydgoto[] = {                          2,
    7,   15,  114,   39,   93,   53,   54,   83,   84,   85,
    3,    8,    5,    9,   16,   71,   10,   51,   50,   17,
   22,   55,   86,  169,  188,   56,   49,   72,   73,   74,
   75,   76,   77,   78,   45,   79,  107,   80,   94,  115,
  116,  144,  117,   96,   97,   98,   99,  135,  136,  100,
  140,  101,  111,
};
static const YYINT yysindex[] = {                      -233,
    0,    0, -232,    0, -229, -196,    0, -194, -189, -229,
    0, -242, -149,    0,    0, -183, -189,    0,   72, -140,
    0, -164,    0,    0,    0,    0,    0, -151,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0, -122,    0, -196, -229,    0,    0,    0, -160, -107,
 -103,    0,    0, -234, -108, -100,   43, -118,    0,    0,
 -134,    0, -196,  -90,  -69,  -69,  -69,  -69,  -70,  -69,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   43,
 -267, -160,    0,    0,    0,  -72,    0,  -69,  -68, -113,
  -69,  -69,    0, -114, -245,  -88,    0,    0,  -24, -207,
    0, -238, -257, -224,    0, -236,  -56,    0,  -69,  -69,
    0,  -73, -134,  -51,  -78,  -61,  -46,  -69,  -42,  -69,
 -114, -182,    0,    0,  -69,  -69,    0,    0,    0,    0,
    0,    0,    0,    0,   93,   93,    0,    0,    0,   93,
    0,   43,   43,  -52,    0,    0, -235, -198, -134,    0,
    0,  -27,  -69,  -41,  -69, -181,    0,  -88,    0, -249,
 -207,    0, -247,  -26, -160,    0,    0,    0, -183,    0,
  -78,    0,  -39,    0,  -47,   43,  -50,  -34,  -18,    0,
    0,  -14,    0, -160,    0,  -38,  -35,  -10,    0,   43,
    0,   -9,  -21,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0, -240,    0,    0,    0,  -31,   21,
    0,    0,    0,    0,    0,    0,  -16,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   -2,   32,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    6,   22,    0,    0,    0,
    0,    0,    0, -263,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0, -227,
    0,    0,    0,    0,    0,   25,    0,   13, -222,    0,
    0,    0,    0, -172,    0, -124,    0,    0, -187,  -80,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  -89,    0,   15,   13, -222,    0,
 -126,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0, -226,   22,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   13,    0,    0,   -6,    0,  -49,
  -37,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  -86,    0,    0,    0,    0,   22,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   22,
    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
  277,  271,    0,  -28,  273,  227,  287,  -97,  275,  276,
    0,    0,    0,  251,    0,  -15,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  217,    0,    0,
    0,    0,    0,    0,    0, -133,    0,    0,  -55,  -62,
 -111,    0,    0,  173,  -81,    0,  167,    0,    0,  170,
    0,  169,    0,
};
#define YYTABLESIZE 363
static const YYINT yytable[] = {                         48,
   24,   81,   95,  102,  103,  104,  154,  106,  163,  164,
  123,  175,  124,  109,  127,  150,    6,  109,   19,  141,
   58,  145,  166,    1,   81,    4,   61,  142,  122,   20,
    6,   61,   62,  125,  121,  109,  110,   20,  176,    6,
  109,  109,  182,  173,  159,  125,  147,  148,  109,  109,
  134,  168,  125,  112,  125,  125,  192,  156,   61,   62,
   11,   48,  109,  143,   13,  109,  125,   14,  109,  109,
   86,  109,  109,  109,  109,  109,  109,  109,  109,  109,
  109,  109,  109,   86,   86,  102,   81,   81,  157,  174,
  171,  102,  125,  137,  138,  139,   23,   86,  102,  102,
   86,   26,   27,   86,   86,   44,  167,   21,  125,  125,
   26,   27,  102,   46,   47,  102,   43,   86,  102,  102,
   81,  102,  102,  102,  102,  102,  102,  102,  102,  102,
  102,  103,  102,   80,   81,   52,  178,  103,   34,   35,
   36,   37,   38,  119,  103,  103,   80,   80,   26,   27,
   59,   46,   47,  179,   60,  187,  120,   63,  103,   82,
   80,  103,   62,   80,  103,  103,   80,  103,  103,  103,
  103,  103,  103,  103,  103,  103,  103,   94,  103,   88,
   80,   78,   78,   94,   77,   77,  105,   89,  113,  110,
   94,   94,   26,   27,   90,   29,   30,   31,   32,   33,
   91,  118,  146,  126,   94,  149,  151,   94,   85,  152,
   94,   94,  125,   94,   94,   94,   94,   94,   94,   94,
   93,   85,   85,   92,   94,  153,   93,  155,  165,  172,
  170,  180,  177,   93,   93,   85,  181,  183,   85,  127,
  185,   85,   85,  184,  186,  189,  191,   93,   26,  193,
   93,   79,  190,   93,   93,   85,   93,   93,   93,   93,
   93,   93,   93,   25,   79,   79,  194,   93,   35,  128,
  129,  130,  131,  132,  133,  134,   34,    5,   79,    5,
   62,   79,   42,   76,   79,   75,   18,   25,    6,   87,
    6,   40,   12,   41,   42,   57,  108,  158,   79,   64,
    5,  160,    5,    5,    5,  161,    0,    5,  162,    5,
    5,    6,    0,    6,    6,    6,    0,    0,    6,    0,
    6,    6,   23,    0,   65,   66,   67,    0,    0,   68,
    0,   69,   70,   26,   27,   28,   29,   30,   31,   32,
   33,    0,    0,    0,   34,   35,   36,   37,   38,   89,
    0,    0,    0,    0,   26,   27,   90,   29,   30,   31,
   32,   33,   91,
};
static const YYINT yycheck[] = {                         28,
   16,   57,   65,   66,   67,   68,  118,   70,  142,  143,
   92,  259,  258,  281,  264,  113,  257,  281,  261,  258,
   49,  258,  258,  257,   80,  258,  261,  285,   91,  272,
  260,  259,  259,  291,   90,  258,  304,  272,  286,  280,
  304,  264,  176,  155,  126,  291,  109,  110,  271,  272,
  300,  149,  291,   82,  291,  291,  190,  120,  286,  286,
  257,   90,  285,  288,  259,  288,  291,  257,  291,  292,
  258,  294,  295,  296,  297,  298,  299,  300,  301,  302,
  303,  304,  305,  271,  272,  258,  142,  143,  271,  271,
  153,  264,  291,  301,  302,  303,  280,  285,  271,  272,
  288,  262,  263,  291,  292,  270,  305,  257,  291,  291,
  262,  263,  285,  265,  266,  288,  257,  305,  291,  292,
  176,  294,  295,  296,  297,  298,  299,  300,  301,  302,
  303,  258,  305,  258,  190,  258,  165,  264,  273,  274,
  275,  276,  277,  257,  271,  272,  271,  272,  262,  263,
  258,  265,  266,  169,  258,  184,  270,  258,  285,  278,
  285,  288,  271,  288,  291,  292,  291,  294,  295,  296,
  297,  298,  299,  300,  301,  302,  303,  258,  305,  270,
  305,  271,  272,  264,  271,  272,  257,  257,  261,  304,
  271,  272,  262,  263,  264,  265,  266,  267,  268,  269,
  270,  270,  259,  292,  285,  279,  258,  288,  258,  271,
  291,  292,  291,  294,  295,  296,  297,  298,  299,  300,
  258,  271,  272,  293,  305,  272,  264,  270,  281,  271,
  258,  271,  259,  271,  272,  285,  284,  288,  288,  264,
  259,  291,  292,  278,  259,  284,  257,  285,  280,  259,
  288,  258,  288,  291,  292,  305,  294,  295,  296,  297,
  298,  299,  300,  280,  271,  272,  288,  305,  271,  294,
  295,  296,  297,  298,  299,  300,  271,  257,  285,  259,
  259,  288,  258,  271,  291,  271,   10,   17,  257,   63,
  259,   19,    6,   19,   19,   45,   80,  125,  305,  257,
  280,  135,  282,  283,  284,  136,   -1,  287,  140,  289,
  290,  280,   -1,  282,  283,  284,   -1,   -1,  287,   -1,
  289,  290,  280,   -1,  282,  283,  284,   -1,   -1,  287,
   -1,  289,  290,  262,  263,  264,  265,  266,  267,  268,
  269,   -1,   -1,   -1,  273,  274,  275,  276,  277,  257,
   -1,   -1,   -1,   -1,  262,  263,  264,  265,  266,  267,
  268,  269,  270,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 1
#endif
#define YYMAXTOKEN 305
#define YYUNDFTOKEN 361
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"ID","MK_SEMICOLON","END","VAR",
"MK_COLON","INT_CONST","OCTAL_CONST","OP_SUB","FLOAT_CONST","SCIENTIFIC",
"STR_CONST","TRUE","FALSE","MK_LPAREN","MK_RPAREN","MK_COMMA","INTEGER","REAL",
"BOOLEAN","STRING","ARRAY","TO","OF","BEG","OP_ASSIGN","PRINT","READ","IF",
"THEN","ELSE","WHILE","DO","FOR","RETURN","OP_OR","OP_AND","OP_NOT","OP_LT",
"OP_LE","OP_EQ","OP_GE","OP_GT","OP_NE","OP_ADD","OP_MUL","OP_DIV","OP_MOD",
"MK_LB","MK_RB",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
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
#line 419 "parser.y"

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
#line 506 "y.tab.c"

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
#line 43 "parser.y"
	{
					symbol_table_init();
					id_list_buf.pb(yytext);
					funct_attri_buf.resize(0);
				}
break;
case 2:
#line 49 "parser.y"
	{
					inserting_symbol_table(id_list_buf,"program","void",funct_attri_buf);
					id_list_buf.clear();
				}
break;
case 3:
#line 55 "parser.y"
	{
					error_detection();
					dumpsymbol();
					pop_symbol_table();
			  	}
break;
case 9:
#line 75 "parser.y"
	{
				funct_attri_buf.resize(0); /*normal variable does not have attribute, so just let the size be zero*/
				inserting_symbol_table(id_list_buf,"variable",yystack.l_mark[0].parsed_string,funct_attri_buf);
				id_list_buf.clear();
				error_detection();
			}
break;
case 11:
#line 83 "parser.y"
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
#line 93 "parser.y"
	{
				funct_attri_buf.pb(const_buf); /*normal variable does not have attribute, so just let the size be zero*/
				inserting_symbol_table(id_list_buf,"constant",const_type_str,funct_attri_buf);
				id_list_buf.clear();
				error_detection();
			}
break;
case 14:
#line 102 "parser.y"
	{yyval.parsed_string=yytext; const_type=1;}
break;
case 15:
#line 103 "parser.y"
	{yyval.parsed_string=yytext; const_type=9;}
break;
case 16:
#line 106 "parser.y"
	{yyval.parsed_string=yytext; const_type=(const_type==1)?1:9; const_type_str="integer ";parse_constant();}
break;
case 17:
#line 107 "parser.y"
	{yyval.parsed_string=yytext; const_type=(const_type==1)?2:10; const_type_str="integer ";parse_constant();}
break;
case 18:
#line 108 "parser.y"
	{yyval.parsed_string=yytext; const_type=3; const_type_str="real ";parse_constant();}
break;
case 19:
#line 109 "parser.y"
	{yyval.parsed_string=yytext; const_type=4; const_type_str="real ";parse_constant();}
break;
case 20:
#line 110 "parser.y"
	{yyval.parsed_string=yytext; const_type=5; const_type_str="real ";parse_constant();}
break;
case 21:
#line 111 "parser.y"
	{yyval.parsed_string=yytext; const_type=6; const_type_str="real ";parse_constant();}
break;
case 22:
#line 112 "parser.y"
	{yyval.parsed_string=yytext; const_type=7; const_type_str="string ";parse_constant();}
break;
case 23:
#line 113 "parser.y"
	{yyval.parsed_string=yytext; const_type=8; const_type_str="boolean ";parse_constant();}
break;
case 24:
#line 114 "parser.y"
	{yyval.parsed_string=yytext; const_type=8; const_type_str="boolean ";parse_constant();}
break;
case 29:
#line 126 "parser.y"
	{
					id_list_buf.pb(yytext);
                    error_detection();
					scope_depth++;
				}
break;
case 30:
#line 132 "parser.y"
	{
					is_funct=1;
					scope_depth--;
				}
break;
case 31:
#line 137 "parser.y"
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
#line 169 "parser.y"
	{
					is_funct=0;
				}
break;
case 38:
#line 184 "parser.y"
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
#line 210 "parser.y"
	{
				/* tmpstr.clear(); */
				/* strcpy(tmpstr,yytext); */
				id_list_buf.pb(yytext);
				/* $$=yytext; */
			}
break;
case 40:
#line 217 "parser.y"
	{
				/* tmpstr.clear(); */
				/* strcpy(tmpstr,yytext); */
				id_list_buf.pb(yytext);
				/* $$=yytext; */
			}
break;
case 41:
#line 225 "parser.y"
	{yyval.parsed_string=yystack.l_mark[0].parsed_string;}
break;
case 43:
#line 229 "parser.y"
	{yyval.parsed_string=yystack.l_mark[0].parsed_string;}
break;
case 44:
#line 230 "parser.y"
	{yyval.parsed_string=yystack.l_mark[0].parsed_string;}
break;
case 45:
#line 234 "parser.y"
	{
				yyval.parsed_string="integer ";
			}
break;
case 46:
#line 238 "parser.y"
	{
				yyval.parsed_string="real ";
			}
break;
case 47:
#line 242 "parser.y"
	{
				yyval.parsed_string="boolean ";
			}
break;
case 48:
#line 246 "parser.y"
	{
				yyval.parsed_string="string ";
			}
break;
case 49:
#line 252 "parser.y"
	{
				is_arr=1;
			}
break;
case 50:
#line 256 "parser.y"
	{
				int delta=atol(yystack.l_mark[-2].parsed_string)-atol(yystack.l_mark[-4].parsed_string)+1;
				char tmp[10];
				sprintf(tmp,"%d",delta);
				strcat(arr_buf,tmp);
				strcat(arr_buf,",");
			}
break;
case 58:
#line 275 "parser.y"
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
#line 287 "parser.y"
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
#line 336 "parser.y"
	{
					inserting_iter_table(yytext,scope_depth+1);
					error_detection();
					/*dumpiterator();*/
					is_loop=1;
				}
break;
case 73:
#line 345 "parser.y"
	{
					is_loop=0;
				}
break;
#line 1001 "y.tab.c"
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
