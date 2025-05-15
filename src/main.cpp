#include "Util/Logger.hpp"
#include "Lexer/Lexer.hpp"
#include "CLI11.hpp"

using namespace Gaussian;
using namespace Gaussian::Lexer;
using namespace Gaussian::Util;

int main(int argc, char* argv[]) {
    CLI::App app{"Gaussian Compiler"};
    argv = app.ensure_utf8(argv);

    std::string input_file;
    std::string log_file = "stdout";
    app.add_option("-i,--input", input_file, "Input file to compile")->required();
    app.add_option("-l,--log", log_file, "Log file path")->default_val("stdout");
    CLI11_PARSE(app, argc, argv);

    Logger::set_log_file(log_file);

    Gaussian::Lexer::Lexer lexer(read_file(input_file));
    std::vector<Token> tokens = lexer.tokenize();

    for (const auto& token : tokens) {
        Logger::log(token.to_string(), 0);
    }
    Logger::log("Tokenization complete.", 0);

    return 0;
}