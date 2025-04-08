#pragma once
#include "ASTNode.hpp"
#include <unordered_set>
#include <memory>

class SemanticAnalyzer
{
    std::unordered_set<std::string> symbolTable;

public:
    void analyze(const std::unique_ptr<Program> &program);

private:
    void analyzeStatement(const std::unique_ptr<Statement> &stmt);
    void analyzeExpression(const std::unique_ptr<Expression> &expr);
};
