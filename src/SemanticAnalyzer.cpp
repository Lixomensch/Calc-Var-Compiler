#include "../include/SemanticAnalyzer.hpp"
#include <stdexcept>
#include <iostream>

void SemanticAnalyzer::analyze(const std::unique_ptr<Program> &program)
{
    symbolTable.clear();

    for (const auto &stmt : program->statements)
    {
        analyzeStatement(stmt);
    }
}

void SemanticAnalyzer::analyzeStatement(const std::unique_ptr<Statement> &stmt)
{
    if (auto varDecl = dynamic_cast<VarDeclaration *>(stmt.get()))
    {
        if (symbolTable.count(varDecl->name))
        {
            throw std::runtime_error("Variable '" + varDecl->name + "' redeclared.");
        }
        symbolTable.insert(varDecl->name);
    }
    else if (auto assign = dynamic_cast<Assignment *>(stmt.get()))
    {
        if (!symbolTable.count(assign->name))
        {
            throw std::runtime_error("Variable '" + assign->name + "' not declared before use.");
        }
        analyzeExpression(assign->expr);
    }
}

void SemanticAnalyzer::analyzeExpression(const std::unique_ptr<Expression> &expr)
{
    if (auto var = dynamic_cast<Variable *>(expr.get()))
    {
        if (!symbolTable.count(var->name))
        {
            throw std::runtime_error("Variable '" + var->name + "' used before declaration.");
        }
    }
    else if (auto binary = dynamic_cast<BinaryExpr *>(expr.get()))
    {
        analyzeExpression(binary->left);
        analyzeExpression(binary->right);
    }
    else if (dynamic_cast<Number *>(expr.get()))
    {
        // Numbers are always valid
    }
    else
    {
        throw std::runtime_error("Unknown expression type.");
    }
}
