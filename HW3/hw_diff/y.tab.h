/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
