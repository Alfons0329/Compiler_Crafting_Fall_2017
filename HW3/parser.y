%{
/**
 * Introduction to Compiler Design by Prof. Yi Ping You
 * Project 2 YACC sample
 */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "symbol_table.h"
extern FILE *yyin;		/* declared by lex */
extern char *yytext;		/* declared by lex */
extern char *buf;		/* declared in lex.l */
char* array_scalar_type;
char arr_buf[50];
extern int yylex(void);
extern int Opt_D; /* declared in lex.l */
extern int linenum;		/* declared in lex.l */
int yyerror(char* );
int param_or_decl; //0 decl 1 param
int is_array; //0 no 1 yes
%}
/* tokens */
%token ARRAY
%token BEG
%token BOOLEAN
%token DEF
%token DO
%token ELSE
%token END
%token FALSE
%token FOR
%token INTEGER
%token IF
%token OF
%token PRINT
%token READ
%token REAL
%token RETURN
%token STRING
%token THEN
%token TO
%token TRUE
%token VAR
%token WHILE

%token ID
%token OCTAL_CONST
%token INT_CONST
%token FLOAT_CONST
%token SCIENTIFIC
%token STR_CONST

%token OP_ADD
%token OP_SUB
%token OP_MUL
%token OP_DIV
%token OP_MOD
%token OP_ASSIGN
%token OP_EQ
%token OP_NE
%token OP_GT
%token OP_LT
%token OP_GE
%token OP_LE
%token OP_AND
%token OP_OR
%token OP_NOT

%token MK_COMMA
%token MK_COLON
%token MK_SEMICOLON
%token MK_LPAREN
%token MK_RPAREN
%token MK_LB
%token MK_RB

/* start symbol */
%start program
%%

program		:	ID MK_SEMICOLON
				{
					strcpy(mysymbol_table[0].mysub_entry[0].name,$1);
					mysymbol_table[0].mysub_entry[0].kind="program";
					mysymbol_table[0].mysub_entry[0].level_str="0(global)";
					mysymbol_table[0].mysub_entry[0].type="void";
				}
			  	program_body
			  	END ID
			  	{
					pop_symbol_table();
					dumpsymbol();
			  	}
			;

program_body	: opt_decl_list opt_func_decl_list compound_stmt
			;

opt_decl_list	: decl_list
				| /* epsilon */
			;

decl_list	: 	decl_list
 				decl
			| 	decl
			;

decl		: VAR	/* scalar type declaration */
			{
				pre_sub_entry_cnt=sub_entry_cnt;
			}
 			id_list MK_COLON scalar_type MK_SEMICOLON
			{
				for(int i=pre_sub_entry_cnt;i<sub_entry_cnt;i++)
				{
					mysymbol_table[scope_depth].mysub_entry[i].kind="variable";
					char* ps_level;
					char depth_n[100];
					if(scope_depth)
					{
						depth_n[0]=scope_depth+'0';
						ps_level="(local)";
						strcat(depth_n,ps_level);
					}
					else
					{
						depth_n[0]='0';
						ps_level="(global)";
						strcat(depth_n,ps_level);
					}
					mysymbol_table[scope_depth].mysub_entry[i].level_str=depth_n;
					mysymbol_table[scope_depth].mysub_entry[i].type=$5;
				}
				pre_sub_entry_cnt=sub_entry_cnt; //update it for next segment
			}
			| VAR    /* array type declaration */
			{
				pre_sub_entry_cnt=sub_entry_cnt;
			}
			id_list MK_COLON array_type MK_SEMICOLON
			{
				//strcat(mysymbol_table[scope_depth].sub_entry[i].array_type_buf,$5); //array type just need to be done once
				for(int i=pre_sub_entry_cnt;i<sub_entry_cnt;i++)
				{
					mysymbol_table[scope_depth].mysub_entry[i].kind="variable";
					char* ps_level;
					char depth_n[100];
					if(scope_depth)
					{
						depth_n[0]=scope_depth+'0';
						ps_level="(local)";
						strcat(depth_n,ps_level);
					}
					else
					{
						depth_n[0]='0';
						ps_level="(global)";
						strcat(depth_n,ps_level);
					}
					mysymbol_table[scope_depth].mysub_entry[i].level_str=depth_n;
					strcat(mysymbol_table[scope_depth].mysub_entry[i].array_type_buf,arr_buf); //altogether using the sprintf to concatenate multiple strings
					mysymbol_table[scope_depth].mysub_entry[i].is_array_decl=true;
				}
				pre_sub_entry_cnt=sub_entry_cnt; //update it for next segment
				is_array=0;//end matching an array, turn off the flag
			}
			| VAR id_list MK_COLON literal_const MK_SEMICOLON
			{
				for(int i=pre_sub_entry_cnt;i<sub_entry_cnt;i++)
				{
					mysymbol_table[scope_depth].mysub_entry[i].kind="constant";
					char* ps_level;
					char depth_n[100];
					if(scope_depth)
					{
						depth_n[0]=scope_depth+'0';
						ps_level="(local)";
						strcat(depth_n,ps_level);
					}
					else
					{
						depth_n[0]='0';
						ps_level="(global)";
						strcat(depth_n,ps_level);
					}
					mysymbol_table[scope_depth].mysub_entry[i].level_str=depth_n;
					strcat(mysymbol_table[scope_depth].mysub_entry[i].attri_type_buf,$4);
				}
				pre_sub_entry_cnt=sub_entry_cnt; //update it for next segment
			} /* const declaration */
			;
int_const	:	INT_CONST
			|	OCTAL_CONST
			;

literal_const	: int_const
				| OP_SUB int_const
				| FLOAT_CONST
				| OP_SUB FLOAT_CONST
				| SCIENTIFIC
				| OP_SUB SCIENTIFIC
				| STR_CONST
				| TRUE
				| FALSE
			;

opt_func_decl_list	: func_decl_list
					| /* epsilon */
			;

func_decl_list		: func_decl_list func_decl
					| func_decl
			;

func_decl	: 	ID MK_LPAREN opt_param_list MK_RPAREN opt_type MK_SEMICOLON
			  	compound_stmt
			  	END
				{
					//scope_depth--;
					for(int i=0;i<SUB_ENTRY_SIZE;i++)
					{
						//find the fucking parameter
						if(mysymbol_table[1].mysub_entry[i].kind=="parameter")
						{
							if(mysymbol_table[1].mysub_entry[i].is_array_decl)
							{
								strcat(mysymbol_table[0].mysub_entry[sub_entry_cnt].attri_type_buf,arr_buf);
							}
							else
							{
								strcat(mysymbol_table[0].mysub_entry[sub_entry_cnt].attri_type_buf,$5);
							}
						}
					}
					pop_symbol_table();
					dumpsymbol();
				}
				ID
			;

opt_param_list		: param_list
					| /* epsilon */
			;

param_list	: param_list MK_SEMICOLON param
			| param
			;

param		: id_list MK_COLON type
			{
				param_or_decl=1;
				for(int i=pre_sub_entry_cnt;i<sub_entry_cnt;i++)
				{
					mysymbol_table[scope_depth].mysub_entry[i].kind="parameter";
					char* ps_level;
					char depth_n[100];
					if(scope_depth)
					{
						depth_n[0]=scope_depth+'0';
						ps_level="(local)";
						strcat(depth_n,ps_level);
					}
					mysymbol_table[scope_depth].mysub_entry[i].level_str=depth_n;
					if(is_array)
					{
						strcat(mysymbol_table[scope_depth].mysub_entry[i].array_type_buf,arr_buf);
						mysymbol_table[scope_depth].mysub_entry[i].is_array_decl=true;
					}
					else
					{
						mysymbol_table[scope_depth].mysub_entry[i].type=$3;
					}
				}
				pre_sub_entry_cnt=sub_entry_cnt; //update it for next segment
			}
			;

id_list		: id_list MK_COMMA ID /*one ID for one sub_entry*/
			{
				sub_entry_cnt++;
			}
			| ID
			{
				mysymbol_table[scope_depth].mysub_entry[sub_entry_cnt].name=$1;
			}
			;

opt_type	: MK_COLON type
			| /* epsilon */
			;

type		: scalar_type
			| array_type
			;

scalar_type	: INTEGER
			{
				if(is_array)
				{
					for(int i=pre_sub_entry_cnt;i<sub_entry_cnt;i++)
					{
						strcat(mysymbol_table[scope_depth].mysub_entry[i].array_type_buf,"integer ");
					}
				}
			}
			| REAL
			{
				if(is_array)
				{
					for(int i=pre_sub_entry_cnt;i<sub_entry_cnt;i++)
					{
						strcat(mysymbol_table[scope_depth].mysub_entry[i].array_type_buf,"real ");
					}
				}
			}
			| BOOLEAN
			{
				if(is_array)
				{
					for(int i=pre_sub_entry_cnt;i<sub_entry_cnt;i++)
					{
						strcat(mysymbol_table[scope_depth].mysub_entry[i].array_type_buf,"boolean ");
					}
				}
			}
			| STRING
			{
				if(is_array)
				{
					for(int i=pre_sub_entry_cnt;i<sub_entry_cnt;i++)
					{
						strcat(mysymbol_table[scope_depth].mysub_entry[i].array_type_buf,"string ");
					}
				}
			}
			;

array_type	: ARRAY
			{
				is_array=1;
				memset(arr_buf,0,sizeof(arr_buf));
			}
 			int_const TO int_const OF type
			{
				sprintf(arr_buf,"[%d",($4-$2+'0'));
				strcat(arr_buf,"]");
			}
			;

stmt		: compound_stmt
			| simple_stmt
			| cond_stmt
			| while_stmt
			| for_stmt
			| return_stmt
			| proc_call_stmt
			;

compound_stmt	: BEG
				{
					scope_depth++;
					sub_entry_cnt=0;
					pre_sub_entry_cnt=0;
				}
			  	opt_decl_list
			  	opt_stmt_list
			  	END
				{
					pop_symbol_table();
					dumpsymbol();
				}
			;

opt_stmt_list		: stmt_list
			| /* epsilon */
			;

stmt_list		: stmt_list stmt
			| stmt
			;

simple_stmt		: var_ref OP_ASSIGN boolean_expr MK_SEMICOLON
			| PRINT boolean_expr MK_SEMICOLON
			| READ boolean_expr MK_SEMICOLON
			;

proc_call_stmt		: ID MK_LPAREN opt_boolean_expr_list MK_RPAREN MK_SEMICOLON
			;

cond_stmt	: IF boolean_expr THEN
			  opt_stmt_list
			  ELSE
			  opt_stmt_list
			  END IF
			| IF boolean_expr THEN opt_stmt_list END IF
			;

while_stmt	: WHILE boolean_expr DO
			  opt_stmt_list
			  END DO
			;

for_stmt	: FOR ID OP_ASSIGN int_const TO int_const DO
			  opt_stmt_list
			  END DO
			;

return_stmt	: RETURN boolean_expr MK_SEMICOLON
			;

opt_boolean_expr_list	: boolean_expr_list
			| /* epsilon */
			;

boolean_expr_list	: boolean_expr_list MK_COMMA boolean_expr
			| boolean_expr
			;

boolean_expr		: boolean_expr OP_OR boolean_term
			| boolean_term
			;

boolean_term		: boolean_term OP_AND boolean_factor
			| boolean_factor
			;

boolean_factor		: OP_NOT boolean_factor
			| relop_expr
			;

relop_expr		: expr rel_op expr
			| expr
			;

rel_op		: OP_LT
			| OP_LE
			| OP_EQ
			| OP_GE
			| OP_GT
			| OP_NE
			;

expr			: expr add_op term
			| term
			;

add_op		: OP_ADD
			| OP_SUB
			;

term		: term mul_op factor
			| factor
			;

mul_op			: OP_MUL
			| OP_DIV
			| OP_MOD
			;

factor		: var_ref
			| OP_SUB var_ref
			| MK_LPAREN boolean_expr MK_RPAREN
			| OP_SUB MK_LPAREN boolean_expr MK_RPAREN
			| ID MK_LPAREN opt_boolean_expr_list MK_RPAREN
			| OP_SUB ID MK_LPAREN opt_boolean_expr_list MK_RPAREN
			| literal_const
			;

var_ref		: ID
			| var_ref dim
			;

dim			: MK_LB boolean_expr MK_RB
			;

%%

int yyerror( char *msg )
{
	(void) msg;
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
	param_or_decl = 0; //0 param 1 decl
	is_array = 0; //0 no 1 yes
	symbol_table_init();
	yyparse();
	fprintf( stdout, "\n" );
	fprintf( stdout, "|--------------------------------|\n" );
	fprintf( stdout, "|  There is no syntactic error!  |\n" );
	fprintf( stdout, "|--------------------------------|\n" );
	exit(0);
}
