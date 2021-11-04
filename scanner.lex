%{
/*Declartion section*/
#include <stdio.h>
#include "tokens.hpp"
//declaring our functions
%}

%option yylineno
%option noyywrap
digit           ([0-9])
letter          ([a-zA-z])
whitespace      ([\t\n\r ])

%x STRING


%%
"void"  return VOID;
"int"   return INT;
"byte"  return BYTE;
"b" return B;
"bool"  return BOOL;
"&&"    return AND;
"||"    return OR;
"!" return NOT;
"true"  return TRUE;
"false" return FALSE;
"return"    return RETURN;
"if"    return IF;
"else"  return ELSE;
"while" return WHILE;
"break" return BREAK;
"continue"  return CONTINUE;
";" return SC;
"," return COMMA;
"(" return LPAREN;
")" return RPAREN;
"{" return LBRACE;
"}" return RBRACE;
"=" return ASSIGN;
"<="|">="|"++"|"!="|"=="|"<"|">" return RELOP;
"+"|"-"|"*"|"/" return BINOP;
^(0|[1-9][0-9]*)$ return NUM;
(\/\/)[^\][\r\n]* return COMMENT;
[a-zA-Z][a-zA-Z0-9]* return ID;
["] BEGIN(STRING)

{whitespace}    ;
.   printf("Other\n");
%%



