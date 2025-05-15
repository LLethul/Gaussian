#include "Util/Logger.hpp"
#include "Lexer/Lexer.hpp"

using namespace Gaussian;
using namespace Gaussian::Lexer;
using namespace Gaussian::Util;

int main(int argc, char* argv[]) {
    Logger::set_log_file("log.txt");

    Gaussian::Lexer::Lexer lexer(read_file(argv[1]));
    std::vector<Token> tokens = lexer.tokenize();

    for (const auto& token : tokens) {
        Logger::log(token.to_string(), 0);
    }
    Logger::log("Tokenization complete.", 0);

    return 0;
}