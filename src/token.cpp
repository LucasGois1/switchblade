#include <iostream>
#include "include/token.h"

using std::string;

_token* new_token(int type, const string& value){
    auto* token = (_token*) calloc(1, sizeof(struct Token));

    token->type = static_cast<TOKEN>(type);
    token->value = value;

    return token;
}