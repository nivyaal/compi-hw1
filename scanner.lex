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

%x              MAHROZET


%%
"void"          return VOID;
"int"           return INT;
"byte"          return BYTE;
"b"             return B;
"bool"          return BOOL;
"and"            return AND;
"or"            return OR;
"not"             return NOT;
"true"          return TRUE;
"false"         return FALSE;
"return"        return RETURN;
"if"            return IF;
"else"          return ELSE;
"while"         return WHILE;
"break"         return BREAK;
"continue"      return CONTINUE;
";"             return SC;
","             return COMMA;
"("             return LPAREN;
")"             return RPAREN;
"{"             return LBRACE;
"}"             return RBRACE;
"="             return ASSIGN;
"<="|">="|"++"|"!="|"=="|"<"|">"        return RELOP;
"+"|"-"|"*"|"/"                         return BINOP;
(0|[1-9][0-9]*)                       return NUM;
(\/\/)[^\][\r\n]*                       return COMMENT;
[a-zA-Z][a-zA-Z0-9]*                    return ID;
["]             {BEGIN(MAHROZET); return STRING_START;}
<MAHROZET>([\x00-\x09\x0b-\x0c\x0e-\x21\x23-\x5b\x5d-\x7f])*   return STRING_NORMAL;
<MAHROZET>((\\)(\"))   return STRING_COMMAS;
<MAHROZET>((\\)(0))    return STRING_NULL;
<MAHROZET>((\\)(n))    return STRING_LF;
<MAHROZET>((\\)(t))    return STRING_TAB;
<MAHROZET>((\\)(r))    return STRING_CR;
<MAHROZET>(\\)(\\)    return STRING_BACK_SLASH;  
<MAHROZET>(\\x)([0-9]|[A-F])([0-9]|[A-F])    return STRING_HEX;
<MAHROZET>(\")      {BEGIN(INITIAL); return STRING_END;}
<MAHROZET>[(\n)|((\)(\"))]  return ERROR_STRING_CUT;
<MAHROZET><<EOF>>  return ERROR_STRING_CUT;
<MAHROZET>(\\x).(\") return ERROR_STRING_HEX;
<MAHROZET>(\\x)..    return ERROR_STRING_HEX;
<MAHROZET>(\\)([\x00-\x7f])  return ERROR_STRING_ESC;


{whitespace}    ;
.   return ERROR;
%%

