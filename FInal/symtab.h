#ifndef _SYMTAB_H_
#define _SYMTAB_H_

#include "header.h"

void initSymTab(struct SymTable *table);
int hashFunc(const char *str);
void insertTab(struct SymTable *table, struct SymNode *newNode);
void pushLoopVar(struct SymTable *table, struct SymNode *newNode);
void popLoopVar(struct SymTable *table);

struct SymNode *createLoopVarNode(const char *name);
struct SymNode *createVarNode(const char *name, int scope, struct PType *type);
struct SymNode *createParamNode(const char *name, int scope, struct PType *type);
struct SymNode *createConstNode(const char *name, int scope, struct PType *pType, struct ConstAttr *constAttr);
struct SymNode *createFuncNode(const char *name, int scope, struct PType *pType, struct FuncAttr *params);
struct SymNode *createProgramNode(const char *name, int scope, struct PType *pType);

struct SymNode *lookupSymbol(struct SymTable *table, const char *id, int scope, __BOOLEAN currentScope);
struct SymNode *lookupLoopVar(struct SymTable *table, const char *id);

void deleteSymbol(struct SymNode *symbol);
void deleteScope(struct SymTable *table, int scope);

void printType(struct PType *type, int flag);
void dumpSymTable(struct SymTable *table);
void printSymTable(struct SymTable *table, int __scope);
#endif
