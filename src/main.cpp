#include <iostream>
#include "include/lexer.h"

using std::string;

int main(int argc, char * argv[]) {

    string sentence = "String greetings = \"Hello World\";\n print(variable);\0";

    analyze(sentence);

    return 0;
}