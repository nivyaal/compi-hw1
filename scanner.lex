%{
#include <stdio.h>
#include tokens.hpp
//declaring our functions


%}

%option yylineno
//should add the other flex vars??
%option noyywrap
digit           ([0-9])
letter          ([a-zA-z])
whitespace      (([\t\n ]))

%%
{digit}+        return NUM
{whitespace}    ;
.

%%

//not sure needed
//here we put functions in C with them we can determine the output of the lexical analyzer