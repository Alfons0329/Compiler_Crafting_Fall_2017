# Intro. To Compiler Design Proj2 Report 0416324 An – Fong Hwu

## Part of Lex I have modified to make it interact with Yacc parser?
I have modified it to make lex scanner return what keyword and some other things required to be parsed.

## What platfotm to run my parser
I use the Linux4 workstation to run my program, just SSH in it and run.

## How to run my parser
Makefile as the picture, description are written in the comments
```
TARGET = parser_exec #target_to_be output , which is the compiled file
OBJECT = lex.yy.c y.tab.h  y.tab.c #link the required libraries together
CC     = gcc -g #gcc -g for debugging oprions
CFLAGS = -Wall -Wextra -pedantic -g3 #compile flags
LEX    = flex #lex lib
LIBS   = -lfl #lfl flag
YACC = yacc -d -v #yacc flag

all: lex.yy.c y.tab.c #altogether
	$(CC) $(CCFLAGS) lex.yy.c y.tab.c -o $(TARGET) $(LIBS)

#generating the required components
y.tab.c: parser.y #compile parser
	$(YACC) parser.y

lex.yy.c: lex.l #compile lexer
	$(LEX) lex.l

.PHONY: clean

clean: #clean the file
	$(RM) -f $(TARGET) $(OBJECT)
```

## Ability of my parser
Able to parse all the all testcases by TA and run through my own testcases
My own testcases--> https://pastebin.com/MZEvqiHW
