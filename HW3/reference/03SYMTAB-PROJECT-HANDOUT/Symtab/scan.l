%{
#include <stdio.h>
#include <string.h>
#include "node.h"
#include "y.tab.h"

struct nodeType* newTokenNode(int tokenType);
%}

%%

[ \n]* {
    /* Just to eat the spaces and new lines 
       so that they won't appear in output */
}

[Pp][Rr][Oo][Gg][Rr][Aa][Mm] {
    yylval.node = newTokenNode(TOK_PROGRAM);
    return TOK_PROGRAM;
}

[Vv][Aa][Rr] {
    yylval.node = newTokenNode(TOK_VAR);
    return TOK_VAR;
}

[Ii][Nn][Tt][Ee][Gg][Ee][Rr] {
    yylval.node = newTokenNode(TOK_INTEGER);
    return TOK_INTEGER;
}

[Rr][Ee][Aa][Ll] {
    yylval.node = newTokenNode(TOK_REAL);
    return TOK_REAL;
}

[Bb][Ee][Gg][Ii][Nn] {
    yylval.node = newTokenNode(TOK_BEGIN);
    return TOK_BEGIN;
}

[Ee][Nn][Dd] {
    yylval.node = newTokenNode(TOK_END);
    return TOK_END;
}

[Nn][Oo][Tt] {
    yylval.node = newTokenNode(TOK_NOT);
    return TOK_NOT;
}

[a-zA-Z][a-zA-Z0-9]* {
    yylval.node = newTokenNode(TOK_ID);
    yylval.node->string = (char*)malloc(yyleng+1);
    strcpy(yylval.node->string, yytext);
    return TOK_ID;
}

"+" {
    yylval.node = newTokenNode('+');
    yylval.node->op = OP_ADD;
    return '+';
}

"-" {
    yylval.node = newTokenNode('-');
    yylval.node->op = OP_SUB;
    return '-';
}

"*" {
    yylval.node = newTokenNode('*');
    yylval.node->op = OP_MUL;
    return '*';
}

"/" {
    yylval.node = newTokenNode('/');
    yylval.node->op = OP_DIV;
    return '/';
}

"[" {
    yylval.node = newTokenNode('[');
    return '[';
}

"]" {
    yylval.node = newTokenNode(']');
    return ']';
}

"(" {
    yylval.node = newTokenNode('(');
    return '(';
}

")" {
    yylval.node = newTokenNode(')');
    return ')';
}

"<" {
    yylval.node = newTokenNode(TOK_REL_OP);
    yylval.node->op = OP_LT;
    return TOK_REL_OP;
}

"<=" {
    yylval.node = newTokenNode(TOK_REL_OP);
    yylval.node->op = OP_LE;
    return TOK_REL_OP;
}

"=" {
    yylval.node = newTokenNode(TOK_REL_OP);
    yylval.node->op = OP_EQ;
    return TOK_REL_OP;
}

">=" {
    yylval.node = newTokenNode(TOK_REL_OP);
    yylval.node->op = OP_GE;
    return TOK_REL_OP;
}

">" {
    yylval.node = newTokenNode(TOK_REL_OP);
    yylval.node->op = OP_GT;
    return TOK_REL_OP;
}

"!=" {
    yylval.node = newTokenNode(TOK_REL_OP);
    yylval.node->op = OP_NE;
    return TOK_REL_OP;
}

, {
    yylval.node = newTokenNode(',');
    return ',';
}

:= {
    yylval.node = newTokenNode(TOK_ASSIGN_OP);
    return TOK_ASSIGN_OP;
}

; {
    yylval.node = newTokenNode(';');
    return ';';
}

: {
    yylval.node = newTokenNode(':');
    return ':';
}

\. {
    yylval.node = newTokenNode('.');
    return '.';
}

".." {
    yylval.node = newTokenNode(TOK_DOTDOT);
    return TOK_DOTDOT;
}

[0-9]+ {
    yylval.node = newTokenNode(TOK_INT_NUM);
    yylval.node->valueValid = VALUE_I_VALID;
    yylval.node->iValue = atoi(yytext);
    return TOK_INT_NUM;
}

[0-9]+\.[0-9]+ {
    yylval.node = newTokenNode(TOK_REAL_NUM);
    yylval.node->valueValid = VALUE_R_VALID;
    yylval.node->rValue = atof(yytext);
    return TOK_REAL_NUM;
}

%%

struct nodeType* newTokenNode(int tokenType) {
    struct nodeType *node = newNode(NODE_TOKEN);
    node->tokenType = tokenType;

    return node;
}

