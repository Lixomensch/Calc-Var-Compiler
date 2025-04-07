#pragma once
#include <string>
#include <memory>
#include <vector>

struct ASTNode
{
    virtual ~ASTNode() = default;
};

struct Expression : ASTNode
{
};

struct Number : Expression
{
    int value;
    Number(int value) : value(value) {}
};

struct Variable : Expression
{
    std::string name;
    Variable(const std::string &name) : name(name) {}
};

struct BinaryExpr : Expression
{
    std::string op;
    std::unique_ptr<Expression> left;
    std::unique_ptr<Expression> right;

    BinaryExpr(const std::string &op, std::unique_ptr<Expression> left, std::unique_ptr<Expression> right)
        : op(op), left(std::move(left)), right(std::move(right)) {}
};

struct Statement : ASTNode
{
};

struct VarDeclaration : Statement
{
    std::string name;
    VarDeclaration(const std::string &name) : name(name) {}
};

struct Assignment : Statement
{
    std::string name;
    std::unique_ptr<Expression> expr;

    Assignment(const std::string &name, std::unique_ptr<Expression> expr)
        : name(name), expr(std::move(expr)) {}
};

struct Program : ASTNode
{
    std::vector<std::unique_ptr<Statement>> statements;
};
