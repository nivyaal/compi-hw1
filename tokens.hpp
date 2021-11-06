#ifndef TOKENS_HPP_
#define TOKENS_HPP_
#include <cstdlib>
  enum tokentype
  {
    VOID = 1,
    INT = 2,
    BYTE = 3,
    B = 4,
    BOOL = 5,
    AND = 6,
    OR = 7,
    NOT = 8,
    TRUE = 9,
    FALSE = 10,
    RETURN = 11,
    IF = 12,
    ELSE = 13,
    WHILE = 14,
    BREAK = 15,
    CONTINUE = 16, 
    SC = 17,
    COMMA = 18,
    LPAREN = 19,
    RPAREN = 20,
    LBRACE = 21,
    RBRACE = 22,
    ASSIGN = 23,
    RELOP = 24,
    BINOP = 25,
    COMMENT = 26,
    ID = 27,
    NUM = 28,
    STRING = 29,
    STRING_START=30, //not sure if needed
    STRING_END =31,
    STRING_NORMAL =32,
    STRING_TAB = 33,
    STRING_LF = 34,
    STRING_BACK_SLASH =35,
    STRING_COMMAS = 36,
    STRING_CR = 37,
    STRING_HEX=38,
    STRING_NULL = 39,
    ERROR=40,
    ERROR_STRING_CUT=41,
    ERROR_STRING_ESC=42,
    ERROR_STRING_HEX=43
  };
  extern int yylineno;
  extern char* yytext;
  extern int yyleng;
  extern int yylex();
#endif /* TOKENS_HPP_ */
