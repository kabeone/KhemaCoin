#include <vector>
#include <utility>
#include <fstream>
#include "../Inc/Transaction.hpp"
#include "../Inc/Block.hpp"

static blk_hash get_rand_hash() {
    std::ifstream f {"/dev/random"};
    std::hash<const char *> h;
    return h("hello world");
}

Block::Block(blk_index idx, std::vector<Transaction> &&v)
: index{idx}, hash{}, transactions{v} {
    time(&timestamp);
}

Block &Block::operator=(Block &&b) {
    std::swap(*this, b);
    return *this;
}

Block &Block::operator=(const Block &b) {
    return *this;
}