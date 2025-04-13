#include "../include/Lexer.hpp"
#include <cctype>

Token Lexer::nextToken()
{
    while (pos < input.size() && std::isspace(input[pos]))
        pos++;

    if (pos >= input.size())
        return Token(TokenType::END, "");

    char current = input[pos];

    if (std::isalpha(current))
    {
        std::string ident;
        while (pos < input.size() && std::isalnum(input[pos]))
        {
            ident += input[pos++];
        }
        if (ident == "int")
            return Token(TokenType::INT, ident);
        return Token(TokenType::IDENTIFIER, ident);
    }

    if (std::isdigit(current))
    {
        std::string number;
        while (pos < input.size() && std::isdigit(input[pos]))
        {
            number += input[pos++];
        }
        return Token(TokenType::NUMBER, number);
    }

    pos++;
    switch (current)
    {
    case '=':
        return Token(TokenType::ASSIGN, "=");
    case '+':
        return Token(TokenType::PLUS, "+");
    case '-':
        return Token(TokenType::MINUS, "-");
    case ';':
        return Token(TokenType::SEMICOLON, ";");
    default:
        return Token(TokenType::END, "");
    }
}

std::vector<Token> Lexer::tokenizeAll()
{
    std::vector<Token> tokens;
    Token token = nextToken();
    while (token.type != TokenType::END)
    {
        tokens.push_back(token);
        token = nextToken();
    }
    tokens.push_back(Token(TokenType::END, ""));
    return tokens;
}
