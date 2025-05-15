#ifndef POSITION_HPP_
#define POSITION_HPP_

#include <cstddef>
#include <string>

namespace Gaussian {

    struct Position {
        size_t line;
        size_t column;

        /**
         * @brief Constructs a Position object with the given line and column.
         * @param line The line number.
         * @param column The column number.
         */
        Position(size_t line = 0, size_t column = 0)
            : line(line), column(column) {}

        bool operator==(const Position& other) const {
            return line == other.line && column == other.column;
        };

        bool operator!=(const Position& other) const {
            return !(*this == other);
        };

        bool operator<(const Position& other) const {
            return (line < other.line) || (line == other.line && column < other.column);
        };
        
        bool operator>(const Position& other) const {
            return (line > other.line) || (line == other.line && column > other.column);
        };

        /**
         * @brief Advances the position based on the given character.
         * @param c The character to advance the position with.
         */
        void advance(char c) {
            if (c == '\n') {
                line++;
                column = 0;
            } else {
                column++;
            }
        };

        /**
         * @brief Converts the Position to a string representation.
         * @return A string in the format "line:column".
         */
        std::string to_string() const;
    };

} // namespace Gaussian

#endif // POSITION_HPP_