#include "Chunk.hpp"

std::string Gaussian::Chunk::to_string() const {
    return start.to_string() + " -> " + end.to_string();
}