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
