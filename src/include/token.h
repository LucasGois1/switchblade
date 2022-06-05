#ifndef TOKEN_H
#define TOKEN_H

#include <iostream>
using std::string;

enum TOKEN {
    TOKEN_IDENTIFIER,
    TOKEN_STRING,
    TOKEN_ASSIGNMENT,
    TOKEN_SEMICOLON,
    TOKEN_COMMA,
    TOKEN_L_PARENTHESE,
    TOKEN_R_PARENTHESE,
    TOKEN_L_BRACE,
    TOKEN_R_BRACE,
    TOKEN_NEW_LINE,
    TOKEN_UNKNOWN,
    TOKEN_EOF
};

typedef struct Token {
    string value;
    TOKEN type;
} _token;

_token* new_token(int type, const string& value);

#endif
