#include <iostream>
#include <cstdlib>
#include <cstring>

#include "include/token.h"
#include "include/lexer.h"

_token *get_corresponding_symbol(const _lexer *lexer);

using std::string;
using std::cout;
using std::endl;

void analyze(const string& content) {
    cout << "Analyzing: " << content << endl;

    _lexer* lexer = build_lexer(content);

    cout << "Value of character " << lexer->actual_caractere << endl;
    cout << "Index: " << lexer->index << endl;
    cout << "Content: " << lexer->content << endl;
    cout << "lexer address: " << &lexer << endl;
    cout << "lexer pointer " << lexer << endl;

    while (lexer->actual_caractere != '\0' && lexer->index < lexer->content.size()) {
        _token* token = build_next_token(lexer);

        cout << "Token: " << token->value << endl;
        cout << "Token type: " << token->type << endl;
    }
}


_lexer* build_lexer(const string& content) {
    auto* lexer = (_lexer*) calloc(1, sizeof(struct Lexer));

    lexer->index = 0;
    lexer->content = content;
    lexer->actual_caractere = lexer->content[lexer->index];

    return lexer;
}

_lexer* advance(_lexer* lexer) {

    if(lexer->actual_caractere != '\0' && lexer->index < lexer->content.size()) {
        lexer->index++;
        lexer->actual_caractere = lexer->content[lexer->index];
    }

    return lexer;
}

_token* build_next_token(_lexer* lexer) {
    if (lexer->actual_caractere == ' ') {
        ignore_spaces(lexer);
    }

    if (isalnum(lexer->actual_caractere)) {
        return get_identifier(lexer);
    }

    if (lexer->actual_caractere == '"') {
        return get_string(lexer);
    }

    _token* t = get_corresponding_symbol(lexer);

    advance(lexer);

    return t;
}

_token *get_corresponding_symbol(const _lexer *lexer) {
    switch (lexer->actual_caractere) {
        case '=':
            return new_token(TOKEN_ASSIGNMENT, "=");

        case ';':
            return new_token(TOKEN_SEMICOLON, ";");

        case ',':
            return new_token(TOKEN_COMMA, ",");

        case '(':
            return new_token(TOKEN_L_PARENTHESE, "(");

        case ')':
            return new_token(TOKEN_R_PARENTHESE, ")");

        case '{':
            return new_token(TOKEN_L_BRACE, "{");

        case '}':
            return new_token(TOKEN_R_BRACE, "}");

        case '\0':
            return new_token(TOKEN_EOF, "EOF");

        case '\n':
            return new_token(TOKEN_NEW_LINE, "\n");

        default:
            return new_token(TOKEN_UNKNOWN, "UNKNOWN");
    }
}

void ignore_spaces(_lexer* lexer) {
    while(lexer->actual_caractere == ' ' || lexer->actual_caractere == 10 ) {
        advance(lexer);
    }
}

_token* get_identifier(_lexer* lexer) {
    char* identifier = create_initial_text();

    while(isalnum(lexer->actual_caractere)) {
        read_text(lexer, identifier);
    }

    return new_token(TOKEN_IDENTIFIER, identifier);
}

char* create_initial_text() {
    char* initial_text = (char*) calloc(1, sizeof(char));

    initial_text[0] = '\0';

    return initial_text;
}

void read_text(_lexer* lexer, char* text) {
    char* next_character = read_char_as_string(lexer);
    text = (char*) realloc(text, sizeof(text) + (strlen(next_character) + 1));

    strcat(text, next_character);

    advance(lexer);
}


char* read_char_as_string(_lexer* lexer) {
    char * str_value = (char*) calloc(2, sizeof(char));

    str_value[0] = lexer->actual_caractere;
    str_value[1] = '\0';

    return str_value;
}

_token* get_string(_lexer* lexer) {
    char* string_value = create_initial_text();

    advance(lexer);

    while(lexer->actual_caractere != '"') {
        read_text(lexer, string_value);
    }

    advance(lexer);

    return new_token(TOKEN_STRING, string_value);
}