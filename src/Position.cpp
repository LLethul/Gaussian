#include "Position.hpp"
#include <string>

std::string Gaussian::Position::to_string() const {
    return std::to_string(line) + ":" + std::to_string(column);
}