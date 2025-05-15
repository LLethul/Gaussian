#include "Lexer/Lexer.hpp"
#include <algorithm>

void Gaussian::Lexer::Lexer::skip_whitespace() {
    while (!is_at_end()) {
        if (isspace(peek()) || peek() == '\n' || peek() == ' ') advance();
        else if (peek() == '#') {
            while (!is_at_end() && peek() != '\n') advance();
            if (peek() == '\n') advance(); break;
        }
        else break;
    }
}

char Gaussian::Lexer::Lexer::peek() const {
    if (is_at_end()) return '\0';
    return source_[current_index_];
}

char Gaussian::Lexer::Lexer::advance() {
    char c = peek();
    if (!is_at_end()) {
        current_index_++;
        current_position_.advance(peek());
    }
    return c;
}

bool Gaussian::Lexer::Lexer::is_at_end() const {
    return current_index_ >= source_.length();
}

Gaussian::Lexer::Token Gaussian::Lexer::Lexer::create_token(TokenType type, const std::string& value, const Position& start) {
    return Token(type, value, Chunk(start, current_position_));
}

Gaussian::Lexer::Token Gaussian::Lexer::Lexer::identifier() {
    std::string value;
    const Position start = current_position_;

    while (isalnum(peek()) || peek() == '_') {
        value += advance();
    }
    return create_token(TokenType::identifier, value, start);
}

Gaussian::Lexer::Token Gaussian::Lexer::Lexer::number() {
    std::string value;
    const Position start = current_position_;
    while (isdigit(peek())) {
        value += advance();
    }
    return create_token(TokenType::number_lit, value, start);
}

Gaussian::Lexer::Token Gaussian::Lexer::Lexer::string_literal() {
    std::string value;
    const Position start = current_position_;
    advance(); // Skip the opening quote
    while (!is_at_end() && peek() != '"') {
        value += advance();
    }
    advance(); // Skip the closing quote
    return create_token(TokenType::string_lit, value, start);
}

Gaussian::Lexer::Token Gaussian::Lexer::Lexer::next_token() {
    skip_whitespace();
    if (is_at_end()) return create_token(TokenType::end_of_file, "\0", current_position_);
    if (last_index_ == current_index_) advance();

    char current_char = peek();
    last_index_ = current_index_;
    
    if (isalpha(current_char)) {
        return identifier();
    } else if (isdigit(current_char)) {
        return number();
    } else if (current_char == '"' || current_char == '\'') {
        return string_literal();
    } else if (Gaussian::Lexer::delimiters.find(std::string(1, current_char)) != Gaussian::Lexer::delimiters.end()) {
        return create_token(Gaussian::Lexer::delimiters.at(std::string(1, current_char)), std::string(1, current_char), current_position_);
    } else if (std::find(Gaussian::Lexer::operators.begin(), Gaussian::Lexer::operators.end(), std::string(1, current_char)) != Gaussian::Lexer::operators.end()) {
        return create_token(TokenType::op, std::string(1, current_char), current_position_);
    }

    return create_token(TokenType::unknown, std::string(1, current_char), current_position_);
}

std::vector<Gaussian::Lexer::Token> Gaussian::Lexer::Lexer::tokenize() {
    std::vector<Token> tokens;
    while (!is_at_end()) {
        tokens.push_back(next_token());
    }
    return tokens;
}