#ifndef UTIL_LOGGER_HPP
#define UTIL_LOGGER_HPP

#include "Util/Logger.hpp"
#include <stacktrace>

void Gaussian::Util::Logger::log(const std::string& message, int level) {
    // Get the current timestamp
    auto now = std::chrono::system_clock::now();
    auto duration = now.time_since_epoch();
    auto millis = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count() / 1000.0;

    // Format the log message
    std::ostringstream log_stream;
    log_stream << Gaussian::Util::Logger::log_levels[level] << " [" << std::fixed << std::setprecision(6) << millis << "]\n-> " << message;

    // Output the log message
    if (log_file_path == "stdout") {
        std::cout << log_stream.str() << std::endl;
    } else {
        append_file(log_file_path, log_stream.str() + "\n");
    }
}

void Gaussian::Util::Logger::set_log_file(const std::string& path) {
    // Set the log file path
    std::string log_file_path = path;
    write_file(log_file_path, ""); // Erase logfile
    append_file(log_file_path, "Log file created: " + log_file_path + "\n");

    Gaussian::Util::Logger::log_file_path = path; // Update the static variable
}

#endif // UTIL_LOGGER_HPP