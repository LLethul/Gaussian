#ifndef ERROR_ERROR_HPP_
#define ERROR_ERROR_HPP_

#include "Chunk.hpp"
#include <string>

namespace Gaussian
{
    namespace Error {

        /**
         * @brief Represents an error in Gaussian.
         */
        struct Error {
            /**
             * @brief The error message.
             */
            std::string what;

            /**
             * @brief The chunk of the source code where the error occurred.
             */
            Chunk chunk;

            /**
             * @brief Constructs an Error object with the given message and position.
             * @param message The error message.
             * @param position The position of the error in the source code.
             */
            Error(const std::string& what, const Chunk& chunk)
                : what(what), chunk(chunk) {}

            /**
             * @brief Converts the error to a string representation.
             * @return A string representation of the error.
             */
            std::string to_string() const;
        };

    }
} // namespace Gaussian


#endif // ERROR_ERROR_HPP_