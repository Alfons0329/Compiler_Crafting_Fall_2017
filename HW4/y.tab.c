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
#include <bits/stdc++.h>
#include "symboltable.h"
#define pb push_back
#define BUF_SIZE 50
//C++ working
extern "C" int yylex(void);
extern FILE *yyin;		/* declared by lex */
extern char *yytext;	/* declared by lex */
extern char *buf;	/* declared in lex.l */
extern int Opt_D; /* declared in lex.l */
extern int linenum;	/* declared in lex.l */
int yyerror(const char*);

//some global variables that needed in the parsing procedure
char arr_buf[BUF_SIZE];
char reverse_arr_buf[BUF_SIZE];
string const_buf;
string const_type_str;
string funct_name;
string array_type_str;
vector<string> id_list_buf; //
vector<string> funct_attri_buf;
//global variables for HW4
vector<string> assign_check_buf;
//data structure for parameter processing starts here
vector<param_struct> funct_param_buf;
param_struct one_param_struct;
//data structure for parameter processing ends here
//important data structure for funct paramater collection including their dimension
//this one is the new array buffer which is easier to be implemented in C++
vector<int> arr_dim_buf;
int is_proc_call;
//use for array scalar type checking
int LHS_dim,RHS_dim,switch_side,matching_param_dim;
string tmp_inheritance;

#line 108 "y.tab.c" /* yacc.c:339  */

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
#line 44 "parser.y" /* yacc.c:355  */

    char* str;

#line 256 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 273 "y.tab.c" /* yacc.c:358  */

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
#define YYLAST   204

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  67
/* YYNRULES -- Number of rules.  */
#define YYNRULES  124
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  208

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
       0,    60,    60,    67,    59,    82,    85,    86,    89,    91,
      95,    94,   102,   117,   116,   127,   128,   131,   138,   145,
     152,   159,   166,   173,   180,   187,   196,   197,   200,   201,
     205,   210,   215,   252,   204,   259,   260,   263,   264,   267,
     295,   299,   305,   309,   313,   314,   317,   322,   327,   332,
     340,   339,   354,   355,   356,   357,   358,   359,   360,   364,
     369,   363,   376,   377,   380,   381,   386,   385,   410,   414,
     422,   421,   435,   431,   443,   448,   447,   456,   462,   455,
     475,   492,   493,   496,   497,   503,   521,   527,   545,   548,
     561,   565,   570,   564,   597,   604,   608,   612,   616,   620,
     624,   631,   636,   630,   661,   668,   672,   680,   685,   679,
     712,   719,   723,   727,   733,   737,   741,   742,   744,   743,
     757,   758,   775,   787,   803
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
  "simple_stmt", "$@12", "proc_call_stmt", "$@13", "cond_stmt", "$@14",
  "while_stmt", "$@15", "for_stmt", "$@16", "$@17", "return_stmt",
  "opt_boolean_expr_list", "boolean_expr_list", "boolean_expr",
  "boolean_term", "boolean_factor", "relop_expr", "$@18", "$@19", "rel_op",
  "expr", "$@20", "$@21", "add_op", "term", "$@22", "$@23", "mul_op",
  "factor", "$@24", "var_ref", "dim", YY_NULLPTR
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

#define YYPACT_NINF -122

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-122)))

#define YYTABLE_NINF -119

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      26,  -122,    76,    30,  -122,  -122,    62,    64,    78,    69,
      62,  -122,  -122,    34,    71,  -122,   102,    69,  -122,  -122,
      83,    85,  -122,    61,  -122,  -122,  -122,  -122,  -122,  -122,
    -122,  -122,  -122,  -122,  -122,  -122,  -122,  -122,  -122,  -122,
      72,  -122,  -122,  -122,    80,    64,    62,   -12,  -122,  -122,
    -122,   103,   104,  -122,   100,   106,  -122,    37,   105,   134,
    -122,  -122,  -122,    64,    74,    97,    10,    10,    10,    10,
      10,   107,  -122,  -122,  -122,   105,  -122,  -122,  -122,  -122,
    -122,  -122,   108,   -12,   110,  -122,  -122,  -122,  -122,  -122,
     109,    -4,    10,    10,  -122,   -11,   117,  -122,  -122,    95,
      -5,  -122,   108,   -32,   -31,    -1,   118,   112,   154,  -122,
      10,   128,  -122,   151,    74,   119,   130,   120,   121,    10,
     108,  -122,     6,   105,    10,    10,   101,    93,    28,  -122,
    -122,  -122,   161,    10,  -122,   -25,    10,    74,  -122,  -122,
     -12,    10,    10,     8,  -122,   162,   117,  -122,  -122,  -122,
    -122,  -122,  -122,  -122,  -122,  -122,  -122,  -122,  -122,  -122,
    -122,  -122,   105,   122,   127,   118,  -122,    16,  -122,   102,
     153,   125,   126,  -122,   164,   170,    43,    43,    43,   171,
     131,    10,  -122,   172,   -12,  -122,  -122,  -122,   105,   113,
      -5,  -122,   175,  -122,   118,  -122,   176,   177,  -122,   159,
    -122,   174,  -122,   105,  -122,   179,   178,  -122
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
       0,   122,    65,    52,    60,    62,    53,    58,    54,    55,
      56,    57,    66,     0,    43,    37,    39,    44,    45,    77,
     122,     0,     0,     0,   121,     0,    86,    88,    90,    94,
     104,   110,   114,     0,     0,     0,    75,     0,     0,    64,
       0,     0,   123,     0,     0,     0,     0,     0,   122,     0,
     115,    89,     0,    63,     0,     0,     0,     0,     0,    68,
      69,    80,     0,    82,    61,     0,     0,     0,    42,    32,
       0,    82,    82,     0,   116,    72,    85,    87,    97,   100,
      99,    95,    98,    96,    92,   105,   106,   102,   111,   112,
     113,   108,    63,     0,    81,    84,   124,     0,    51,     0,
       0,     0,     0,   117,     0,     0,     0,     0,     0,     0,
       0,     0,    67,     0,     0,   119,   120,    74,    63,    93,
     103,   109,     0,    71,    83,    33,     0,     0,    76,     0,
      78,     0,    34,    63,    73,     0,     0,    79
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -122,  -122,  -122,  -122,  -122,   143,  -122,   180,  -122,  -122,
     -37,   173,  -122,  -122,   181,  -122,  -122,  -122,  -122,  -122,
    -122,   129,   184,  -122,   -88,   182,   183,  -122,   124,   -16,
    -122,  -122,  -121,  -122,  -122,  -122,  -122,  -122,  -122,  -122,
    -122,  -122,  -122,  -122,  -122,  -122,     7,  -122,   -62,    73,
     -81,  -122,  -122,  -122,  -122,    17,  -122,  -122,  -122,    18,
    -122,  -122,  -122,    22,  -122,   -57,  -122
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     6,     8,     9,    10,    11,    52,    51,
      41,    94,    16,    17,    18,    23,    84,   169,   199,    54,
      55,    56,    57,   115,    86,    87,    88,    47,    72,    73,
      46,   108,    74,    75,    76,   111,    77,   107,    78,   175,
      79,   132,    80,   116,   203,    81,   163,   164,   165,    96,
      97,    98,   126,   176,   154,    99,   127,   177,   157,   100,
     128,   178,   161,   101,   117,   102,   112
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      25,    82,   145,    50,    95,   103,   104,   105,   106,   123,
      59,   121,   124,   124,    35,    36,   129,   130,    82,   124,
      30,   118,    35,    36,    48,    49,   138,   166,  -107,  -107,
    -107,   122,    34,   124,   120,    90,    35,    36,    37,    38,
      39,   179,    91,   124,   147,   119,   113,   131,   135,   168,
     124,     1,   124,    30,    50,    92,   144,   143,   173,    93,
     124,   158,   159,   160,   182,    34,    82,   197,    90,    35,
      36,    37,    38,    39,   167,    91,     4,    28,     5,    29,
      20,    21,   205,    20,    64,     7,    31,    14,    28,    12,
      29,    32,    93,    33,    15,    30,    22,    31,    35,    36,
      48,    49,    32,   170,    33,    82,    24,    34,    27,    24,
      45,    35,    36,    37,    38,    39,    65,    40,    66,   194,
      67,    68,    89,    69,   155,   156,  -101,  -101,    53,    70,
      71,    82,   -91,   -91,   -91,   -91,   -91,   -91,   148,   149,
     150,   151,   152,   153,  -101,  -101,    82,   196,   171,   172,
      62,    60,    61,   183,    63,    83,   -70,   114,  -118,   110,
     125,   133,   124,   134,   136,   137,   140,   139,   162,   141,
     142,   174,   180,   181,   184,   185,   186,   187,   188,   193,
     192,   195,   198,   200,   202,   207,   201,   204,   206,    58,
      19,    13,    85,   189,    42,   190,     0,   146,    26,   109,
     191,     0,     0,    43,    44
};

static const yytype_int16 yycheck[] =
{
      16,    58,   123,    40,    66,    67,    68,    69,    70,    20,
      47,    92,    44,    44,    26,    27,    48,    48,    75,    44,
      10,    25,    26,    27,    28,    29,   114,    52,    33,    34,
      35,    93,    22,    44,    91,    25,    26,    27,    28,    29,
      30,   162,    32,    44,   125,    49,    83,    48,   110,   137,
      44,    25,    44,    10,    91,    45,    50,   119,    50,    49,
      44,    33,    34,    35,    48,    22,   123,   188,    25,    26,
      27,    28,    29,    30,   136,    32,     0,     3,    48,     5,
      46,    47,   203,    46,    47,    23,    12,     9,     3,    25,
       5,    17,    49,    19,    25,    10,    25,    12,    26,    27,
      28,    29,    17,   140,    19,   162,     4,    22,    25,     4,
      49,    26,    27,    28,    29,    30,    11,    32,    13,   181,
      15,    16,    25,    18,    31,    32,    31,    32,    48,    24,
      25,   188,    37,    38,    39,    40,    41,    42,    37,    38,
      39,    40,    41,    42,    31,    32,   203,   184,   141,   142,
      50,    48,    48,   169,    48,    21,    49,    47,    49,    51,
      43,    49,    44,     9,    36,    14,    36,    48,     7,    49,
      49,     9,    50,    46,    21,    50,    50,    13,     8,    48,
       9,     9,     7,     7,    25,     7,     9,    13,     9,    46,
      10,     7,    63,   176,    21,   177,    -1,   124,    17,    75,
     178,    -1,    -1,    21,    21
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
      24,    25,    81,    82,    85,    86,    87,    89,    91,    93,
      95,    98,   118,    21,    69,    74,    77,    78,    79,    25,
      25,    32,    45,    49,    64,   101,   102,   103,   104,   108,
     112,   116,   118,   101,   101,   101,   101,    90,    84,    81,
      51,    88,   119,    63,    47,    76,    96,   117,    25,    49,
     118,   103,   101,    20,    44,    43,   105,   109,   113,    48,
      48,    48,    94,    49,     9,   101,    36,    14,    77,    48,
      36,    49,    49,   101,    50,    85,   102,   103,    37,    38,
      39,    40,    41,    42,   107,    31,    32,   111,    33,    34,
      35,   115,     7,    99,   100,   101,    52,   101,    77,    70,
      63,    99,    99,    50,     9,    92,   106,   110,   114,    85,
      50,    46,    48,    82,    21,    50,    50,    13,     8,   108,
     112,   116,     9,    48,   101,     9,    63,    85,     7,    71,
       7,     9,    25,    97,    13,    85,     9,     7
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
      84,    82,    85,    85,    86,    86,    88,    87,    87,    87,
      90,    89,    92,    91,    91,    94,    93,    96,    97,    95,
      98,    99,    99,   100,   100,   101,   101,   102,   102,   103,
     103,   105,   106,   104,   104,   107,   107,   107,   107,   107,
     107,   109,   110,   108,   108,   111,   111,   113,   114,   112,
     112,   115,   115,   115,   116,   116,   116,   116,   117,   116,
     116,   116,   118,   118,   119
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
       0,     6,     1,     0,     2,     1,     0,     5,     3,     3,
       0,     6,     0,     9,     6,     0,     7,     0,     0,    12,
       3,     1,     0,     3,     1,     3,     1,     3,     1,     2,
       1,     0,     0,     5,     1,     1,     1,     1,     1,     1,
       1,     0,     0,     5,     1,     1,     1,     0,     0,     5,
       1,     1,     1,     1,     1,     2,     3,     4,     0,     5,
       5,     1,     1,     2,     3
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
#line 60 "parser.y" /* yacc.c:1646  */
    {
					symbol_table_init();
					id_list_buf.pb(yytext);
					funct_attri_buf.clear();
                    program_name_checking(program_name,(yyvsp[0].str),0);
				}
#line 1518 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 67 "parser.y" /* yacc.c:1646  */
    {
					inserting_symbol_table(id_list_buf,"program","void",funct_attri_buf);
					id_list_buf.clear();
				}
#line 1527 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 73 "parser.y" /* yacc.c:1646  */
    {
					error_detection();
                    program_name_checking(program_name,(yyvsp[0].str),1);
					dumpsymbol();
					pop_symbol_table();
					perfect();
			  	}
#line 1539 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 95 "parser.y" /* yacc.c:1646  */
    {
				funct_attri_buf.clear(); //normal variable does not have attribute, so just let the size be zero
				inserting_symbol_table(id_list_buf,"variable",(yyvsp[0].str),funct_attri_buf);
				id_list_buf.clear();
				error_detection();
			}
#line 1550 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 103 "parser.y" /* yacc.c:1646  */
    {
                funct_attri_buf.clear(); //normal variable does not have attribute, so just let the size be zero
				array_dimension_parser();
                array_type_str=(yyvsp[-1].str);
                array_type_str+=" ";
                array_type_str+=reverse_arr_buf;
				inserting_symbol_table(id_list_buf,"variable",array_type_str,funct_attri_buf);

				id_list_buf.clear();
				error_detection();
				memset(arr_buf,0,sizeof(arr_buf));//update it for next segment
				is_arr=0;
			}
#line 1568 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 117 "parser.y" /* yacc.c:1646  */
    {
				funct_attri_buf.pb(const_buf); //normal variable does not have attribute, so just let the size be zero
				inserting_symbol_table(id_list_buf,"constant",const_type_str,funct_attri_buf);
				id_list_buf.clear();
				error_detection();
                funct_attri_buf.clear();
			}
#line 1580 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 127 "parser.y" /* yacc.c:1646  */
    {(yyval.str)=yytext; const_type=1;}
#line 1586 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 128 "parser.y" /* yacc.c:1646  */
    {(yyval.str)=yytext; const_type=9;}
#line 1592 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 132 "parser.y" /* yacc.c:1646  */
    {
					const_type=(const_type==1)?1:9;
					const_type_str="integer";
					parse_constant();
					(yyval.str)=strdup(const_type_str.c_str());
				}
#line 1603 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 139 "parser.y" /* yacc.c:1646  */
    {
					const_type=(const_type==1)?2:10;
					const_type_str="integer";
					parse_constant();
					(yyval.str)=strdup(const_type_str.c_str());
				}
#line 1614 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 146 "parser.y" /* yacc.c:1646  */
    {
					const_type=3;
					const_type_str="real";
					parse_constant();
					(yyval.str)=strdup(const_type_str.c_str());
				}
#line 1625 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 153 "parser.y" /* yacc.c:1646  */
    {
					const_type=4;
					const_type_str="real";
					parse_constant();
					(yyval.str)=strdup(const_type_str.c_str());
				}
#line 1636 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 160 "parser.y" /* yacc.c:1646  */
    {
					const_type=5;
					const_type_str="real";
					parse_constant();
					(yyval.str)=strdup(const_type_str.c_str());
				}
#line 1647 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 167 "parser.y" /* yacc.c:1646  */
    {
					const_type=6;
					const_type_str="real";
					parse_constant();
					(yyval.str)=strdup(const_type_str.c_str());
				}
#line 1658 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 174 "parser.y" /* yacc.c:1646  */
    {
					 const_type=7;
					 const_type_str="string";
					 parse_constant();
					 (yyval.str)=strdup(const_type_str.c_str());
				 }
#line 1669 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 181 "parser.y" /* yacc.c:1646  */
    {
					const_type=8;
					const_type_str="boolean";
					parse_constant();
					(yyval.str)=strdup(const_type_str.c_str());
				}
#line 1680 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 188 "parser.y" /* yacc.c:1646  */
    {
					const_type=8;
					const_type_str="boolean";
					parse_constant();
					(yyval.str)=strdup(const_type_str.c_str());
				}
#line 1691 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 205 "parser.y" /* yacc.c:1646  */
    {
                    funct_name = yytext;
                    scope_depth++;
				}
#line 1700 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 210 "parser.y" /* yacc.c:1646  */
    {
					is_funct=1;
					scope_depth--;
				}
#line 1709 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 215 "parser.y" /* yacc.c:1646  */
    {
                    id_list_buf.pb(funct_name);

                    if(is_arr)
					{
						cout<<"<Error> found in Line: "<<linenum<<" function cannot return a non-scalar type!"<<endl;
                        memset(arr_buf,0,sizeof(arr_buf));//update it for next segment*/
					}
					else
					{
						//here we push_back the funct_attri_buf inorder to match the attributes of function
						funct_attri_buf.clear(); //primitive initialization
						for(unsigned int i=0;i<mysymbol_table[1].size();i++) //search the parameter for function attribute
						{
							if((mysymbol_table[1][i].kind=="parameter")&&(mysymbol_table[1][i].name[0]!=0))
							{
                                funct_attri_buf.pb(mysymbol_table[1][i].type);
							}
						}
                        if((yyvsp[-1].str)==";") //prevent logic null string error
                        {
							inserting_symbol_table(id_list_buf,"function","void",funct_attri_buf);
                        }
                        else
                        {
                            inserting_symbol_table(id_list_buf,"function",(yyvsp[-1].str),funct_attri_buf);
                        }

					}
					dumpsymbol();
                    id_list_buf.clear();
                    funct_attri_buf.clear();
                    error_detection();
					is_arr=0;
				}
#line 1749 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 252 "parser.y" /* yacc.c:1646  */
    {
					funct_name.clear();
					is_funct=0;
				}
#line 1758 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 268 "parser.y" /* yacc.c:1646  */
    {
				funct_attri_buf.clear();
				if(is_arr)
				{
                    if(error_detection()==0)
					{
						array_dimension_parser();
                        array_type_str=(yyvsp[0].str);
                        array_type_str+=" ";
                        array_type_str+=reverse_arr_buf;
						inserting_symbol_table(id_list_buf,"parameter",array_type_str,funct_attri_buf);
                        memset(arr_buf,0,sizeof(arr_buf));//update it for next segment
					}
				}
				else
				{
					if(error_detection()==0)
					{
						inserting_symbol_table(id_list_buf,"parameter",(yyvsp[0].str),funct_attri_buf);
					}
				}

                id_list_buf.clear();
				is_arr=0;
			}
#line 1788 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 296 "parser.y" /* yacc.c:1646  */
    {
                id_list_buf.pb(yytext);
			}
#line 1796 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 300 "parser.y" /* yacc.c:1646  */
    {
				id_list_buf.pb(yytext);
			}
#line 1804 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 306 "parser.y" /* yacc.c:1646  */
    {
				(yyval.str)=(yyvsp[0].str);
			}
#line 1812 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 313 "parser.y" /* yacc.c:1646  */
    {(yyval.str)=(yyvsp[0].str);}
#line 1818 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 314 "parser.y" /* yacc.c:1646  */
    {(yyval.str)=(yyvsp[0].str);}
#line 1824 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 318 "parser.y" /* yacc.c:1646  */
    {
                char* synth = (char* )"integer";//suppose this is not implemented, IOS CONVERSION ERROR WILL BE THROWN
                (yyval.str)=synth;
			}
#line 1833 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 323 "parser.y" /* yacc.c:1646  */
    {
                char* synth = (char* )"real";//suppose this is not implemented, IOS CONVERSION ERROR WILL BE THROWN
                (yyval.str)=synth;
			}
#line 1842 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 328 "parser.y" /* yacc.c:1646  */
    {
                char* synth = (char* )"boolean";//suppose this is not implemented, IOS CONVERSION ERROR WILL BE THROWN
                (yyval.str)=synth;
			}
#line 1851 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 333 "parser.y" /* yacc.c:1646  */
    {
                char* synth = (char* )"string";//suppose this is not implemented, IOS CONVERSION ERROR WILL BE THROWN
                (yyval.str)=synth;
			}
#line 1860 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 340 "parser.y" /* yacc.c:1646  */
    {
				is_arr=1;
			}
#line 1868 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 344 "parser.y" /* yacc.c:1646  */
    {
                (yyval.str)=(yyvsp[0].str);
                int delta=atol((yyvsp[-2].str))-atol((yyvsp[-4].str))+1;
				char tmp[10];
				sprintf(tmp,"%d",delta);
				strcat(arr_buf,tmp);
				strcat(arr_buf,",");
			}
#line 1881 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 364 "parser.y" /* yacc.c:1646  */
    {
					scope_depth++;
				}
#line 1889 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 369 "parser.y" /* yacc.c:1646  */
    {
                    dumpsymbol();
                    pop_symbol_table();
				}
#line 1898 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 386 "parser.y" /* yacc.c:1646  */
    {
				switch_side=1;
				RHS_dim=0;
				/* cout<<"Switch side assign !! \n\n"; */
				tmp_inheritance=has_scalar(find_type((yyvsp[0].str)),LHS_dim,"assign LHS");
			}
#line 1909 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 393 "parser.y" /* yacc.c:1646  */
    {
				/* cout<<"we have an assign LHS "<<find_type($1)<<" with RHS "<<find_type($4)<<endl; */
				if(find_type((yyvsp[-1].str))=="none")
				{
					/* cout<<"const type "<<$4<<endl; */
					assignop(find_type((yyvsp[-4].str)),(yyvsp[-1].str),(yyvsp[-4].str),(yyvsp[-1].str));
				}
				else
				{
					/* cout<<"non const right type "<<$4<<endl; */
					assignop(find_type((yyvsp[-4].str)),find_type((yyvsp[-1].str)),(yyvsp[-4].str),(yyvsp[-1].str));
				}
				tmp_inheritance.clear();
				switch_side=0;
				LHS_dim=0;
				RHS_dim=0;
            }
#line 1931 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 411 "parser.y" /* yacc.c:1646  */
    {
				simple((yyvsp[-1].str));
			}
#line 1939 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 415 "parser.y" /* yacc.c:1646  */
    {
				simple((yyvsp[-1].str));
			}
#line 1947 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 422 "parser.y" /* yacc.c:1646  */
    {
				if(find_kind((yyvsp[0].str))!="function")
				{
					printf("<Error> Found in Line%d: symbol %s is not the function\n",linenum,(yyvsp[0].str));
				}
			}
#line 1958 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 435 "parser.y" /* yacc.c:1646  */
    {
					/* cout<<"conditional type in is "<<find_type($2)<<endl; */
					condition(find_type((yyvsp[-2].str)),"conditional");
				}
#line 1967 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 448 "parser.y" /* yacc.c:1646  */
    {
				condition(find_type((yyvsp[0].str)),"while");
			}
#line 1975 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 456 "parser.y" /* yacc.c:1646  */
    {
					inserting_iter_table(yytext,scope_depth+1);
					error_detection();
					is_loop=1;
				}
#line 1985 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 462 "parser.y" /* yacc.c:1646  */
    {
					if(atoi((yyvsp[-1].str))-atoi((yyvsp[-3].str)) < 0)
					{
						printf("<Error> Found in Line%d: loop parameter's lower bound >= uppper bound\n",linenum);
					}
				}
#line 1996 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 470 "parser.y" /* yacc.c:1646  */
    {
					is_loop=0;
				}
#line 2004 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 476 "parser.y" /* yacc.c:1646  */
    {
				if(is_funct==0)
				{
					cout<<"<Error> found in Line: "<<linenum<<" Program cannot have a return value "<<endl;
				}
				if(has_scalar(find_type((yyvsp[-1].str)),LHS_dim,"return_stmt ") == "error")
                {
					cout<<"<Error> found in Line: "<<linenum<<" The return value of function should be a scalar type "<<endl;
                }
				else
				{
					check_return(find_type(funct_name),has_scalar(find_type((yyvsp[-1].str)),LHS_dim,"return_stmt "));
				}
			}
#line 2023 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 498 "parser.y" /* yacc.c:1646  */
    {
				(yyval.str)=(yyvsp[0].str);
			}
#line 2031 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 504 "parser.y" /* yacc.c:1646  */
    {
							if(find_type((yyvsp[0].str))=="none")
							{
								/* cout<<"Right const type "<<$3<<endl; */
								(yyval.str)=strdup(boolop(find_type((yyvsp[-2].str)),(yyvsp[0].str),(yyvsp[-2].str),(yyvsp[0].str)).c_str());
							}
							else if(find_type((yyvsp[-2].str))=="none")
							{
								/* cout<<"Left const type "<<$3<<endl; */
								(yyval.str)=strdup(boolop((yyvsp[-2].str),find_type((yyvsp[0].str)),(yyvsp[-2].str),(yyvsp[0].str)).c_str());
							}
							else
							{
								/* cout<<"Both Non const type "<<$4<<endl; */
								(yyval.str)=strdup(boolop(find_type((yyvsp[-2].str)),find_type((yyvsp[0].str)),(yyvsp[-2].str),(yyvsp[0].str)).c_str());
							}
						}
#line 2053 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 522 "parser.y" /* yacc.c:1646  */
    {
							(yyval.str)=(yyvsp[0].str);
						}
#line 2061 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 528 "parser.y" /* yacc.c:1646  */
    {
							if(find_type((yyvsp[0].str))=="none")
							{
								/* cout<<"Right const type "<<$3<<endl; */
								(yyval.str)=strdup(boolop(find_type((yyvsp[-2].str)),(yyvsp[0].str),(yyvsp[-2].str),(yyvsp[0].str)).c_str());
							}
							else if(find_type((yyvsp[-2].str))=="none")
							{
								/* cout<<"Left const type "<<$3<<endl; */
								(yyval.str)=strdup(boolop((yyvsp[-2].str),find_type((yyvsp[0].str)),(yyvsp[-2].str),(yyvsp[0].str)).c_str());
							}
							else
							{
								/* cout<<"Both Non const type "<<$4<<endl; */
								(yyval.str)=strdup(boolop(find_type((yyvsp[-2].str)),find_type((yyvsp[0].str)),(yyvsp[-2].str),(yyvsp[0].str)).c_str());
							}
						}
#line 2083 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 545 "parser.y" /* yacc.c:1646  */
    {(yyval.str)=(yyvsp[0].str);}
#line 2089 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 549 "parser.y" /* yacc.c:1646  */
    {
						if(find_type((yyvsp[0].str))=="none")
						{
							/* cout<<"Right const type "<<$2<<endl; */
							(yyval.str)=strdup(boolop((yyvsp[0].str),(yyvsp[0].str),(yyvsp[0].str),(yyvsp[0].str)).c_str());
						}
						else
						{
							/* cout<<"Both Non const type "<<$2<<endl; */
							(yyval.str)=strdup(boolop(find_type((yyvsp[0].str)),find_type((yyvsp[0].str)),(yyvsp[0].str),(yyvsp[0].str)).c_str());
						}
					}
#line 2106 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 561 "parser.y" /* yacc.c:1646  */
    {(yyval.str)=(yyvsp[0].str);}
#line 2112 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 565 "parser.y" /* yacc.c:1646  */
    {
					/* cout<<"relop most left part "<<endl; */
					switch_side=0;
				}
#line 2121 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 570 "parser.y" /* yacc.c:1646  */
    {
					/* cout<<"Switch side relop !! \n\n"; */
					switch_side=1;
					RHS_dim=0;
				}
#line 2131 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 576 "parser.y" /* yacc.c:1646  */
    {
				/* cout<<"RELOP EXPR HAPPENS HERE linenum "<<linenum<<endl; */
					if(find_type((yyvsp[0].str))=="none")
					{
						/* cout<<"Right const type "<<$5<<endl; */
						(yyval.str)=strdup(relop(find_type((yyvsp[-4].str)),(yyvsp[0].str),(yyvsp[-4].str),(yyvsp[0].str)).c_str());
					}
					else if(find_type((yyvsp[-4].str))=="none")
					{
						/* cout<<"Left const type "<<$5<<endl; */
						(yyval.str)=strdup(relop((yyvsp[-4].str),find_type((yyvsp[0].str)),(yyvsp[-4].str),(yyvsp[0].str)).c_str());
					}
					else
					{
						/* cout<<"Both Non const type "<<$5<<endl; */
						(yyval.str)=strdup(relop(find_type((yyvsp[-4].str)),find_type((yyvsp[0].str)),(yyvsp[-4].str),(yyvsp[0].str)).c_str());
					}
					switch_side=0;
					LHS_dim=0;
					RHS_dim=0;
				}
#line 2157 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 598 "parser.y" /* yacc.c:1646  */
    {
					/* cout<<"relop -> expr "<<endl; */
					(yyval.str)=(yyvsp[0].str);
				}
#line 2166 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 605 "parser.y" /* yacc.c:1646  */
    {
				(yyval.str)=(yyvsp[0].str);  /*pass the factor up*/
			}
#line 2174 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 609 "parser.y" /* yacc.c:1646  */
    {
				(yyval.str)=(yyvsp[0].str);  /*pass the factor up*/
			}
#line 2182 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 613 "parser.y" /* yacc.c:1646  */
    {
				(yyval.str)=(yyvsp[0].str);  /*pass the factor up*/
			}
#line 2190 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 617 "parser.y" /* yacc.c:1646  */
    {
				(yyval.str)=(yyvsp[0].str);  /*pass the factor up*/
			}
#line 2198 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 621 "parser.y" /* yacc.c:1646  */
    {
				(yyval.str)=(yyvsp[0].str);  /*pass the factor up*/
			}
#line 2206 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 625 "parser.y" /* yacc.c:1646  */
    {
				(yyval.str)=(yyvsp[0].str);  /*pass the factor up*/
			}
#line 2214 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 631 "parser.y" /* yacc.c:1646  */
    {
					/* cout<<"addop most left part "<<endl; */
					switch_side=0;
				}
#line 2223 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 636 "parser.y" /* yacc.c:1646  */
    {
					switch_side=1;
					RHS_dim=0;
				}
#line 2232 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 641 "parser.y" /* yacc.c:1646  */
    {
                	if(find_type((yyvsp[0].str))=="none")
					{
						/* cout<<" Left variable type "<<$1<<" Right const type "<<$5<<endl; */
						(yyval.str)=strdup(addop(find_type((yyvsp[-4].str)),(yyvsp[0].str),(yyvsp[-4].str),(yyvsp[0].str),(yyvsp[-2].str)).c_str());
					}
					else if(find_type((yyvsp[-4].str))=="none")
					{
						/* cout<<" Left const type "<<$1<<" Right variable type "<<$5<<endl; */
						(yyval.str)=strdup(addop((yyvsp[-4].str),find_type((yyvsp[0].str)),(yyvsp[-4].str),(yyvsp[0].str),(yyvsp[-2].str)).c_str());
					}
					else
					{
						/* cout<<"Both Non const type "<<$5<<endl; */
						(yyval.str)=strdup(addop(find_type((yyvsp[-4].str)),find_type((yyvsp[0].str)),(yyvsp[-4].str),(yyvsp[0].str),(yyvsp[-2].str)).c_str());
					}
					switch_side=0;
					LHS_dim=0;
					RHS_dim=0;
            	}
#line 2257 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 662 "parser.y" /* yacc.c:1646  */
    {
					/* cout<<"expr->term "<<endl; */
					(yyval.str)=(yyvsp[0].str);
				}
#line 2266 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 669 "parser.y" /* yacc.c:1646  */
    {
					(yyval.str)=(yyvsp[0].str);  /*pass the factor up*/
				}
#line 2274 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 673 "parser.y" /* yacc.c:1646  */
    {
					(yyval.str)=(yyvsp[0].str);  /*pass the factor up*/
				}
#line 2282 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 680 "parser.y" /* yacc.c:1646  */
    {
				/* cout<<"mulop most left part "<<endl; */
				switch_side=0;
			}
#line 2291 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 685 "parser.y" /* yacc.c:1646  */
    {
				/* cout<<"Switch side mul !! \n\n"; */
				switch_side=1;
				RHS_dim=0;
			}
#line 2301 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 691 "parser.y" /* yacc.c:1646  */
    {
				/* cout<<"555555  "<<endl; */
				if(find_type((yyvsp[0].str))=="none")
				{
					/* cout<<" Left variable type xdxdxdxddx "<<$1<<" Right const type "<<$4<<endl; */
					(yyval.str)=strdup(mulop(find_type((yyvsp[-4].str)),(yyvsp[0].str),(yyvsp[-4].str),(yyvsp[0].str),(yyvsp[-2].str)).c_str());
				}
				else if(find_type((yyvsp[-4].str))=="none")
				{
					/* cout<<" Left const type "<<$1<<" Right variable type "<<$4<<endl; */
					(yyval.str)=strdup(mulop((yyvsp[-4].str),find_type((yyvsp[0].str)),(yyvsp[-4].str),(yyvsp[0].str),(yyvsp[-2].str)).c_str());
				}
				else
				{
					/* cout<<"Both Non const type "<<$4<<endl; */
					(yyval.str)=strdup(mulop(find_type((yyvsp[-4].str)),find_type((yyvsp[0].str)),(yyvsp[-4].str),(yyvsp[0].str),(yyvsp[-2].str)).c_str());
				}
				switch_side=0;
				LHS_dim=0;
				RHS_dim=0;
			}
#line 2327 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 713 "parser.y" /* yacc.c:1646  */
    {
				/* cout<<"term->factor"<<endl; */
				(yyval.str)=(yyvsp[0].str);  /*pass the factor up*/
			}
#line 2336 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 720 "parser.y" /* yacc.c:1646  */
    {
				(yyval.str)=(yyvsp[0].str);  /*pass the factor up*/
			}
#line 2344 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 724 "parser.y" /* yacc.c:1646  */
    {
				(yyval.str)=(yyvsp[0].str);  /*pass the factor up*/
			}
#line 2352 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 728 "parser.y" /* yacc.c:1646  */
    {
				(yyval.str)=(yyvsp[0].str);  /*pass the factor up*/
			}
#line 2360 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 734 "parser.y" /* yacc.c:1646  */
    {
				(yyval.str)=(yyvsp[0].str);
			}
#line 2368 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 738 "parser.y" /* yacc.c:1646  */
    {
				(yyval.str)=(yyvsp[0].str);
			}
#line 2376 "y.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 744 "parser.y" /* yacc.c:1646  */
    {
                one_param_struct.param_name=(yyvsp[0].str);
				one_param_struct.param_dim=0;
				funct_param_buf.pb(one_param_struct);
				LHS_dim=0;
                is_proc_call=1;
            }
#line 2388 "y.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 752 "parser.y" /* yacc.c:1646  */
    {
				procedure_call_checking();
                funct_param_buf.clear();
                is_proc_call=0;
            }
#line 2398 "y.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 759 "parser.y" /* yacc.c:1646  */
    {
                (yyval.str)=(yyvsp[0].str);
                if(is_proc_call)
                {
					if(linenum==68)
						cout<<" push constant "<<(yyvsp[0].str)<<" to function "<<endl;

					one_param_struct.param_name=(yyvsp[0].str);
					one_param_struct.param_dim=LHS_dim;
					funct_param_buf.pb(one_param_struct);
					LHS_dim=0;
                }
            }
#line 2416 "y.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 776 "parser.y" /* yacc.c:1646  */
    {
                (yyval.str)=(yyvsp[0].str);
                if(is_proc_call)
                {
					one_param_struct.param_name=(yyvsp[0].str);
					one_param_struct.param_dim=LHS_dim;
					funct_param_buf.pb(one_param_struct);
					LHS_dim=0;
                }
				/* cout<<"Array First time reference! "<<endl; */
            }
#line 2432 "y.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 788 "parser.y" /* yacc.c:1646  */
    {
				if(switch_side)
				{
					RHS_dim++;
					/* cout<<"Array RIGHT dimension reference at Line"<<linenum<<"  now dim count up to"<<RHS_dim<<endl; */
				}
				else
				{
					LHS_dim++;
					/* cout<<"Array LEFT dimension reference at Line"<<linenum<<"  now dim count up to"<<LHS_dim<<endl; */
				}
				matching_param_dim=1;
			}
#line 2450 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2454 "y.tab.c" /* yacc.c:1646  */
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
#line 806 "parser.y" /* yacc.c:1906  */


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
