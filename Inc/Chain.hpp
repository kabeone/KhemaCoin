#ifndef BLOCKCHAIN_CHAIN_HPP
#define BLOCKCHAIN_CHAIN_HPP

#include <vector>
#include "../Inc/Block.hpp"

class Chain {
public:
    Chain();
    Chain(const Chain &) = default;
    Chain(Chain &&) = default;
    ~Chain() = default;

    Chain &operator=(const Chain &);
    Chain &operator=(Chain &&);

    blk_index add_Transaction(std::vector<Transaction>);
private:
    std::vector<Block> chain;
    blk_index idx;
};


#endif
