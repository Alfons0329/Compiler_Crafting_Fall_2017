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
 $$ yylaval
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
char funct_type_buf_parser[BUF_SIZE];
char funct_attri_buf[BUF_SIZE];
extern int yylex(void);
extern int Opt_D; /* declared in lex.l */
extern int linenum;		/* declared in lex.l */

int yyerror(char* );
//0 not constant, 1 int 2 -int  3 float 4 -float 5 scientific 6 -scientific 7 string 8 bool 9 OCTAL 10 -OCTAL


#line 97 "y.tab.c" /* yacc.c:339  */

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

union YYSTYPE
{
#line 34 "parser.y" /* yacc.c:355  */

    char* parsed_string;

#line 245 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 262 "y.tab.c" /* yacc.c:358  */

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
#define YYLAST   192

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  55
/* YYNRULES -- Number of rules.  */
#define YYNRULES  112
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  196

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
       0,    99,    99,   110,    98,   124,   127,   128,   131,   133,
     138,   136,   183,   235,   234,   281,   282,   285,   286,   287,
     288,   289,   290,   291,   292,   293,   296,   297,   300,   301,
     305,   322,   328,   361,   304,   370,   371,   374,   375,   378,
     421,   439,   460,   461,   464,   465,   468,   474,   481,   488,
     498,   497,   516,   517,   518,   519,   520,   521,   522,   526,
     544,   525,   576,   577,   580,   581,   584,   585,   586,   589,
     592,   597,   600,   606,   605,   623,   626,   627,   630,   631,
     634,   635,   638,   639,   642,   643,   646,   647,   650,   651,
     652,   653,   654,   655,   658,   659,   662,   663,   666,   667,
     670,   671,   672,   675,   676,   677,   678,   679,   680,   681,
     684,   685,   688
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
  "opt_decl_list", "decl_list", "decl", "$@3", "$@4", "int_const",
  "literal_const", "opt_func_decl_list", "func_decl_list", "func_decl",
  "$@5", "$@6", "$@7", "$@8", "opt_param_list", "param_list", "param",
  "id_list", "opt_type", "type", "scalar_type", "array_type", "$@9",
  "stmt", "compound_stmt", "$@10", "$@11", "opt_stmt_list", "stmt_list",
  "simple_stmt", "proc_call_stmt", "cond_stmt", "while_stmt", "for_stmt",
  "$@12", "return_stmt", "opt_boolean_expr_list", "boolean_expr_list",
  "boolean_expr", "boolean_term", "boolean_factor", "relop_expr", "rel_op",
  "expr", "add_op", "term", "mul_op", "factor", "var_ref", "dim", YY_NULLPTR
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

#define YYPACT_NINF -115

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-115)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -10,  -115,    32,   -14,  -115,  -115,    34,    49,    55,    77,
      34,  -115,  -115,   -22,    87,  -115,   100,    77,  -115,  -115,
      88,    79,  -115,    61,  -115,  -115,  -115,  -115,  -115,  -115,
    -115,  -115,  -115,  -115,  -115,  -115,  -115,  -115,  -115,  -115,
      51,  -115,  -115,  -115,    80,    49,    34,     1,  -115,  -115,
    -115,    83,    89,  -115,    76,    97,  -115,    39,   114,   112,
    -115,  -115,  -115,    49,    78,   110,    43,    43,    43,    43,
      43,    94,  -115,  -115,  -115,   114,  -115,  -115,  -115,  -115,
    -115,  -115,   -20,     1,   105,  -115,  -115,  -115,  -115,  -115,
     104,    95,    43,    43,  -115,    -2,    93,  -115,  -115,   109,
      82,  -115,   106,     7,    10,    15,     6,    43,   146,  -115,
      43,    43,  -115,   142,    78,   111,   122,    43,   113,    43,
     106,  -115,   -27,   114,    43,    43,  -115,  -115,  -115,  -115,
    -115,  -115,  -115,  -115,    11,    11,  -115,  -115,  -115,    11,
    -115,  -115,  -115,   114,   115,   117,   116,  -115,    18,   -30,
      78,  -115,  -115,     1,   118,    43,   -24,  -115,    85,    93,
    -115,    68,    82,  -115,   152,   119,    43,  -115,  -115,  -115,
     100,   143,  -115,   120,  -115,   114,   153,   162,  -115,   116,
     163,     1,  -115,   164,  -115,  -115,  -115,   167,   158,   150,
     114,  -115,  -115,   168,   169,  -115
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     2,     0,     0,     1,     3,     7,     0,     0,    27,
       6,     9,    41,     0,     0,    30,     0,    26,    29,     8,
       0,     0,     4,     0,    59,     5,    28,    40,    50,    48,
      25,    46,    47,    49,    24,    16,    15,    19,    21,    23,
       0,    17,    13,    10,     0,    36,     7,     0,    20,    22,
      18,     0,     0,    12,     0,    35,    38,     0,    63,     0,
      14,    11,    31,     0,     0,     0,     0,     0,     0,     0,
       0,   110,    65,    52,    60,    62,    53,    58,    54,    55,
      56,    57,     0,     0,    43,    37,    39,    44,    45,    73,
     110,     0,     0,     0,   109,     0,    81,    83,    85,    87,
      95,    99,   103,     0,     0,     0,     0,    77,     0,    64,
       0,     0,   111,     0,     0,     0,     0,    77,   110,     0,
     104,    84,     0,    63,     0,     0,    96,    97,    90,    93,
      92,    88,    91,    89,     0,     0,   100,   101,   102,     0,
      67,    68,    75,    63,     0,    76,    79,    61,     0,     0,
       0,    42,    32,     0,     0,    77,     0,   105,     0,    80,
      82,    86,    94,    98,     0,     0,     0,    66,   112,    51,
       0,     0,   107,     0,   106,    63,     0,     0,    69,    78,
       0,     0,   108,     0,    71,    72,    33,     0,     0,     0,
      63,    70,    34,     0,     0,    74
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -115,  -115,  -115,  -115,  -115,   132,  -115,   170,  -115,  -115,
     -39,   160,  -115,  -115,   165,  -115,  -115,  -115,  -115,  -115,
    -115,   121,   172,  -115,  -104,   166,   171,  -115,   108,   -16,
    -115,  -115,  -114,  -115,  -115,  -115,  -115,  -115,  -115,  -115,
    -115,  -106,  -115,   -63,    62,   -80,  -115,  -115,    54,  -115,
      50,  -115,    52,   -56,  -115
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     6,     8,     9,    10,    11,    52,    51,
      41,    94,    16,    17,    18,    23,    84,   170,   189,    54,
      55,    56,    57,   115,    86,    87,    88,    47,    72,    73,
      46,   108,    74,    75,    76,    77,    78,    79,    80,   116,
      81,   144,   145,   146,    96,    97,    98,   134,    99,   135,
     100,   139,   101,   102,   112
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      25,    50,    82,    95,   103,   104,   105,   106,    59,   158,
     151,   154,   121,   143,   124,     1,   110,   124,   123,    82,
     124,    30,   168,   157,    20,    21,   174,    35,    36,   164,
     122,   111,     4,    34,     5,   120,    90,    35,    36,    37,
      38,    39,   124,    91,   113,   160,   169,   148,   149,   173,
     124,   124,    50,    30,   124,   140,   156,     7,   141,   124,
      93,   183,   124,   142,    14,    34,   167,    82,    90,    35,
      36,    37,    38,    39,    12,    91,   193,    35,    36,    48,
      49,    28,    28,    29,    29,    20,    64,    82,    92,    30,
      31,    31,    93,   175,   176,    32,    32,    33,    33,   126,
     127,    34,    15,   179,    24,    35,    36,    37,    38,    39,
      45,    40,    22,    27,   171,   136,   137,   138,    24,    82,
     118,    35,    36,    48,    49,    65,    62,    66,    53,    67,
      68,    60,    69,    83,    82,    89,   125,    61,    70,    71,
     126,   127,   187,   107,   119,    63,   128,   129,   130,   131,
     132,   133,   114,   117,   180,   147,   150,   111,   153,   152,
     124,   177,   155,   166,   181,   165,   184,   178,   172,   185,
     182,   191,   186,   188,   190,   192,   195,   194,    58,    13,
      19,    42,    26,   109,    85,   162,   159,    43,   161,     0,
       0,   163,    44
};

static const yytype_int16 yycheck[] =
{
      16,    40,    58,    66,    67,    68,    69,    70,    47,   123,
     114,   117,    92,     7,    44,    25,    36,    44,    20,    75,
      44,    10,    52,    50,    46,    47,    50,    26,    27,   143,
      93,    51,     0,    22,    48,    91,    25,    26,    27,    28,
      29,    30,    44,    32,    83,   125,   150,   110,   111,   155,
      44,    44,    91,    10,    44,    48,   119,    23,    48,    44,
      49,   175,    44,    48,     9,    22,    48,   123,    25,    26,
      27,    28,    29,    30,    25,    32,   190,    26,    27,    28,
      29,     3,     3,     5,     5,    46,    47,   143,    45,    10,
      12,    12,    49,     8,     9,    17,    17,    19,    19,    31,
      32,    22,    25,   166,     4,    26,    27,    28,    29,    30,
      49,    32,    25,    25,   153,    33,    34,    35,     4,   175,
      25,    26,    27,    28,    29,    11,    50,    13,    48,    15,
      16,    48,    18,    21,   190,    25,    43,    48,    24,    25,
      31,    32,   181,    49,    49,    48,    37,    38,    39,    40,
      41,    42,    47,    49,   170,     9,    14,    51,    36,    48,
      44,     9,    49,    46,    21,    50,    13,    48,    50,     7,
      50,    13,     9,     9,     7,    25,     7,     9,    46,     7,
      10,    21,    17,    75,    63,   135,   124,    21,   134,    -1,
      -1,   139,    21
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    25,    54,    55,     0,    48,    56,    23,    57,    58,
      59,    60,    25,    75,     9,    25,    65,    66,    67,    60,
      46,    47,    25,    68,     4,    82,    67,    25,     3,     5,
      10,    12,    17,    19,    22,    26,    27,    28,    29,    30,
      32,    63,    64,    78,    79,    49,    83,    80,    28,    29,
      63,    62,    61,    48,    72,    73,    74,    75,    58,    63,
      48,    48,    50,    48,    47,    11,    13,    15,    16,    18,
      24,    25,    81,    82,    85,    86,    87,    88,    89,    90,
      91,    93,   106,    21,    69,    74,    77,    78,    79,    25,
      25,    32,    45,    49,    64,    96,    97,    98,    99,   101,
     103,   105,   106,    96,    96,    96,    96,    49,    84,    81,
      36,    51,   107,    63,    47,    76,    92,    49,    25,    49,
     106,    98,    96,    20,    44,    43,    31,    32,    37,    38,
      39,    40,    41,    42,   100,   102,    33,    34,    35,   104,
      48,    48,    48,     7,    94,    95,    96,     9,    96,    96,
      14,    77,    48,    36,    94,    49,    96,    50,    85,    97,
      98,   101,   103,   105,    85,    50,    46,    48,    52,    77,
      70,    63,    50,    94,    50,     8,     9,     9,    48,    96,
      82,    21,    50,    85,    13,     7,     9,    63,     9,    71,
       7,    13,    25,    85,     9,     7
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    53,    55,    56,    54,    57,    58,    58,    59,    59,
      61,    60,    60,    62,    60,    63,    63,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    65,    65,    66,    66,
      68,    69,    70,    71,    67,    72,    72,    73,    73,    74,
      75,    75,    76,    76,    77,    77,    78,    78,    78,    78,
      80,    79,    81,    81,    81,    81,    81,    81,    81,    83,
      84,    82,    85,    85,    86,    86,    87,    87,    87,    88,
      89,    89,    90,    92,    91,    93,    94,    94,    95,    95,
      96,    96,    97,    97,    98,    98,    99,    99,   100,   100,
     100,   100,   100,   100,   101,   101,   102,   102,   103,   103,
     104,   104,   104,   105,   105,   105,   105,   105,   105,   105,
     106,   106,   107
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     0,     7,     3,     1,     0,     2,     1,
       0,     6,     5,     0,     6,     1,     1,     1,     2,     1,
       2,     1,     2,     1,     1,     1,     1,     0,     2,     1,
       0,     0,     0,     0,    13,     1,     0,     3,     1,     3,
       3,     1,     2,     0,     1,     1,     1,     1,     1,     1,
       0,     7,     1,     1,     1,     1,     1,     1,     1,     0,
       0,     6,     1,     0,     2,     1,     4,     3,     3,     5,
       8,     6,     6,     0,    11,     3,     1,     0,     3,     1,
       3,     1,     3,     1,     2,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     1,     1,     3,     1,
       1,     1,     1,     1,     2,     3,     4,     4,     5,     1,
       1,     2,     3
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
#line 99 "parser.y" /* yacc.c:1646  */
    {
					strcpy(mysymbol_table[scope_depth].mysub_entry[sub_entry_cnt].name,yytext);
					//printf("program name %s",mysymbol_table[0].mysub_entry[0].name);
					global_sub_entry_cnt=1;
					global_pre_sub_entry_cnt=global_sub_entry_cnt;
					is_array = 0;
					is_function=0;
					is_loop=0;
					const_type=0;
				}
#line 1499 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 110 "parser.y" /* yacc.c:1646  */
    {
					strcpy(mysymbol_table[0].mysub_entry[0].kind,"program");
					strcpy(mysymbol_table[0].mysub_entry[0].level_str,"0(global)");
					strcpy(mysymbol_table[0].mysub_entry[0].type,"void");
				}
#line 1509 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 117 "parser.y" /* yacc.c:1646  */
    {
					error_detection();
					dumpsymbol();
					pop_symbol_table();
			  	}
#line 1519 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 138 "parser.y" /* yacc.c:1646  */
    {
				//printf("7->");}
				if(scope_depth==0) //global declaration
				{
					for(int i=global_pre_sub_entry_cnt;i<global_sub_entry_cnt;i++)
					{
						strcpy(mysymbol_table[scope_depth].mysub_entry[i].kind,"variable");
						char* ps_level;
						char depth_n[100];
						memset(depth_n,0,sizeof(depth_n));

						depth_n[0]='0';
						ps_level="(global)";
						strcat(depth_n,ps_level);

						strcpy(mysymbol_table[scope_depth].mysub_entry[i].level_str,depth_n);
						strcpy(mysymbol_table[scope_depth].mysub_entry[i].type,(yyvsp[0].parsed_string));
					}
					global_pre_sub_entry_cnt=global_sub_entry_cnt; //update it for next segment
					error_detection();
					//dumpsymbol();
				}
				else //non global declaration
				{
					for(int i=pre_sub_entry_cnt;i<sub_entry_cnt;i++)
					{
						strcpy(mysymbol_table[scope_depth].mysub_entry[i].kind,"variable");
						char* ps_level;
						char depth_n[100];
						memset(depth_n,0,sizeof(depth_n));

						depth_n[0]=scope_depth+'0';
						ps_level="(local)";
						strcat(depth_n,ps_level);

						strcpy(mysymbol_table[scope_depth].mysub_entry[i].level_str,depth_n);
						strcpy(mysymbol_table[scope_depth].mysub_entry[i].type,(yyvsp[0].parsed_string));
					}
					pre_sub_entry_cnt=sub_entry_cnt; //update it for next segment
					error_detection();
					//dumpsymbol();
				}

			}
#line 1568 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 185 "parser.y" /* yacc.c:1646  */
    {
				//printf("9->");}
				if(scope_depth==0) //global declaration
				{
					for(int i=global_pre_sub_entry_cnt;i<global_sub_entry_cnt;i++)
					{
						strcpy(mysymbol_table[scope_depth].mysub_entry[i].kind,"variable");
						char* ps_level;
						char depth_n[100];
						memset(depth_n,0,sizeof(depth_n));

						depth_n[0]='0';
						ps_level="(global)";
						strcat(depth_n,ps_level);
						strcpy(mysymbol_table[scope_depth].mysub_entry[i].level_str,depth_n);
						//printf("arr buf %s and table arr type buf %s\n",arr_buf,mysymbol_table[scope_depth].mysub_entry[i].array_type_buf);
						array_dimension_parser();
						strcat(mysymbol_table[scope_depth].mysub_entry[i].array_type_buf,reverse_arr_buf); //altogether using the s//printf to concatenate multiple strings
						mysymbol_table[scope_depth].mysub_entry[i].is_array_decl=true;
					}
					global_pre_sub_entry_cnt=global_sub_entry_cnt;
					error_detection();
				}
				else //non global declaration
				{
					for(int i=pre_sub_entry_cnt;i<sub_entry_cnt;i++)
					{
						strcpy(mysymbol_table[scope_depth].mysub_entry[i].kind,"variable");
						char* ps_level;
						char depth_n[100];
						memset(depth_n,0,sizeof(depth_n));

						depth_n[0]=scope_depth+'0';
						ps_level="(local)";
						strcat(depth_n,ps_level);
						strcpy(mysymbol_table[scope_depth].mysub_entry[i].level_str,depth_n);
						//printf("arr buf %s and table arr type buf %s\n",arr_buf,mysymbol_table[scope_depth].mysub_entry[i].array_type_buf);
						array_dimension_parser();
						strcat(mysymbol_table[scope_depth].mysub_entry[i].array_type_buf,reverse_arr_buf); //altogether using the s//printf to concatenate multiple strings
						mysymbol_table[scope_depth].mysub_entry[i].is_array_decl=true;
					}
					pre_sub_entry_cnt=sub_entry_cnt;
					error_detection();
				}
				 //update it for next segment
				memset(arr_buf,0,sizeof(arr_buf));
				is_array=0;//end matching an array, turn off the flag

			}
#line 1622 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 235 "parser.y" /* yacc.c:1646  */
    {
				//printf("10->");}
				if(scope_depth==0) //global declaration
				{
					for(int i=global_pre_sub_entry_cnt;i<global_sub_entry_cnt;i++)
					{
						strcpy(mysymbol_table[scope_depth].mysub_entry[i].kind,"constant");
						char* ps_level;
						char depth_n[100];
						memset(depth_n,0,sizeof(depth_n));

						depth_n[0]='0';
						ps_level="(global)";
						strcat(depth_n,ps_level);

						strcpy(mysymbol_table[scope_depth].mysub_entry[i].level_str,depth_n);
						assign_constant_type(scope_depth,i);
					}
					global_pre_sub_entry_cnt=global_sub_entry_cnt; //update it for next segment
					error_detection();
					//dumpsymbol();
				}
				else //non-global declaration
				{
					for(int i=pre_sub_entry_cnt;i<sub_entry_cnt;i++)
					{
						strcpy(mysymbol_table[scope_depth].mysub_entry[i].kind,"constant");
						char* ps_level;
						char depth_n[100];
						memset(depth_n,0,sizeof(depth_n));

						depth_n[0]=scope_depth+'0';
						ps_level="(local)";
						strcat(depth_n,ps_level);

						strcpy(mysymbol_table[scope_depth].mysub_entry[i].level_str,depth_n);
						assign_constant_type(scope_depth,i);
					}
					pre_sub_entry_cnt=sub_entry_cnt; //update it for next segment
					error_detection();
					//dumpsymbol();
				}
			}
#line 1670 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 281 "parser.y" /* yacc.c:1646  */
    {(yyval.parsed_string)=yytext; const_type=1;}
#line 1676 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 282 "parser.y" /* yacc.c:1646  */
    {(yyval.parsed_string)=yytext; const_type=9;}
#line 1682 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 285 "parser.y" /* yacc.c:1646  */
    {(yyval.parsed_string)=yytext; const_type=(const_type==1)?1:9; parse_constant();}
#line 1688 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 286 "parser.y" /* yacc.c:1646  */
    {(yyval.parsed_string)=yytext; const_type=(const_type==1)?2:10; parse_constant();}
#line 1694 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 287 "parser.y" /* yacc.c:1646  */
    {(yyval.parsed_string)=yytext; const_type=3; parse_constant();}
#line 1700 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 288 "parser.y" /* yacc.c:1646  */
    {(yyval.parsed_string)=yytext; const_type=4; parse_constant();}
#line 1706 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 289 "parser.y" /* yacc.c:1646  */
    {(yyval.parsed_string)=yytext; const_type=5; parse_constant();}
#line 1712 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 290 "parser.y" /* yacc.c:1646  */
    {(yyval.parsed_string)=yytext; const_type=6; parse_constant();}
#line 1718 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 291 "parser.y" /* yacc.c:1646  */
    {(yyval.parsed_string)=yytext; const_type=7; parse_constant();}
#line 1724 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 292 "parser.y" /* yacc.c:1646  */
    {(yyval.parsed_string)=yytext; const_type=8; parse_constant();}
#line 1730 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 293 "parser.y" /* yacc.c:1646  */
    {(yyval.parsed_string)=yytext; const_type=8; parse_constant();}
#line 1736 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 305 "parser.y" /* yacc.c:1646  */
    {
					//printf("11->");}
					sub_entry_cnt=0;
					pre_sub_entry_cnt=0;


					strcat(mysymbol_table[0].mysub_entry[global_sub_entry_cnt].name,yytext);
					strcpy(mysymbol_table[0].mysub_entry[global_sub_entry_cnt].kind,"function");
					strcpy(mysymbol_table[0].mysub_entry[global_sub_entry_cnt].level_str,"0(global)");
					//printf("Global entry count %d \n",global_sub_entry_cnt);
					mysymbol_table[0].mysub_entry[global_sub_entry_cnt].is_funct_decl=1;
					//memset(funct_type_buf_parser,0,sizeof(funct_type_buf_parser));
					memset(funct_attri_buf,0,sizeof(funct_attri_buf));
                    error_detection();
					scope_depth+=1;
				}
#line 1757 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 322 "parser.y" /* yacc.c:1646  */
    {
					is_function=1;
					scope_depth-=1;
					global_sub_entry_cnt++;
				}
#line 1767 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 328 "parser.y" /* yacc.c:1646  */
    {
					//is_function=1 here will be better
					//setting the function type
					if(is_array)
					{
						array_dimension_parser();
						strcat(mysymbol_table[0].mysub_entry[global_sub_entry_cnt-1].funct_type_buf,reverse_arr_buf);
					}
					memset(funct_attri_buf,0,sizeof(funct_attri_buf));
					for(int i=0;i<SUB_ENTRY_SIZE;i++)
					{
						if(strcmp(mysymbol_table[1].mysub_entry[i].kind,"parameter")==0&&(mysymbol_table[1].mysub_entry[i].name[0]!=0))
						{
							if(mysymbol_table[1].mysub_entry[i].is_array_decl)
							{
								strcat(funct_attri_buf,mysymbol_table[1].mysub_entry[i].array_type_buf);
								strcat(funct_attri_buf,","); //for indentation
							}
							else
							{
								strcat(funct_attri_buf,mysymbol_table[1].mysub_entry[i].type);
							    strcat(funct_attri_buf,","); //for indentation
							}
						}
					}
					//setting the function attribute(parameter which passed in)
					strcat(mysymbol_table[0].mysub_entry[global_sub_entry_cnt-1].attri_type_buf,funct_attri_buf);
					global_pre_sub_entry_cnt=global_sub_entry_cnt;
					is_array=0;
					 //global function end by 1
				}
#line 1803 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 361 "parser.y" /* yacc.c:1646  */
    {
					//printf("12->");}
					//set the function attribute and type after all declared
					/*pop_symbol_table(); //function pop itself*/
					is_function=0;
				}
#line 1814 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 379 "parser.y" /* yacc.c:1646  */
    {
				//printf("13->");}

				for(int i=pre_sub_entry_cnt;i<sub_entry_cnt;i++)
				{
					strcpy(mysymbol_table[scope_depth].mysub_entry[i].kind,"parameter");
					//printf("i is now %d and name %s\n",i,mysymbol_table[scope_depth].mysub_entry[i].name);
					char* ps_level;
					char depth_n[100];
					memset(depth_n,0,sizeof(depth_n));
					if(scope_depth)
					{
						depth_n[0]=scope_depth+'0';
						ps_level="(local)";
						strcat(depth_n,ps_level);
						//printf("Depth n %s \n",depth_n);
					}
					strcpy(mysymbol_table[scope_depth].mysub_entry[i].level_str,depth_n);
					if(is_array)
					{
						array_dimension_parser();
						if(error_detection()==0)
						{
							strcat(mysymbol_table[scope_depth].mysub_entry[i].array_type_buf,reverse_arr_buf);
							mysymbol_table[scope_depth].mysub_entry[i].is_array_decl=true;
						}
					}
					else
					{
						if(error_detection()==0)
						{
							strcpy(mysymbol_table[scope_depth].mysub_entry[i].type,(yyvsp[0].parsed_string));
						}
					}
				}
				pre_sub_entry_cnt=sub_entry_cnt; //update it for next segment
				//printf("parsing parameter done dump symbol table\n");
				memset(arr_buf,0,sizeof(arr_buf));
				is_array=0;
			}
#line 1859 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 422 "parser.y" /* yacc.c:1646  */
    {
				//printf("14->");}
				//printf("ID is %s",yytext);
				if(scope_depth==0) //global declaration
				{
					strcpy(mysymbol_table[0].mysub_entry[global_sub_entry_cnt].name,yytext);
					global_sub_entry_cnt++;
				}
				else //non global declaration
				{
					strcpy(mysymbol_table[scope_depth].mysub_entry[sub_entry_cnt].name,yytext);
					sub_entry_cnt++;
				}
				(yyval.parsed_string)=yytext;
				//printf(" AND PASSED IN ID NAME %s \n",mysymbol_table[scope_depth].mysub_entry[sub_entry_cnt].name);
				//dumpsymbol();
			}
#line 1881 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 440 "parser.y" /* yacc.c:1646  */
    {

				//printf("15->");}
				//printf("ID is %s",yytext);
				if(scope_depth==0) //global declaration
				{
					strcpy(mysymbol_table[0].mysub_entry[global_sub_entry_cnt].name,yytext);
					global_sub_entry_cnt++;
				}
				else //non global declaration
				{
					strcpy(mysymbol_table[scope_depth].mysub_entry[sub_entry_cnt].name,yytext);
					sub_entry_cnt++;
				}
				(yyval.parsed_string)=yytext;
				//printf(" AND PASSED IN ID NAME %s \n",mysymbol_table[scope_depth].mysub_entry[sub_entry_cnt].name);
				//dumpsymbol();
			}
#line 1904 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 464 "parser.y" /* yacc.c:1646  */
    {(yyval.parsed_string)=(yyvsp[0].parsed_string);}
#line 1910 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 465 "parser.y" /* yacc.c:1646  */
    {(yyval.parsed_string)=(yyvsp[0].parsed_string);}
#line 1916 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 469 "parser.y" /* yacc.c:1646  */
    {
				//printf("16->");}
				(yyval.parsed_string)="integer ";
				assign_scalar_type("integer ");
			}
#line 1926 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 475 "parser.y" /* yacc.c:1646  */
    {
				//printf("17->");}
				//printf("TYPE is %s",yytext);
				(yyval.parsed_string)="real ";
				assign_scalar_type("real ");
			}
#line 1937 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 482 "parser.y" /* yacc.c:1646  */
    {
				//printf("18->");}
				//printf("TYPE is %s",yytext);
				(yyval.parsed_string)="boolean ";
				assign_scalar_type("boolean ");
			}
#line 1948 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 489 "parser.y" /* yacc.c:1646  */
    {
				//printf("19->");}
				//printf("TYPE is %s",yytext);
				(yyval.parsed_string)="string ";
				assign_scalar_type("string ");
			}
#line 1959 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 498 "parser.y" /* yacc.c:1646  */
    {
				//printf("20->");}
				is_array=1;
			}
#line 1968 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 503 "parser.y" /* yacc.c:1646  */
    {
				//printf("21->");}

				int delta=atol((yyvsp[-2].parsed_string))-atol((yyvsp[-4].parsed_string))+1;
				char tmp[10];
				//printf("\narray dim FROM %s to %s delta is %d\n",$3,$5,delta);
				sprintf(tmp,"%d",delta);
				strcat(arr_buf,tmp);
				strcat(arr_buf,",");
				//printf("Array buf %s \n",arr_buf);
			}
#line 1984 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 526 "parser.y" /* yacc.c:1646  */
    {
					//printf("22->");}
					if(scope_depth==0&&is_function)
					{
						scope_depth++;
					}
					else
					{
						scope_depth++;
						sub_entry_cnt=0;
						pre_sub_entry_cnt=0;
					}
					//printf("compound_stmt begin\n");
					//printf("Scope depth %d, pre_sub_entry_cnt %d sub_entry_cnt %d \n",scope_depth,pre_sub_entry_cnt,sub_entry_cnt);

				}
#line 2005 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 544 "parser.y" /* yacc.c:1646  */
    {
					//printf("23->");}
					//printf("compound_stmt end\n");
					//printf("Scope depth %d, pre_sub_entry_cnt %d sub_entry_cnt %d \n",scope_depth,pre_sub_entry_cnt,sub_entry_cnt);
					if(is_function&&scope_depth>1) //prevernt double popping
					{
						//printf("pop type 1 function controller is '%d' \n",is_function);
						//error_detection();
						dumpsymbol();
						pop_symbol_table();
					}
					else if(!is_loop)/*if(!is_function) *///normal like
					{
						//printf("pop type 1 function controller is '%d' \n",is_function);
						//error_detection();
						dumpsymbol();
						pop_symbol_table();
					}
					/*
					begin
					    var a: integer;
					    begin
					        var a: boolean;
					    end
					// outer ’a’ has been hidden in this scope
					end just directly popping, rather than waiting till the end test!
					*/
				}
#line 2038 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 606 "parser.y" /* yacc.c:1646  */
    {
					strcpy(myiter_table[iterator_cnt].iterator_name,yytext);
					myiter_table[iterator_cnt].iterator_level=scope_depth+1;
					//printf("Loop scope depth %d and name %s\n",scope_depth,yytext);
					error_detection();
					//dumpiterator();
					iterator_cnt++;
					is_loop=1;
				}
#line 2052 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 618 "parser.y" /* yacc.c:1646  */
    {
					is_loop=0;
				}
#line 2060 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2064 "y.tab.c" /* yacc.c:1646  */
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
#line 691 "parser.y" /* yacc.c:1906  */


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
