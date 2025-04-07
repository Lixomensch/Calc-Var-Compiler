#pragma once
#include "Token.hpp"
#include "ASTNode.hpp"
#include <vector>
#include <memory>

class Parser
{
    std::vector<Token> tokens;
    size_t current = 0;

public:
    Parser(const std::vector<Token> &tokens) : tokens(tokens) {}

    std::unique_ptr<Program> parse();

private:
    bool match(TokenType type);
    const Token &advance();
    const Token &peek();
    bool check(TokenType type);

    std::unique_ptr<Statement> parseStatement();
    std::unique_ptr<Statement> parseVarDeclaration();
    std::unique_ptr<Statement> parseAssignment();
    std::unique_ptr<Expression> parseExpression();
    std::unique_ptr<Expression> parseTerm();
    std::unique_ptr<Expression> parseFactor();
};
