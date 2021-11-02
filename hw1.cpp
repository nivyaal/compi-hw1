#include "tokens.hpp"
#include <stdio.h>
#include <string.h>



void showToken(const char* val){
	printf("<%d> <%s> <%s>",yylineno, val, yytext);
}



int main()
{
	int token;
	while(token = yylex()) {
		if(token == NUM){
			showToken("NUM");
		}
	}
	return 0;
}