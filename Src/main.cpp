#include <iostream>
#include "../Inc/Chain.hpp"
#include "hash/Inc/Sha.hpp"

int main() {
    Sha b {};
    Chain c {};

    std::cout << (b.hash256("a") == b.hash256("a")) << std::endl;
    return 0;
}
