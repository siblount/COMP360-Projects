#pragma once
#include <vector>

#include "analyzer.hpp"
#include "lexeme.hpp"


class LexicalAnalyzer : public Analyzer {
public:
    LexicalAnalyzer();
    std::vector<Lexeme> Analyze(std::string input) override;
private:
    Lexeme ParseLexeme(std::string lexeme);
    inline void FinalizeLexeme(std::vector<Lexeme>& lexemes, std::string& s);
};