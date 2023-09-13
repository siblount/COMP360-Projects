#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

#include "lexical_analyzer.hpp"

int main() {
    // Ask the user to enter a string (one-line only).
    std::string input;
    std::cout << "Enter a string to parse: ";
    std::getline(std::cin, input);
    LexicalAnalyzer analyzer;
    auto lexemes = analyzer.Analyze(input);
    for (auto lexeme : lexemes) {
        std::cout << lexeme.value << " : " << lexeme.GetCategoryString() << std::endl;
    }
    return 0;
}

