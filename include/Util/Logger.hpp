#ifndef UTIL_LOGGER_HPP_
#define UTIL_LOGGER_HPP_

#include <iostream>
#include <string>
#include <vector>
#include "Util/Fs.hpp"

namespace Gaussian {

    namespace Util {

        namespace Logger {

            static std::string log_file_path = "stdout"; // Default log file path

            /**
             * @brief Logs a message to the console.
             * @param message The message to log.
             * @param level The log level (0 = info, 1 = warning, 2 = error, 3 = debug).
             */
            void log(const std::string& message, int level = 0);

            /**
             * @brief Sets the log file path.
             * @param path The path to the log file.
             */
            void set_log_file(const std::string& path);

            static std::vector<std::string> log_levels = {
                "[info]", "[warning]", "[error]", "[debug]"
            };

        } // namespace Logger

    } // namespace Util

} // namespace Gaussian

#endif // UTIL_LOGGER_HPP_