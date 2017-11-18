TARGET = parser
OBJECT = lex.yy.c y.tab.h  y.tab.c #link the required libraries together
CC     = gcc -g
CFLAGS = -Wall -Wextra -pedantic -g3
LEX    = flex
LIBS   = -lfl -ly
YACC = yacc -d -v

all: lex.yy.c y.tab.c
	$(CC) $(CCFLAGS) lex.yy.c y.tab.c -o $(TARGET) $(LIBS)

y.tab.c: parser.y #generating the required componentes
	$(YACC) parser .y

lex.yy.c: lex.legal
	$(LEX) lex.l

.PHONY: clean

clean:
	$(RM) -f $(TARGET) $(OBJECT)
