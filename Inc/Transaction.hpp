#ifndef BLOCKCHAIN_TRANSACTION_HPP
#define BLOCKCHAIN_TRANSACTION_HPP

#include <functional>

class Transaction {
public:
    Transaction(unsigned long amount, size_t send, size_t recv);
    ~Transaction() = default;

private:
    unsigned long amount;
    size_t sender;
    size_t receiver;
};


#endif //BLOCKCHAIN_TRANSACTION_HPP
