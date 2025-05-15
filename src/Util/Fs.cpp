#include "Util/Fs.hpp"

bool Gaussian::Util::file_exists(const std::string& path) {
    std::ifstream file(path);
    return file.good();
}

std::string Gaussian::Util::read_file(const std::string& path) {
    std::ifstream file(path);
    if (!file) {
        std::cerr << "Error: Could not open file " << path << std::endl;
        return "";
    }
    std::ostringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

void Gaussian::Util::write_file(const std::string& path, const std::string& content) {
    std::ofstream file(path);
    if (!file) {
        std::cerr << "Error: Could not open file " << path << std::endl;
        return;
    }
    file << content;
    if (!file) {
        std::cerr << "Error: Could not write to file " << path << std::endl;
    }
    file.close();
    if (!file) {
        std::cerr << "Error: Could not close file " << path << std::endl;
    }
}

void Gaussian::Util::append_file(const std::string& path, const std::string& content) {
    std::ofstream file(path, std::ios::app);
    if (!file) {
        std::cerr << "Error: Could not open file " << path << std::endl;
        return;
    }
    file << content;
    if (!file) {
        std::cerr << "Error: Could not write to file " << path << std::endl;
    }
    file.close();
    if (!file) {
        std::cerr << "Error: Could not close file " << path << std::endl;
    }
}