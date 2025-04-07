#include "../include/Parser.hpp"
#include <stdexcept>

bool Parser::match(TokenType type)
{
    if (check(type))
    {
        advance();
        return true;
    }
    return false;
}

const Token &Parser::advance()
{
    if (!check(TokenType::END))
        current++;
    return tokens[current - 1];
}

const Token &Parser::peek()
{
    return tokens[current];
}

bool Parser::check(TokenType type)
{
    return peek().type == type;
}

std::unique_ptr<Program> Parser::parse()
{
    auto program = std::make_unique<Program>();
    while (!check(TokenType::END))
    {
        program->statements.push_back(parseStatement());
    }
    return program;
}

std::unique_ptr<Statement> Parser::parseStatement()
{
    if (match(TokenType::INT))
    {
        return parseVarDeclaration();
    }
    else
    {
        return parseAssignment();
    }
}

std::unique_ptr<Statement> Parser::parseVarDeclaration()
{
    if (!check(TokenType::IDENTIFIER))
        throw std::runtime_error("Expected variable name");
    std::string name = advance().value;
    if (!match(TokenType::SEMICOLON))
        throw std::runtime_error("Expected ';'");
    return std::make_unique<VarDeclaration>(name);
}

std::unique_ptr<Statement> Parser::parseAssignment()
{
    if (!check(TokenType::IDENTIFIER))
        throw std::runtime_error("Expected variable name");
    std::string name = advance().value;
    if (!match(TokenType::ASSIGN))
        throw std::runtime_error("Expected '='");
    auto expr = parseExpression();
    if (!match(TokenType::SEMICOLON))
        throw std::runtime_error("Expected ';'");
    return std::make_unique<Assignment>(name, std::move(expr));
}

std::unique_ptr<Expression> Parser::parseExpression()
{
    auto expr = parseTerm();
    while (match(TokenType::PLUS) || match(TokenType::MINUS))
    {
        std::string op = tokens[current - 1].value;
        auto right = parseTerm();
        expr = std::make_unique<BinaryExpr>(op, std::move(expr), std::move(right));
    }
    return expr;
}

std::unique_ptr<Expression> Parser::parseTerm()
{
    return parseFactor(); // No * or / in CalcVar
}

std::unique_ptr<Expression> Parser::parseFactor()
{
    if (match(TokenType::NUMBER))
    {
        return std::make_unique<Number>(std::stoi(tokens[current - 1].value));
    }
    if (match(TokenType::IDENTIFIER))
    {
        return std::make_unique<Variable>(tokens[current - 1].value);
    }
    throw std::runtime_error("Expected number or identifier");
}
