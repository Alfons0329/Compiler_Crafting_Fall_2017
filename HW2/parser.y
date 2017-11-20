%{
#include <stdio.h>
#include <stdlib.h>

extern int linenum;             /* declared in lex.l */
extern FILE *yyin;              /* declared by lex */
extern char *yytext;            /* declared by lex */
extern char buf[256];           /* declared in lex.l */
%}
// symbols
%token COMMA SEMICOLON COLON BRACELEFT BRACERIGHT BRACKETLEFT BRACKETRIGHT

//assign, which is right associative

// mathematical operators
%right ASSIGN
%left LESS LESSEQUAL LESSGREATER GREATEREQUAL GREATER EQUAL
%left PLUS MINUS
%left MULTIPLY DIVIDE MOD
%left NOT
%left AND OR
%nonassoc UNARY_NEGATIVE

// logical operators


// KW
%token KWARRAY KWBEGIN KWBOOLEAN KWDEF KWDO KWELSE KWEND KWFALSSE KWFOR KWINTEGER
%token KWIF KWOF KWPRINT KWREAD KWREAL KWSTRING KWTHEN KWTO KWTRUE KWFALSE KWRETURN KWVAR KWWHILE

//mathematical numbers
%token OCTAL INTEGER REAL

//identifier
%token IDENT

//others
%token STRING

%%
/*use non-capital for non terminal and capital for terminal*/
/*2.1  Program Units */
/*Program */
program	: programname SEMICOLON programbody KWEND IDENT /*{printf("pgrm->");} */
		;

programname	: IDENT /*{printf("programname->");} */
		;

programbody : var_const_decl_list  func_decl_list  compound_statement  /*{printf("programbody->");}*/ //these list should be zero or more
		;

var_const_decl_list : 	var_const_decl_list var_const_decl /*{printf("1->");}*/|
						var_const_decl /*{printf("2->");}*/|
						epsilon
		;

var_const_decl :	var_decl /*{printf("4->");}*/|
					array_decl /*{printf("5->");}*/|
					const_decl /*{printf("6->");} */
		;

func_decl_list : 	func_decl_list func_decl/*{printf("7->");}*/|
					func_decl/*{printf("8->");}*/|
					epsilon
 		;

/*Function*/
func_decl : IDENT BRACELEFT arg_lists BRACERIGHT func_type SEMICOLON  compound_statement KWEND IDENT /*{printf("func_decl");} */
		;

arg_lists : arg/*{printf("10->");}*/|
			arg_lists SEMICOLON arg/*{printf("11->");}*/|
			epsilon //zero or more formal arguments is fine
		;

arg  : 	identifier_list COLON var_type/*{printf("13->");}*/|
		identifier_list COLON array_decl/*{printf("14->");}*/
		;

identifier_list :  	IDENT COMMA identifier_list/*{printf("15->");}*/|
					IDENT /*{printf("16->");}*/|
					epsilon |//identifier list for expanding more and more
		;

func_type : COLON KWINTEGER /*{printf("18->");}*/|
			COLON KWREAL /*{printf("19->");}*/|
			COLON KWBOOLEAN /*{printf("20->");}*/|
			COLON KWSTRING /*{printf("21->");}*/|
			COLON KWARRAY array_dimension_decl var_type /*{printf("22->");}*/|
			epsilon
		;
/*2.2 Data Types and Declarations */

var_decl : 	KWVAR identifier_list COLON var_type SEMICOLON /*{printf("var_decl->");} */
		;

var_type : 	KWINTEGER/*{printf("23->");}*/|
			KWREAL/*{printf("24->");}*/|
			KWSTRING/*{printf("25->");}*/|
			KWARRAY/*{printf("26->");}*/|
			KWBOOLEAN/*{printf("27->");}*/|
		;

array_decl : KWVAR identifier_list COLON KWARRAY array_dimension_decl var_type SEMICOLON /*{printf("array_decl->");}*/
		;

array_dimension_decl :	array_dimension_decl INTEGER KWTO INTEGER KWOF more_array_or_not /*{printf("28->");}*/|
						INTEGER KWTO INTEGER KWOF more_array_or_not /*{printf("29->");}*/
		;

more_array_or_not : KWARRAY/*{printf("30->");}*/|
					epsilon
		;

const_decl : KWVAR identifier_list COLON literal_constant_list SEMICOLON /*{printf("const_decl->");}*/
		;

literal_constant_list :	INTEGER/*{printf("32->");}*/|
						REAL/*{printf("33->");}*/|
						STRING/*{printf("34->");}*/|
						KWTRUE/*{printf("35->");}*/|
						KWFALSE/*{printf("36->");}
		;

/*2.3 Statements in program are listed below */
statement_list :	statement_list statement/*{printf("37->");}*/|
					statement/*{printf("38->");}*/|
					epsilon
		;

statement : 		compound_statement/*{printf("40->");}*/|
					simple_statement SEMICOLON /*{printf("41->");}*/|
					conditional_statement/*{printf("42->");}*/|
					while_statement/*{printf("43->");}*/|
					for_statement/*{printf("44->");}*/|
					return_statement SEMICOLON/*{printf("45->");}*/|
					function_invocation_statement SEMICOLON/*{printf("46->");}
		;
/*2.3.1 compound_statement*/
compound_statement : KWBEGIN var_const_decl_list statement_list KWEND /*{printf("compound_statement->");}*/
		;

/*2.3.2 simple statement*/
simple_statement : 	//variable_reference ASSIGN array_reference/*{printf("48->");}*/|
					variable_reference ASSIGN expression_list /*{printf("47->");}*/||
					KWPRINT variable_reference /*{printf("49->");}*/|
					KWPRINT expression /*{printf("50->");}*/|
					KWREAD variable_reference /*{printf("51->");}*/
		;

variable_reference	: 	IDENT /*{printf("54->");}*/ | IDENT BRACKETLEFT expression BRACKETRIGHT array_extend /*{printf("55->");}*/
		;

integer_expression : 	INTEGER MULTIPLY INTEGER|
						INTEGER DIVIDE INTEGER|
						INTEGER MOD INTEGER|
						INTEGER PLUS INTEGER|
						INTEGER MINUS INTEGER|
						INTEGER|
						IDENT
		;

array_extend     : 	BRACKETLEFT expression BRACKETRIGHT /*{printf("63->");}*/|
					array_extend BRACKETLEFT expression BRACKETRIGHT/*{printf("64->");}*/|
					epsilon
		;
expression :	MINUS expression  %prec UNARY_NEGATIVE/*{printf("65->");}*/| //unary expression gets highest priority
				BRACELEFT expression BRACERIGHT/*{printf("66->");}*/|
				literal_constant_list/*{printf("67->");}*/| //required for mathematical operation with constant
				variable_reference/*{printf("68->");}*/| //required for mathematical operation with variable
				function_invocation_statement/*{printf("70->");}*/| //required for mathematical operation with function
				expression MULTIPLY expression/*{printf("71->");}*/|
				expression DIVIDE expression/*{printf("72->");}*/|
				expression MOD expression/*{printf("73->");}*/|
				expression PLUS expression/*{printf("74->");}*/|
				expression MINUS expression/*{printf("75->");}*/|
				boolean_expression/*{printf("76->");}*/|
				NOT expression/*{printf("77->");}*/|
				expression AND  expression/*{printf("78->");}*/|
				expression OR expression/*{printf("79->");}*/
		;

boolean_expression :	expression LESS expression/*{printf("80->");}*/|
						expression LESSEQUAL expression/*{printf("81->");}*/|
						expression EQUAL expression/*{printf("82->");}*/|
						expression GREATEREQUAL expression/*{printf("83->");}*/|
						expression GREATER expression/*{printf("84->");}*/|
						expression LESSGREATER expression/*{printf("85->");}*/
		;

function_invocation_statement :	IDENT BRACELEFT expression_list BRACERIGHT/*{printf("function_definition");}*/
		;

expression_list : 	expression_list COMMA expression /*{printf("86->");}*/|
					expression/*{printf("87->");}*/|
					epsilon //in order to terminate
		;

/*2.3.3 Conditional statements*/
conditional_statement :	KWIF boolean_expression KWTHEN statement_list KWELSE statement_list KWEND KWIF/*{printf("89->");}*/|
						KWIF boolean_expression KWTHEN statement_list KWEND KWIF/*{printf("90->");}*/
		;

/*2.3.4 while statements*/
while_statement : KWWHILE boolean_expression KWDO statement_list KWEND KWDO/*{printf("91->");}*/
		;

for_statement : KWFOR IDENT ASSIGN INTEGER KWTO INTEGER KWDO statement_list KWEND KWDO/*{printf("92->");}*/
		;

return_statement : KWRETURN expression/*{printf("93->");}*/
		;

epsilon :  /*{printf("TERMINATE EPSILON");}/*epsilon does nothing*/
		;
%%

int yyerror( char *msg ) /*parsing error goes here*/
{
    fprintf( stderr, "\n|--------------------------------------------------------------------------\n" );
	fprintf( stderr, "| Error found in Line #%d: %s\n", linenum, buf );
	fprintf( stderr, "|\n" );
	fprintf( stderr, "| Unmatched token: %s\n", yytext );
    fprintf( stderr, "|--------------------------------------------------------------------------\n" );
    exit(-1);
}

int  main( int argc, char **argv )
{
	if( argc != 2 ) {
		fprintf(  stdout,  "Usage:  ./parser  [filename]\n"  );
		exit(0);
	}

	FILE *fp = fopen( argv[1], "r" );

	if( fp == NULL )  {
		fprintf( stdout, "Open  file  error\n" );
		exit(-1);
	}

	yyin = fp;
	yyparse();

	fprintf( stdout, "\n" );
	fprintf( stdout, "|--------------------------------|\n" );
	fprintf( stdout, "|  There is no syntactic error!  |\n" );
	fprintf( stdout, "|--------------------------------|\n" );
	exit(0);
}
