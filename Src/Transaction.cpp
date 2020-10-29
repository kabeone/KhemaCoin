#include "../Inc/Transaction.hpp"

Transaction::Transaction(unsigned long amount, size_t sender, size_t receiver) {
    this->amount = amount;
    this->sender = sender;
    this->receiver = receiver;
}