#include <stdio.h>
#include "semcheck.h"
#include <stdlib.h>
#include <string.h>
#include "header.h"
#include "symtab.h"

extern int linenum;

void printOperator(OPERATOR op)
{
    switch (op)
    {
    case ADD_t:
        fprintf(stdout, "+");
        break;
    case SUB_t:
        fprintf(stdout, "-");
        break;
    case MUL_t:
        fprintf(stdout, "*");
        break;
    case DIV_t:
        fprintf(stdout, "/");
        break;
    case MOD_t:
        fprintf(stdout, "mod");
        break;
    case LT_t:
        fprintf(stdout, "<");
        break;
    case LE_t:
        fprintf(stdout, "<=");
        break;
    case EQ_t:
        fprintf(stdout, "=");
        break;
    case GE_t:
        fprintf(stdout, ">=");
        break;
    case GT_t:
        fprintf(stdout, ">");
        break;
    case NE_t:
        fprintf(stdout, "<>");
        break;
    case AND_t:
        fprintf(stdout, "and");
        break;
    case OR_t:
        fprintf(stdout, "or");
        break;
    default:
        /* FIXME */
        break;
    }
}

struct idNode_sem *createIdList(const char *str)
{
    struct idNode_sem *newNode = (struct idNode_sem *)malloc(sizeof(struct idNode_sem));
    newNode->value = (char *)malloc(sizeof(char) * (strlen(str) + 1));
    strcpy(newNode->value, str);
    newNode->next = NULL;
    return newNode;
}

struct ConstAttr *createConstAttr(SEMTYPE type, void *value)
{
    struct ConstAttr *result = (struct ConstAttr *)malloc(sizeof(struct ConstAttr));
    result->category = type;
    result->hasMinus = __FALSE;
    switch (type)
    {
    case INTEGER_t:
        result->value.integerVal = *(int *)value;
        if (*(int *)value < 0)
            result->hasMinus = __TRUE;
        break;
    case REAL_t:
        result->value.realVal = *(float *)value;
        if (*(float *)value < 0.0)
            result->hasMinus = __TRUE;
        break;
    case STRING_t:
        result->value.stringVal = (char *)malloc(sizeof(char) * (strlen((char *)value) + 1));
        strcpy(result->value.stringVal, (char *)value);
        break;
    case BOOLEAN_t:
        result->value.booleanVal = *(__BOOLEAN *)value;
        break;
    default:
        /* FIXME */
        break;
    }
    return result;
}

struct param_sem *createParam(struct idNode_sem *ids, struct PType *pType)
{
    struct param_sem *result = (struct param_sem *)malloc(sizeof(struct param_sem));
    result->idlist = ids;
    result->pType = pType;
    result->next = NULL;
    return result;
}

struct expr_sem *createExprSem(const char *id)
{
    struct expr_sem *result = (struct expr_sem *)malloc(sizeof(struct expr_sem));
    result->beginningOp = NONE_t;
    result->isDeref = __FALSE;
    result->varRef = (struct var_ref_sem *)malloc(sizeof(struct var_ref_sem));
    result->varRef->id = (char *)malloc(sizeof(char) * (strlen(id) + 1));
    strcpy(result->varRef->id, id);
    result->varRef->dimNum = 0;
    result->varRef->dim = 0;
    result->pType = NULL;
    result->next = NULL;
    return result;
}

void increaseDim(struct expr_sem *expr, SEMTYPE dimType)
{
    struct typeNode *newNode = (struct typeNode *)malloc(sizeof(struct typeNode));
    newNode->value = dimType;
    newNode->next = NULL;

    ++(expr->varRef->dimNum);
    if (expr->varRef->dim == NULL)
    { // the first dim
        expr->varRef->dim = newNode;
    }
    else
    { // others, attached after the last
        struct typeNode *typePtr;
        for (typePtr = (expr->varRef->dim); (typePtr->next) != NULL; typePtr = (typePtr->next))
            ;
        typePtr->next = newNode;
    }
}

void idlist_addNode(struct idNode_sem *node, const char *string)
{
    struct idNode_sem *newNode = (struct idNode_sem *)malloc(sizeof(struct idNode_sem));
    newNode->value = (char *)malloc(sizeof(char) * (strlen(string) + 1));
    strcpy(newNode->value, string);
    newNode->next = NULL;

    struct idNode_sem *ptr;
    for (ptr = node; (ptr->next) != NULL; ptr = (ptr->next))
        ;
    ptr->next = newNode;
}

void param_sem_addParam(struct param_sem *lhs, struct param_sem *rhs)
{
    struct param_sem *ptr;
    for (ptr = lhs; (ptr->next) != NULL; ptr = (ptr->next))
        ;
    ptr->next = rhs;
}

struct PType *createPType(SEMTYPE type)
{
    struct PType *result = (struct PType *)malloc(sizeof(struct PType));
    result->isError = __FALSE;
    result->isArray = __FALSE; // scalar
    result->type = type;
    result->dimNum = 0;
    result->dim = NULL;
    return result;
}

void increaseArrayDim(struct PType *pType, int lo, int hi)
{
    pType->isArray = __TRUE;

    // increase # of dim
    ++(pType->dimNum);
    // setup properties of newDim
    struct ArrayDimNode *newDim = (struct ArrayDimNode *)malloc(sizeof(struct ArrayDimNode));
    newDim->low = lo;
    newDim->high = hi;
    newDim->size = hi - lo + 1;
    newDim->next = NULL;
    // add newDim into pType, in the front of list
    newDim->next = pType->dim;
    pType->dim = newDim;
}

struct ArrayDimNode *copyArrayDimList(struct ArrayDimNode *src)
{
    struct ArrayDimNode *dest = NULL;
    struct ArrayDimNode *ptr = NULL; // ptr: points to the last element of new list
    struct ArrayDimNode *srcElem;
    for (srcElem = src; srcElem != NULL; srcElem = (srcElem->next))
    {
        struct ArrayDimNode *newNode = (struct ArrayDimNode *)malloc(sizeof(struct ArrayDimNode));
        newNode->low = srcElem->low;
        newNode->high = srcElem->high;
        newNode->size = srcElem->size;
        newNode->next = NULL;
        if (dest == NULL)
        { // copy the first element
            dest = newNode;
            ptr = newNode;
        }
        else
        { // attach to list
            ptr->next = newNode;
            ptr = newNode;
        }
    }
    return dest;
}

struct PType *copyPType(struct PType *src)
{
    struct PType *dest = NULL;
    if (src != NULL)
    {
        dest = (struct PType *)malloc(sizeof(struct PType));
        dest->isError = src->isError;
        dest->isArray = src->isArray;
        dest->type = src->type;
        dest->dimNum = src->dimNum;
        dest->dim = copyArrayDimList(src->dim);
    }
    return dest;
}

/* verification(s) */

void verifyLoopParam(int lo, int hi)
{
    if (lo < 0 || hi < 0)
    {
        fprintf(stdout, "<Error> found in Line %d: lower or upper bound of loop parameter < 0\n", linenum);
    }
    else if (lo > hi)
    {
        fprintf(stdout, "<Error> found in Line %d: loop parameter's lower bound > uppper bound\n", linenum);
    }
}

void verifyArrayDim(struct PType *pType, int lo, int hi)
{
    __BOOLEAN isPass = __TRUE;

    if (lo >= hi || lo < 1 || hi < 1)
    {
        isPass = __FALSE;
        pType->isError = __TRUE;
    }
}

void verifyArrayType(struct idNode_sem *ids, struct PType *pType)
{
    struct idNode_sem *ptr;
    if (pType->isError == __TRUE)
    {
        fprintf(stdout, "<Error> found in Line %d: wrong dimension declaration for array ", linenum);
        printf("%s", ids->value);
        for (ptr = ids->next; ptr != NULL; ptr = (ptr->next))
        {
            printf(", %s", ptr->value);
        }
        printf("\n");
    }
}

SEMTYPE verifyArrayIndex(struct expr_sem *expr)
{
    SEMTYPE result;
    if ((expr->isDeref == __FALSE) || (expr->pType->isArray == __TRUE) || (expr->pType->type != INTEGER_t))
    {
        fprintf(stdout, "<Error> found in Line %d: array index is not integer\n", linenum);
        result = ERROR_t;
    }
    else
    {
        result = INTEGER_t;
    }
    return result;
}

__BOOLEAN verifyRedeclaration(struct SymTable *table, const char *str, int scope)
{
    __BOOLEAN result = __TRUE;
    if ((lookupLoopVar(table, str) != NULL) || (lookupSymbol(table, str, scope, __TRUE) != NULL))
    { // first check loop variable(s), then check normal variable(s)
        fprintf(stdout, "<Error> found in Line %d: symbol '%s' is redeclared\n", linenum, str);
        result = __FALSE;
    }
    else
    {
        result = __TRUE;
    }
    return result;
}

__BOOLEAN verifyExistence(struct SymTable *table, struct expr_sem *expr, int scope, __BOOLEAN isAssignmentLHS)
{
    __BOOLEAN result = __TRUE;
    // expr is dereferenced...
    expr->isDeref = __TRUE;
    struct SymNode *node;
    node = lookupLoopVar(table, expr->varRef->id); // first check loop variable
    if (node == NULL)
    { // if not found, check normal symbol
        node = lookupSymbol(table, expr->varRef->id, scope, __FALSE);
    }
    if (node == NULL)
    { // symbol not found
        fprintf(stdout, "<Error> found in Line %d: '%s' is not declared\n", linenum, expr->varRef->id);
        expr->pType = createPType(ERROR_t);
        result = __FALSE;
    }
    else
    { // deference and verify, if pass, setup PType field in expr_sem
        if (node->category == PROGRAM_t)
        {
            fprintf(stdout, "<Error> found in Line %d: '%s' is program\n", linenum, node->name);
            expr->pType = createPType(ERROR_t);
            result = __FALSE;
        }
        else if (node->category == FUNCTION_t)
        {
            fprintf(stdout, "<Error> found in Line %d: '%s' is function\n", linenum, node->name);
            expr->pType = createPType(ERROR_t);
            result = __FALSE;
        }
        else if (node->category == LOOPVAR_t && isAssignmentLHS == __TRUE)
        {
            fprintf(stdout, "<Error> found in Line %d: loop variable '%s' cannot be assigned\n", linenum, node->name);
            expr->pType = createPType(ERROR_t);
            result = __FALSE;
        }
        else if (node->category == CONSTANT_t && isAssignmentLHS == __TRUE)
        {
            fprintf(stdout, "<Error> found in Line %d: constant '%s' cannot be assigned\n", linenum, node->name);
            expr->pType = createPType(ERROR_t);
            result = __FALSE;
        }
        else
        {
            if (expr->varRef->dimNum == 0)
            {
                expr->pType = copyPType(node->type);
            }
            else
            { // dereference dimension
                if (node->type->dimNum < expr->varRef->dimNum)
                {
                    fprintf(stdout, "<Error> found in Line %d: '%s' is %d dimension(s), but reference in %d dimension(s)\n", linenum, node->name, node->type->dimNum, expr->varRef->dimNum);
                    expr->pType = createPType(ERROR_t);
                    result = __FALSE;
                }
                else if (node->type->dimNum == expr->varRef->dimNum)
                { // result in scalar!
                    expr->pType = createPType(node->type->type);
                }
                else
                { // result in array type
                    expr->pType = (struct PType *)malloc(sizeof(struct PType));
                    expr->pType->isError = __FALSE;
                    expr->pType->isArray = __TRUE;
                    expr->pType->type = node->type->type;
                    expr->pType->dimNum = (node->type->dimNum) - (expr->varRef->dimNum);

                    int i;
                    struct ArrayDimNode *arrPtr;
                    for (i = 0, arrPtr = (node->type->dim); i < (expr->varRef->dimNum); i++, arrPtr = (arrPtr->next))
                        ;
                    expr->pType->dim = copyArrayDimList(arrPtr);
                }
            }
        }
    }
    return result;
}

void verifyUnaryMinus(struct expr_sem *expr)
{
    expr->beginningOp = SUB_t;

    if (expr->isDeref == __FALSE)
    {
        fprintf(stdout, "<Error> found in Line %d: operand of unary - is not integer/real\n", linenum);
        expr->isDeref = __TRUE;
        expr->pType->type = ERROR_t;
    }
    else if (!(((expr->pType->type) == INTEGER_t) || ((expr->pType->type) == REAL_t)))
    {
        fprintf(stdout, "<Error> found in Line %d: operand of unary - is not integer/real\n", linenum);
        expr->pType->type = ERROR_t;
    }
}

void verifyUnaryNOT(struct expr_sem *expr)
{
    expr->beginningOp = NOT_t;

    if (expr->pType->dimNum != 0)
    {
        fprintf(stdout, "<Error> found in Line %d: operand of operator 'not' cannot be array type\n", linenum);
        expr->pType->type = ERROR_t;
    }
    else if (expr->pType->type != BOOLEAN_t)
    {
        fprintf(stdout, "<Error> found in Line %d: operand of operator 'not' is not boolean\n", linenum);
        expr->pType->type = ERROR_t;
    }
    else
    { // pass verification, result is boolean
        expr->pType->type = BOOLEAN_t;
    }
}

void verifyAssignmentTypeMatch(struct expr_sem *LHS, struct expr_sem *RHS)
{
    __BOOLEAN misMatch = __FALSE;

    if ((LHS->pType->type) == ERROR_t || (RHS->pType->type) == ERROR_t)
    { // previous error(s)
        if ((LHS->pType->type) == ERROR_t)
            fprintf(stdout, "<Error> found in Line %d: error type in LHS of assignment\n", linenum);
        if ((RHS->pType->type) == ERROR_t)
            fprintf(stdout, "<Error> found in Line %d: error type in RHS of assignment\n", linenum);
    }
    else if (LHS->pType->type != RHS->pType->type)
    { // verify type
        if (!(LHS->pType->type == REAL_t && RHS->pType->type == INTEGER_t))
        {
            misMatch = __TRUE;
        }
    }
    // verify dimension #
    if (LHS->pType->dimNum != RHS->pType->dimNum)
    {
        misMatch = __TRUE;
    }
    else
    { // dim # is the same, verify each dim(s)
        struct ArrayDimNode *lhsPtr, *rhsPtr;
        for (lhsPtr = (LHS->pType->dim), rhsPtr = (RHS->pType->dim); lhsPtr != 0; lhsPtr = (lhsPtr->next), rhsPtr = (rhsPtr->next))
        {
            if (lhsPtr->size != rhsPtr->size)
            {
                misMatch = __TRUE;
                break;
            }
        }
    }

    if (misMatch == __TRUE)
    {
        fprintf(stdout, "<Error> found in Line %d: type mismatch, LHS= ", linenum);
        printType(LHS->pType, 0);
        fprintf(stdout, ", RHS= ");
        printType(RHS->pType, 0);
        fprintf(stdout, "\n");
    }
    else if (LHS->pType->dimNum != 0)
    { // array assignment
        fprintf(stdout, "<Error> found in Line %d: array assignment is not allowed\n", linenum);
    }
}

void verifyModOp(struct expr_sem *op1, struct expr_sem *op2)
{
    if ((op1->pType->type) == ERROR_t || (op2->pType->type) == ERROR_t)
    {
        op1->pType->type = ERROR_t;
        if ((op1->pType->type) == ERROR_t)
            fprintf(stdout, "<Error> found in Line %d: error in left operand of 'mod' operator\n", linenum);
        if ((op2->pType->type) == ERROR_t)
            fprintf(stdout, "<Error> found in Line %d: error in right operand of 'mod' operator\n", linenum);
    }
    else if (op2->beginningOp != NONE_t)
    {
        fprintf(stdout, "<Error> found in Line %d: adjacent operator 'mod", linenum);
        fprintf(stdout, "' and '");
        printOperator(op2->beginningOp);
        fprintf(stdout, "'\n");
        op1->pType->type = ERROR_t;
    }
    else if ((op1->pType->dimNum) != 0 || (op2->pType->dimNum) != 0)
    {
        fprintf(stdout, "<Error> found in Line %d: one of the operands of operator 'mod' is array type\n", linenum);
        op1->pType->type = ERROR_t;
    }
    else if ((op1->pType->type) != INTEGER_t || (op2->pType->type) != INTEGER_t)
    {
        fprintf(stdout, "<Error> found in Line %d: one of the operands of operator 'mod' is not integer\n", linenum);
        op1->pType->type = ERROR_t;
    }
    else
    { // pass verify
        op1->pType->type = INTEGER_t;
    }
}

void verifyArithmeticOp(struct expr_sem *op1, OPERATOR operator, struct expr_sem *op2)
{
    if ((op1->pType->type) == ERROR_t || (op2->pType->type) == ERROR_t)
    {
        op1->pType->type = ERROR_t;
        if ((op1->pType->type) == ERROR_t)
        {
            fprintf(stdout, "<Error> found in Line %d: error in left operand of '", linenum);
            printOperator(operator);
            fprintf(stdout, "' operator\n");
        }
        if ((op2->pType->type) == ERROR_t)
        {
            fprintf(stdout, "<Error> found in Line %d: error in right operand of '", linenum);
            printOperator(operator);
            fprintf(stdout, "' operator\n");
        }
    }
    else if (op2->beginningOp != NONE_t)
    {
        fprintf(stdout, "<Error> found in Line %d: adjacent operator '", linenum);
        printOperator(operator);
        fprintf(stdout, "' and '");
        printOperator(op2->beginningOp);
        fprintf(stdout, "'\n");
        op1->pType->type = ERROR_t;
    }
    else if ((op1->pType->dimNum) != 0 || (op2->pType->dimNum) != 0)
    {
        fprintf(stdout, "<Error> found in Line %d: one of the operands of operator '", linenum);
        printOperator(operator);
        fprintf(stdout, "' is array type\n");
        op1->pType->type = ERROR_t;
    }
    else if (op1->pType->type == STRING_t && op2->pType->type == STRING_t)
    { // string concatenation
        if (operator== ADD_t)
        {
            op1->pType->type = STRING_t;
        }
        else
        {
            fprintf(stdout, "<Error> found in Line %d: one of the operands of operator '", linenum);
            printOperator(operator);
            fprintf(stdout, "' is string type\n");
        }
    }
    else if (((op1->pType->type == INTEGER_t || op1->pType->type == REAL_t) &&
              (op2->pType->type == INTEGER_t || op2->pType->type == REAL_t)))
    { // need to consider type coercion
        if (op1->pType->type == INTEGER_t && op2->pType->type == INTEGER_t)
        {
            op1->pType->type = INTEGER_t;
        }
        else
        {
            op1->pType->type = REAL_t;
        }
    }
    else
    { // fail verify, dump error message
        fprintf(stdout, "<Error> found in Line %d: operands of operator '", linenum);
        printOperator(operator);
        fprintf(stdout, "' are not both integer or both real\n");
        op1->pType->type = ERROR_t;
    }
}

void verifyRelOp(struct expr_sem *op1, OPERATOR operator, struct expr_sem *op2)
{
    if ((op1->pType->type) == ERROR_t || (op2->pType->type) == ERROR_t)
    {
        op1->pType->type = ERROR_t;
        if ((op1->pType->type) == ERROR_t)
        {
            fprintf(stdout, "<Error> found in Line %d: error in left operand of '", linenum);
            printOperator(operator);
            fprintf(stdout, "' operator\n");
        }
        if ((op2->pType->type) == ERROR_t)
        {
            fprintf(stdout, "<Error> found in Line %d: error in right operand of '", linenum);
            printOperator(operator);
            fprintf(stdout, "' operator\n");
        }
    }
    else if (op2->beginningOp != NONE_t)
    {
        fprintf(stdout, "<Error> found in Line %d: adjacent operator '", linenum);
        printOperator(operator);
        fprintf(stdout, "' and '");
        printOperator(op2->beginningOp);
        fprintf(stdout, "'\n");
        op1->pType->type = ERROR_t;
    }
    else if ((op1->pType->dimNum) != 0 || (op2->pType->dimNum) != 0)
    {
        fprintf(stdout, "<Error> found in Line %d: one of the operands of operator '", linenum);
        printOperator(operator);
        fprintf(stdout, "' is array type\n");
        op1->pType->type = ERROR_t;
    }
    else if (!((op1->pType->type == INTEGER_t && op2->pType->type == INTEGER_t) || (op1->pType->type == REAL_t && op2->pType->type == REAL_t)))
    {
        fprintf(stdout, "<Error> found in Line %d: operands of operator '", linenum);
        printOperator(operator);
        fprintf(stdout, "' are not both integer or both real\n");
        op1->pType->type = ERROR_t;
    }
    else
    { // pass verification, result is boolean!
        op1->pType->type = BOOLEAN_t;
    }
}

void verifyAndOrOp(struct expr_sem *op1, OPERATOR operator, struct expr_sem *op2)
{
    if ((op1->pType->type) == ERROR_t || (op2->pType->type) == ERROR_t)
    {
        op1->pType->type = ERROR_t;
        if ((op1->pType->type) == ERROR_t)
        {
            fprintf(stdout, "<Error> found in Line %d: error in left operand of '", linenum);
            printOperator(operator);
            fprintf(stdout, "' operator\n");
        }
        if ((op2->pType->type) == ERROR_t)
        {
            fprintf(stdout, "<Error> found in Line %d: error in right operand of '", linenum);
            printOperator(operator);
            fprintf(stdout, "' operator\n");
        }
    }
    else if (op2->beginningOp != NONE_t)
    {
        fprintf(stdout, "<Error> found in Line %d: adjacent operator '", linenum);
        printOperator(operator);
        fprintf(stdout, "' and '");
        printOperator(op2->beginningOp);
        fprintf(stdout, "'\n");
        op1->pType->type = ERROR_t;
    }
    else if ((op1->pType->dimNum) != 0 || (op2->pType->dimNum) != 0)
    {
        fprintf(stdout, "<Error> found in Line %d: one of the operands of operator '", linenum);
        printOperator(operator);
        fprintf(stdout, "' is array type\n");
        op1->pType->type = ERROR_t;
    }
    else if ((op1->pType->type) != BOOLEAN_t || (op2->pType->type) != BOOLEAN_t)
    {
        fprintf(stdout, "<Error> found in Line %d: one of the operands of operator '", linenum);
        printOperator(operator);
        fprintf(stdout, "' is not boolean\n");
        op1->pType->type = ERROR_t;
    }
    else
    { // pass verification, result is boolean!
        op1->pType->type = BOOLEAN_t;
    }
}

struct expr_sem *verifyFuncInvoke(const char *id, struct expr_sem *exprList, struct SymTable *table, int scope)
{
    (void)scope;
    struct expr_sem *result = (struct expr_sem *)malloc(sizeof(struct expr_sem));
    // setup attributes except `pType`
    result->beginningOp = NONE_t;
    result->isDeref = __TRUE;
    result->varRef = 0;
    result->next = 0;

    struct SymNode *node = 0;
    node = lookupSymbol(table, id, 0, __FALSE); // function always in scope 0 (global scope)

    if (node == NULL)
    { // symbol not found
        fprintf(stdout, "<Error> found in Line %d: symbol '%s' not found\n", linenum, id);
        result->pType = createPType(ERROR_t);
    }
    else if (node->category != FUNCTION_t)
    {
        fprintf(stdout, "<Error> found in Line %d: symbol '%s' is not a function\n", linenum, id);
        result->pType = createPType(ERROR_t);
    }
    else
    { // check parameters...
        if (node->attribute->formalParam->paramNum == 0)
        {
            if (exprList != NULL)
            {
                fprintf(stdout, "<Error> found in Line %d: too many arguments to function '%s'\n", linenum, node->name);
                result->pType = createPType(ERROR_t);
            }
            else
            {
                result->pType = node->type; // return type of function declaration
            }
        }
        else
        {
            __BOOLEAN mismatch = __FALSE;
            struct PTypeList *listPtr;
            struct expr_sem *exprPtr;
            for (listPtr = (node->attribute->formalParam->params), exprPtr = exprList; (listPtr != 0) && (exprPtr != 0); listPtr = (listPtr->next), exprPtr = (exprPtr->next))
            { // compare each parameter
                if (listPtr->value->type != exprPtr->pType->type)
                { // verify type
                    if (!((listPtr->value->type == REAL_t) && (exprPtr->pType->type == INTEGER_t)))
                        mismatch = __TRUE;
                }
                if (listPtr->value->dimNum != exprPtr->pType->dimNum)
                { // verify dimension #
                    mismatch = __TRUE;
                }
                else
                { // dim # is the same, verify each dim(s)
                    struct ArrayDimNode *lhsPtr, *rhsPtr;
                    for (lhsPtr = (listPtr->value->dim), rhsPtr = (exprPtr->pType->dim); lhsPtr != 0; lhsPtr = (lhsPtr->next), rhsPtr = (rhsPtr->next))
                    {
                        if (lhsPtr->size != rhsPtr->size)
                        {
                            mismatch = __TRUE;
                            break;
                        }
                    }
                }
            }
            if (mismatch == __TRUE)
            {
                fprintf(stdout, "<Error> found in Line %d: parameter type mismatch\n", linenum);
                result->pType = createPType(ERROR_t);
            }
            else
            {
                if (listPtr != NULL)
                {
                    fprintf(stdout, "<Error> found in Line %d: too few arguments to function '%s'\n", linenum, node->name);
                    result->pType = createPType(ERROR_t);
                }
                else if (exprPtr != NULL)
                {
                    fprintf(stdout, "<Error> found in Line %d: too many arguments to function '%s'\n", linenum, node->name);
                    result->pType = createPType(ERROR_t);
                }
                else
                {
                    result->pType = node->type;
                }
            }
        }
    }
    return result;
}

void verifyScalarExpr(struct expr_sem *expr, const char *str)
{
    if (expr->pType->type == ERROR_t)
        ;
    else if (expr->pType->dim)
    {
        fprintf(stdout, "<Error> found in Line %d: operand of %s statement is array type\n", linenum, str);
    }
}

void verifyBooleanExpr(struct expr_sem *expr, const char *str)
{
    if (expr->pType->type == ERROR_t)
    {
        fprintf(stdout, "<Error> found in Line %d: operand of %s statement is not boolean type\n", linenum, str);
    }
    else if (expr->pType->dim)
    {
        fprintf(stdout, "<Error> found in Line %d: operand of %s statement is array type\n", linenum, str);
    }
    else if (expr->pType->type != BOOLEAN_t)
    {
        fprintf(stdout, "<Error> found in Line %d: operand of %s statement is not boolean type\n", linenum, str);
    }
}

void verifyReturnStatement(struct expr_sem *expr, struct PType *funcReturn)
{
    if (funcReturn == 0)
    {
        fprintf(stdout, "<Error> found in Line %d: program cannot be returned\n", linenum);
    }
    else if (funcReturn->type == VOID_t)
    {
        fprintf(stdout, "<Error> found in Line %d: void function cannot be returned\n", linenum);
    }
    else if (funcReturn->type != expr->pType->type)
    {
        fprintf(stdout, "<Error> found in Line %d: return type mismatch\n", linenum);
    }
    else if (funcReturn->dimNum != expr->pType->dimNum)
    {
        fprintf(stdout, "<Error> found in Line %d: return dimension number mismatch\n", linenum);
    }
    else
    {
        struct ArrayDimNode *returnDim, *exprDim;
        int i;
        for (returnDim = (funcReturn->dim), exprDim = (expr->pType->dim), i = 0; returnDim != 0; returnDim = (returnDim->next), exprDim = (exprDim->next), ++i)
        {
            if (returnDim->size != exprDim->size)
            {
                fprintf(stdout, "<Error> found in Line %d: size of #%d-th dimension in return statement mismatch\n", linenum, i);
            }
        }
    }
}

__BOOLEAN insertParamIntoSymTable(struct SymTable *table, struct param_sem *params, int scope)
{
    __BOOLEAN result = __FALSE;

    struct param_sem *parPtr;
    struct idNode_sem *idPtr;
    struct SymNode *newNode;
    for (parPtr = params; parPtr != NULL; parPtr = (parPtr->next))
    {
        if (parPtr->pType->isError == __TRUE)
        {
            result = __TRUE;
        }
        else
        {
            for (idPtr = (parPtr->idlist); idPtr != NULL; idPtr = (idPtr->next))
            {
                if (verifyRedeclaration(table, idPtr->value, scope) == __FALSE)
                {
                    result = __TRUE;
                }
                else
                { // without error, insert into symbol table
                    newNode = createParamNode(idPtr->value, scope, parPtr->pType);
                    insertTab(table, newNode);
                }
            }
        }
    }
    return result; // __TRUE: with some error(s)
}

void insertFuncIntoSymTable(struct SymTable *table, const char *id, struct param_sem *params, struct PType *retType, int scope)
{
    if (verifyRedeclaration(table, id, scope) == __FALSE)
    {
        return;
    }
    struct FuncAttr *formalParam = (struct FuncAttr *)malloc(sizeof(struct FuncAttr));
    formalParam->paramNum = 0;
    formalParam->params = NULL;

    if (params != NULL)
    {
        struct param_sem *parPtr;
        struct idNode_sem *idPtr;

        struct PTypeList *lastPtr = NULL; // incicate the last element in PType list

        for (parPtr = params; parPtr != NULL; parPtr = (parPtr->next))
        {
            for (idPtr = (parPtr->idlist); idPtr != NULL; idPtr = (idPtr->next))
            {
                if (formalParam->paramNum == 0)
                { // add the first entry
                    formalParam->params = (struct PTypeList *)malloc(sizeof(struct PTypeList));
                    formalParam->params->value = copyPType(parPtr->pType);
                    formalParam->params->next = NULL;

                    ++(formalParam->paramNum);

                    lastPtr = formalParam->params;
                }
                else
                {
                    struct PTypeList *newPTypeList = (struct PTypeList *)malloc(sizeof(struct PTypeList));
                    newPTypeList->value = copyPType(parPtr->pType);
                    newPTypeList->next = NULL;
                    lastPtr->next = newPTypeList;
                    ++(formalParam->paramNum);

                    lastPtr = (lastPtr->next);
                }
            }
        }
    }

    struct SymNode *newNode = createFuncNode(id, scope, retType, formalParam);
    insertTab(table, newNode);
}

void insertLoopVarIntoTable(struct SymTable *table, const char *id)
{
    struct SymNode *nodePtr = 0;
    nodePtr = lookupLoopVar(table, id);
    if (nodePtr != 0)
    {
        fprintf(stdout, "<Error> found in Line %d: symbol '%s' is redeclared\n", linenum, id);
        // Push it even redeclared, it will be pop out when leave
        pushLoopVar(table, createLoopVarNode(id));
    }
    else
    {
        pushLoopVar(table, createLoopVarNode(id));
    }
}

void deletePType(struct PType *type)
{
    struct ArrayDimNode *cur, *next;
    if (type != NULL)
    {
        for (cur = type->dim; cur != NULL; cur = next)
        {
            next = cur->next;
            free(cur);
        }
        free(type);
    }
}

void deleteSymAttr(union SymAttr *attr, SEMTYPE category)
{
    if (attr != 0)
    {
        if (category == CONSTANT_t)
        {
            if (attr->constVal->category == STRING_t)
            {
                free(attr->constVal->value.stringVal);
            }
            free(attr->constVal);
        }
        else if (category == FUNCTION_t)
        {
            if (attr->formalParam->params != NULL)
            {
                struct PTypeList *cur, *next;
                for (cur = (attr->formalParam->params); cur != NULL; cur = next)
                {
                    next = cur->next;
                    deletePType(cur->value);
                    free(cur);
                }
            }
            free(attr->formalParam);
        }
        free(attr);
    }
}

void deleteIdList(struct idNode_sem *idlist)
{
    if (idlist == NULL)
        return;
    struct idNode_sem *current, *previous;
    for (current = (idlist->next), previous = idlist; current != NULL; previous = current, current = (current->next))
    {
        if (previous->value != NULL)
            free(previous->value);
        free(previous);
    }
    if (previous->value != NULL)
        free(previous->value);
    free(previous);
}
