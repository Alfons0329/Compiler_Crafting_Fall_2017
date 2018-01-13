#ifndef _SEMCHECK_H_
#define _SEMCHECK_H_
#include "header.h"
#include "symtab.h"

struct idNode_sem *createIdList( const char *str );
void idlist_addNode( struct idNode_sem *node, const char *string );

struct ConstAttr *createConstAttr( SEMTYPE type, void *value );
struct PType *createPType( SEMTYPE type );
struct expr_sem *createExprSem( const char *id );
void increaseArrayDim( struct PType *pType, int lo, int hi );

void increaseDim( struct expr_sem* expr, SEMTYPE dimType );

struct param_sem *createParam( struct idNode_sem *ids, struct PType *pType );
void param_sem_addParam( struct param_sem *lhs, struct param_sem *rhs );

__BOOLEAN insertParamIntoSymTable( struct SymTable *table, struct param_sem *params, int scope );
void insertFuncIntoSymTable( struct SymTable *table, const char *id, struct param_sem *params, struct PType *retType, int scope );
void insertLoopVarIntoTable( struct SymTable *table, const char *id );
/* verification */
void verifyArrayDim( struct PType *pType, int lo, int hi );
void verifyArrayType( struct idNode_sem *ids, struct PType *pType );
__BOOLEAN verifyRedeclaration( struct SymTable *table, const char *str, int scope );
SEMTYPE verifyArrayIndex( struct expr_sem *expr );
__BOOLEAN verifyExistence( struct SymTable *table, struct expr_sem *expr, int scope, __BOOLEAN isAssignmentLHS );
void verifyAssignmentTypeMatch( struct expr_sem *LHS, struct expr_sem *RHS );
void verifyModOp( struct expr_sem *op1, struct expr_sem *op2 );
void verifyArithmeticOp( struct expr_sem *op1, OPERATOR operator, struct expr_sem *op2 );
void verifyRelOp( struct expr_sem *op1, OPERATOR operator, struct expr_sem *op2 );
void verifyUnaryNot( struct expr_sem *expr );
void verifyAndOrOp( struct expr_sem *op1, OPERATOR operator, struct expr_sem *op2 );
//struct expr_sem *verifyFuncInvoke( const char *id, struct expr_sem *exprList );
struct expr_sem *verifyFuncInvoke( const char *id, struct expr_sem *exprList, struct SymTable *table, int scope );
void verifyScalarExpr( struct expr_sem *expr, const char *str );
void verifyBooleanExpr( struct expr_sem *expr, const char *str );
void verifyReturnStatement( struct expr_sem *expr, struct PType *funcReturn );
void verifyLoopParam( int lo, int hi );
void verifyUnaryNOT( struct expr_sem *expr );
void verifyUnaryMinus( struct expr_sem *expr );


struct PType *copyPType( struct PType *src );
struct ArrayDimNode *copyArrayDimList( struct ArrayDimNode *src );

void deletePType( struct PType *type );
void deleteSymAttr( union SymAttr *attr, SEMTYPE category );
void deleteIdList( struct idNode_sem *idlist );

#endif

