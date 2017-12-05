%{
/**
 * Introduction to Compiler Design by Prof. Yi Ping You
 * Project 2 YACC sample
 $$ yylaval
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
char funct_type_buf_parser[BUF_SIZE];
char funct_attri_buf[BUF_SIZE];
extern int yylex(void);
extern int Opt_D; /* declared in lex.l */
extern int linenum;		/* declared in lex.l */

int yyerror(char* );
//0 not constant, 1 int 2 -int  3 float 4 -float 5 scientific 6 -scientific 7 string 8 bool 9 OCTAL 10 -OCTAL

%}
/* tokens */

%union
{
    char* parsed_string;
}

%token <parsed_string>ARRAY
%token <parsed_string>BEG
%token <parsed_string>BOOLEAN
%token <parsed_string>DEF
%token <parsed_string>DO
%token <parsed_string>ELSE
%token <parsed_string>END
%token <parsed_string>FALSE
%token <parsed_string>FOR
%token <parsed_string>INTEGER
%token <parsed_string>IF
%token <parsed_string>OF
%token <parsed_string>PRINT
%token <parsed_string>READ
%token <parsed_string>REAL
%token <parsed_string>RETURN
%token <parsed_string>STRING
%token <parsed_string>THEN
%token <parsed_string>TO
%token <parsed_string>TRUE
%token <parsed_string>VAR
%token <parsed_string>WHILE

%token <parsed_string>ID
%token <parsed_string>OCTAL_CONST
%token <parsed_string>INT_CONST
%token <parsed_string>FLOAT_CONST
%token <parsed_string>SCIENTIFIC
%token <parsed_string>STR_CONST

%token <parsed_string>OP_ADD
%token <parsed_string>OP_SUB
%token <parsed_string>OP_MUL
%token <parsed_string>OP_DIV
%token <parsed_string>OP_MOD
%token <parsed_string>OP_ASSIGN
%token <parsed_string>OP_EQ
%token <parsed_string>OP_NE
%token <parsed_string>OP_GT
%token <parsed_string>OP_LT
%token <parsed_string>OP_GE
%token <parsed_string>OP_LE
%token <parsed_string>OP_AND
%token <parsed_string>OP_OR
%token <parsed_string>OP_NOT

%token <parsed_string>MK_COMMA
%token <parsed_string>MK_COLON
%token <parsed_string>MK_SEMICOLON
%token <parsed_string>MK_LPAREN
%token <parsed_string>MK_RPAREN
%token <parsed_string>MK_LB
%token <parsed_string>MK_RB

/* start symbol */
%type <parsed_string> decl int_const literal_const param id_list type scalar_type array_type

%start program
%%

program		:	ID
				{
					strcpy(mysymbol_table[scope_depth].mysub_entry[sub_entry_cnt].name,yytext);
					//printf("program name %s",mysymbol_table[0].mysub_entry[0].name);
					global_sub_entry_cnt=1;
					global_pre_sub_entry_cnt=global_sub_entry_cnt;
					is_array = 0;
					is_function=0;
					is_loop=0;
					const_type=0;
				}
				MK_SEMICOLON
				{
					strcpy(mysymbol_table[0].mysub_entry[0].kind,"program");
					strcpy(mysymbol_table[0].mysub_entry[0].level_str,"0(global)");
					strcpy(mysymbol_table[0].mysub_entry[0].type,"void");
				}
			  	program_body
			  	END ID
			  	{
					error_detection();
					dumpsymbol();
					pop_symbol_table();
			  	}
			;

program_body	: opt_decl_list opt_func_decl_list compound_stmt /*//printf("1->");}*/
			;

opt_decl_list	: decl_list /*{//printf("2->");}*/
				| /* epsilon */
			;

decl_list	: 	decl_list /*//printf("3->");}*/
 				decl /*//printf("4->");}*/
			| 	decl /*//printf("5->");}*/
			;

decl		: VAR	/* scalar type declaration */
 			id_list MK_COLON scalar_type
			{
				//printf("7->");}
				if(scope_depth==0) //global declaration
				{
					for(int i=global_pre_sub_entry_cnt;i<global_sub_entry_cnt;i++)
					{
						strcpy(mysymbol_table[scope_depth].mysub_entry[i].kind,"variable");
						char* ps_level;
						char depth_n[100];
						memset(depth_n,0,sizeof(depth_n));

						depth_n[0]='0';
						ps_level="(global)";
						strcat(depth_n,ps_level);

						strcpy(mysymbol_table[scope_depth].mysub_entry[i].level_str,depth_n);
						strcpy(mysymbol_table[scope_depth].mysub_entry[i].type,$4);
					}
					global_pre_sub_entry_cnt=global_sub_entry_cnt; //update it for next segment
					error_detection();
					//dumpsymbol();
				}
				else //non global declaration
				{
					for(int i=pre_sub_entry_cnt;i<sub_entry_cnt;i++)
					{
						strcpy(mysymbol_table[scope_depth].mysub_entry[i].kind,"variable");
						char* ps_level;
						char depth_n[100];
						memset(depth_n,0,sizeof(depth_n));

						depth_n[0]=scope_depth+'0';
						ps_level="(local)";
						strcat(depth_n,ps_level);

						strcpy(mysymbol_table[scope_depth].mysub_entry[i].level_str,depth_n);
						strcpy(mysymbol_table[scope_depth].mysub_entry[i].type,$4);
					}
					pre_sub_entry_cnt=sub_entry_cnt; //update it for next segment
					error_detection();
					//dumpsymbol();
				}

			}
			MK_SEMICOLON
			| VAR    /* array type declaration */
			id_list MK_COLON array_type MK_SEMICOLON
			{
				//printf("9->");}
				if(scope_depth==0) //global declaration
				{
					for(int i=global_pre_sub_entry_cnt;i<global_sub_entry_cnt;i++)
					{
						strcpy(mysymbol_table[scope_depth].mysub_entry[i].kind,"variable");
						char* ps_level;
						char depth_n[100];
						memset(depth_n,0,sizeof(depth_n));

						depth_n[0]='0';
						ps_level="(global)";
						strcat(depth_n,ps_level);
						strcpy(mysymbol_table[scope_depth].mysub_entry[i].level_str,depth_n);
						//printf("arr buf %s and table arr type buf %s\n",arr_buf,mysymbol_table[scope_depth].mysub_entry[i].array_type_buf);
						array_dimension_parser();
						strcat(mysymbol_table[scope_depth].mysub_entry[i].array_type_buf,reverse_arr_buf); //altogether using the s//printf to concatenate multiple strings
						mysymbol_table[scope_depth].mysub_entry[i].is_array_decl=true;
					}
					global_pre_sub_entry_cnt=global_sub_entry_cnt;
					error_detection();
				}
				else //non global declaration
				{
					for(int i=pre_sub_entry_cnt;i<sub_entry_cnt;i++)
					{
						strcpy(mysymbol_table[scope_depth].mysub_entry[i].kind,"variable");
						char* ps_level;
						char depth_n[100];
						memset(depth_n,0,sizeof(depth_n));

						depth_n[0]=scope_depth+'0';
						ps_level="(local)";
						strcat(depth_n,ps_level);
						strcpy(mysymbol_table[scope_depth].mysub_entry[i].level_str,depth_n);
						//printf("arr buf %s and table arr type buf %s\n",arr_buf,mysymbol_table[scope_depth].mysub_entry[i].array_type_buf);
						array_dimension_parser();
						strcat(mysymbol_table[scope_depth].mysub_entry[i].array_type_buf,reverse_arr_buf); //altogether using the s//printf to concatenate multiple strings
						mysymbol_table[scope_depth].mysub_entry[i].is_array_decl=true;
					}
					pre_sub_entry_cnt=sub_entry_cnt;
					error_detection();
				}
				 //update it for next segment
				memset(arr_buf,0,sizeof(arr_buf));
				is_array=0;//end matching an array, turn off the flag

			}
			| VAR id_list MK_COLON literal_const /* const declaration */
			{
				//printf("10->");}
				if(scope_depth==0) //global declaration
				{
					for(int i=global_pre_sub_entry_cnt;i<global_sub_entry_cnt;i++)
					{
						strcpy(mysymbol_table[scope_depth].mysub_entry[i].kind,"constant");
						char* ps_level;
						char depth_n[100];
						memset(depth_n,0,sizeof(depth_n));

						depth_n[0]='0';
						ps_level="(global)";
						strcat(depth_n,ps_level);

						strcpy(mysymbol_table[scope_depth].mysub_entry[i].level_str,depth_n);
						assign_constant_type(scope_depth,i);
					}
					global_pre_sub_entry_cnt=global_sub_entry_cnt; //update it for next segment
					error_detection();
					//dumpsymbol();
				}
				else //non-global declaration
				{
					for(int i=pre_sub_entry_cnt;i<sub_entry_cnt;i++)
					{
						strcpy(mysymbol_table[scope_depth].mysub_entry[i].kind,"constant");
						char* ps_level;
						char depth_n[100];
						memset(depth_n,0,sizeof(depth_n));

						depth_n[0]=scope_depth+'0';
						ps_level="(local)";
						strcat(depth_n,ps_level);

						strcpy(mysymbol_table[scope_depth].mysub_entry[i].level_str,depth_n);
						assign_constant_type(scope_depth,i);
					}
					pre_sub_entry_cnt=sub_entry_cnt; //update it for next segment
					error_detection();
					//dumpsymbol();
				}
			}
			MK_SEMICOLON
			;

int_const	:	INT_CONST {$$=yytext; const_type=1;}
			|	OCTAL_CONST {$$=yytext; const_type=9;}
			;

literal_const	: int_const {$$=yytext; const_type=(const_type==1)?1:9; parse_constant();}
				| OP_SUB int_const {$$=yytext; const_type=(const_type==1)?2:10; parse_constant();}
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
					//printf("11->");}
					sub_entry_cnt=0;
					pre_sub_entry_cnt=0;
					scope_depth+=1;

					strcat(mysymbol_table[0].mysub_entry[global_sub_entry_cnt].name,yytext);
					strcpy(mysymbol_table[0].mysub_entry[global_sub_entry_cnt].kind,"function");
					strcpy(mysymbol_table[0].mysub_entry[global_sub_entry_cnt].level_str,"0(global)");
					//printf("Global entry count %d \n",global_sub_entry_cnt);
					mysymbol_table[0].mysub_entry[global_sub_entry_cnt].is_funct_decl=1;
					//memset(funct_type_buf_parser,0,sizeof(funct_type_buf_parser));
					memset(funct_attri_buf,0,sizeof(funct_attri_buf));

				}
 				MK_LPAREN opt_param_list MK_RPAREN
				{
					is_function=1;
					scope_depth-=1;
					global_sub_entry_cnt++;
				}
				opt_type MK_SEMICOLON
				{
					 //is_function=1 here will be better

					//setting the function type
					if(is_array)
					{
						array_dimension_parser();
						strcat(mysymbol_table[0].mysub_entry[global_sub_entry_cnt-1].funct_type_buf,reverse_arr_buf);
					}
					//setting the function attribute(parameter which passed in)
					strcat(mysymbol_table[0].mysub_entry[global_sub_entry_cnt-1].attri_type_buf,funct_attri_buf);
					//printf("Function attribute %s after parsing and function type %s \n",mysymbol_table[0].mysub_entry[global_sub_entry_cnt-1].attri_type_buf,mysymbol_table[0].mysub_entry[global_sub_entry_cnt-1].funct_type_buf);
					//printf("dump function symbol test \n");
					//dumpsymbol();
					global_pre_sub_entry_cnt=global_sub_entry_cnt;
					is_array=0;
					 //global function end by 1
				}
			  	compound_stmt
			  	END
				{
					//printf("12->");}
					//set the function attribute and type after all declared
					/*dumpsymbol();
					pop_symbol_table(); //function pop itself*/
					is_function=0;
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
				//printf("13->");}

				for(int i=pre_sub_entry_cnt;i<sub_entry_cnt;i++)
				{
					strcpy(mysymbol_table[scope_depth].mysub_entry[i].kind,"parameter");
					//printf("i is now %d and name %s\n",i,mysymbol_table[scope_depth].mysub_entry[i].name);
					char* ps_level;
					char depth_n[100];
					memset(depth_n,0,sizeof(depth_n));
					if(scope_depth)
					{
						depth_n[0]=scope_depth+'0';
						ps_level="(local)";
						strcat(depth_n,ps_level);
						//printf("Depth n %s \n",depth_n);
					}
					strcpy(mysymbol_table[scope_depth].mysub_entry[i].level_str,depth_n);
					if(is_array)
					{
						//printf("Found an array parameter passed in \n");
						//printf("arr buf %s \n",arr_buf);
						array_dimension_parser();
						if(error_detection()==0)
						{
							
							strcat(mysymbol_table[scope_depth].mysub_entry[i].array_type_buf,reverse_arr_buf);
							strcat(funct_attri_buf,mysymbol_table[scope_depth].mysub_entry[i].array_type_buf);
							strcat(funct_attri_buf,","); //for indentation			
							mysymbol_table[scope_depth].mysub_entry[i].is_array_decl=true;
						}
					}
					else
					{
						if(error_detection()==0)
						{
						
							strcpy(mysymbol_table[scope_depth].mysub_entry[i].type,$3);
							strcat(funct_attri_buf,mysymbol_table[scope_depth].mysub_entry[i].type);
						        strcat(funct_attri_buf,","); //for indentation
						}
					}
				}
				pre_sub_entry_cnt=sub_entry_cnt; //update it for next segment
				//printf("parsing parameter done dump symbol table\n");
				memset(arr_buf,0,sizeof(arr_buf));
				is_array=0;
			}
			;

id_list		: id_list MK_COMMA ID /*one ID for one sub_entry*/
			{
				//printf("14->");}
				//printf("ID is %s",yytext);
				if(scope_depth==0) //global declaration
				{
					strcpy(mysymbol_table[0].mysub_entry[global_sub_entry_cnt].name,yytext);
					global_sub_entry_cnt++;
				}
				else //non global declaration
				{
					strcpy(mysymbol_table[scope_depth].mysub_entry[sub_entry_cnt].name,yytext);
					sub_entry_cnt++;
				}
				$$=yytext;
				//printf(" AND PASSED IN ID NAME %s \n",mysymbol_table[scope_depth].mysub_entry[sub_entry_cnt].name);
				//dumpsymbol();
			}
			| ID
			{

				//printf("15->");}
				//printf("ID is %s",yytext);
				if(scope_depth==0) //global declaration
				{
					strcpy(mysymbol_table[0].mysub_entry[global_sub_entry_cnt].name,yytext);
					global_sub_entry_cnt++;
				}
				else //non global declaration
				{
					strcpy(mysymbol_table[scope_depth].mysub_entry[sub_entry_cnt].name,yytext);
					sub_entry_cnt++;
				}
				$$=yytext;
				//printf(" AND PASSED IN ID NAME %s \n",mysymbol_table[scope_depth].mysub_entry[sub_entry_cnt].name);
				//dumpsymbol();
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
				//printf("16->");}
				$$="integer ";
				assign_scalar_type("integer ");
			}
			| REAL
			{
				//printf("17->");}
				//printf("TYPE is %s",yytext);
				$$="real ";
				assign_scalar_type("real ");
			}
			| BOOLEAN
			{
				//printf("18->");}
				//printf("TYPE is %s",yytext);
				$$="boolean ";
				assign_scalar_type("boolean ");
			}
			| STRING
			{
				//printf("19->");}
				//printf("TYPE is %s",yytext);
				$$="string ";
				assign_scalar_type("string ");
			}
			;

array_type	: ARRAY
			{
				//printf("20->");}
				is_array=1;
			}
 			int_const TO int_const OF type
			{
				//printf("21->");}

				int delta=atol($5)-atol($3)+1;
				char tmp[10];
				//printf("\narray dim FROM %s to %s delta is %d\n",$3,$5,delta);
				sprintf(tmp,"%d",delta);
				strcat(arr_buf,tmp);
				strcat(arr_buf,",");
				//printf("Array buf %s \n",arr_buf);
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
					//printf("22->");}
					if(scope_depth==0&&is_function)
					{
						scope_depth++;
					}
					else
					{
						scope_depth++;
						sub_entry_cnt=0;
						pre_sub_entry_cnt=0;
					}
					//printf("compound_stmt begin\n");
					//printf("Scope depth %d, pre_sub_entry_cnt %d sub_entry_cnt %d \n",scope_depth,pre_sub_entry_cnt,sub_entry_cnt);

				}
			  	opt_decl_list
			  	opt_stmt_list
				{
					//printf("23->");}
					//printf("compound_stmt end\n");
					//printf("Scope depth %d, pre_sub_entry_cnt %d sub_entry_cnt %d \n",scope_depth,pre_sub_entry_cnt,sub_entry_cnt);
					if(is_function&&scope_depth>1) //prevernt double popping
					{
						//printf("pop type 1 function controller is '%d' \n",is_function);
						//error_detection();
						dumpsymbol();
						pop_symbol_table();
					}
					else if(!is_loop)/*if(!is_function) *///normal like
					{
						//printf("pop type 1 function controller is '%d' \n",is_function);
						//error_detection();
						dumpsymbol();
						pop_symbol_table();
					}
					/*
					begin
					    var a: integer;
					    begin
					        var a: boolean;
					    end
					// outer ’a’ has been hidden in this scope
					end just directly popping, rather than waiting till the end test!
					*/
				}
			  	END

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

for_stmt	: 	FOR ID
				{
					strcpy(myiter_table[iterator_cnt].iterator_name,yytext);
					myiter_table[iterator_cnt].iterator_level=scope_depth+1;
					//printf("Loop scope depth %d and name %s\n",scope_depth,yytext);
					error_detection();
					//dumpiterator();
					iterator_cnt++;
					is_loop=1;
				}
 			  	OP_ASSIGN int_const TO int_const DO
			  	opt_stmt_list
			  	END DO
				{
					is_loop=0;
				}
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
