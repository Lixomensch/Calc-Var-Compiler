#pragma once
#include "Token.hpp"
#include <string>
#include <vector>

class Lexer
{
    std::string input;
    size_t pos = 0;

public:
    Lexer(const std::string &input) : input(input) {}

    Token nextToken();
    std::vector<Token> tokenizeAll();
};
