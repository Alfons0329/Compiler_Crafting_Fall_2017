%{
/**
 * Introduction to Compiler Design by Prof. Yi Ping You
 * Project 2 YACC sample
 */
#include <bits/stdc++.h>
#include "symbol_table.h"

#define push_back pb
extern FILE *yyin;		/* declared by lex */
extern "C"{
	extern int yylex(void);
	int yyerror(const char* );
}
extern char *yytext;	/* declared by lex */
extern char *buf;	/* declared in lex.l */
char arr_buf[BUF_SIZE];
char reverse_arr_buf[BUF_SIZE];
extern int yylex(void);
extern int Opt_D; /* declared in lex.l */
extern int linenum;	/* declared in lex.l */
int yyerror(char* );

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
					symbol_table_init();
					tmpstr.clear();
					strcpy(tmpstr,yytext);
					id_list_buf.pb(tmpstr);
					funct_attri_buf.resize(0);
				}
				MK_SEMICOLON
				{
					inserting_symbol_table(id_list_buf,"program","void",funct_attri_buf);
					id_list_buf.clear();
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

decl		: VAR id_list MK_COLON scalar_type/* scalar type declaration */
			{
				funct_attri_buf.resize(0); //normal variable does not have attribute, so just let the size be zero
				inserting_symbol_table(id_list_buf,"variable",$4,funct_attri_buf);
				id_list_buf.clear();
				error_detection();
			}
			MK_SEMICOLON
			| VAR id_list MK_COLON array_type MK_SEMICOLON   /* array type declaration */
			{
				funct_attri_buf.resize(0); //normal variable does not have attribute, so just let the size be zero
				array_dimension_parser();
				inserting_symbol_table(id_list_buf,"variable",reverse_arr_buf,funct_attri_buf);
				id_list_buf.clear();
				error_detection();
				memset(arr_buf,0,sizeof(arr_buf));//update it for next segment
				is_array=0;
			}
			| VAR id_list MK_COLON literal_const /* const declaration */
			{
				funct_attri_buf.pb(const_buf); //normal variable does not have attribute, so just let the size be zero
				array_dimension_parser();
				inserting_symbol_table(id_list_buf,"constant",,funct_attri_buf);
				id_list_buf.clear();
				error_detection();
			}
			MK_SEMICOLON
			;

int_const	:	INT_CONST {$$=yytext; const_type=1;}
			|	OCTAL_CONST {$$=yytext; const_type=9;}
			;

literal_const	: int_const {$$=yytext; const_type=(const_type==1)?1:9; const_type_str="integer ";}
				| OP_SUB int_const {$$=yytext; const_type=(const_type==1)?2:10; const_type_str="integer ";}
				| FLOAT_CONST {$$=yytext; const_type=3; const_type_str="real ";}
				| OP_SUB FLOAT_CONST {$$=yytext; const_type=4; const_type_str="real ";}
				| SCIENTIFIC {$$=yytext; const_type=5; const_type_str="real ";}
				| OP_SUB SCIENTIFIC {$$=yytext; const_type=6; const_type_str="real ";}
				| STR_CONST {$$=yytext; const_type=7; const_type_str="string ";}
				| TRUE {$$=yytext; const_type=8; const_type_str="boolean ";}
				| FALSE {$$=yytext; const_type=8; const_type_str="boolean ";}
			;

opt_func_decl_list	: func_decl_list
					| /* epsilon */
			;

func_decl_list		: func_decl_list func_decl
					| func_decl
			;

func_decl	: 	ID
				{
					id_list_buf.pb(yytext);
                    error_detection();
					scope_depth+=1;
				}
 				MK_LPAREN opt_param_list MK_RPAREN
				{
					is_function=1;
					scope_depth-=1;
					global_sub_entry_cnt++;
				}
				opt_type MK_SEMICOLON
				{
					//setting the function type
					funct_attri_buf.resize(0); //normal variable does not have attribute, so just let the size be zero

					if(is_array)
					{
						array_dimension_parser();
						strcat(mysymbol_table[0].mysub_entry[global_sub_entry_cnt-1].funct_type_buf,reverse_arr_buf);
					}
					//here we push_back the funct_attri_buf inorder to match the attributes of function
					memset(funct_attri_buf,0,sizeof(funct_attri_buf));
					for(int i=0;i<SUB_ENTRY_SIZE;i++)
					{
						if(strcmp(mysymbol_table[1].mysub_entry[i].kind,"parameter")==0&&(mysymbol_table[1].mysub_entry[i].name[0]!=0))
						{
							if(mysymbol_table[1].mysub_entry[i].is_array_decl)
							{
								strcat(funct_attri_buf,mysymbol_table[1].mysub_entry[i].array_type_buf);
								strcat(funct_attri_buf,","); //for indentation
							}
							else
							{
								strcat(funct_attri_buf,mysymbol_table[1].mysub_entry[i].type);
							    strcat(funct_attri_buf,","); //for indentation
							}
						}
					}
					//setting the function attribute(parameter which passed in)
					strcat(mysymbol_table[0].mysub_entry[global_sub_entry_cnt-1].attri_type_buf,funct_attri_buf);
					global_pre_sub_entry_cnt=global_sub_entry_cnt;
					is_array=0;
					 //global function end by 1
					inserting_symbol_table(id_list_buf,"function",$4,funct_attri_buf);
 					id_list_buf.clear();
 					error_detection();
				}
			  	compound_stmt
			  	END
				{
					//printf("12->");}
					//set the function attribute and type after all declared
					/*pop_symbol_table(); //function pop itself*/
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
				funct_attri_buf.resize(0);
				if(is_array)
				{
					array_dimension_parser();
					if(error_detection()==0)
					{
						funct_attri_buf.resize(0);
						array_dimension_parser();
						inserting_symbol_table(id_list_buf,"parameter",reverse_arr_buf,funct_attri_buf);
						id_list_buf.clear();
					}
				}
				else
				{
					if(error_detection()==0)
					{
						inserting_symbol_table(id_list_buf,"parameter",$3,funct_attri_buf);
						id_list_buf.clear();
					}
				}
				is_array=0;
			}
			;

id_list		: id_list MK_COMMA ID /*one ID for one sub_entry*/
			{
				tmpstr.clear();
				strcpy(tmpstr,yytext);
				id_list_buf.pb(tmpstr);
				/* $$=yytext; */
			}
			| ID
			{
				tmpstr.clear();
				strcpy(tmpstr,yytext);
				id_list_buf.pb(tmpstr);
				/* $$=yytext; */
			}
			;

opt_type	: MK_COLON type {$$=$2;}
			| /* epsilon */
			;

type		: scalar_type {$$=$1;} /*type transmittion*/
			| array_type {$$=$1;} /*type transmittion*/
			;

scalar_type	: INTEGER
			{
				$$="integer ";
			}
			| REAL
			{
				$$="real ";
			}
			| BOOLEAN
			{
				$$="boolean ";
			}
			| STRING
			{
				$$="string ";
			}
			;

array_type	: ARRAY
			{
				is_array=1;
			}
 			int_const TO int_const OF type
			{
				int delta=atol($5)-atol($3)+1;
				char tmp[10];
				sprintf(tmp,"%d",delta);
				strcat(arr_buf,tmp);
				strcat(arr_buf,",");
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
