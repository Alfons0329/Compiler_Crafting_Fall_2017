%{
/**
 * Introduction to Compiler Design by Prof. Yi Ping You
 * Project 2 YACC sample
 */
#include <bits/stdc++.h>
#include "symboltable.h"
#define pb push_back
#define BUF_SIZE 50
//C++ working
extern "C" int yylex(void);
extern FILE *yyin;		/* declared by lex */
extern char *yytext;	/* declared by lex */
extern char *buf;	/* declared in lex.l */
extern int Opt_D; /* declared in lex.l */
extern int linenum;	/* declared in lex.l */
int yyerror(const char*);

//some global variables that needed in the parsing procedure
char arr_buf[BUF_SIZE];
char reverse_arr_buf[BUF_SIZE];
string const_buf;
string const_type_str;
string funct_name;
vector<string> id_list_buf; //
vector<string> funct_attri_buf;
%}
/*tokens*/
%union
{
    char* parsed_string;
}
%token <parsed_string>ARRAY BEG BOOLEAN DEF DO ELSE END FALSE FOR INTEGER IF OF PRINT READ REAL RETURN STRING THEN TO TRUE VAR WHILE
%token <parsed_string>ID OCTAL_CONST INT_CONST FLOAT_CONST SCIENTIFIC STR_CONST
%token <parsed_string>OP_ADD OP_SUB OP_MUL OP_DIV OP_MOD OP_ASSIGN OP_EQ OP_NE OP_GT OP_LT OP_GE OP_LE OP_AND OP_OR OP_NOT
%token <parsed_string>MK_COMMA MK_COLON MK_SEMICOLON MK_LPAREN MK_RPAREN MK_LB MK_RB
/* start symbol */
%type <parsed_string> decl func_decl opt_type int_const literal_const param id_list type scalar_type array_type

%start program
%%

program		:	ID
				{
					symbol_table_init();
					id_list_buf.pb(yytext);
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
                dumpsymbol();
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
				is_arr=0;
			}
			| VAR id_list MK_COLON literal_const /* const declaration */
			{
				funct_attri_buf.pb(const_buf); //normal variable does not have attribute, so just let the size be zero
				inserting_symbol_table(id_list_buf,"constant",const_type_str,funct_attri_buf);
				id_list_buf.clear();
				error_detection();
			}
			MK_SEMICOLON
			;

int_const	:	INT_CONST {$$=yytext; const_type=1;}
			|	OCTAL_CONST {$$=yytext; const_type=9;}
			;

literal_const	: int_const {$$=yytext; const_type=(const_type==1)?1:9; const_type_str="integer ";parse_constant();}
				| OP_SUB int_const {$$=yytext; const_type=(const_type==1)?2:10; const_type_str="integer ";parse_constant();}
				| FLOAT_CONST {$$=yytext; const_type=3; const_type_str="real ";parse_constant();}
				| OP_SUB FLOAT_CONST {$$=yytext; const_type=4; const_type_str="real ";parse_constant();}
				| SCIENTIFIC {$$=yytext; const_type=5; const_type_str="real ";parse_constant();}
				| OP_SUB SCIENTIFIC {$$=yytext; const_type=6; const_type_str="real ";parse_constant();}
				| STR_CONST {$$=yytext; const_type=7; const_type_str="string ";parse_constant();}
				| TRUE {$$=yytext; const_type=8; const_type_str="boolean ";parse_constant();}
				| FALSE {$$=yytext; const_type=8; const_type_str="boolean ";parse_constant();}
			;

opt_func_decl_list	: func_decl_list
					| /* epsilon */
			;

func_decl_list		: func_decl_list func_decl
					| func_decl
			;

func_decl	: 	ID
				{
                    funct_name = yytext;
                    scope_depth++;
				}
 				MK_LPAREN opt_param_list MK_RPAREN
				{
					is_funct=1;
					scope_depth--;
				}
				opt_type MK_SEMICOLON
				{
                    id_list_buf.pb(funct_name);
                    funct_name.clear();
                    if(is_arr)
					{
						array_dimension_parser();
						//here we push_back the funct_attri_buf inorder to match the attributes of function
						funct_attri_buf.resize(0); //primitive initialization
						for(unsigned int i=0;i<mysymbol_table[1].size();i++) //search the parameter for function attribute
						{
							if((mysymbol_table[1][i].kind=="parameter")&&(mysymbol_table[1][i].name[0]!=0))
							{
								funct_attri_buf.pb(mysymbol_table[1][i].type+",");
							}
						}
						inserting_symbol_table(id_list_buf,"function",reverse_arr_buf,funct_attri_buf);
					}
					else
					{
						//here we push_back the funct_attri_buf inorder to match the attributes of function
						funct_attri_buf.resize(0); //primitive initialization
						for(unsigned int i=0;i<mysymbol_table[1].size();i++) //search the parameter for function attribute
						{
							if((mysymbol_table[1][i].kind=="parameter")&&(mysymbol_table[1][i].name[0]!=0))
							{
								funct_attri_buf.pb(mysymbol_table[1][i].type+",");
							}
						}
                        if($7==NULL) //prevent logic null string error
                        {
                            inserting_symbol_table(id_list_buf,"function","void",funct_attri_buf);
                        }
                        else
                        {
                            inserting_symbol_table(id_list_buf,"function",$7,funct_attri_buf);
                        }

					}
                    id_list_buf.clear();
                    error_detection();
					is_arr=0;
				}
			  	compound_stmt
			  	END
				{
					is_funct=0;
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
				if(is_arr)
				{
					if(error_detection()==0)
					{
						array_dimension_parser();
						inserting_symbol_table(id_list_buf,"parameter",reverse_arr_buf,funct_attri_buf);
					}
				}
				else
				{
					if(error_detection()==0)
					{
						inserting_symbol_table(id_list_buf,"parameter",$3,funct_attri_buf);
					}
				}
                id_list_buf.clear();
				is_arr=0;
			}
			;

id_list		: id_list MK_COMMA ID /*one ID for one sub_entry*/
			{
                id_list_buf.pb(yytext);
                cout<<"Match id "<<yytext<<endl;
			}
			| ID
			{
				id_list_buf.pb(yytext);
                cout<<"Match id "<<yytext<<endl;
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
                char* synth = (char* )"integer";
                $$=synth;
			}
			| REAL
			{
                char* synth = (char* )"real ";
                $$=synth;
			}
			| BOOLEAN
			{
                char* synth = (char* )"boolean ";
                $$=synth;
			}
			| STRING
			{
                char* synth = (char* )"string ";
                $$=synth;
			}
			;

array_type	: ARRAY
			{
				is_arr=1;
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
					scope_depth++;
				}
			  	opt_decl_list
			  	opt_stmt_list
				{
					if(is_funct&&scope_depth>1) //prevernt double popping
					{
						dumpsymbol();
						pop_symbol_table();
					}
					else if(!is_loop)/*if(!is_funct) *///normal like
					{
						dumpsymbol();
						pop_symbol_table();
					}
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
					inserting_iter_table(yytext,scope_depth+1);
					error_detection();
					//dumpiterator();
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

int yyerror(const char *msg )
{
	fprintf( stderr, "\n|--------------------------------------------------------------------------\n" );
	fprintf( stderr, "| Error found in Line #%d: %s\n", linenum, buf );
	fprintf( stderr, "|\n" );
	fprintf( stderr, "| Unmatched token: %s\n", yytext );
	fprintf( stderr, "|--------------------------------------------------------------------------\n" );
	exit(-1);
}
