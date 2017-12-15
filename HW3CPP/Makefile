parser: parser.y lex.l
	yacc -d  parser.y
	flex lex.l
	g++ -std=c++11 -o parser  symboltable.h   main.cpp  lex.yy.c y.tab.c -lm -lfl
clean:
	rm -f out.o
	rm -f y.tab.h
	rm -f y.tab.c
	rm -f parser
