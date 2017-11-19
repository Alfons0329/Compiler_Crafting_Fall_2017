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
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    COMMA = 258,
    SEMICOLON = 259,
    COLON = 260,
    BRACELEFT = 261,
    BRACERIGHT = 262,
    BRACKETLEFT = 263,
    BRACKETRIGHT = 264,
    ASSIGN = 265,
    LESS = 266,
    LESSEQUAL = 267,
    LESSGREATER = 268,
    GREATEREQUAL = 269,
    GREATER = 270,
    EQUAL = 271,
    PLUS = 272,
    MINUS = 273,
    MULTIPLY = 274,
    DIVIDE = 275,
    MOD = 276,
    NOT = 277,
    AND = 278,
    OR = 279,
    UNARY_NEGATIVE = 280,
    KWARRAY = 281,
    KWBEGIN = 282,
    KWBOOLEAN = 283,
    KWDEF = 284,
    KWDO = 285,
    KWELSE = 286,
    KWEND = 287,
    KWFALSSE = 288,
    KWFOR = 289,
    KWINTEGER = 290,
    KWIF = 291,
    KWOF = 292,
    KWPRINT = 293,
    KWREAD = 294,
    KWREAL = 295,
    KWSTRING = 296,
    KWTHEN = 297,
    KWTO = 298,
    KWTRUE = 299,
    KWFALSE = 300,
    KWRETURN = 301,
    KWVAR = 302,
    KWWHILE = 303,
    OCTAL = 304,
    INTEGER = 305,
    REAL = 306,
    IDENT = 307,
    STRING = 308
  };
#endif
/* Tokens.  */
#define COMMA 258
#define SEMICOLON 259
#define COLON 260
#define BRACELEFT 261
#define BRACERIGHT 262
#define BRACKETLEFT 263
#define BRACKETRIGHT 264
#define ASSIGN 265
#define LESS 266
#define LESSEQUAL 267
#define LESSGREATER 268
#define GREATEREQUAL 269
#define GREATER 270
#define EQUAL 271
#define PLUS 272
#define MINUS 273
#define MULTIPLY 274
#define DIVIDE 275
#define MOD 276
#define NOT 277
#define AND 278
#define OR 279
#define UNARY_NEGATIVE 280
#define KWARRAY 281
#define KWBEGIN 282
#define KWBOOLEAN 283
#define KWDEF 284
#define KWDO 285
#define KWELSE 286
#define KWEND 287
#define KWFALSSE 288
#define KWFOR 289
#define KWINTEGER 290
#define KWIF 291
#define KWOF 292
#define KWPRINT 293
#define KWREAD 294
#define KWREAL 295
#define KWSTRING 296
#define KWTHEN 297
#define KWTO 298
#define KWTRUE 299
#define KWFALSE 300
#define KWRETURN 301
#define KWVAR 302
#define KWWHILE 303
#define OCTAL 304
#define INTEGER 305
#define REAL 306
#define IDENT 307
#define STRING 308

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
