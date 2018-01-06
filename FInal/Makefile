TARGET   = parser
OBJECT   = lex.yy.c y.tab.c y.output parser y.tab.h
CC       = gcc
CFLAGS   = -Wall -Wextra -pedantic -g3
LEX      = flex
YACC     = yacc -v -t -l
YACCFLAG = -d
LIBS     = -lfl -lm

all: $(TARGET)
	
$(TARGET): y.tab.c lex.yy.c main.c semcheck.c symtab.c
	$(CC) $^ -o $(TARGET) $(CCFLAGS) $(LIBS)

y.tab.c: parser.y
	$(YACC) $(YACCFLAG) $<

lex.yy.c: lex.l
	$(LEX) $<

.PHONY: clean

clean:
	$(RM) -f $(TARGET) $(OBJECT)
