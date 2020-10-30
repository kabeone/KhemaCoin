#include <vector>
#include "../Inc/Chain.hpp"

Chain::Chain() {
    this->chain = std::vector<Block>();
    this->idx = 0;
}

Chain &Chain::operator=(const Chain &from) {
    this->chain = from.chain;
    return *this;
}

Chain &Chain::operator=(Chain &&from) {
    std::swap(*this, from);
    return *this;
}

blk_index Chain::add_Transaction(std::vector<Transaction> t) {
    blk_index tmp = idx;
    chain.emplace_back(idx++, std::move(t));
    return tmp;
}