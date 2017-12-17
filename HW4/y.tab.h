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
extern YYSTYPE yylval;
