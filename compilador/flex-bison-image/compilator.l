%{
// Archivo: compilator.l
// Descripción: Archivo de definición léxica para el compilador.
// Autor: Soto Angeles Paulette Esmeralda, Niebla Leyva Brayhan Daniel
// Fecha: 12-01-2024
// Nota: Este archivo utiliza la herramienta Flex para análisis léxico.

#include <stdio.h>
#include "y.tab.h"
%}

// Definición de patrones de tokens
type "int"|"float"|"char"|"string"|"double"
nr [1-9][0-9]*
palabra [_a-zA-Z][_a-zA-Z0-9]*
caracter \'[a-zA-Z]\'
caracteres \"[a-zA-Z][a-zA-Z]*\"
include1 \<{palabra}.h\>
include2 \<{palabra}\>

%%
// Reglas para reconocer tokens y generar acciones

// Palabras clave y tokens reservados
struct {return STRUCT;}

"const" {return CONST;}

"Escribir" {return PRINT;}

"EscribirF" {return PRINTF;}

"retornar" { return RETURN; }

"#importar"[ ]*({include1}|{include1}) { return LIBRARY; }

("void"|"int")[ ]+main\(\) { return MAIN; }

"cpy" {return STRCPY;}

"cmp" {return STRCMP;}

// Operadores y símbolos
"*" { return MULTY; }

"/" { return DIV; }

"+" { return PLUS; }

"-" { return MINUS; }

">" { return GT; }

"<" { return LT; }

"!=" { return DIF; }

"==" { return EQUAL; }

"||" { return OR; }

"&&" { return AND; }

// Estructuras
"si" { return IF; }

"sino" {return ELSE;}

"mientras" { return WHILE; }

"para" { return FOR; }

// Tipos de datos y variables
("int"|"float"|"char"|"string") { strcpy(yylval.strval, yytext); return TYPE;}

{palabra}(\[{nr}\])+ { strcpy(yylval.strval, yytext);  return VECTOR; }

{caracter}|{caracteres} { strcpy(yylval.strval, yytext);  return CARACTER; }

0|[1-9][0-9]* { strcpy(yylval.strval, yytext); return NUMBER; }

{palabra} { strcpy(yylval.strval, yytext); return NAME; }

// Asignación
"=" { return ATTRIBUTE; }

// Ignorar espacios y tabuladores
[ \t] ;

// Contar líneas nuevas
\n {yylineno++;}

// Caracteres no reconocidos
. {return yytext[0];}
