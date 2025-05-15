#ifndef CHUNK_HPP_
#define CHUNK_HPP_

#include "Position.hpp"
#include <string>

namespace Gaussian {

    struct Chunk {
        Position start;
        Position end;

        /**
         * @brief Constructs a Chunk object with the given start and end positions.
         * @param start The starting position of the chunk.
         * @param end The ending position of the chunk.
         */
        Chunk(const Position& start, const Position& end)
            : start(start), end(end) {};

        bool operator==(const Chunk& other) const {
            return start == other.start && end == other.end;
        };

        bool operator!=(const Chunk& other) const {
            return !(*this == other);
        };

        bool operator<(const Chunk& other) const {
            return (start < other.start) || (start == other.start && end < other.end);
        };

        bool operator>(const Chunk& other) const {
            return (start > other.start) || (start == other.start && end > other.end);
        };

        /**
         * @brief Returns the string representation of the chunk.
         * @return A string representation of the chunk in the format "start:end".
         */
        std::string to_string() const;
    };

};

#endif // CHUNK_HPP_