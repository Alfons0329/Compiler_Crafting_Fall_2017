/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */


/**
 * Introduction to Compiler Design by Prof. Yi Ping You
 * Project 3 YACC sample
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "header.h"
#include "symtab.h"
#include "semcheck.h"

//#include "test.h"

int yydebug;

extern int linenum;		/* declared in lex.l */
extern FILE *yyin;		/* declared by lex */
extern char *yytext;		/* declared by lex */
extern char buf[256];		/* declared in lex.l */
extern int yylex(void);
int yyerror(char* );

int scope = 0;

int Opt_D = 1;			/* symbol table dump option */
char fileName[256];


struct SymTable *symbolTable;	// main symbol table

__BOOLEAN paramError;			// indicate is parameter have any error?

struct PType *funcReturn;		// record function's return type, used at 'return statement' production rule




# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ARRAY = 258,
    BEG = 259,
    BOOLEAN = 260,
    DEF = 261,
    DO = 262,
    ELSE = 263,
    END = 264,
    FALSE = 265,
    FOR = 266,
    INTEGER = 267,
    IF = 268,
    OF = 269,
    PRINT = 270,
    READ = 271,
    REAL = 272,
    RETURN = 273,
    STRING = 274,
    THEN = 275,
    TO = 276,
    TRUE = 277,
    VAR = 278,
    WHILE = 279,
    OP_ADD = 280,
    OP_SUB = 281,
    OP_MUL = 282,
    OP_DIV = 283,
    OP_MOD = 284,
    OP_ASSIGN = 285,
    OP_EQ = 286,
    OP_NE = 287,
    OP_GT = 288,
    OP_LT = 289,
    OP_GE = 290,
    OP_LE = 291,
    OP_AND = 292,
    OP_OR = 293,
    OP_NOT = 294,
    MK_COMMA = 295,
    MK_COLON = 296,
    MK_SEMICOLON = 297,
    MK_LPAREN = 298,
    MK_RPAREN = 299,
    MK_LB = 300,
    MK_RB = 301,
    ID = 302,
    INT_CONST = 303,
    FLOAT_CONST = 304,
    SCIENTIFIC = 305,
    STR_CONST = 306
  };
#endif
/* Tokens.  */
#define ARRAY 258
#define BEG 259
#define BOOLEAN 260
#define DEF 261
#define DO 262
#define ELSE 263
#define END 264
#define FALSE 265
#define FOR 266
#define INTEGER 267
#define IF 268
#define OF 269
#define PRINT 270
#define READ 271
#define REAL 272
#define RETURN 273
#define STRING 274
#define THEN 275
#define TO 276
#define TRUE 277
#define VAR 278
#define WHILE 279
#define OP_ADD 280
#define OP_SUB 281
#define OP_MUL 282
#define OP_DIV 283
#define OP_MOD 284
#define OP_ASSIGN 285
#define OP_EQ 286
#define OP_NE 287
#define OP_GT 288
#define OP_LT 289
#define OP_GE 290
#define OP_LE 291
#define OP_AND 292
#define OP_OR 293
#define OP_NOT 294
#define MK_COMMA 295
#define MK_COLON 296
#define MK_SEMICOLON 297
#define MK_LPAREN 298
#define MK_RPAREN 299
#define MK_LB 300
#define MK_RB 301
#define ID 302
#define INT_CONST 303
#define FLOAT_CONST 304
#define SCIENTIFIC 305
#define STR_CONST 306

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{


	int intVal;
	float realVal;
	//__BOOLEAN booleanVal;
	char *lexeme;
	struct idNode_sem *id;
	//SEMTYPE type;
	struct ConstAttr *constVal;
	struct PType *ptype;
	struct param_sem *par;
	struct expr_sem *exprs;
	/*struct var_ref_sem *varRef; */
	struct expr_sem_node *exprNode;


};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */



#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   190

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  51
/* YYNRULES -- Number of rules.  */
#define YYNRULES  108
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  193

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   306

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    77,    77,    76,    92,    95,    96,    99,   100,   103,
     118,   134,   152,   157,   162,   167,   172,   177,   182,   186,
     191,   198,   199,   202,   203,   207,   212,   206,   225,   226,
     229,   234,   237,   240,   245,   248,   249,   252,   253,   256,
     257,   258,   259,   262,   269,   272,   273,   274,   275,   276,
     277,   278,   282,   282,   298,   299,   302,   303,   306,   309,
     310,   313,   319,   324,   327,   330,   335,   339,   338,   351,
     352,   355,   358,   359,   362,   369,   375,   379,   382,   386,
     389,   393,   396,   400,   403,   404,   405,   406,   407,   408,
     411,   415,   418,   419,   422,   426,   429,   430,   431,   434,
     439,   444,   449,   454,   468,   482,   498,   502,   509
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ARRAY", "BEG", "BOOLEAN", "DEF", "DO",
  "ELSE", "END", "FALSE", "FOR", "INTEGER", "IF", "OF", "PRINT", "READ",
  "REAL", "RETURN", "STRING", "THEN", "TO", "TRUE", "VAR", "WHILE",
  "OP_ADD", "OP_SUB", "OP_MUL", "OP_DIV", "OP_MOD", "OP_ASSIGN", "OP_EQ",
  "OP_NE", "OP_GT", "OP_LT", "OP_GE", "OP_LE", "OP_AND", "OP_OR", "OP_NOT",
  "MK_COMMA", "MK_COLON", "MK_SEMICOLON", "MK_LPAREN", "MK_RPAREN",
  "MK_LB", "MK_RB", "ID", "INT_CONST", "FLOAT_CONST", "SCIENTIFIC",
  "STR_CONST", "$accept", "program", "$@1", "program_body",
  "opt_decl_list", "decl_list", "decl", "literal_const",
  "opt_func_decl_list", "func_decl_list", "func_decl", "$@2", "$@3",
  "opt_param_list", "param_list", "param", "id_list", "opt_type", "type",
  "scalar_type", "array_type", "array_index", "stmt", "compound_stmt",
  "$@4", "opt_stmt_list", "stmt_list", "simple_stmt", "proc_call_stmt",
  "cond_stmt", "condition", "while_stmt", "condition_while", "for_stmt",
  "$@5", "loop_param", "return_stmt", "opt_boolean_expr_list",
  "boolean_expr_list", "boolean_expr", "boolean_term", "boolean_factor",
  "relop_expr", "rel_op", "expr", "add_op", "term", "mul_op", "factor",
  "var_ref", "dim", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306
};
# endif

#define YYPACT_NINF -116

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-116)))

#define YYTABLE_NINF -56

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -38,  -116,    16,    -9,  -116,     0,   -11,    55,     7,     0,
    -116,  -116,    10,    22,    41,  -116,     7,  -116,  -116,    44,
      12,  -116,   -11,  -116,   102,  -116,  -116,    61,  -116,  -116,
    -116,  -116,  -116,  -116,    27,  -116,  -116,  -116,  -116,    17,
      69,    72,  -116,    78,  -116,    26,     0,  -116,   109,  -116,
    -116,  -116,  -116,  -116,  -116,    88,   -11,    98,    89,    61,
     104,  -116,  -116,  -116,  -116,    99,    31,    31,    31,    31,
      31,    92,  -116,  -116,   138,    24,  -116,  -116,  -116,  -116,
    -116,  -116,   -19,   134,    98,  -116,  -116,    90,    31,    31,
     106,  -116,   130,   113,   115,  -116,  -116,    93,    94,  -116,
     108,    45,    48,    50,   147,   113,    31,  -116,  -116,    31,
      31,  -116,    98,  -116,   114,   125,    31,   116,   108,  -116,
     -24,    31,    24,    31,    31,  -116,  -116,  -116,  -116,  -116,
    -116,  -116,  -116,    46,    46,  -116,  -116,  -116,    46,  -116,
    -116,  -116,    89,   117,   120,   113,    70,   -25,  -116,  -116,
     -16,    11,    31,  -116,   119,   133,   115,  -116,   118,    94,
    -116,   148,   122,    31,  -116,  -116,   149,   121,  -116,   141,
    -116,   123,  -116,    89,   152,   159,  -116,   113,   124,  -116,
     -16,  -116,   161,  -116,  -116,  -116,   165,   155,    89,  -116,
     164,   167,  -116
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     2,     0,     0,     1,     6,     0,     0,    22,     5,
       8,    34,     0,     0,     0,    52,    21,    24,     7,     0,
       0,     3,    29,     4,     0,    23,    33,     0,    41,    20,
      39,    40,    42,    19,     0,    12,    14,    16,    18,     0,
       0,     0,    25,    28,    31,     0,     6,    44,     0,    13,
      15,    17,    11,     9,    10,     0,     0,     0,    52,     0,
      36,    30,    32,    37,    38,     0,     0,     0,     0,     0,
       0,   106,    57,    45,     0,    54,    46,    51,    47,    48,
      49,    50,     0,     0,     0,    26,    67,     0,     0,     0,
     106,   105,     0,    64,    77,    79,    81,    83,    91,    95,
      99,     0,     0,     0,     0,    66,    73,    53,    56,     0,
       0,   107,     0,    35,     0,     0,     0,   106,   100,    80,
       0,    73,    55,     0,     0,    92,    93,    86,    89,    88,
      84,    87,    85,     0,     0,    96,    97,    98,     0,    59,
      60,    71,    52,     0,    72,    75,     0,     0,    43,    52,
       0,     0,    73,   101,     0,     0,    76,    78,    82,    90,
      94,     0,     0,     0,    58,   108,     0,     0,    69,     0,
     102,     0,   103,    52,     0,     0,    61,    74,     0,    70,
       0,   104,     0,    63,    65,    27,     0,     0,    52,    62,
       0,     0,    68
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -116,  -116,  -116,  -116,   129,  -116,   168,   156,  -116,  -116,
     162,  -116,  -116,  -116,  -116,   126,   173,  -116,   -65,   160,
     163,   127,   110,   -15,  -116,  -115,  -116,  -116,  -116,  -116,
    -116,  -116,  -116,  -116,  -116,     1,  -116,  -109,  -116,   -64,
      64,   -80,  -116,  -116,    51,  -116,    54,  -116,    52,   -57,
    -116
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     7,     8,     9,    10,    91,    15,    16,
      17,    55,   114,    42,    43,    44,    45,    85,    62,    63,
      64,    48,    72,    73,    24,    74,    75,    76,    77,    78,
      92,    79,   104,    80,   115,   169,    81,   143,   144,   145,
      94,    95,    96,   133,    97,   134,    98,   138,    99,   100,
     111
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      23,    82,    93,   101,   102,   103,   105,   155,   119,     1,
     167,   109,   154,   123,   123,    27,     4,    28,    82,   113,
     153,   165,    29,     6,    30,   120,   110,   161,   -52,    31,
     118,    32,   168,     5,    33,    65,    11,    66,    34,    67,
      68,    29,    69,   171,   157,   146,   147,   148,    70,   123,
      19,    20,   151,    33,    14,   170,    29,    87,   182,    52,
      35,    36,    37,    38,    13,    82,    19,    57,    33,    21,
      88,    71,    87,   190,    89,    49,    50,    51,    90,    35,
      36,    37,    38,   123,    22,    82,   123,   139,   123,    89,
     140,    26,   141,    90,    35,    36,    37,    38,   -55,   177,
      65,    27,    66,    28,    67,    68,    46,    69,   123,    47,
      30,    53,   164,    70,    54,    31,    82,    32,   125,   126,
      56,   135,   136,   137,   127,   128,   129,   130,   131,   132,
      59,    82,    60,   116,   166,   106,    71,   117,    49,    50,
      51,   173,   174,   125,   126,    84,    86,   107,   112,   121,
     122,   123,   124,   110,   142,   150,   149,   175,   178,   152,
     163,   162,   180,   172,   176,   183,   184,   181,   189,   179,
     187,   185,   188,   191,   192,    58,    39,    18,    25,    12,
      40,   186,    61,    41,   158,   108,    83,   156,   159,     0,
     160
};

static const yytype_int16 yycheck[] =
{
      15,    58,    66,    67,    68,    69,    70,   122,    88,    47,
      26,    30,   121,    38,    38,     3,     0,     5,    75,    84,
      44,    46,    10,    23,    12,    89,    45,   142,     4,    17,
      87,    19,    48,    42,    22,    11,    47,    13,    26,    15,
      16,    10,    18,   152,   124,   109,   110,   112,    24,    38,
      40,    41,   116,    22,    47,    44,    10,    26,   173,    42,
      48,    49,    50,    51,     9,   122,    40,    41,    22,    47,
      39,    47,    26,   188,    43,    48,    49,    50,    47,    48,
      49,    50,    51,    38,    43,   142,    38,    42,    38,    43,
      42,    47,    42,    47,    48,    49,    50,    51,     9,   163,
      11,     3,    13,     5,    15,    16,     4,    18,    38,    48,
      12,    42,    42,    24,    42,    17,   173,    19,    25,    26,
      42,    27,    28,    29,    31,    32,    33,    34,    35,    36,
      21,   188,    44,    43,   149,    43,    47,    47,    48,    49,
      50,     8,     9,    25,    26,    41,    47,     9,    14,    43,
      20,    38,    37,    45,     7,    30,    42,     9,     9,    43,
      40,    44,    21,    44,    42,    13,     7,    44,    13,    48,
       9,    47,     7,     9,     7,    46,    20,     9,    16,     6,
      20,   180,    56,    20,   133,    75,    59,   123,   134,    -1,
     138
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    47,    53,    54,     0,    42,    23,    55,    56,    57,
      58,    47,    68,     9,    47,    60,    61,    62,    58,    40,
      41,    47,    43,    75,    76,    62,    47,     3,     5,    10,
      12,    17,    19,    22,    26,    48,    49,    50,    51,    59,
      71,    72,    65,    66,    67,    68,     4,    48,    73,    48,
      49,    50,    42,    42,    42,    63,    42,    41,    56,    21,
      44,    67,    70,    71,    72,    11,    13,    15,    16,    18,
      24,    47,    74,    75,    77,    78,    79,    80,    81,    83,
      85,    88,   101,    73,    41,    69,    47,    26,    39,    43,
      47,    59,    82,    91,    92,    93,    94,    96,    98,   100,
     101,    91,    91,    91,    84,    91,    43,     9,    74,    30,
      45,   102,    14,    70,    64,    86,    43,    47,   101,    93,
      91,    43,    20,    38,    37,    25,    26,    31,    32,    33,
      34,    35,    36,    95,    97,    27,    28,    29,    99,    42,
      42,    42,     7,    89,    90,    91,    91,    91,    70,    42,
      30,    91,    43,    44,    89,    77,    92,    93,    96,    98,
     100,    77,    44,    40,    42,    46,    75,    26,    48,    87,
      44,    89,    44,     8,     9,     9,    42,    91,     9,    48,
      21,    44,    77,    13,     7,    47,    87,     9,     7,    13,
      77,     9,     7
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    52,    54,    53,    55,    56,    56,    57,    57,    58,
      58,    58,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    60,    60,    61,    61,    63,    64,    62,    65,    65,
      66,    66,    67,    68,    68,    69,    69,    70,    70,    71,
      71,    71,    71,    72,    73,    74,    74,    74,    74,    74,
      74,    74,    76,    75,    77,    77,    78,    78,    79,    79,
      79,    80,    81,    81,    82,    83,    84,    86,    85,    87,
      87,    88,    89,    89,    90,    90,    91,    91,    92,    92,
      93,    93,    94,    94,    95,    95,    95,    95,    95,    95,
      96,    96,    97,    97,    98,    98,    99,    99,    99,   100,
     100,   100,   100,   100,   100,   100,   101,   101,   102
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     6,     3,     1,     0,     2,     1,     5,
       5,     5,     1,     2,     1,     2,     1,     2,     1,     1,
       1,     1,     0,     2,     1,     0,     0,    11,     1,     0,
       3,     1,     3,     3,     1,     2,     0,     1,     1,     1,
       1,     1,     1,     6,     1,     1,     1,     1,     1,     1,
       1,     1,     0,     5,     1,     0,     2,     1,     4,     3,
       3,     5,     8,     6,     1,     6,     1,     0,    11,     1,
       2,     3,     1,     0,     3,     1,     3,     1,     3,     1,
       2,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     1,     1,     3,     1,     1,     1,     1,     1,
       2,     3,     4,     4,     5,     1,     1,     2,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

    {
			  struct PType *pType = createPType( VOID_t );
			  struct SymNode *newNode = createProgramNode( (yyvsp[0].lexeme), scope, pType );
			  insertTab( symbolTable, newNode );
			}

    break;

  case 3:

    {
			  // dump symbol table
			  if( Opt_D == 1 )
				printSymTable( symbolTable, scope );
			}

    break;

  case 9:

    {
			  // insert into symbol table
			  struct idNode_sem *ptr;
			  struct SymNode *newNode;
			  for( ptr=(yyvsp[-3].id) ; ptr!=0 ; ptr=(ptr->next) ) {
			  	if( verifyRedeclaration( symbolTable, ptr->value, scope ) ==__FALSE ) { }
				else {
					newNode = createVarNode( ptr->value, scope, (yyvsp[-1].ptype) );
					insertTab( symbolTable, newNode );
				}
			  }

			  deleteIdList( (yyvsp[-3].id) );
			}

    break;

  case 10:

    {
			  // insert into symbol table
			  struct idNode_sem *ptr;
			  struct SymNode *newNode;
			  for( ptr=(yyvsp[-3].id) ; ptr!=0 ; ptr=(ptr->next) ) {
			  	if( (yyvsp[-1].ptype)->isError == __TRUE ) { }
				else if( verifyRedeclaration( symbolTable, ptr->value, scope ) ==__FALSE ) { }
				else {
					newNode = createVarNode( ptr->value, scope, (yyvsp[-1].ptype) );
					insertTab( symbolTable, newNode );
				}
			  }

			  deleteIdList( (yyvsp[-3].id) );
			}

    break;

  case 11:

    {
			  struct PType *pType = createPType( (yyvsp[-1].constVal)->category );
			  // insert constants into symbol table
			  struct idNode_sem *ptr;
			  struct SymNode *newNode;
			  for( ptr=(yyvsp[-3].id) ; ptr!=0 ; ptr=(ptr->next) ) {
			  	if( verifyRedeclaration( symbolTable, ptr->value, scope ) ==__FALSE ) { }
				else {
					newNode = createConstNode( ptr->value, scope, pType, (yyvsp[-1].constVal) );
					insertTab( symbolTable, newNode );
				}
			  }
			  
			  deleteIdList( (yyvsp[-3].id) );
			}

    break;

  case 12:

    {
			  int tmp = (yyvsp[0].intVal);
			  (yyval.constVal) = createConstAttr( INTEGER_t, &tmp );
			}

    break;

  case 13:

    {
			  int tmp = -(yyvsp[0].intVal);
			  (yyval.constVal) = createConstAttr( INTEGER_t, &tmp );
			}

    break;

  case 14:

    {
			  float tmp = (yyvsp[0].realVal);
			  (yyval.constVal) = createConstAttr( REAL_t, &tmp );
			}

    break;

  case 15:

    {
			  float tmp = -(yyvsp[0].realVal);
			  (yyval.constVal) = createConstAttr( REAL_t, &tmp );
			}

    break;

  case 16:

    {
			  float tmp = (yyvsp[0].realVal);
			  (yyval.constVal) = createConstAttr( REAL_t, &tmp );
			}

    break;

  case 17:

    {
			  float tmp = -(yyvsp[0].realVal);
			  (yyval.constVal) = createConstAttr( REAL_t, &tmp );
			}

    break;

  case 18:

    {
			  (yyval.constVal) = createConstAttr( STRING_t, (yyvsp[0].lexeme) );
			}

    break;

  case 19:

    {
			  __BOOLEAN tmp = __TRUE;
			  (yyval.constVal) = createConstAttr( BOOLEAN_t, &tmp );
			}

    break;

  case 20:

    {
			  __BOOLEAN tmp = __FALSE;
			  (yyval.constVal) = createConstAttr( BOOLEAN_t, &tmp );
			}

    break;

  case 25:

    {
			  // check and insert parameters into symbol table
			  paramError = insertParamIntoSymTable( symbolTable, (yyvsp[0].par), scope+1 );
			}

    break;

  case 26:

    {
			  // check and insert function into symbol table
			  insertFuncIntoSymTable( symbolTable, (yyvsp[-5].lexeme), (yyvsp[-3].par), (yyvsp[0].ptype), scope );
			  funcReturn = (yyvsp[0].ptype);
			}

    break;

  case 27:

    {
			  funcReturn = 0;
			}

    break;

  case 28:

    { (yyval.par) = (yyvsp[0].par); }

    break;

  case 29:

    { (yyval.par) = 0; }

    break;

  case 30:

    {
			  param_sem_addParam( (yyvsp[-2].par), (yyvsp[0].par) );
			  (yyval.par) = (yyvsp[-2].par);
			}

    break;

  case 31:

    { (yyval.par) = (yyvsp[0].par); }

    break;

  case 32:

    { (yyval.par) = createParam( (yyvsp[-2].id), (yyvsp[0].ptype) ); }

    break;

  case 33:

    {
			  idlist_addNode( (yyvsp[-2].id), (yyvsp[0].lexeme) );
			  (yyval.id) = (yyvsp[-2].id);
			}

    break;

  case 34:

    { (yyval.id) = createIdList((yyvsp[0].lexeme)); }

    break;

  case 35:

    { (yyval.ptype) = (yyvsp[0].ptype); }

    break;

  case 36:

    { (yyval.ptype) = createPType( VOID_t ); }

    break;

  case 37:

    { (yyval.ptype) = (yyvsp[0].ptype); }

    break;

  case 38:

    { (yyval.ptype) = (yyvsp[0].ptype); }

    break;

  case 39:

    { (yyval.ptype) = createPType( INTEGER_t ); }

    break;

  case 40:

    { (yyval.ptype) = createPType( REAL_t ); }

    break;

  case 41:

    { (yyval.ptype) = createPType( BOOLEAN_t ); }

    break;

  case 42:

    { (yyval.ptype) = createPType( STRING_t ); }

    break;

  case 43:

    {
				increaseArrayDim( (yyvsp[0].ptype), (yyvsp[-4].intVal), (yyvsp[-2].intVal) );
				(yyval.ptype) = (yyvsp[0].ptype);
			}

    break;

  case 44:

    { (yyval.intVal) = (yyvsp[0].intVal); }

    break;

  case 52:

    { 
			  scope++;
			}

    break;

  case 53:

    { 
			  // print contents of current scope
			  if( Opt_D == 1 )
			  	printSymTable( symbolTable, scope );
			  deleteScope( symbolTable, scope );	// leave this scope, delete...
			  scope--; 
			}

    break;

  case 58:

    {
			}

    break;

  case 61:

    {
			  //verifyFuncInvoke( $1, $3, symbolTable, scope );
			}

    break;

  case 67:

    {
			  insertLoopVarIntoTable( symbolTable, (yyvsp[0].lexeme) );
			}

    break;

  case 68:

    {
			  popLoopVar( symbolTable );
			}

    break;

  case 69:

    { (yyval.intVal) = (yyvsp[0].intVal); }

    break;

  case 70:

    { (yyval.intVal) = -(yyvsp[0].intVal); }

    break;

  case 72:

    { (yyval.exprs) = (yyvsp[0].exprs); }

    break;

  case 73:

    { (yyval.exprs) = 0; }

    break;

  case 74:

    {
			  struct expr_sem *exprPtr;
			  for( exprPtr=(yyvsp[-2].exprs) ; (exprPtr->next)!=0 ; exprPtr=(exprPtr->next) );
			  exprPtr->next = (yyvsp[0].exprs);
			  (yyval.exprs) = (yyvsp[-2].exprs);
			}

    break;

  case 75:

    {
			  (yyval.exprs) = (yyvsp[0].exprs);
			}

    break;

  case 76:

    {
			  (yyval.exprs) = (yyvsp[-2].exprs);
			}

    break;

  case 77:

    { (yyval.exprs) = (yyvsp[0].exprs); }

    break;

  case 78:

    {
			  (yyval.exprs) = (yyvsp[-2].exprs);
			}

    break;

  case 79:

    { (yyval.exprs) = (yyvsp[0].exprs); }

    break;

  case 80:

    {
			  (yyval.exprs) = (yyvsp[0].exprs);
			}

    break;

  case 81:

    { (yyval.exprs) = (yyvsp[0].exprs); }

    break;

  case 82:

    {
			  (yyval.exprs) = (yyvsp[-2].exprs);
			}

    break;

  case 83:

    { (yyval.exprs) = (yyvsp[0].exprs); }

    break;

  case 84:

    { (yyval.intVal) = LT_t; }

    break;

  case 85:

    { (yyval.intVal) = LE_t; }

    break;

  case 86:

    { (yyval.intVal) = EQ_t; }

    break;

  case 87:

    { (yyval.intVal) = GE_t; }

    break;

  case 88:

    { (yyval.intVal) = GT_t; }

    break;

  case 89:

    { (yyval.intVal) = NE_t; }

    break;

  case 90:

    {
			  (yyval.exprs) = (yyvsp[-2].exprs);
			}

    break;

  case 91:

    { (yyval.exprs) = (yyvsp[0].exprs); }

    break;

  case 92:

    { (yyval.intVal) = ADD_t; }

    break;

  case 93:

    { (yyval.intVal) = SUB_t; }

    break;

  case 94:

    {
			  (yyval.exprs) = (yyvsp[-2].exprs);
			}

    break;

  case 95:

    { (yyval.exprs) = (yyvsp[0].exprs); }

    break;

  case 96:

    { (yyval.intVal) = MUL_t; }

    break;

  case 97:

    { (yyval.intVal) = DIV_t; }

    break;

  case 98:

    { (yyval.intVal) = MOD_t; }

    break;

  case 99:

    {
			  (yyval.exprs) = (yyvsp[0].exprs);
			  (yyval.exprs)->beginningOp = NONE_t;
			}

    break;

  case 100:

    {
			  (yyval.exprs) = (yyvsp[0].exprs);
			  (yyval.exprs)->beginningOp = SUB_t;
			}

    break;

  case 101:

    {
			  (yyvsp[-1].exprs)->beginningOp = NONE_t;
			  (yyval.exprs) = (yyvsp[-1].exprs); 
			}

    break;

  case 102:

    {
			  (yyval.exprs) = (yyvsp[-1].exprs);
			  (yyval.exprs)->beginningOp = SUB_t;
			}

    break;

  case 103:

    {
			  //$$ = verifyFuncInvoke( $1, $3, symbolTable, scope );
			  (yyval.exprs) = (struct expr_sem *)malloc(sizeof(struct expr_sem));
			  (yyval.exprs)->isDeref = __TRUE;
			  (yyval.exprs)->varRef = 0;
              (yyval.exprs)->next = 0;

              struct SymNode *node = 0;
              node = lookupSymbol( symbolTable, (yyvsp[-3].lexeme), 0, __FALSE );

              (yyval.exprs)->pType = node->type;
			  (yyval.exprs)->beginningOp = NONE_t;
			}

    break;

  case 104:

    {
			  //$$ = verifyFuncInvoke( $2, $4, symbolTable, scope );
			  (yyval.exprs) = (struct expr_sem *)malloc(sizeof(struct expr_sem));
			  (yyval.exprs)->isDeref = __TRUE;
			  (yyval.exprs)->varRef = 0;
              (yyval.exprs)->next = 0;

              struct SymNode *node = 0;
              node = lookupSymbol( symbolTable, (yyvsp[-3].lexeme), 0, __FALSE );

              (yyval.exprs)->pType = node->type;
			  (yyval.exprs)->beginningOp = SUB_t;
			}

    break;

  case 105:

    {
			  (yyval.exprs) = (struct expr_sem *)malloc(sizeof(struct expr_sem));
			  (yyval.exprs)->isDeref = __TRUE;
			  (yyval.exprs)->varRef = 0;
			  (yyval.exprs)->pType = createPType( (yyvsp[0].constVal)->category );
			  (yyval.exprs)->next = 0;
			  if( (yyvsp[0].constVal)->hasMinus == __TRUE ) {
			  	(yyval.exprs)->beginningOp = SUB_t;
			  }
			  else {
				(yyval.exprs)->beginningOp = NONE_t;
			  }
			}

    break;

  case 106:

    {
			  (yyval.exprs) = createExprSem( (yyvsp[0].lexeme) );
			}

    break;

  case 107:

    {
			  increaseDim( (yyvsp[-1].exprs), (yyvsp[0].intVal) );
			  (yyval.exprs) = (yyvsp[-1].exprs);
			}

    break;

  case 108:

    {
              (yyval.intVal) = INTEGER_t;
            }

    break;



      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}



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

