%{
/**
 * Introduction to Compiler Design by Prof. Yi Ping You
 * Project 2 YACC sample
 */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "symbol_table.h"
#define BUF_SIZE 50
extern FILE *yyin;		/* declared by lex */

extern char *yytext;		/* declared by lex */
extern char *buf;		/* declared in lex.l */

char* array_scalar_type;
char arr_buf[BUF_SIZE];
char reverse_arr_buf[BUF_SIZE];
char const_buf[BUF_SIZE];
extern int yylex(void);
extern int Opt_D; /* declared in lex.l */
extern int linenum;		/* declared in lex.l */

int yyerror(char* );
int param_or_decl; //0 decl 1 param
int is_array; //0 no 1 yes
int is_function;
int const_type=0; //0 not constant, 1 int 2 -int  3 float 4 -float 5 scientific 6 -scientific 7 string 8 bool
/*
printf template for debugging

printf("0->")
*/

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

program		:	ID
				{
					//
					printf("1->");
					puts(yytext);
					strcpy(mysymbol_table[scope_depth].mysub_entry[sub_entry_cnt].name,yytext);
					printf("program name %s",mysymbol_table[0].mysub_entry[0].name);
					is_function=0;
					const_type=0;
				}
				MK_SEMICOLON
				{
					mysymbol_table[0].mysub_entry[0].kind="program";
					mysymbol_table[0].mysub_entry[0].level_str="0(global)";
					mysymbol_table[0].mysub_entry[0].type="void";

					dumpsymbol();
				}
			  	program_body
			  	END ID
			  	{
					pop_symbol_table();
					dumpsymbol();
			  	}
			;

program_body	: opt_decl_list opt_func_decl_list compound_stmt {printf("1->");}
			;

opt_decl_list	: decl_list {printf("2->");}
				| /* epsilon */
			;

decl_list	: 	decl_list {printf("3->");}
 				decl {printf("4->");}
			| 	decl {printf("5->");}
			;

decl		: VAR	/* scalar type declaration */
			{
				{printf("6->");}
			}
 			id_list MK_COLON scalar_type
			{
				{printf("7->");}

				for(int i=pre_sub_entry_cnt;i<sub_entry_cnt;i++)
				{
					mysymbol_table[scope_depth].mysub_entry[i].kind="variable";
					char* ps_level;
					char depth_n[100];
					memset(depth_n,0,sizeof(depth_n));
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
					printf("8888888888888888888888888 \n");
					mysymbol_table[scope_depth].mysub_entry[i].type=$5;
					printf("8888888888888888888888888 \n");
				}
				pre_sub_entry_cnt=sub_entry_cnt; //update it for next segment
			}
			MK_SEMICOLON
			| VAR    /* array type declaration */
			{
				{printf("8->");}
			}
			id_list MK_COLON array_type MK_SEMICOLON
			{
				{printf("9->");}

				for(int i=pre_sub_entry_cnt;i<sub_entry_cnt;i++)
				{
					mysymbol_table[scope_depth].mysub_entry[i].kind="variable";
					char* ps_level;
					char depth_n[100];
					memset(depth_n,0,sizeof(depth_n));
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
					printf("arr buf %s \n",arr_buf);
					memset(reverse_arr_buf,0,sizeof(reverse_arr_buf));
					for(int i=49,j=0;i>=0;i--)
					{
						if(arr_buf[i]!=0)
						{
							reverse_arr_buf[j]='[';
							reverse_arr_buf[j+1]=arr_buf[i];
							reverse_arr_buf[j+2]=']';
							j+=3;
						}
					}
					strcat(mysymbol_table[scope_depth].mysub_entry[i].array_type_buf,reverse_arr_buf); //altogether using the sprintf to concatenate multiple strings

					mysymbol_table[scope_depth].mysub_entry[i].is_array_decl=true;
				}
				pre_sub_entry_cnt=sub_entry_cnt; //update it for next segment
				memset(arr_buf,0,sizeof(arr_buf));
				is_array=0;//end matching an array, turn off the flag
			}
			| VAR id_list MK_COLON literal_const
			{
				{printf("10->");}

				for(int i=pre_sub_entry_cnt;i<sub_entry_cnt;i++)
				{
					mysymbol_table[scope_depth].mysub_entry[i].kind="constant";
					char* ps_level;
					char depth_n[100];
					memset(depth_n,0,sizeof(depth_n));
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
					assign_constant_type(scope_depth,i);
				}
				pre_sub_entry_cnt=sub_entry_cnt; //update it for next segment
				error_detection();
				dumpsymbol();
			} /* const declaration */
			MK_SEMICOLON
			;

int_const	:	INT_CONST {$$=yytext;}
			|	OCTAL_CONST {$$=yytext;}
			;

literal_const	: int_const {$$=yytext; const_type=1; parse_constant();}
				| OP_SUB int_const {$$=yytext; const_type=2; parse_constant();}
				| FLOAT_CONST {$$=yytext; const_type=3; parse_constant();}
				| OP_SUB FLOAT_CONST {$$=yytext; const_type=4; parse_constant();}
				| SCIENTIFIC {$$=yytext; const_type=5; parse_constant();}
				| OP_SUB SCIENTIFIC {$$=yytext; const_type=6; parse_constant();}
				| STR_CONST {$$=yytext; const_type=7; parse_constant();}
				| TRUE {$$=yytext; const_type=8; parse_constant();}
				| FALSE {$$=yytext; const_type=8; parse_constant();}
			;

opt_func_decl_list	: func_decl_list
					| /* epsilon */
			;

func_decl_list		: func_decl_list func_decl
					| func_decl
			;

func_decl	: 	ID
				{
					{printf("11->");}
					scope_depth++;
					sub_entry_cnt=0;
					pre_sub_entry_cnt=0;
					printf("compound_stmt begin\n");
					is_function=1;

				}
 				MK_LPAREN opt_param_list MK_RPAREN opt_type MK_SEMICOLON
			  	compound_stmt
			  	END
				{
					//scope_depth--;
					{printf("12->");}
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

				{printf("13->");}

				for(int i=pre_sub_entry_cnt;i<sub_entry_cnt;i++)
				{
					mysymbol_table[scope_depth].mysub_entry[i].kind="parameter";
					printf("i is now %d and name %s\n",i,mysymbol_table[scope_depth].mysub_entry[i].name);
					char* ps_level;
					char depth_n[100];
					memset(depth_n,0,sizeof(depth_n));
					if(scope_depth)
					{
						depth_n[0]=scope_depth+'0';
						ps_level="(local)";
						strcat(depth_n,ps_level);
						printf("Depth n %s \n",depth_n);
					}
					mysymbol_table[scope_depth].mysub_entry[i].level_str=depth_n;
					if(is_array)
					{
						printf("Found an array parameter passed in \n");
						printf("arr buf %s \n",arr_buf);
						memset(reverse_arr_buf,0,sizeof(reverse_arr_buf));
						for(int i=49,j=0;i>=0;i--)
						{
							if(arr_buf[i]!=0)
							{
								reverse_arr_buf[j]='[';
								reverse_arr_buf[j+1]=arr_buf[i];
								reverse_arr_buf[j+2]=']';
								j+=3;
							}
						}
						strcat(mysymbol_table[scope_depth].mysub_entry[i].array_type_buf,reverse_arr_buf);
						mysymbol_table[scope_depth].mysub_entry[i].is_array_decl=true;
					}
					else
					{
						mysymbol_table[scope_depth].mysub_entry[i].type=$3;
					}
				}
				pre_sub_entry_cnt=sub_entry_cnt; //update it for next segment
				printf("parsing parameter done dump symbol table\n");
				memset(arr_buf,0,sizeof(arr_buf));
				dumpsymbol();
			}
			;

id_list		: id_list MK_COMMA ID /*one ID for one sub_entry*/
			{
				{printf("14->");}
				printf("ID is %s",yytext);
				strcpy(mysymbol_table[scope_depth].mysub_entry[sub_entry_cnt].name,yytext);
				$$=yytext;
				printf(" AND PASSED IN ID NAME %s \n",mysymbol_table[scope_depth].mysub_entry[sub_entry_cnt].name);
				sub_entry_cnt++;

				dumpsymbol();
			}
			| ID
			{

				{printf("15->");}
				printf("ID is %s",yytext);
				strcpy(mysymbol_table[scope_depth].mysub_entry[sub_entry_cnt].name,yytext);
				$$=yytext;
				printf(" AND PASSED IN ID NAME %s \n",mysymbol_table[scope_depth].mysub_entry[sub_entry_cnt].name);
				sub_entry_cnt++;

				dumpsymbol();
			}
			;

opt_type	: MK_COLON type
			| /* epsilon */
			;

type		: scalar_type {$$=$1;} /*type transmittion*/
			| array_type {$$=$1;} /*type transmittion*/
			;

scalar_type	: INTEGER
			{
				{printf("16->");}
				printf("TYPE is %s",yytext);
				$$="integer";
				if(is_array)
				{
					for(int i=pre_sub_entry_cnt;i<sub_entry_cnt;i++)
					{
						strcat(mysymbol_table[scope_depth].mysub_entry[i].array_type_buf,"integer ");
					}
				}
				printf("match $$:%s \n",$$);
			}
			| REAL
			{
				{printf("17->");}
				printf("TYPE is %s",yytext);
				$$="real";
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
				{printf("18->");}
				printf("TYPE is %s",yytext);
				$$="boolean";
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
				{printf("19->");}
				printf("TYPE is %s",yytext);
				$$="string";
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
				{printf("20->");}
				is_array=1;
			}
 			int_const TO int_const OF type
			{
				{printf("21->");}

				int delta=atol($5)-atol($3)+1;
				char tmp[10];
				printf("\narray dim FROM %s to %s delta is %d\n",$3,$5,delta);
				sprintf(tmp,"%d",delta);
				strcat(arr_buf,tmp);
				printf("Array buf %s \n",arr_buf);
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
					{printf("22->");}
					if(!is_function)
					{
						sub_entry_cnt=0;
						pre_sub_entry_cnt=0;
						scope_depth++;
					}
					is_function=0;
					printf("compound_stmt begin\n");

				}
			  	opt_decl_list
			  	opt_stmt_list
			  	END
				{
					{printf("23->");}
					printf("compound_stmt end\n");

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
