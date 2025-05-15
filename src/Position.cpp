#include "Position.hpp"
#include <string>

std::string Gaussian::Position::to_string() const {
    return std::to_string(line + 1) + ":" + std::to_string(column + 1);
}