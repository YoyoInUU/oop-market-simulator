#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
using namespace std;

// Transaction class: encapsulation
class Transaction {
  private:
    string user_name_;
    string stock_symbol_;
    string transaction_type_; // "BUY" or "SELL"
    double transaction_price_;
    int quantity_;
    time_t timestamp_;

  public:
    Transaction(string user, string symbol, string type, double price, int qty);
    void print_transaction() const;
};

#endif
