#ifndef LEXER_TOKEN_HPP_
#define LEXER_TOKEN_HPP_

#include <string>
#include <sstream>
#include <map>
#include <vector>
#include "Chunk.hpp"

namespace Gaussian {

    namespace Lexer {
        
        enum class TokenType {
            string_lit, number_lit, identifier,
            op, keyword,
            comment, 
            
            l_paren, r_paren,
            l_brace, r_brace,
            l_bracket, r_bracket,
            comma, semicolon,
            dot, colon, at,

            end_of_file,
            unknown,
        };

        /**
         * @brief Represents a token in the source code.
         */
        struct Token {
            /**
             * @brief The type of the token.
             */
            TokenType type;

            /**
             * @brief The value of the token.
             */
            std::string value;

            /**
             * @brief The chunk of the token in the source code.
             */
            Chunk chunk;

            /**
             * @brief Constructs a Token object.
             * @param type The type of the token.
             * @param value The value of the token.
             * @param chunk The chunk of the token in the source code.
             */
            Token(TokenType type, const std::string& value, const Chunk& chunk)
                : type(type), value(value), chunk(chunk) {}

            /**
             * @brief Converts the token to a string representation.
             * @return A string representation of the token.
             */
            std::string to_string() const;
        };

        /**
         * @brief Maps keywords to their corresponding token types.
         */
        static std::map<std::string, TokenType> keyword_map = {
            {"if", TokenType::keyword},
            {"else", TokenType::keyword},
            {"while", TokenType::keyword},
            {"for", TokenType::keyword},
            {"return", TokenType::keyword},
        };

        /**
         * @brief A list of supported operators.
         */
        static std::vector<std::string> operators = {
            "+", "-", "*", "/", "=", "==", "!=", "<", ">", "<=", ">="
        };

        static std::map<std::string, TokenType> delimiters = {
            {"(", TokenType::l_paren},
            {")", TokenType::r_paren},
            {"{", TokenType::l_brace},
            {"}", TokenType::r_brace},
            {"[", TokenType::l_bracket},
            {"]", TokenType::r_bracket},
            {",", TokenType::comma},
            {";", TokenType::semicolon},
            {".", TokenType::dot},
            {":", TokenType::colon},
            {"@", TokenType::at}
        };

    }

}

#endif // LEXER_TOKEN_HPP_