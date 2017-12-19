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
string array_type_str;
vector<string> id_list_buf; //
vector<string> funct_attri_buf;
//global variables for HW4
vector<string> assign_check_buf;
//data structure for parameter processing starts here
vector<param_struct> funct_param_buf;
param_struct one_param_struct;
//data structure for parameter processing ends here
//important data structure for funct paramater collection including their dimension
//this one is the new array buffer which is easier to be implemented in C++
vector<int> arr_dim_buf;
int is_proc_call;
//use for array scalar type checking
int LHS_dim,RHS_dim,switch_side;
string tmp_inheritance;
%}
/*tokens*/
%union
{
    char* str;
}
%token <str>ARRAY BEG BOOLEAN DEF DO ELSE END FALSE FOR INTEGER IF OF PRINT READ REAL RETURN STRING THEN TO TRUE VAR WHILE
%token <str>ID OCTAL_CONST INT_CONST FLOAT_CONST SCIENTIFIC STR_CONST
%token <str>OP_ADD OP_SUB OP_MUL OP_DIV OP_MOD OP_ASSIGN OP_EQ OP_NE OP_GT OP_LT OP_GE OP_LE OP_AND OP_OR OP_NOT
%token <str>MK_COMMA MK_COLON MK_SEMICOLON MK_LPAREN MK_RPAREN MK_LB MK_RB
/* start symbol */
%type <str> decl func_decl opt_type int_const literal_const param id_list type scalar_type array_type
/* HW4 more type to be implemented*/
%type <str> var_ref factor
%type <str> boolean_expr_list boolean_expr boolean_term boolean_factor relop_expr expr term add_op mul_op
%start program
%%

program		:	ID
				{
					symbol_table_init();
					id_list_buf.pb(yytext);
					funct_attri_buf.clear();
                    program_name_checking(program_name,$1,0);
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
                    program_name_checking(program_name,$7,1);
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
				funct_attri_buf.clear(); //normal variable does not have attribute, so just let the size be zero
				inserting_symbol_table(id_list_buf,"variable",$4,funct_attri_buf);
				id_list_buf.clear();
				error_detection();
			}
			MK_SEMICOLON
			| VAR id_list MK_COLON array_type MK_SEMICOLON   /* array type declaration */
			{
                funct_attri_buf.clear(); //normal variable does not have attribute, so just let the size be zero
				array_dimension_parser();
                array_type_str=$4;
                array_type_str+=" ";
                array_type_str+=reverse_arr_buf;
				inserting_symbol_table(id_list_buf,"variable",array_type_str,funct_attri_buf);

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
                funct_attri_buf.clear();
			}
			MK_SEMICOLON
			;

int_const	:	INT_CONST {$$=yytext; const_type=1;}
			|	OCTAL_CONST {$$=yytext; const_type=9;}
			;

literal_const	: int_const
				{
					const_type=(const_type==1)?1:9;
					const_type_str="integer";
					parse_constant();
					$$=strdup(const_type_str.c_str());
				}
				| OP_SUB int_const
				{
					const_type=(const_type==1)?2:10;
					const_type_str="integer";
					parse_constant();
					$$=strdup(const_type_str.c_str());
				}
				| FLOAT_CONST
				{
					const_type=3;
					const_type_str="real";
					parse_constant();
					$$=strdup(const_type_str.c_str());
				}
				| OP_SUB FLOAT_CONST
				{
					const_type=4;
					const_type_str="real";
					parse_constant();
					$$=strdup(const_type_str.c_str());
				}
				| SCIENTIFIC
				{
					const_type=5;
					const_type_str="real";
					parse_constant();
					$$=strdup(const_type_str.c_str());
				}
				| OP_SUB SCIENTIFIC
				{
					const_type=6;
					const_type_str="real";
					parse_constant();
					$$=strdup(const_type_str.c_str());
				}
				| STR_CONST
				{
					 const_type=7;
					 const_type_str="string ";
					 parse_constant();
					 $$=strdup(const_type_str.c_str());
				 }
				| TRUE
				{
					const_type=8;
					const_type_str="boolean";
					parse_constant();
					$$=strdup(const_type_str.c_str());
				}
				| FALSE
				{
					const_type=8;
					const_type_str="boolean";
					parse_constant();
					$$=strdup(const_type_str.c_str());
				}
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
						cout<<"<Error> found in Line: "<<linenum<<" function cannot return a non-scalar type!"<<endl;
						/*array_dimension_parser();
						//here we push_back the funct_attri_buf inorder to match the attributes of function
						funct_attri_buf.clear(); //primitive initialization
						for(unsigned int i=0;i<mysymbol_table[1].size();i++) //search the parameter for function attribute
						{
							if((mysymbol_table[1][i].kind=="parameter")&&(mysymbol_table[1][i].name[0]!=0))
							{
                                funct_attri_buf.pb(mysymbol_table[1][i].type);
							}
						}
                        array_type_str=$7;
                        array_type_str+=" ";
                        array_type_str+=reverse_arr_buf;
						inserting_symbol_table(id_list_buf,"function",array_type_str,funct_attri_buf);*/
                        memset(arr_buf,0,sizeof(arr_buf));//update it for next segment*/
					}
					else
					{
						//here we push_back the funct_attri_buf inorder to match the attributes of function
						funct_attri_buf.clear(); //primitive initialization
						for(unsigned int i=0;i<mysymbol_table[1].size();i++) //search the parameter for function attribute
						{
							if((mysymbol_table[1][i].kind=="parameter")&&(mysymbol_table[1][i].name[0]!=0))
							{
                                funct_attri_buf.pb(mysymbol_table[1][i].type);
							}
						}
                        if($7==";") //prevent logic null string error
                        {
							inserting_symbol_table(id_list_buf,"function","void",funct_attri_buf);
                        }
                        else
                        {
                            inserting_symbol_table(id_list_buf,"function",$7,funct_attri_buf);
                        }

					}
					dumpsymbol();
                    id_list_buf.clear();
                    funct_attri_buf.clear();
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
				funct_attri_buf.clear();
				if(is_arr)
				{
                    if(error_detection()==0)
					{
						array_dimension_parser();
                        array_type_str=$3;
                        array_type_str+=" ";
                        array_type_str+=reverse_arr_buf;
						inserting_symbol_table(id_list_buf,"parameter",array_type_str,funct_attri_buf);
                        memset(arr_buf,0,sizeof(arr_buf));//update it for next segment
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
			}
			| ID
			{
				id_list_buf.pb(yytext);
			}
			;

opt_type	: MK_COLON type
			{
				$$=$2;
			}
			|
			/* epsilon */
			;

type		: scalar_type {$$=$1;} /*type transmittion*/
			| array_type {$$=$1;} /*type transmittion*/
			;

scalar_type	: INTEGER
			{
                char* synth = (char* )"integer";//suppose this is not implemented, IOS CONVERSION ERROR WILL BE THROWN
                $$=synth;
			}
			| REAL
			{
                char* synth = (char* )"real";//suppose this is not implemented, IOS CONVERSION ERROR WILL BE THROWN
                $$=synth;
			}
			| BOOLEAN
			{
                char* synth = (char* )"boolean";//suppose this is not implemented, IOS CONVERSION ERROR WILL BE THROWN
                $$=synth;
			}
			| STRING
			{
                char* synth = (char* )"string";//suppose this is not implemented, IOS CONVERSION ERROR WILL BE THROWN
                $$=synth;
			}
			;

array_type	: ARRAY
			{
				is_arr=1;
			}
 			int_const TO int_const OF type
			{
                $$=$7;
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
                    dumpsymbol();
                    pop_symbol_table();
				}
			  	END
			;

opt_stmt_list		: stmt_list
			| /* epsilon */
			;

stmt_list		: stmt_list stmt
			| stmt
			;

simple_stmt	:
			var_ref
			{
				switch_side=1;
				RHS_dim=0;
				/* cout<<666666<<endl; */
				tmp_inheritance=has_scalar(find_type($1),LHS_dim,"assign LHS");
			}
            OP_ASSIGN boolean_expr MK_SEMICOLON
            {
				cout<<"we have an assign LHS "<<find_type($1)<<" with RHS "<<find_type($4)<<endl;
				if(find_type($4)=="none")
				{
					cout<<"const type "<<$4<<endl;
					assignop(find_type($1),$4,$1,$4);
				}
				else
				{
					cout<<"non const right type "<<$4<<endl;
					assignop(find_type($1),find_type($4),$1,$4);
				}
				tmp_inheritance.clear();
				switch_side=0;
				LHS_dim=0;
				RHS_dim=0;
            }
			| PRINT boolean_expr MK_SEMICOLON
			{
				simple($2);
			}
			| READ boolean_expr MK_SEMICOLON
			{
				simple($2);
			}
			;

proc_call_stmt	:
            ID MK_LPAREN opt_boolean_expr_list MK_RPAREN MK_SEMICOLON
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
					is_loop=1;
				}
 			  	OP_ASSIGN int_const TO int_const DO
				{
					if(atoi($7)-atoi($5) < 0)
					{
						printf("<Error> Found in Line%d: loop parameter's lower bound >= uppper bound\n",linenum);
					}
				}
			  	opt_stmt_list
			  	END DO
				{
					is_loop=0;
				}
			;

return_stmt	: RETURN boolean_expr MK_SEMICOLON
			{
				has_scalar(find_type($2),LHS_dim,"return_stmt ");
			}
			;

opt_boolean_expr_list	: boolean_expr_list
			| /* epsilon */
			;

boolean_expr_list	: boolean_expr_list MK_COMMA boolean_expr
			| boolean_expr {$$=$1;}
			;

boolean_expr		: 	boolean_expr OP_OR boolean_term
						{
							if(find_type($3)=="none")
							{
								/* cout<<"Right const type "<<$3<<endl; */
								$$=strdup(boolop(find_type($1),$3,$1,$3).c_str());
							}
							else if(find_type($1)=="none")
							{
								/* cout<<"Left const type "<<$3<<endl; */
								$$=strdup(boolop($1,find_type($3),$1,$3).c_str());
							}
							else
							{
								/* cout<<"Both Non const type "<<$4<<endl; */
								$$=strdup(boolop(find_type($1),find_type($3),$1,$3).c_str());
							}
						}
						| boolean_term
						{
							$$=$1;
						}
			;

boolean_term		: 	boolean_term OP_AND boolean_factor
						{
							if(find_type($3)=="none")
							{
								/* cout<<"Right const type "<<$3<<endl; */
								$$=strdup(boolop(find_type($1),$3,$1,$3).c_str());
							}
							else if(find_type($1)=="none")
							{
								/* cout<<"Left const type "<<$3<<endl; */
								$$=strdup(boolop($1,find_type($3),$1,$3).c_str());
							}
							else
							{
								/* cout<<"Both Non const type "<<$4<<endl; */
								$$=strdup(boolop(find_type($1),find_type($3),$1,$3).c_str());
							}
						}
						| boolean_factor {$$=$1;}
			;

boolean_factor		: OP_NOT boolean_factor /*do self relation*/
					{
						if(find_type($2)=="none")
						{
							/* cout<<"Right const type "<<$2<<endl; */
							$$=strdup(boolop($2,$2,$2,$2).c_str());
						}
						else
						{
							/* cout<<"Both Non const type "<<$2<<endl; */
							$$=strdup(boolop(find_type($2),find_type($2),$2,$2).c_str());
						}
					}
					| relop_expr {$$=$1;}
			;

relop_expr	: 	expr
				rel_op
				{
					switch_side=1;
					RHS_dim=0;
				}
				expr
				{
				/* cout<<"RELOP EXPR HAPPENS HERE linenum "<<linenum<<endl; */
					if(find_type($4)=="none")
					{
						/* cout<<"Right const type "<<$4<<endl; */
						$$=strdup(relop(find_type($1),$4,$1,$4).c_str());
					}
					else if(find_type($1)=="none")
					{
						/* cout<<"Left const type "<<$4<<endl; */
						$$=strdup(relop($1,find_type($4),$1,$4).c_str());
					}
					else
					{
						/* cout<<"Both Non const type "<<$4<<endl; */
						$$=strdup(relop(find_type($1),find_type($4),$1,$4).c_str());
					}
					switch_side=0;
					LHS_dim=0;
					RHS_dim=0;
				}
				| expr {$$=$1;}
			;

rel_op		: OP_LT
			| OP_LE
			| OP_EQ
			| OP_GE
			| OP_GT
			| OP_NE
			;

expr		: 	expr
 				add_op
				{
					switch_side=1;
					RHS_dim=0;
				}
				term
            	{
                	if(find_type($4)=="none")
					{
						/* cout<<" Left variable type "<<$1<<" Right const type "<<$4<<endl; */
						$$=strdup(addop(find_type($1),$4,$1,$4,$2).c_str());
					}
					else if(find_type($1)=="none")
					{
						/* cout<<" Left const type "<<$1<<" Right variable type "<<$4<<endl; */
						$$=strdup(addop($1,find_type($4),$1,$4,$2).c_str());
					}
					else
					{
						/* cout<<"Both Non const type "<<$4<<endl; */
						$$=strdup(addop(find_type($1),find_type($4),$1,$4,$2).c_str());
					}
					switch_side=0;
					LHS_dim=0;
					RHS_dim=0;
            	}
				| term {$$=$1;}
			;

add_op		: OP_ADD
			| OP_SUB
			;

term		:
			term
			mul_op
			{
				switch_side=1;
				RHS_dim=0;
			}
			factor /*use dollar sign to do things*/
			{
				/* cout<<"555555  "<<endl; */
				if(find_type($4)=="none")
				{
					/* cout<<" Left variable type xdxdxdxddx "<<$1<<" Right const type "<<$4<<endl; */
					$$=strdup(mulop(find_type($1),$4,$1,$4,$2).c_str());
				}
				else if(find_type($1)=="none")
				{
					/* cout<<" Left const type "<<$1<<" Right variable type "<<$4<<endl; */
					$$=strdup(mulop($1,find_type($4),$1,$4,$2).c_str());
				}
				else
				{
					/* cout<<"Both Non const type "<<$4<<endl; */
					$$=strdup(mulop(find_type($1),find_type($4),$1,$4,$2).c_str());
				}
				switch_side=0;
				LHS_dim=0;
				RHS_dim=0;
			}
			| factor
			{
				$$=$1;  /*pass the factor up*/
			}
			;

mul_op		: OP_MUL
			| OP_DIV
			| OP_MOD
			;

factor		: var_ref
			{
				$$=$1;
			}
			| OP_SUB var_ref
			{
				$$=$2;
			}
			| MK_LPAREN boolean_expr MK_RPAREN
			| OP_SUB MK_LPAREN boolean_expr MK_RPAREN
			| ID /*function param here*/
            {
				one_param_struct.param_name=$1;
				one_param_struct.param_dim=0;
				funct_param_buf.pb(one_param_struct);
				LHS_dim=0;
                is_proc_call=1;
            }
            MK_LPAREN opt_boolean_expr_list MK_RPAREN
            {
				procedure_call_checking();
                funct_param_buf.clear();
                is_proc_call=0;
            }
			| OP_SUB ID MK_LPAREN opt_boolean_expr_list MK_RPAREN
			| literal_const
            {
                $$=$1;
                if(is_proc_call)
                {
					one_param_struct.param_name=$1;
					one_param_struct.param_dim=LHS_dim;
					funct_param_buf.pb(one_param_struct);
					LHS_dim=0;
                }
            }
			;

var_ref		:
            ID
            {
                $$=$1;
                if(is_proc_call)
                {
					one_param_struct.param_name=$1;
					one_param_struct.param_dim=LHS_dim;
					funct_param_buf.pb(one_param_struct);
					LHS_dim=0;
                }
				/* cout<<"Array First time reference! "<<endl; */
            }
			| var_ref dim
			{
				if(switch_side)
				{
					RHS_dim++;
					cout<<"Array RIGHT dimension reference at Line"<<linenum<<"  now dim count up to"<<RHS_dim<<endl;
				}
				else
				{
					LHS_dim++;
					cout<<"Array LEFT dimension reference at Line"<<linenum<<"  now dim count up to"<<LHS_dim<<endl;
				}

			}
			;

dim			: MK_LB boolean_expr MK_RB
			;

%%

int yyerror(const char *msg )
{
    const char* tmp = msg;
    fprintf( stderr, "\n|--------------------------------------------------------------------------\n" );
	fprintf( stderr, "| Error found in Line #%d: %s\n", linenum, buf );
	fprintf( stderr, "|\n" );
	fprintf( stderr, "| Unmatched token: %s\n", yytext );
	fprintf( stderr, "|--------------------------------------------------------------------------\n" );
	exit(-1);
}
