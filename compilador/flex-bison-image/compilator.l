%{
#include <stdio.h>
#include "y.tab.h"
%}
type "int"|"float"|"char"|"string"|"double"
nr [1-9][0-9]*
palabra [_a-zA-Z][_a-zA-Z0-9]*
caracter \'[a-zA-Z]\'
caracteres \"[a-zA-Z][a-zA-Z]*\"
include1 \<{palabra}.h\>
include2 \<{palabra}\>

%%
struct {return STRUCT;}

"const" {return CONST;}

"Escribir" {return PRINT;}

"EscribirF" {return PRINTF;}

"retornar" { return RETURN; }

"#importar"[ ]*({include1}|{include1}) { return LIBRARY; }

("void"|"int")[ ]+main\(\) { return MAIN; }

"cpy" {return STRCPY;}

"cmp" {return STRCMP;}

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

"si" { return IF; }

"sino" {return ELSE;}

"mientras" { return WHILE; }

"para" { return FOR; }

("int"|"float"|"char"|"string") { strcpy(yylval.strval, yytext); return TYPE;}

{palabra}(\[{nr}\])+ { strcpy(yylval.strval, yytext);  return VECTOR; }

{caracter}|{caracteres} { strcpy(yylval.strval, yytext);  return CARACTER; }

0|[1-9][0-9]* { strcpy(yylval.strval, yytext); return NUMBER; }

{palabra} { strcpy(yylval.strval, yytext); return NAME; }

"=" { return ATTRIBUTE; }

[ \t] ;

\n {yylineno++;}

. {return yytext[0];}
