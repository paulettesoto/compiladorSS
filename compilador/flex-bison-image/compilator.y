%{
// Archivo: compilator.y
// Descripción: Archivo de especificación de la gramática para el compilador.
// Autor: Soto Angeles Paulette Esmeralda, Niebla Leyva Brayhan Daniel
// Fecha: 12-01-2024
// Nota: Este archivo utiliza la herramienta Bison para análisis sintáctico.

#include <stdio.h>

// Definición de funciones externas
int yylex(void);
int yyerror(char* s);

#include <stdlib.h>
#include "tabla.h" // Incluye el archivo de tabla para funciones y variables
#define MAXNUMBEROFVARIABLES 1024
#define MAXNUMBEROFFUNCTIONS 1024
#define ERR 12312312

// Definición de tablas para variables y funciones
struct varTableCell varTable[MAXNUMBEROFVARIABLES];
struct funcTableCell funcTable[MAXNUMBEROFFUNCTIONS];

// Contadores de variables y funciones
int nrVar = 0;
int nrFunc = 0;

extern FILE* yyin;
extern char* yytext;
extern int yylineno;


%}
%union {
char strval[2048];
int intval;
}

// Definición de tokens y tipos
%token <strval>STRCPY CONST <strval>STRCMP PRINT PRINTF LIBRARY MAIN <strval>TYPE <strval>NAME VECTOR <strval>CARACTER <strval>NUMBER STRUCT ATTRIBUTE GT LT DIF EQUAL MULTY DIV PLUS MINUS AND OR IF ELSE FOR WHILE RETURN
%type <strval>value
%type <strval>paramlist
%type <strval>parameter
%type <strval>callList
%type <intval>Exp
%right IF ELSE
%left '(' ')'
%left PLUS
%left MINUS
%left MULTY
%left DIV
%left ATTRIBUTE
%left AND
%left OR
%left GT LT DIF EQUAL
%left NAME CARACTER NUMBER
%start progr
%%

// Reglas de producción
progr: libraries st FunctionMain FunctionDfn {printf("\n\n\n");}
     ;

libraries :  LIBRARY
           | libraries LIBRARY
           ;

st : Dec ';'
           | st Dec ';'
           ;

Dec : TYPE NAME  { 
					// Agregar variable a la tabla de variables
					int res = addVarTable($1, $2, nrVar, varTable); if (res == 0) {printf(" "); } else {nrVar++;} 
				 } 
           | TYPE VECTOR  
           | TYPE NAME '('')'  
           | TYPE NAME '(' paramlist ')'  { 
											// Agregar función a la tabla de funciones
											addFuncTable($2, $1, $4, nrFunc++,funcTable, 0); 
										  }
           | STRUCT NAME'{' st '}'
           | STRUCT NAME NAME 
           | CONST TYPE NAME  
           | CONST TYPE VECTOR  
           | CONST TYPE NAME '('')'  
           | CONST TYPE NAME '(' paramlist ')' 
           | CONST STRUCT NAME'{' st '}'
           | CONST STRUCT NAME NAME 
           ;

paramlist : parameter { for (int i = 0; i < 2048; i++) { $$[i] = $1[i];} }
                | paramlist ','  parameter { 
				// Concatenar parámetros separados por comas
				char s[2048]; strcpy(s, $1); strcat(s, " "); strcat(s, $3); for (int i = 0; i < 2048; i++) { $$[i] = s[i];} }
            ;
            
parameter : TYPE 
          ; 

        /* block */
FunctionMain : MAIN block 
     ;

block : '{' insList RETURN Exp ';' '}'
     | '{' insList RETURN value ';' '}'
     ;
        /* Instruction List */
insList : ins ';' 
                  | insList ins ';' 
                  | insControl
                  | insList insControl
                  ;

        /* insControl*/
insControl : IF '(' condition ')' '{' insList '}'
        | IF '(' condition ')' '{' insList '}' ELSE '{' insList '}'
        | WHILE '(' condition ')' '{' insList '}'
        | FOR '(' ins ';' condition ';' insList ')' '{' insList '}'
        ;

        /* condition*/
condition : condition GT condition
         | condition LT condition
         | condition DIF condition
         | condition EQUAL condition
         | condition AND condition
         | condition OR condition
         | '('  condition ')'
         | NAME { 
		 // Verificar si la variable está declarada
            int pos = posVarTable($1, varTable, nrVar);
            if (pos == -1) {
              printf("La variable %s no fue declarada! Linea: %d\n", $1, yylineno);
            }
         }
         | CARACTER
         | NUMBER
         ;

        /* ins */
ins: NAME ATTRIBUTE value { if (setValue($1, $3, varTable, nrVar) == 1) printf(" "); else printf("Error en la linea %d\n", yylineno); }
            | NAME ATTRIBUTE Exp { 
                char buff[2048];
                int resultado = $3;
                sprintf(buff, "%d", resultado);
                if (setValue($1, buff, varTable, nrVar) && $3 != ERR) 
                    printf(" "); 
                else printf("Error en la linea %d\n", yylineno);
            }
            | STRCPY '(' NAME ',' NAME ')'
            | STRCPY '(' NAME ',' CARACTER ')'
            | STRCPY '(' CARACTER ',' CARACTER ')'
            | STRCPY '(' CARACTER ',' NAME ')'
            | STRCMP '(' NAME ',' NAME ')'
            | STRCMP '(' NAME ',' CARACTER ')'
            | STRCMP '(' CARACTER ',' CARACTER ')'
            | STRCMP '(' CARACTER ',' NAME ')'
            | NAME '(' callList ')' {int res; 
                if ((res = checkFunc($1, $3, funcTable, varTable, nrFunc, nrVar)) == 1) {  printf(" "); } 
                else { printf("La funcion de la linea %d no es valida. Error: %d\n", yylineno, res); } 
                if (res == 1) { 
                        int pos = -1;
                        for (int i = 0; i < nrFunc; i++) {
                                if (strcmp(funcTable[i].name, $1) == 0) {
                                        pos = i;
                                        break;
                                }
                        }
                        if (funcTable[pos].reserved == 1) {
                                printf("%d\n", execReservedFunc(pos,$3 ,varTable, nrVar, funcTable, nrFunc));
                        }
                } }
            | NAME '.' NAME ATTRIBUTE value
            | NAME '.' NAME ATTRIBUTE NAME '.' NAME
            | NAME '.' NAME ATTRIBUTE NAME
            | NAME ATTRIBUTE NAME '.' NAME
            | Dec
            | PRINT '(' Exp ')' { printf("%d\n",$3); }
            | PRINTF '(' NAME ')' { print($3, varTable, nrVar); printf("\n");}
            ;

Exp: Exp PLUS Exp { $$ = $1 + $3; }
        | Exp MULTY  Exp { $$ = $1 * $3; }
        | Exp MINUS Exp { $$ = $1 - $3; }
        | Exp DIV Exp { $$ = $1 / $3; }
        | '(' Exp ')' { $$ = $2; }
        | NUMBER { $$ = atoi($1); } // Valor numérico
        | NAME { int poz = posVarTable($1, varTable, nrVar); 
                if (poz == -1) { printf("La variable %s no existe! Linea: %d\n", $1, yylineno); $$ = ERR;}
                else {
                  if (varTable[poz].initialized == 0) { printf("La variable %s no fue inicializada!\n", $1); $$ = ERR; }
                  if (strcmp(varTable[poz].currentVar.type, "int") != 0) {printf("Error! expresion invalida! Linea: %d\n",yylineno); $$ = ERR;}
                  else { $$ = *((int *)(varTable[poz].address)); } } // Obtener el valor de la variable
                }
        | NAME '(' callList ')' {int res; 
                if ((res = checkFunc($1, $3, funcTable, varTable, nrFunc, nrVar)) == 1) {  printf(" "); } 
                else { printf("La funcion en la linea %d no es valida. Error: %d\n", yylineno, res); } 
                if (res == 1) { 
                        int pos = -1;
                        for (int i = 0; i < nrFunc; i++) {
                                if (strcmp(funcTable[i].name, $1) == 0) {
                                        pos = i;
                                        break;
                                }
                        }
                        if (funcTable[pos].reserved == 1) {
                                $$ = execReservedFunc(pos,$3 ,varTable, nrVar, funcTable, nrFunc);
                        }
                } }  
        ;

/*FunctionDfn*/
FunctionDfn : TYPE NAME '(' paramlist ')' block
           ;
        
callList : NAME { for (int i = 0; i < 2048; i++) { $$[i] = $1[i];} }  
                 | callList ',' NAME { char s[2048]; strcpy(s, $1); strcat(s, " "); strcat(s , $3);  for (int i = 0; i < 2048; i++) { $$[i] = s[i];}}
                 | NUMBER
     | callList ',' NUMBER
                 | CARACTER
     | callList ',' CARACTER
                 | NAME '(' callList ')'
     | callList ',' NAME '(' callList ')'
;
        /*  importante*/
value :  CARACTER { for (int i = 0; i < 2048; i++) { $$[i] = $1[i];} }
         ;

%%
// Función de manejo de errores
int yyerror(char * s){

}
// Función principal
int main(int argc, char** argv){
		// Agregar funciones reservadas al inicio
        addFuncTable("maximum", "int", "int int", nrFunc++, funcTable, 1);
        addFuncTable("minimum", "int", "int int", nrFunc++, funcTable, 1);
        yyin=fopen(argv[1],"r");
        yyparse();
		// Redirigir la salida estándar al archivo "status.txt"
        freopen("status.txt", "w", stdout);
        printf("La funcion ha sido declarada en el programa: \n\n");
		// Imprimir información de las funciones declaradas
        for (int i = 0; i < nrFunc; i++) {
                printf("Funcion %d\n", i);
                printf("Nombre: %s\n", funcTable[i].name);
                printf("Tipo de retorno: %s\n", funcTable[i].typeReturn);
                printf("Funcion reservada: %d\n", funcTable[i].reserved);
                for (int j = 0; j < funcTable[i].numberParam; j++) {
                        printf("Tipo de parametro %d: %s\n", j, funcTable[i].typeParam[j]);
                }
                printf("\n");
        }

        printf("\n");
		// Imprimir información de las variables declaradas
        printf("situacion de las variables declaradas en el programa:\n");
        for (int i = 0; i < nrVar; i++) {
                struct var v;
                v = varTable[i].currentVar;
                printf("Nombre: %s\n", v.name);
                printf("Tipo: %s\n", v.type);
                print(v.name, varTable, nrVar);
                printf("\n");
        }
}