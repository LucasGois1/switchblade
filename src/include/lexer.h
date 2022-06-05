#ifndef LEXER_H
#define LEXER_H

#include <iostream>
#include "token.h"

using std::string;

typedef struct Lexer {
    char actual_caractere;
    int index;
    string content;
} _lexer;

void analyze(const string& content);

_lexer* build_lexer(const string& content);
_lexer* advance(_lexer* lexer);
_token* build_next_token(_lexer* lexer);
void ignore_spaces(_lexer* lexer);
_token* get_identifier(_lexer* lexer);
char* create_initial_text();
void read_text(_lexer* lexer, char* text);
char* read_char_as_string(_lexer* lexer);
_token* get_string(_lexer* lexer);

#endif