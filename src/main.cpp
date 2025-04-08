#include "Lexer.hpp"
#include "Parser.hpp"
#include "SemanticAnalyzer.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cerr << "Usage: ./calcvar <source_file>\n";
        return 1;
    }

    std::ifstream inputFile(argv[1]);
    if (!inputFile.is_open())
    {
        std::cerr << "Error opening file: " << argv[1] << '\n';
        return 1;
    }

    std::stringstream buffer;
    buffer << inputFile.rdbuf();
    std::string code = buffer.str();

    try
    {
        Lexer lexer(code);
        auto tokens = lexer.tokenizeAll();

        Parser parser(tokens);
        auto program = parser.parse();

        SemanticAnalyzer analyzer;
        analyzer.analyze(program);

        std::cout << "Semantic analysis completed successfully.\n";
    }
    catch (const std::exception &e)
    {
        std::cerr << "Semantic error: " << e.what() << '\n';
        return 1;
    }

    return 0;
}
