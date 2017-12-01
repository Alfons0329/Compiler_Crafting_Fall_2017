#ifndef __SYMTAB_H___
#define __SYMTAB_H___

enum StdType {TypeInt, TypeReal};

struct SymTableEntry {
    char name[100];
    enum StdType type;
};

struct SymTable {
    int size;
    struct SymTableEntry entries[100];
};

extern struct SymTable SymbolTable;

#include "node.h"
void semanticCheck(struct nodeType* node);

#endif

