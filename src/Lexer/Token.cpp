#include "Lexer/Token.hpp"

std::string Gaussian::Lexer::Token::to_string() const {
    std::stringstream ss;
    ss << "<token value=\'" << value << "\' position=" << chunk.to_string() << ">";
    return ss.str();
}