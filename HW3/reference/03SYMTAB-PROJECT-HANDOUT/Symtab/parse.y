%{
#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "symtab.h"

struct nodeType* newOpNode(int op);
extern struct nodeType* ASTRoot;
%}

/* The union structure for yylval
   Here all terminals/nonterminals are represented by the same type
   you can add other types, and use yylval.type to access the union field */
%union {
    struct nodeType *node;
}

/* Declare the types for each terminal/nonterminal */
%token <node> TOK_PROGRAM TOK_VAR TOK_ARRAY TOK_OF TOK_INTEGER TOK_REAL TOK_FUNCTION TOK_PROCEDURE
%token <node> TOK_BEGIN TOK_END TOK_IF TOK_THEN TOK_ELSE TOK_WHILE TOK_DO TOK_NOT
%token <node> TOK_ASSIGN_OP TOK_REL_OP TOK_DOTDOT
%token <node> TOK_ID TOK_INT_NUM TOK_REAL_NUM '+' '-' '*' '/' '[' ']' '(' ')' ',' ';' ':' '.'

%type <node> goal program program_head identifier_list compound_statement
%type <node> variable_declaration type statement_list statement
%type <node> expression simple_expression term factor

%%

goal
    : program
        { ASTRoot = $1; }
    ;

program
    : program_head variable_declaration compound_statement '.'
        { $$ = newNode(NODE_PROGRAM);
          addChild($$, $2);
          addChild($$, $3);
          deleteNode($1);
          deleteNode($4); }
    ;

program_head
    : TOK_PROGRAM TOK_ID '(' identifier_list ')' ';'
        { $$ = $2;
          deleteNode($1);
          deleteNode($3);
          deleteNode($4);
          deleteNode($5);
          deleteNode($6); }
    ;

identifier_list
    : TOK_ID
        { $$ = newNode(NODE_LIST);
          addChild($$, $1); }
    | identifier_list ',' TOK_ID
        { $$ = $1;
          addChild($$, $3);
          deleteNode($2); }
    ;

variable_declaration
    : TOK_VAR identifier_list ':' type ';'
        { $$ = newNode(NODE_VAR_DECL);
          addChild($$, $2);
          addChild($$, $4);
          deleteNode($1);
          deleteNode($3);
          deleteNode($5); }
    ;

type
    : TOK_INTEGER
        { $$ = $1;
          $$->nodeType = NODE_TYPE_INT; }
    | TOK_REAL
        { $$ = $1;
          $$->nodeType = NODE_TYPE_REAL; }
    ;

compound_statement
    : TOK_BEGIN TOK_END
        { $$ = newNode(NODE_LIST);
          deleteNode($1);
          deleteNode($2); }
    | TOK_BEGIN statement_list TOK_END
        { $$ = $2;
          deleteNode($1);
          deleteNode($3); }
    ;

statement_list
    : statement
        { $$ = newNode(NODE_LIST);
          addChild($$, $1); }
    | statement_list ';' statement
        { $$ = $1;
          addChild($$, $3);
          deleteNode($2); }
    ;

statement
    : TOK_ID TOK_ASSIGN_OP expression
        { $$ = newNode(NODE_ASSIGN_STMT);
          addChild($$, $1);
          addChild($$, $3);
          $1->nodeType = NODE_SYM_REF;
          deleteNode($2); }
    ;

expression
    : simple_expression
        { $$ = $1; }
    ;

simple_expression
    : term
        { $$ = $1; }
    | simple_expression '+' term
        { $$ = newOpNode(OP_ADD);
          addChild($$, $1);
          addChild($$, $3);
          deleteNode($2); }
    | simple_expression '-' term
        { $$ = newOpNode(OP_SUB);
          addChild($$, $1);
          addChild($$, $3);
          deleteNode($2); }
    ;

term
    : factor
        { $$ = $1; }
    | term '*' factor
        { $$ = newOpNode(OP_MUL);
          addChild($$, $1);
          addChild($$, $3);
          deleteNode($2); }
    | term '/' factor
        { $$ = newOpNode(OP_DIV);
          addChild($$, $1);
          addChild($$, $3);
          deleteNode($2); }
    ;

/* The first rule may be a variable or a procedure with no parameter */
factor
    : TOK_ID
        { $$ = $1;
          $$->nodeType = NODE_VAR_OR_PROC; }
    | TOK_INT_NUM
        { $$ = $1;
          $$->nodeType = NODE_INT; }
    | TOK_REAL_NUM
        { $$ = $1;
          $$->nodeType = NODE_REAL; }
    | '(' expression ')'
        { $$ = $2;
          deleteNode($1);
          deleteNode($3); }
    ;

%%

struct nodeType *ASTRoot;

int yyerror(const char* s) {
    printf("Syntax error\n");
    exit(0);
}

struct nodeType* newOpNode(int op) {
    struct nodeType *node = newNode(NODE_OP);
    node->op = op;

    return node;
}

int main() {
    yyparse();
    printf("********************************\n"
           "*       No syntax error!       *\n"
           "********************************\n");

    printTree(ASTRoot, 0);

    SymbolTable.size = 0;
    semanticCheck(ASTRoot);
    printf("********************************\n"
           "*      No semantic error!      *\n"
           "********************************\n");

    return 0;
}
