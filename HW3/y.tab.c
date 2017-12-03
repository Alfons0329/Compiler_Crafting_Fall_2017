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
#line 1 "parser.y" /* yacc.c:339  */

/**
 * Introduction to Compiler Design by Prof. Yi Ping You
 * Project 2 YACC sample
 */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "symbol_table.h"
#define BUF_SIZE 50
extern FILE *yyin;		/* declared by lex */

extern char *yytext;		/* declared by lex */
extern char *buf;		/* declared in lex.l */

char* array_scalar_type;
char arr_buf[BUF_SIZE];
char reverse_arr_buf[BUF_SIZE];
char const_buf[BUF_SIZE];
extern int yylex(void);
extern int Opt_D; /* declared in lex.l */
extern int linenum;		/* declared in lex.l */

int yyerror(char* );
int param_or_decl; //0 decl 1 param
int is_array; //0 no 1 yes
int is_function;
int const_type=0; //0 not constant, 1 int 2 -int  3 float 4 -float 5 scientific 6 -scientific 7 string 8 bool
/*
printf template for debugging

printf("0->")
*/


#line 102 "y.tab.c" /* yacc.c:339  */

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
    ID = 280,
    OCTAL_CONST = 281,
    INT_CONST = 282,
    FLOAT_CONST = 283,
    SCIENTIFIC = 284,
    STR_CONST = 285,
    OP_ADD = 286,
    OP_SUB = 287,
    OP_MUL = 288,
    OP_DIV = 289,
    OP_MOD = 290,
    OP_ASSIGN = 291,
    OP_EQ = 292,
    OP_NE = 293,
    OP_GT = 294,
    OP_LT = 295,
    OP_GE = 296,
    OP_LE = 297,
    OP_AND = 298,
    OP_OR = 299,
    OP_NOT = 300,
    MK_COMMA = 301,
    MK_COLON = 302,
    MK_SEMICOLON = 303,
    MK_LPAREN = 304,
    MK_RPAREN = 305,
    MK_LB = 306,
    MK_RB = 307
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
#define ID 280
#define OCTAL_CONST 281
#define INT_CONST 282
#define FLOAT_CONST 283
#define SCIENTIFIC 284
#define STR_CONST 285
#define OP_ADD 286
#define OP_SUB 287
#define OP_MUL 288
#define OP_DIV 289
#define OP_MOD 290
#define OP_ASSIGN 291
#define OP_EQ 292
#define OP_NE 293
#define OP_GT 294
#define OP_LT 295
#define OP_GE 296
#define OP_LE 297
#define OP_AND 298
#define OP_OR 299
#define OP_NOT 300
#define MK_COMMA 301
#define MK_COLON 302
#define MK_SEMICOLON 303
#define MK_LPAREN 304
#define MK_RPAREN 305
#define MK_LB 306
#define MK_RB 307

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 257 "y.tab.c" /* yacc.c:358  */

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
#define YYLAST   199

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  52
/* YYNRULES -- Number of rules.  */
#define YYNRULES  109
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  193

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   307

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
      45,    46,    47,    48,    49,    50,    51,    52
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    96,    96,   106,    95,   121,   124,   125,   128,   128,
     130,   135,   133,   166,   211,   210,   242,   243,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   257,   258,   261,
     262,   266,   278,   265,   302,   303,   306,   307,   310,   361,
     372,   386,   387,   390,   391,   394,   408,   421,   434,   450,
     449,   467,   468,   469,   470,   471,   472,   473,   477,   476,
     501,   502,   505,   506,   509,   510,   511,   514,   517,   522,
     525,   530,   535,   538,   539,   542,   543,   546,   547,   550,
     551,   554,   555,   558,   559,   562,   563,   564,   565,   566,
     567,   570,   571,   574,   575,   578,   579,   582,   583,   584,
     587,   588,   589,   590,   591,   592,   593,   596,   597,   600
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ARRAY", "BEG", "BOOLEAN", "DEF", "DO",
  "ELSE", "END", "FALSE", "FOR", "INTEGER", "IF", "OF", "PRINT", "READ",
  "REAL", "RETURN", "STRING", "THEN", "TO", "TRUE", "VAR", "WHILE", "ID",
  "OCTAL_CONST", "INT_CONST", "FLOAT_CONST", "SCIENTIFIC", "STR_CONST",
  "OP_ADD", "OP_SUB", "OP_MUL", "OP_DIV", "OP_MOD", "OP_ASSIGN", "OP_EQ",
  "OP_NE", "OP_GT", "OP_LT", "OP_GE", "OP_LE", "OP_AND", "OP_OR", "OP_NOT",
  "MK_COMMA", "MK_COLON", "MK_SEMICOLON", "MK_LPAREN", "MK_RPAREN",
  "MK_LB", "MK_RB", "$accept", "program", "$@1", "$@2", "program_body",
  "opt_decl_list", "decl_list", "$@3", "decl", "$@4", "$@5", "int_const",
  "literal_const", "opt_func_decl_list", "func_decl_list", "func_decl",
  "$@6", "$@7", "opt_param_list", "param_list", "param", "id_list",
  "opt_type", "type", "scalar_type", "array_type", "$@8", "stmt",
  "compound_stmt", "$@9", "opt_stmt_list", "stmt_list", "simple_stmt",
  "proc_call_stmt", "cond_stmt", "while_stmt", "for_stmt", "return_stmt",
  "opt_boolean_expr_list", "boolean_expr_list", "boolean_expr",
  "boolean_term", "boolean_factor", "relop_expr", "rel_op", "expr",
  "add_op", "term", "mul_op", "factor", "var_ref", "dim", YY_NULLPTR
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
     305,   306,   307
};
# endif

#define YYPACT_NINF -120

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-120)))

#define YYTABLE_NINF -9

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -9,  -120,    33,   -29,  -120,  -120,    22,    14,    39,    51,
      78,  -120,  -120,     4,    80,  -120,   106,    51,  -120,    22,
      89,    94,  -120,    63,  -120,  -120,  -120,  -120,  -120,  -120,
    -120,  -120,  -120,  -120,  -120,  -120,  -120,  -120,  -120,  -120,
    -120,   127,  -120,  -120,  -120,    67,    14,    22,    32,  -120,
    -120,  -120,    70,    71,  -120,    83,    79,  -120,    19,   121,
     107,  -120,  -120,    84,    14,    81,   113,    -5,    -5,    -5,
      -5,    -5,    86,  -120,  -120,   131,   121,  -120,  -120,  -120,
    -120,  -120,  -120,   -21,    32,    81,    95,  -120,  -120,  -120,
    -120,   108,   109,    45,    -5,    -5,  -120,    11,   114,  -120,
    -120,   110,    56,  -120,   111,    -2,    13,    16,    -3,    -5,
    -120,  -120,    -5,    -5,  -120,   145,  -120,   106,    32,    -5,
     112,    -5,   111,  -120,   -16,   121,    -5,    -5,  -120,  -120,
    -120,  -120,  -120,  -120,  -120,  -120,    53,    53,  -120,  -120,
    -120,    53,  -120,  -120,  -120,   121,   115,   117,   116,    44,
     -15,    81,   155,   146,   118,    -5,   -12,  -120,    87,   114,
    -120,    77,    56,  -120,   157,   122,    -5,  -120,  -120,  -120,
    -120,    32,  -120,   119,  -120,   121,   158,   165,  -120,   116,
     148,   167,  -120,   166,  -120,  -120,  -120,   121,   163,   168,
    -120,   171,  -120
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     2,     0,     0,     1,     3,     7,     0,     0,    28,
       6,    10,    40,     0,     0,    31,     0,    27,    30,     0,
       0,     0,     4,     0,    58,     5,    29,     9,    39,    49,
      47,    26,    45,    46,    48,    25,    17,    16,    20,    22,
      24,     0,    18,    14,    11,     0,    35,     7,     0,    21,
      23,    19,     0,     0,    13,     0,    34,    37,     0,    61,
       0,    15,    12,    42,     0,     0,     0,     0,     0,     0,
       0,     0,   107,    63,    51,     0,    60,    52,    57,    53,
      54,    55,    56,     0,     0,     0,     0,    36,    38,    43,
      44,     0,   107,     0,     0,     0,   106,     0,    78,    80,
      82,    84,    92,    96,   100,     0,     0,     0,     0,    74,
      59,    62,     0,     0,   108,     0,    41,     0,     0,    74,
     107,     0,   101,    81,     0,    61,     0,     0,    93,    94,
      87,    90,    89,    85,    88,    86,     0,     0,    97,    98,
      99,     0,    65,    66,    72,    61,     0,    73,    76,     0,
       0,     0,     0,     0,     0,    74,     0,   102,     0,    77,
      79,    83,    91,    95,     0,     0,     0,    64,   109,    50,
      32,     0,   104,     0,   103,    61,     0,     0,    67,    75,
       0,     0,   105,     0,    69,    70,    33,    61,     0,     0,
      68,     0,    71
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -120,  -120,  -120,  -120,  -120,   132,  -120,  -120,   161,  -120,
    -120,   -41,   160,  -120,  -120,   169,  -120,  -120,  -120,  -120,
     120,   175,  -120,   -82,   162,   164,  -120,   123,   -14,  -120,
    -119,  -120,  -120,  -120,  -120,  -120,  -120,  -120,  -106,  -120,
     -59,    61,   -80,  -120,  -120,    52,  -120,    54,  -120,    48,
     -58,  -120
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     6,     8,     9,    10,    19,    11,    53,
      52,    42,    96,    16,    17,    18,    23,   180,    55,    56,
      57,    58,    86,    88,    89,    90,    48,    73,    74,    47,
      75,    76,    77,    78,    79,    80,    81,    82,   146,   147,
     148,    98,    99,   100,   136,   101,   137,   102,   141,   103,
     104,   114
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      51,    83,    25,   116,   145,    31,   158,    60,    97,   105,
     106,   107,   108,   154,   123,   112,     1,    35,    83,     5,
      92,    36,    37,    38,    39,    40,   164,    93,   126,   126,
     113,   125,   126,     4,   157,   122,   124,   168,   174,    12,
      94,   126,   126,   115,    95,     7,   142,   160,    14,   173,
      20,    21,    51,   149,   150,   126,   183,   126,    36,    37,
     126,   143,   156,    31,   144,    20,    65,    83,   189,   169,
     120,    36,    37,    49,    50,    35,    15,   153,    92,    36,
      37,    38,    39,    40,    29,    93,    30,    83,   126,   138,
     139,   140,   167,    32,   121,   175,   176,    29,    33,    30,
      34,    -8,    95,   152,    31,    22,    32,   179,   128,   129,
      24,    33,    46,    34,    28,    54,    35,    83,    61,    62,
      36,    37,    38,    39,    40,    24,    41,    64,    84,    83,
     181,    85,    66,    63,    67,   109,    68,    69,    91,    70,
     110,   128,   129,   117,   118,    71,    72,   130,   131,   132,
     133,   134,   135,    36,    37,    49,    50,   127,   119,   151,
     126,   155,   113,   166,   170,   165,   177,   171,   172,   182,
     178,   184,   185,   186,   187,   188,   190,   191,   192,    59,
      27,    43,    13,    44,    87,    45,    26,   159,   161,   163,
       0,   162,     0,     0,     0,     0,     0,     0,     0,   111
};

static const yytype_int16 yycheck[] =
{
      41,    59,    16,    85,     7,    10,   125,    48,    67,    68,
      69,    70,    71,   119,    94,    36,    25,    22,    76,    48,
      25,    26,    27,    28,    29,    30,   145,    32,    44,    44,
      51,    20,    44,     0,    50,    93,    95,    52,    50,    25,
      45,    44,    44,    84,    49,    23,    48,   127,     9,   155,
      46,    47,    93,   112,   113,    44,   175,    44,    26,    27,
      44,    48,   121,    10,    48,    46,    47,   125,   187,   151,
      25,    26,    27,    28,    29,    22,    25,   118,    25,    26,
      27,    28,    29,    30,     3,    32,     5,   145,    44,    33,
      34,    35,    48,    12,    49,     8,     9,     3,    17,     5,
      19,    23,    49,   117,    10,    25,    12,   166,    31,    32,
       4,    17,    49,    19,    25,    48,    22,   175,    48,    48,
      26,    27,    28,    29,    30,     4,    32,    48,    21,   187,
     171,    47,    11,    50,    13,    49,    15,    16,    25,    18,
       9,    31,    32,    48,    36,    24,    25,    37,    38,    39,
      40,    41,    42,    26,    27,    28,    29,    43,    49,    14,
      44,    49,    51,    46,     9,    50,     9,    21,    50,    50,
      48,    13,     7,    25,     7,     9,    13,     9,     7,    47,
      19,    21,     7,    21,    64,    21,    17,   126,   136,   141,
      -1,   137,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    76
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    25,    54,    55,     0,    48,    56,    23,    57,    58,
      59,    61,    25,    74,     9,    25,    66,    67,    68,    60,
      46,    47,    25,    69,     4,    81,    68,    61,    25,     3,
       5,    10,    12,    17,    19,    22,    26,    27,    28,    29,
      30,    32,    64,    65,    77,    78,    49,    82,    79,    28,
      29,    64,    63,    62,    48,    71,    72,    73,    74,    58,
      64,    48,    48,    50,    48,    47,    11,    13,    15,    16,
      18,    24,    25,    80,    81,    83,    84,    85,    86,    87,
      88,    89,    90,   103,    21,    47,    75,    73,    76,    77,
      78,    25,    25,    32,    45,    49,    65,    93,    94,    95,
      96,    98,   100,   102,   103,    93,    93,    93,    93,    49,
       9,    80,    36,    51,   104,    64,    76,    48,    36,    49,
      25,    49,   103,    95,    93,    20,    44,    43,    31,    32,
      37,    38,    39,    40,    41,    42,    97,    99,    33,    34,
      35,   101,    48,    48,    48,     7,    91,    92,    93,    93,
      93,    14,    81,    64,    91,    49,    93,    50,    83,    94,
      95,    98,   100,   102,    83,    50,    46,    48,    52,    76,
       9,    21,    50,    91,    50,     8,     9,     9,    48,    93,
      70,    64,    50,    83,    13,     7,    25,     7,     9,    83,
      13,     9,     7
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    53,    55,    56,    54,    57,    58,    58,    60,    59,
      59,    62,    61,    61,    63,    61,    64,    64,    65,    65,
      65,    65,    65,    65,    65,    65,    65,    66,    66,    67,
      67,    69,    70,    68,    71,    71,    72,    72,    73,    74,
      74,    75,    75,    76,    76,    77,    77,    77,    77,    79,
      78,    80,    80,    80,    80,    80,    80,    80,    82,    81,
      83,    83,    84,    84,    85,    85,    85,    86,    87,    87,
      88,    89,    90,    91,    91,    92,    92,    93,    93,    94,
      94,    95,    95,    96,    96,    97,    97,    97,    97,    97,
      97,    98,    98,    99,    99,   100,   100,   101,   101,   101,
     102,   102,   102,   102,   102,   102,   102,   103,   103,   104
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     0,     7,     3,     1,     0,     0,     3,
       1,     0,     6,     5,     0,     6,     1,     1,     1,     2,
       1,     2,     1,     2,     1,     1,     1,     1,     0,     2,
       1,     0,     0,    11,     1,     0,     3,     1,     3,     3,
       1,     2,     0,     1,     1,     1,     1,     1,     1,     0,
       7,     1,     1,     1,     1,     1,     1,     1,     0,     5,
       1,     0,     2,     1,     4,     3,     3,     5,     8,     6,
       6,    10,     3,     1,     0,     3,     1,     3,     1,     3,
       1,     2,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     3,     1,     1,     1,     3,     1,     1,     1,     1,
       1,     2,     3,     4,     4,     5,     1,     1,     2,     3
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
#line 96 "parser.y" /* yacc.c:1646  */
    {
					//
					printf("1->");
					puts(yytext);
					strcpy(mysymbol_table[scope_depth].mysub_entry[sub_entry_cnt].name,yytext);
					printf("program name %s",mysymbol_table[0].mysub_entry[0].name);
					is_function=0;
					const_type=0;
				}
#line 1490 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 106 "parser.y" /* yacc.c:1646  */
    {
					mysymbol_table[0].mysub_entry[0].kind="program";
					strcpy(mysymbol_table[0].mysub_entry[0].level_str,"0(global)");
					mysymbol_table[0].mysub_entry[0].type="void";

					dumpsymbol();
				}
#line 1502 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 115 "parser.y" /* yacc.c:1646  */
    {
					pop_symbol_table();
					dumpsymbol();
			  	}
#line 1511 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 121 "parser.y" /* yacc.c:1646  */
    {printf("1->");}
#line 1517 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 124 "parser.y" /* yacc.c:1646  */
    {printf("2->");}
#line 1523 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 128 "parser.y" /* yacc.c:1646  */
    {printf("3->");}
#line 1529 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 129 "parser.y" /* yacc.c:1646  */
    {printf("4->");}
#line 1535 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 130 "parser.y" /* yacc.c:1646  */
    {printf("5->");}
#line 1541 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 135 "parser.y" /* yacc.c:1646  */
    {
				{printf("7->");}

				for(int i=pre_sub_entry_cnt;i<sub_entry_cnt;i++)
				{
					mysymbol_table[scope_depth].mysub_entry[i].kind="variable";
					char* ps_level;
					char depth_n[100];
					memset(depth_n,0,sizeof(depth_n));
					if(scope_depth)
					{
						depth_n[0]=scope_depth+'0';
						ps_level="(local)";
						strcat(depth_n,ps_level);
					}
					else
					{
						depth_n[0]='0';
						ps_level="(global)";
						strcat(depth_n,ps_level);
					}
					strcpy(mysymbol_table[scope_depth].mysub_entry[i].level_str,depth_n);
					printf("8888888888888888888888888 \n");
					mysymbol_table[scope_depth].mysub_entry[i].type=(yyvsp[0]);
					printf("8888888888888888888888888 \n");
				}
				pre_sub_entry_cnt=sub_entry_cnt; //update it for next segment
				error_detection();
				dumpsymbol();
			}
#line 1576 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 168 "parser.y" /* yacc.c:1646  */
    {
				{printf("9->");}

				for(int i=pre_sub_entry_cnt;i<sub_entry_cnt;i++)
				{
					mysymbol_table[scope_depth].mysub_entry[i].kind="variable";
					char* ps_level;
					char depth_n[100];
					memset(depth_n,0,sizeof(depth_n));
					if(scope_depth)
					{
						depth_n[0]=scope_depth+'0';
						ps_level="(local)";
						strcat(depth_n,ps_level);
					}
					else
					{
						depth_n[0]='0';
						ps_level="(global)";
						strcat(depth_n,ps_level);
					}
					strcpy(mysymbol_table[scope_depth].mysub_entry[i].level_str,depth_n);
					printf("arr buf %s \n",arr_buf);
					memset(reverse_arr_buf,0,sizeof(reverse_arr_buf));
					for(int i=49,j=0;i>=0;i--)
					{
						if(arr_buf[i]!=0)
						{
							reverse_arr_buf[j]='[';
							reverse_arr_buf[j+1]=arr_buf[i];
							reverse_arr_buf[j+2]=']';
							j+=3;
						}
					}
					strcat(mysymbol_table[scope_depth].mysub_entry[i].array_type_buf,reverse_arr_buf); //altogether using the sprintf to concatenate multiple strings

					mysymbol_table[scope_depth].mysub_entry[i].is_array_decl=true;
				}
				pre_sub_entry_cnt=sub_entry_cnt; //update it for next segment
				memset(arr_buf,0,sizeof(arr_buf));
				is_array=0;//end matching an array, turn off the flag
			}
#line 1623 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 211 "parser.y" /* yacc.c:1646  */
    {
				{printf("10->");}

				for(int i=pre_sub_entry_cnt;i<sub_entry_cnt;i++)
				{
					mysymbol_table[scope_depth].mysub_entry[i].kind="constant";
					char* ps_level;
					char depth_n[100];
					memset(depth_n,0,sizeof(depth_n));
					if(scope_depth)
					{
						depth_n[0]=scope_depth+'0';
						ps_level="(local)";
						strcat(depth_n,ps_level);
					}
					else
					{
						depth_n[0]='0';
						ps_level="(global)";
						strcat(depth_n,ps_level);
					}
					strcpy(mysymbol_table[scope_depth].mysub_entry[i].level_str,depth_n);
					assign_constant_type(scope_depth,i);
				}
				pre_sub_entry_cnt=sub_entry_cnt; //update it for next segment
				error_detection();
				dumpsymbol();
			}
#line 1656 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 242 "parser.y" /* yacc.c:1646  */
    {(yyval)=yytext;}
#line 1662 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 243 "parser.y" /* yacc.c:1646  */
    {(yyval)=yytext;}
#line 1668 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 246 "parser.y" /* yacc.c:1646  */
    {(yyval)=yytext; const_type=1; parse_constant();}
#line 1674 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 247 "parser.y" /* yacc.c:1646  */
    {(yyval)=yytext; const_type=2; parse_constant();}
#line 1680 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 248 "parser.y" /* yacc.c:1646  */
    {(yyval)=yytext; const_type=3; parse_constant();}
#line 1686 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 249 "parser.y" /* yacc.c:1646  */
    {(yyval)=yytext; const_type=4; parse_constant();}
#line 1692 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 250 "parser.y" /* yacc.c:1646  */
    {(yyval)=yytext; const_type=5; parse_constant();}
#line 1698 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 251 "parser.y" /* yacc.c:1646  */
    {(yyval)=yytext; const_type=6; parse_constant();}
#line 1704 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 252 "parser.y" /* yacc.c:1646  */
    {(yyval)=yytext; const_type=7; parse_constant();}
#line 1710 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 253 "parser.y" /* yacc.c:1646  */
    {(yyval)=yytext; const_type=8; parse_constant();}
#line 1716 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 254 "parser.y" /* yacc.c:1646  */
    {(yyval)=yytext; const_type=8; parse_constant();}
#line 1722 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 266 "parser.y" /* yacc.c:1646  */
    {
					{printf("11->");}
					scope_depth++;
					sub_entry_cnt=0;
					pre_sub_entry_cnt=0;
					printf("compound_stmt begin\n");
					is_function=1;

				}
#line 1736 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 278 "parser.y" /* yacc.c:1646  */
    {
					//scope_depth--;
					{printf("12->");}
					for(int i=0;i<SUB_ENTRY_SIZE;i++)
					{
						//find the fucking parameter
						if(mysymbol_table[1].mysub_entry[i].kind=="parameter")
						{
							if(mysymbol_table[1].mysub_entry[i].is_array_decl)
							{
								strcat(mysymbol_table[0].mysub_entry[sub_entry_cnt].attri_type_buf,arr_buf);
							}
							else
							{
								strcat(mysymbol_table[0].mysub_entry[sub_entry_cnt].attri_type_buf,(yyvsp[-4]));
							}
						}
					}
					pop_symbol_table();
					dumpsymbol();
				}
#line 1762 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 311 "parser.y" /* yacc.c:1646  */
    {
				param_or_decl=1;

				{printf("13->");}

				for(int i=pre_sub_entry_cnt;i<sub_entry_cnt;i++)
				{
					mysymbol_table[scope_depth].mysub_entry[i].kind="parameter";
					printf("i is now %d and name %s\n",i,mysymbol_table[scope_depth].mysub_entry[i].name);
					char* ps_level;
					char depth_n[100];
					memset(depth_n,0,sizeof(depth_n));
					if(scope_depth)
					{
						depth_n[0]=scope_depth+'0';
						ps_level="(local)";
						strcat(depth_n,ps_level);
						printf("Depth n %s \n",depth_n);
					}
					strcpy(mysymbol_table[scope_depth].mysub_entry[i].level_str,depth_n);
					if(is_array)
					{
						printf("Found an array parameter passed in \n");
						printf("arr buf %s \n",arr_buf);
						memset(reverse_arr_buf,0,sizeof(reverse_arr_buf));
						for(int i=49,j=0;i>=0;i--)
						{
							if(arr_buf[i]!=0)
							{
								reverse_arr_buf[j]='[';
								reverse_arr_buf[j+1]=arr_buf[i];
								reverse_arr_buf[j+2]=']';
								j+=3;
							}
						}
						strcat(mysymbol_table[scope_depth].mysub_entry[i].array_type_buf,reverse_arr_buf);
						mysymbol_table[scope_depth].mysub_entry[i].is_array_decl=true;
					}
					else
					{
						mysymbol_table[scope_depth].mysub_entry[i].type=(yyvsp[0]);
					}
				}
				pre_sub_entry_cnt=sub_entry_cnt; //update it for next segment
				printf("parsing parameter done dump symbol table\n");
				memset(arr_buf,0,sizeof(arr_buf));
				dumpsymbol();
			}
#line 1815 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 362 "parser.y" /* yacc.c:1646  */
    {
				{printf("14->");}
				printf("ID is %s",yytext);
				strcpy(mysymbol_table[scope_depth].mysub_entry[sub_entry_cnt].name,yytext);
				(yyval)=yytext;
				printf(" AND PASSED IN ID NAME %s \n",mysymbol_table[scope_depth].mysub_entry[sub_entry_cnt].name);
				sub_entry_cnt++;

				dumpsymbol();
			}
#line 1830 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 373 "parser.y" /* yacc.c:1646  */
    {

				{printf("15->");}
				printf("ID is %s",yytext);
				strcpy(mysymbol_table[scope_depth].mysub_entry[sub_entry_cnt].name,yytext);
				(yyval)=yytext;
				printf(" AND PASSED IN ID NAME %s \n",mysymbol_table[scope_depth].mysub_entry[sub_entry_cnt].name);
				sub_entry_cnt++;

				dumpsymbol();
			}
#line 1846 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 390 "parser.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1852 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 391 "parser.y" /* yacc.c:1646  */
    {(yyval)=(yyvsp[0]);}
#line 1858 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 395 "parser.y" /* yacc.c:1646  */
    {
				{printf("16->");}
				printf("TYPE is %s",yytext);
				(yyval)="integer";
				if(is_array)
				{
					for(int i=pre_sub_entry_cnt;i<sub_entry_cnt;i++)
					{
						strcat(mysymbol_table[scope_depth].mysub_entry[i].array_type_buf,"integer ");
					}
				}
				printf("match $$:%s \n",(yyval));
			}
#line 1876 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 409 "parser.y" /* yacc.c:1646  */
    {
				{printf("17->");}
				printf("TYPE is %s",yytext);
				(yyval)="real";
				if(is_array)
				{
					for(int i=pre_sub_entry_cnt;i<sub_entry_cnt;i++)
					{
						strcat(mysymbol_table[scope_depth].mysub_entry[i].array_type_buf,"real ");
					}
				}
			}
#line 1893 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 422 "parser.y" /* yacc.c:1646  */
    {
				{printf("18->");}
				printf("TYPE is %s",yytext);
				(yyval)="boolean";
				if(is_array)
				{
					for(int i=pre_sub_entry_cnt;i<sub_entry_cnt;i++)
					{
						strcat(mysymbol_table[scope_depth].mysub_entry[i].array_type_buf,"boolean ");
					}
				}
			}
#line 1910 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 435 "parser.y" /* yacc.c:1646  */
    {
				{printf("19->");}
				printf("TYPE is %s",yytext);
				(yyval)="string";
				if(is_array)
				{
					for(int i=pre_sub_entry_cnt;i<sub_entry_cnt;i++)
					{
						strcat(mysymbol_table[scope_depth].mysub_entry[i].array_type_buf,"string ");
					}
				}
			}
#line 1927 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 450 "parser.y" /* yacc.c:1646  */
    {
				{printf("20->");}
				is_array=1;
			}
#line 1936 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 455 "parser.y" /* yacc.c:1646  */
    {
				{printf("21->");}

				int delta=atol((yyvsp[-2]))-atol((yyvsp[-4]))+1;
				char tmp[10];
				printf("\narray dim FROM %s to %s delta is %d\n",(yyvsp[-4]),(yyvsp[-2]),delta);
				sprintf(tmp,"%d",delta);
				strcat(arr_buf,tmp);
				printf("Array buf %s \n",arr_buf);
			}
#line 1951 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 477 "parser.y" /* yacc.c:1646  */
    {
					{printf("22->");}
					if(!is_function)
					{
						sub_entry_cnt=0;
						pre_sub_entry_cnt=0;
						scope_depth++;
					}
					is_function=0;
					printf("compound_stmt begin\n");

				}
#line 1968 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 492 "parser.y" /* yacc.c:1646  */
    {
					{printf("23->");}
					printf("compound_stmt end\n");

					pop_symbol_table();
					dumpsymbol();
				}
#line 1980 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1984 "y.tab.c" /* yacc.c:1646  */
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
#line 603 "parser.y" /* yacc.c:1906  */


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
