TARGET   = parser
OBJECT   = lex.yy.c y.tab.c y.output parser y.tab.h
CC       = g++ -std=c++11
CCFLAGS   = -Wall -Wextra -pedantic -g3
LEX      = flex
YACC     = yacc -v -t
YACCFLAG = -d
LIBS     = -lfl -lm

all: $(TARGET)

$(TARGET): y.tab.c lex.yy.c main.cpp symbol_table.h
	$(CC) $^ -o $(TARGET) $(CCFLAGS) $(LIBS)

y.tab.c: parser.y
	$(YACC) $(YACCFLAG) $<

lex.yy.c: lex.l
	$(LEX) $<

.PHONY: clean

clean:
	$(RM) -f $(TARGET) $(OBJECT)
