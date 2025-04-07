#pragma once
#include <string>

enum class TokenType
{
    INT,
    IDENTIFIER,
    ASSIGN,
    PLUS,
    MINUS,
    NUMBER,
    SEMICOLON,
    END
};

struct Token
{
    TokenType type;
    std::string value;

    Token(TokenType type, const std::string &value) : type(type), value(value) {}
};
