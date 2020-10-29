#ifndef BLOCKCHAIN_BLOCK_HPP
#define BLOCKCHAIN_BLOCK_HPP

typedef unsigned long blk_index;
typedef size_t blk_hash;

#include <vector>
#include <functional>
#include "../Inc/Transaction.hpp"

class Block {
public:
    Block(blk_index idx, std::vector<Transaction> &&v);
    Block(const Block &) = default;
    Block(Block &&) = default;
    ~Block() = default;

    Block &operator=(const Block &);
    Block &operator=(Block &&);

private:
    std::vector<Transaction> transactions;
    blk_index index;
    blk_hash hash;
    time_t timestamp;
};

#endif
