#include "tokens.hpp"
#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;


void showToken(const string val){
	cout<<yylineno<<" "<<val<<" " << yytext<< endl;
}

void showStringToken(const string str)
{
	cout<<yylineno<<" STRING "<< str <<endl;
}

void showCommentToken()
{
	cout<<yylineno<<" COMMENT //"<<endl;
}

string hexToString(string hexString)
{
	int ascii;
	string NumString= hexString.substr(2,hexString.size()-2);
	stringstream convertStream;
	convertStream << hex <<NumString;
	convertStream >> ascii;
	string s(1,ascii);
	return s;
}

string extractIllegalHex()
{
	string str = yytext;
	if(str[str.size()-1]=='\"'){
		return str.substr(1,2);
	}
	else{
		return str.substr(1,3);
	}
}

int main()
{
	int token;
	string strBuilder = "";
	while(token = yylex()) {
		switch (token)
		{
			case VOID:
				showToken("VOID");
				break;
			case INT:
				showToken("INT");
				break;
			case BYTE:
				showToken("BYTE");
				break;
			case B:
				showToken("B");
				break;		
			case BOOL:
				showToken("BOOL");
				break;	
			case AND:
				showToken("AND");
				break;	
			case OR:
				showToken("OR");
				break;	
			case NOT:
				showToken("NOT");
				break;	
			case TRUE:
				showToken("TRUE");
				break;	
			case FALSE:
				showToken("FALSE");
				break;	
			case RETURN:
				showToken("RETURN");
				break;	
			case IF:
				showToken("IF");
				break;	
			case ELSE:
				showToken("ELSE");	
				break;	
			case WHILE:
				showToken("WHILE");
				break;	
			case BREAK:
				showToken("BREAK");
				break;	
			case CONTINUE:
				showToken("CONTINUE");
				break;	
			case SC:
				showToken("SC");
				break;	
			case COMMA:
				showToken("COMMA");
				break;
			case LPAREN:
				showToken("LPAREN");
				break;
			case RPAREN:
				showToken("RPAREN");
				break;			
			case LBRACE:
				showToken("LBRACE");
				break;
			case RBRACE:
				showToken("RBRACE");
				break;
			case ASSIGN:
				showToken("ASSIGN");
				break;	
			case RELOP:
				showToken("RELOP");
				break;
			case BINOP:
				showToken("BINOP");
				break;
			case COMMENT:
				showCommentToken();
				break;							
			case ID:
				showToken("ID");
				break;	
			case NUM:
				showToken("NUM");
				break;
			case STRING_START: // not sure if needed
				strBuilder = "";
				break;
			case STRING_END:
				showStringToken(strBuilder);
				break;
			case STRING_NORMAL:
				strBuilder.append(yytext);
				break;
			case STRING_BACK_SLASH:
				strBuilder.append(1,'\\');
				break;
			case STRING_TAB:
				strBuilder.append(1,'\t');
				break;
			case STRING_LF:
				strBuilder.append(1,'\n');
				break;
			case STRING_COMMAS:
				strBuilder.append(1,'\"');
				break;
			case STRING_CR:
				strBuilder.append(1,'\r');
				break;
			case STRING_NULL:
			    strBuilder.append(1,'\0');
				break;
			case STRING_HEX:
				strBuilder.append(hexToString(yytext));
				break;
			case ERROR://maybe we should trim it
				cout<<"Error "<<yytext <<endl; exit(-1);
				break; 
			case ERROR_STRING_CUT:	
				cout<<"Error unclosed string"<<endl; exit(-2);
				break;
			case ERROR_STRING_HEX: //not managed yet
				cout<<"Error undefined escape sequence " << extractIllegalHex()  <<endl; exit(-3);

			case ERROR_STRING_ESC:
				cout<<"Error undefined escape sequence " <<yytext[1] <<endl; exit(-3);
	
		}
	}
	return 0;
}


