%{
#include <stdio.h>
#define MAXNUMBEROFVARIABLES 1024
#define MAXNUMBEROFFUNCTIONS 1024
//struct varTableCell variabile[MAXNUMBEROFVARIABLES];
//struct varTableCell functii[MAXNUMBEROFFUNCTIONS];
int nrVar = 0;
int nrFunc = 0;

extern FILE* yyin;
extern char* yytext;
extern int yylineno;


%}
%union {
int intval;
char* strval;
char charval;
}

%token LIBRARY MAIN TYPE NAME VECTOR CARACTER NUMBER STRUCT ATTRIBUTE GT LT DIF EQUAL MULTY DIV PLUS MINUS AND OR IF ELSE FOR WHILE
%right IF ELSE
%left MULTY
%left DIV
%left PLUS
%left MINUS
%left ATTRIBUTE
%left AND
%left OR
%left GT LT DIF EQUAL
%left NAME CARACTER NUMBER
%start progr
%%
progr: libraries st FunctionMain {printf("Sintaxis correcta\n");}
     ;

libraries :  LIBRARY
	   | libraries LIBRARY
	   ;

st : Dec 
           | st Dec
	   ;

Dec : TYPE NAME ';'
	   | TYPE VECTOR ';' 
           | TYPE NAME '('')' ';'
           | TYPE NAME '(' paramlist ')' ';'
	   | STRUCT NAME'{' st '}'';'
           ;

paramlist : parameter
            | paramlist ','  parameter 
            ;
            
parameter : TYPE NAME
	  | TYPE VECTOR
          ; 

	/* block */
FunctionMain : MAIN block 
     ;

block : '{' insList '}'
     ;
     
	/* Instruction List */
insList :  ins ';' 
                  | insList ins ';' 
		  | insControl
		  | insList insControl
                  ;

	/* insControl*/
insControl : IF '(' condition ')' block
		    | IF '(' condition ')' block ELSE block
		    | WHILE '(' condition ')' block
 		    | FOR '(' ins ';' condition ';' insList ')' block
		    ;

	/* condition*/
condition : condition GT condition
	 | condition LT condition
	 | condition DIF condition
	 | condition EQUAL condition
	 | condition AND condition
	 | condition OR condition
	 | NAME
	 | CARACTER
	 | NUMBER
	 ;

	/* ins */
ins: NAME ATTRIBUTE exp	 
            | NAME '(' callList ')'
	    | Dec
            ;
        
callList : CARACTER
		 | NUMBER
		 | callList ',' NUMBER
           	 | callList ',' CARACTER
		 | callList ',' NAME
		 | NAME	 
           ;

	/* exp*/
exp : exp MULTY exp
	 | exp DIV exp
	 | exp PLUS exp
	 | exp MINUS exp
	 | NAME
	 | CARACTER
	 | NUMBER
	 ;

%%
int yyerror(char * s){

}

int main(int argc, char** argv){
yyin=fopen(argv[1],"r");
yyparse();
}