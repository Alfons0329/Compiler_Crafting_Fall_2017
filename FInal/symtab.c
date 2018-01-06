#include "header.h"
#include "symtab.h"
#include "semcheck.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void initSymTab(struct SymTable *table)
{
	int i;
	for (i = 0; i < HASHBUNCH; ++i)
		table->entry[i] = NULL;
	table->loopVarDepth = 0;
	table->loopVar = NULL;
}

int hashFunc(const char *str)
{
	size_t str_length = strlen(str);
	size_t i;
	int result = 0;

	for (i = 0; i < str_length; ++i)
	{
		i += str[i];
	}

	return (result % HASHBUNCH);
}

void insertTab(struct SymTable *table, struct SymNode *newNode)
{
	int location = hashFunc(newNode->name);

	if (table->entry[location] == NULL)
	{ // the first entry
		table->entry[location] = newNode;
	}
	else
	{
		struct SymNode *nodePtr;
		for (nodePtr = table->entry[location]; (nodePtr->next) != 0; nodePtr = nodePtr->next)
			;
		nodePtr->next = newNode;
		newNode->prev = nodePtr;
	}
}

void pushLoopVar(struct SymTable *table, struct SymNode *newNode)
{
	if (table->loopVar == 0)
	{ // the first
		table->loopVar = newNode;
	}
	else
	{
		struct SymNode *nodePtr;
		for (nodePtr = (table->loopVar); (nodePtr->next) != 0; nodePtr = (nodePtr->next))
			;
		nodePtr->next = newNode;
		newNode->prev = nodePtr;
	}

	(table->loopVarDepth)++;
}

void popLoopVar(struct SymTable *table)
{
	struct SymNode *nodePtr;
	if (table->loopVar->next == 0)
	{
		table->loopVar = 0;
	}
	else
	{
		for (nodePtr = (table->loopVar); (nodePtr->next->next) != 0; nodePtr = (nodePtr->next))
			;
		nodePtr->next = 0;
	}
	(table->loopVarDepth)--;
}

struct SymNode *createLoopVarNode(const char *name)
{
	struct SymNode *newNode = (struct SymNode *)malloc(sizeof(struct SymNode));
	// setup name
	newNode->name = (char *)malloc(sizeof(char) * (strlen(name) + 1));
	strcpy(newNode->name, name);
	// setup kind: variable
	newNode->category = LOOPVAR_t;
	// setup scope
	newNode->scope = -1;
	// setup type
	newNode->type = (struct PType *)malloc(sizeof(struct PType));
	newNode->type->isError = __FALSE;
	newNode->type->isArray = __FALSE;
	newNode->type->type = INTEGER_t;
	newNode->type->dimNum = 0;
	newNode->type->dim = 0;
	// without attribute
	newNode->attribute = 0;

	newNode->next = 0;
	newNode->prev = 0;

	return newNode;
}

struct SymNode *createVarNode(const char *name, int scope, struct PType *type)
{
	struct SymNode *newNode = (struct SymNode *)malloc(sizeof(struct SymNode));
	// setup name
	newNode->name = (char *)malloc(sizeof(char) * (strlen(name) + 1));
	strcpy(newNode->name, name);
	// setup kind: variable
	newNode->category = VARIABLE_t;
	// setup scope
	newNode->scope = scope;
	// setup type
	newNode->type = type;
	// without attribute
	newNode->attribute = NULL;

	newNode->next = NULL;
	newNode->prev = NULL;

	return newNode;
}

struct SymNode *createParamNode(const char *name, int scope, struct PType *type)
{
	struct SymNode *newNode = (struct SymNode *)malloc(sizeof(struct SymNode));
	// setup name
	newNode->name = (char *)malloc(sizeof(char) * (strlen(name) + 1));
	strcpy(newNode->name, name);
	// setup kind: parameter
	newNode->category = PARAMETER_t;
	// setup scope
	newNode->scope = scope;
	// setup type
	newNode->type = type;
	// without attribute
	newNode->attribute = 0;

	newNode->next = 0;
	newNode->prev = 0;

	return newNode;
}

struct SymNode *createConstNode(const char *name, int scope, struct PType *pType, struct ConstAttr *constAttr)
{
	struct SymNode *newNode = (struct SymNode *)malloc(sizeof(struct SymNode));
	// setup name /
	newNode->name = (char *)malloc(sizeof(char) * (strlen(name) + 1));
	strcpy(newNode->name, name);
	// setup kind: constant
	newNode->category = CONSTANT_t;
	// setup scope
	newNode->scope = scope;
	// setup type
	newNode->type = pType;
	// setup attribute
	newNode->attribute = (union SymAttr *)malloc(sizeof(union SymAttr));
	newNode->attribute->constVal = constAttr;

	newNode->next = 0;
	newNode->prev = 0;

	return newNode;
}

struct SymNode *createFuncNode(const char *name, int scope, struct PType *pType, struct FuncAttr *params)
{
	struct SymNode *newNode = (struct SymNode *)malloc(sizeof(struct SymNode));
	// setup name
	newNode->name = (char *)malloc(sizeof(char) * (strlen(name) + 1));
	strcpy(newNode->name, name);
	// setup kind: function
	newNode->category = FUNCTION_t;
	// setup scope
	newNode->scope = scope;
	// setup type
	newNode->type = pType;
	// setup attribute
	newNode->attribute = (union SymAttr *)malloc(sizeof(union SymAttr));
	newNode->attribute->formalParam = params;

	newNode->next = 0;
	newNode->prev = 0;

	return newNode;
}

struct SymNode *createProgramNode(const char *name, int scope, struct PType *pType)
{
	struct SymNode *newNode = (struct SymNode *)malloc(sizeof(struct SymNode));

	// setup name
	newNode->name = (char *)malloc(sizeof(char) * (strlen(name) + 1));
	strcpy(newNode->name, name);
	// setup kind: program
	newNode->category = PROGRAM_t;
	// setup scope
	newNode->scope = scope;
	// setup type: void
	newNode->type = pType;
	// without attribute
	newNode->attribute = NULL;

	newNode->next = NULL;
	newNode->prev = NULL;

	return newNode;
}

/**
 * __BOOLEAN currentScope: true: only search current scope
 */
struct SymNode *lookupSymbol(struct SymTable *table, const char *id, int scope, __BOOLEAN currentScope)
{
	int index = hashFunc(id);

	struct SymNode *nodePtr;
	for (nodePtr = (table->entry[index]); nodePtr != NULL; nodePtr = (nodePtr->next))
	{
		if (((nodePtr->scope) == scope) && !strcmp(nodePtr->name, id))
		{
			return nodePtr;
		}
	}
	// not found...
	if ((currentScope == __TRUE) || (scope == 0))
	{
		return NULL;
	}
	return lookupSymbol(table, id, scope - 1, __FALSE);
}

struct SymNode *lookupLoopVar(struct SymTable *table, const char *id)
{
	int depth = table->loopVarDepth;
	int i;
	struct SymNode *nodePtr;
	for (i = 0, nodePtr = (table->loopVar); i < depth; i++, nodePtr = (nodePtr->next))
	{
		if (!strcmp(nodePtr->name, id))
		{
			return nodePtr;
		}
	}
	return NULL;
}

void deleteSymbol(struct SymNode *symbol)
{
	// delete name
	if (symbol->name != 0)
		free(symbol->name);
	// delete PType
	//deletePType( symbol->type );
	// delete SymAttr, according to category
	deleteSymAttr(symbol->attribute, symbol->category);
	symbol->next = 0;
	symbol->prev = 0;

	free(symbol);
}

void deleteScope(struct SymTable *table, int scope)
{
	int i;
	struct SymNode *current, *next;
	for (i = 0; i < HASHBUNCH; ++i)
	{
		for (current = (table->entry[i]); current != 0; current = next)
		{
			next = current->next;
			if (current->scope == scope)
			{
				if (current->prev == 0)
				{
					if (next != 0)
						next->prev = 0;
					table->entry[i] = current->next;
					deleteSymbol(current);
				}
				else
				{
					if (next != 0)
						next->prev = current->prev;
					current->prev->next = next;
					deleteSymbol(current);
				}
			}
		}
	}
}
/**
 * if flag == 1, invoked at symbol table dump
 */
void printType(struct PType *type, int flag)
{
	char buffer[50];
	memset(buffer, 0, sizeof(buffer));
	struct PType *pType = type;

	switch (pType->type)
	{
	case INTEGER_t:
		sprintf(buffer, "integer");
		break;
	case REAL_t:
		sprintf(buffer, "real");
		break;
	case BOOLEAN_t:
		sprintf(buffer, "boolean");
		break;
	case STRING_t:
		sprintf(buffer, "string");
		break;
	case VOID_t:
		sprintf(buffer, "void");
		break;
	default:
		/* FIXME */
		break;
	}

	int i;
	struct ArrayDimNode *ptrr;

	if (pType->dimNum > 0)
	{
		strcat(buffer, " ");
	}

	for (i = 0, ptrr = pType->dim; i < (pType->dimNum); i++, ptrr = (ptrr->next))
	{
		char buf[15];
		memset(buf, 0, sizeof(buf));
		sprintf(buf, "[%d]", ptrr->size);
		//printf("[%d]", ptrr->size);
		strcat(buffer, buf);
	}
	if (flag == 1)
		printf("%-17s", buffer);
	else
		printf("%s", buffer);
}

void printSymTable(struct SymTable *table, int __scope)
{
	int i;
	for (i = 0; i < 110; i++)
	{
		printf("=");
	}
	printf("\n");
	//printf("================================================================================================================\n");
	printf("%-33s%-11s%-11s%-17s%-11s\n", "Name", "Kind", "Level", "Type", "Attribute");
	// Name [33 space] Kind [11 space] Level [11 space] Type [17 space] Attribute
	//printf("Name                             Kind       Level      Type                             Attribute               \n");
	//printf("----------------------------------------------------------------------------------------------------------------\n");
	for (i = 0; i < 110; i++)
	{
		printf("-");
	}
	printf("\n");
	struct SymNode *ptr;
	for (i = 0; i < HASHBUNCH; i++)
	{
		for (ptr = (table->entry[i]); ptr != 0; ptr = (ptr->next))
		{
			if (ptr->scope == __scope)
			{
				// Name
				printf("%-33s", ptr->name);

				// Kind
				switch (ptr->category)
				{
				case VARIABLE_t:
					printf("%-11s", "variable");
					break;
				case CONSTANT_t:
					printf("%-11s", "constant");
					break;
				case PROGRAM_t:
					printf("%-11s", "program");
					break;
				case FUNCTION_t:
					printf("%-11s", "function");
					break;
				case PARAMETER_t:
					printf("%-11s", "parameter");
					break;
				default:
					/* FIXME */
					break;
				}

				// Level
				if (ptr->scope == 0)
				{
					printf("%d%-10s", ptr->scope, "(global)");
				}
				else
				{
					printf("%d%-10s", ptr->scope, "(local)");
				}

				// Type
				printType(ptr->type, 1);

				// Attribute
				if (ptr->category == FUNCTION_t)
				{
					int i;
					struct PTypeList *pTypePtr;
					for (i = 0, pTypePtr = (ptr->attribute->formalParam->params); i < (ptr->attribute->formalParam->paramNum); i++, pTypePtr = (pTypePtr->next))
					{
						printType(pTypePtr->value, 0);
						if (i < (ptr->attribute->formalParam->paramNum) - 1)
						{
							printf(", ");
						}
					}
				}
				else if (ptr->category == CONSTANT_t)
				{
					switch (ptr->attribute->constVal->category)
					{
					case INTEGER_t:
						printf("%d", ptr->attribute->constVal->value.integerVal);
						break;
					case REAL_t:
						printf("%lf", ptr->attribute->constVal->value.realVal);
						break;
					case BOOLEAN_t:
						if (ptr->attribute->constVal->value.booleanVal == __TRUE)
							printf("true");
						else
							printf("false");
						break;
					case STRING_t:
						printf("\"%s\"", ptr->attribute->constVal->value.stringVal);
						break;
					default:
						/* FIXME */
						break;
					}
				}

				printf("\n");
			} // if( ptr->scope == __scope )
		}	 // for( ptr=(table->entry[i]) ; ptr!=0 ; ptr=(ptr->next) )
	}		  // for( i=0 ; i<HASHBUNCH ; i++ )
	for (i = 0; i < 110; i++)
		printf("-");
	printf("\n");
}
