#pragma once
#include <cassert>
#include <string>
#include <vector>
#include <iostream>

#include "../lexical_analyzer.hpp"
#include "../lexeme.hpp"

namespace LexicalAnalyzerTests {

    void AssertLexemesEqual(std::vector<Lexeme> a, std::vector<Lexeme> b) {
        assert(a.size() == b.size());

        for (int i = 0; i < a.size(); i++) {
            assert(a[i].category == b[i].category);
            assert(a[i].value == b[i].value);
        }
    }
    
    void Test1() {
        std::string input = "void try (float temp){ float data; float number; float sum; sum = temp + data - number; }";
        std::vector<Lexeme> expected = {
            Lexeme{TokenCategory::KEYWORD, "void"},
            Lexeme{TokenCategory::IDENTIFIER, "try"},
            Lexeme{TokenCategory::PUNCTUATION, "("},
            Lexeme{TokenCategory::KEYWORD, "float"},
            Lexeme{TokenCategory::IDENTIFIER, "temp"},
            Lexeme{TokenCategory::PUNCTUATION, ")"},
            Lexeme{TokenCategory::PUNCTUATION, "{"},
            Lexeme{TokenCategory::KEYWORD, "float"},
            Lexeme{TokenCategory::IDENTIFIER, "data"},
            Lexeme{TokenCategory::PUNCTUATION, ";"},
            Lexeme{TokenCategory::KEYWORD, "float"},
            Lexeme{TokenCategory::IDENTIFIER, "number"},
            Lexeme{TokenCategory::PUNCTUATION, ";"},
            Lexeme{TokenCategory::KEYWORD, "float"},
            Lexeme{TokenCategory::IDENTIFIER, "sum"},
            Lexeme{TokenCategory::PUNCTUATION, ";"},
            Lexeme{TokenCategory::IDENTIFIER, "sum"},
            Lexeme{TokenCategory::OPERATOR, "="},
            Lexeme{TokenCategory::IDENTIFIER, "temp"},
            Lexeme{TokenCategory::OPERATOR, "+"},
            Lexeme{TokenCategory::IDENTIFIER, "data"},
            Lexeme{TokenCategory::OPERATOR, "-"},
            Lexeme{TokenCategory::IDENTIFIER, "number"},
            Lexeme{TokenCategory::PUNCTUATION, ";"},
            Lexeme{TokenCategory::PUNCTUATION, "}"},
        };
        LexicalAnalyzer a;
        AssertLexemesEqual(a.Analyze(input), expected);
        std::cout << "Test1 passed!" << std::endl;

    }

    void Test2() {
        std::string input = "void try () { float number; float sum; float temp; sum = temp – number; }";
        std::vector<Lexeme> expected = {
            Lexeme{TokenCategory::KEYWORD, "void"},
            Lexeme{TokenCategory::IDENTIFIER, "try"},
            Lexeme{TokenCategory::PUNCTUATION, "("},
            Lexeme{TokenCategory::PUNCTUATION, ")"},
            Lexeme{TokenCategory::PUNCTUATION, "{"},
            Lexeme{TokenCategory::KEYWORD, "float"},
            Lexeme{TokenCategory::IDENTIFIER, "number"},
            Lexeme{TokenCategory::PUNCTUATION, ";"},
            Lexeme{TokenCategory::KEYWORD, "float"},
            Lexeme{TokenCategory::IDENTIFIER, "sum"},
            Lexeme{TokenCategory::PUNCTUATION, ";"},
            Lexeme{TokenCategory::KEYWORD, "float"},
            Lexeme{TokenCategory::IDENTIFIER, "temp"},
            Lexeme{TokenCategory::PUNCTUATION, ";"},
            Lexeme{TokenCategory::IDENTIFIER, "sum"},
            Lexeme{TokenCategory::OPERATOR, "="},
            Lexeme{TokenCategory::IDENTIFIER, "temp"},
            Lexeme{TokenCategory::OPERATOR, "–"},
            Lexeme{TokenCategory::IDENTIFIER, "number"},
            Lexeme{TokenCategory::PUNCTUATION, ";"},
            Lexeme{TokenCategory::PUNCTUATION, "}"},
        };
        LexicalAnalyzer a;
        try {
            AssertLexemesEqual(a.Analyze(input), expected);
        } catch (std::invalid_argument e) {
            std::cout << "Test2 passed!" << std::endl;
            return;
        }
        std::cout << "Test2 failed, did not catch negative sign." << std::endl;
    }

    void Test3() {
        std::string input = "void try () { float number; float sum; float temp; sum = temp - number; }";
        std::vector<Lexeme> expected = {
            Lexeme{TokenCategory::KEYWORD, "void"},
            Lexeme{TokenCategory::IDENTIFIER, "try"},
            Lexeme{TokenCategory::PUNCTUATION, "("},
            Lexeme{TokenCategory::PUNCTUATION, ")"},
            Lexeme{TokenCategory::PUNCTUATION, "{"},
            Lexeme{TokenCategory::KEYWORD, "float"},
            Lexeme{TokenCategory::IDENTIFIER, "number"},
            Lexeme{TokenCategory::PUNCTUATION, ";"},
            Lexeme{TokenCategory::KEYWORD, "float"},
            Lexeme{TokenCategory::IDENTIFIER, "sum"},
            Lexeme{TokenCategory::PUNCTUATION, ";"},
            Lexeme{TokenCategory::KEYWORD, "float"},
            Lexeme{TokenCategory::IDENTIFIER, "temp"},
            Lexeme{TokenCategory::PUNCTUATION, ";"},
            Lexeme{TokenCategory::IDENTIFIER, "sum"},
            Lexeme{TokenCategory::OPERATOR, "="},
            Lexeme{TokenCategory::IDENTIFIER, "temp"},
            Lexeme{TokenCategory::OPERATOR, "-"},
            Lexeme{TokenCategory::IDENTIFIER, "number"},
            Lexeme{TokenCategory::PUNCTUATION, ";"},
            Lexeme{TokenCategory::PUNCTUATION, "}"},
        };
        LexicalAnalyzer a;
        try {
            AssertLexemesEqual(a.Analyze(input), expected);
        } catch (std::invalid_argument e) {
            std::cout << "Test3 failed!" << std::endl;
            std::cout << e.what() << std::endl;
            return;
        }
        std::cout << "Test3 passed!" << std::endl;
    }

    void ExecuteTests() {
        Test1();
        Test2();
        Test3();
    }
}