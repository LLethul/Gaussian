#ifndef UTIL_FS_HPP_
#define UTIL_FS_HPP_

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <filesystem>

namespace Gaussian {

    namespace Util {

        /**
         * @brief Checks if a file exists at the given path.
         * @param path The path to the file.
         * @return True if the file exists, false otherwise.
         */
        bool file_exists(const std::string& path);

        /**
         * @brief Reads the contents of a file into a string.
         * @param path The path to the file.
         * @return The contents of the file as a string.
         */
        std::string read_file(const std::string& path);

        /**
         * @brief Writes a string to a file at the given path.
         * @param path The path to the file.
         * @param content The content to write to the file.
         */
        void write_file(const std::string& path, const std::string& content);

        /**
         * @brief Appends a string to a file at the given path.
         * @param path The path to the file.
         * @param content The content to append to the file.
         * @note If the file does not exist, it will be created.
         */
        void append_file(const std::string& path, const std::string& content);

    } // namespace Util

} // namespace Gaussian

#endif // UTIL_FS_HPP_