#ifndef LEXER_LEXER_HPP_
#define LEXER_LEXER_HPP_

#include "Token.hpp"

namespace Gaussian {

    namespace Lexer {

        class Lexer {
        public:
            /**
             * @brief Constructs a Lexer object with the given source code.
             * @param source The source code to tokenize.
             */
            Lexer(const std::string& source) : source_(source), current_position_(0, 0), current_index_(0) {};

            /**
             * @brief Tokenizes the source code into a vector of tokens.
             * @return A vector of tokens.
             */
            std::vector<Token> tokenize();

        private:
            std::string source_;
            Position current_position_;
            size_t current_index_;
            size_t last_index_;

            /**
             * @brief Retrieves the next token from the source code.
             * @return The next token.
             */
            Token next_token();

            /**
             * @brief Skips whitespace and comments in the source code.
             */
            void skip_whitespace();

            /**
             * @brief Peeks at the current character without advancing the position.
             * @return The current character.
             */
            char peek() const;

            /**
             * @brief Advances the current position and retrieves the next character.
             * @return The next character.
             */
            char advance();

            /**
             * @brief Checks if the lexer has reached the end of the source code.
             * @return True if at the end, false otherwise.
             */
            bool is_at_end() const;

            /**
             * @brief Creates a token with the specified type and value.
             * @param type The type of the token.
             * @param value The value of the token.
             * @param start The starting position of the token.
             * @return The created token.
             */
            Token create_token(TokenType type, const std::string& value, const Position& start);

            /**
             * @brief Parses an identifier token from the source code.
             * @return The identifier token.
             */
            Token identifier();

            /**
             * @brief Parses a number token from the source code.
             * @return The number token.
             */
            Token number();

            /**
             * @brief Parses a string literal token from the source code.
             * @return The string literal token.
             */
            Token string_literal();
        };

    } // namespace Lexer

} // namespace Gaussian

#endif // LEXER_LEXER_HPP_