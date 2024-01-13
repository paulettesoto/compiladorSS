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

// Definición de la regla principal "progr"
progr: libraries st FunctionMain {printf("Sintaxis correcta\n");}
     ;

// Reglas para la sección "libraries"
libraries :  LIBRARY
	   | libraries LIBRARY
	   ;
// Reglas para la sección "st"
st : Dec 
           | st Dec
	   ;

// Reglas para la declaración de variables y funciones "Dec"
Dec : TYPE NAME ';'
	   | TYPE VECTOR ';' 
           | TYPE NAME '('')' ';'
           | TYPE NAME '(' paramlist ')' ';'
	   | STRUCT NAME'{' st '}'';'
           ;

// Reglas para la lista de parámetros "paramlist"
paramlist : parameter
            | paramlist ','  parameter 
            ;
            
// Regla para la definición de parámetros "parameter"
parameter : TYPE NAME
	  | TYPE VECTOR
          ; 

// Regla para la función principal "FunctionMain"
FunctionMain : MAIN block 
     ;
// Regla para un bloque de código "block"
block : '{' insList '}'
     ;
     
// Reglas para la lista de instrucciones "insList"
insList :  ins ';' 
                  | insList ins ';' 
		  | insControl
		  | insList insControl
                  ;

// Reglas para el control de flujo "insControl"
insControl : IF '(' condition ')' block
		    | IF '(' condition ')' block ELSE block
		    | WHILE '(' condition ')' block
 		    | FOR '(' ins ';' condition ';' insList ')' block
		    ;

// Regla para una condición "condition"
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


// Reglas para las instrucciones "ins"
ins: NAME ATTRIBUTE exp	 
            | NAME '(' callList ')'
	    | Dec
            ;
        
// Regla para la lista de llamadas a funciones "callList"
callList : CARACTER
		 | NUMBER
		 | callList ',' NUMBER
           	 | callList ',' CARACTER
		 | callList ',' NAME
		 | NAME	 
           ;

// Regla para expresiones "exp"
exp : exp MULTY exp
	 | exp DIV exp
	 | exp PLUS exp
	 | exp MINUS exp
	 | NAME
	 | CARACTER
	 | NUMBER
	 ;

%%
// Función de manejo de errores
int yyerror(char * s){

}
// Función principal
int main(int argc, char** argv){
yyin=fopen(argv[1],"r");
yyparse();
}