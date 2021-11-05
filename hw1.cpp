#include "tokens.hpp"
#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

enum tokentype2{
	STRING_START=30, //not sure if needed
	STRING_END =31,
	STRING_NORMAL =32,
	STRING_TAB = 33,
	STRING_LF = 34,
	STRING_BACK_SLASH =35,
	STRING_COMMAS = 36,
	STRING_HEX=37 //not managed yet in lex file

};//not sure if \0 is included

void showToken(const string val){
	cout<<yylineno<<" "<<val<<" " << yytext<< endl;
}

void showStringToken(const string str)
{
	cout<<yylineno<<" STRING "<< str;
}

string hexToString (string hexString)
{
	char ascii;
	hexString= hexString.substr(1,hexString.size()-1);
	stringstream convertStream;
	convertStream << hex <<hexString;
	convertStream >> ascii;
	string s(1,ascii);
	return s;
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
				showToken("COMMENT");
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
				strBuilder.append("\\");
				break;
			case STRING_TAB:
				strBuilder.append("\r");
				break;
			case STRING_LF:
				strBuilder.append("\n");
				break;
			case STRING_COMMAS:
				strBuilder.append("\"");
				break;
			case STRING_HEX:
				strBuilder.append(hexToString(yytext));
				break;

	
		}
	}
	return 0;
}


// inline const std::string ToString(tokentype token)
// {
// 	switch(token)
// 	{
// 		case VOID: return "VOID";
// 		case INT: return "INT";
// 		case BYTE: return "BYTE";
// 		case B: return "B";
// 		case BOOL: return "BOOL";
// 		case AND: return "AND";
// 		case OR: return "OR";
// 		case NOT: return "NOT";
// 		case TRUE: return "TRUE";
// 		case FALSE: return "FALSE";
// 		case RETURN: return "RETURN";
// 		case IF: return "IF";
// 		case ELSE: return "ELSE";
// 		case WHILE: return "WHILE";
// 		case BREAK: return "BREAK";
// 		case CONTINUE: return "CONTINUE";
// 		case SC: return "SC";
// 		case COMMA: return "COMMA";
// 		case LPAREN: return "LPAREN";
// 		case RPAREN: return "RPAREN";
// 		case LBRACE: return "LBRACE";
// 		case RBRACE: return "RBRACE";
// 		case ASSIGN: return "ASSIGN";
// 		case RELOP: return "RELOP";
// 		case BINOP: return "BINOP";
// 		case COMMENT: return "COMMENT";
// 		case ID: return "ID";
// 		case NUM: return "NUM";
// 		case STRING: return "STRING";
// 	}
// }
