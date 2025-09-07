#include <ctime>
#include <iostream>

#include "Transaction.h"

using namespace std;

// constructor
Transaction::Transaction(string user, string symbol, string type, double price, int qty)
    : user_name_(move(user)),
      stock_symbol_(move(symbol)),
      transaction_type_(move(type)),
      transaction_price_(price),
      quantity_(qty),
      timestamp_(time(nullptr)) {}

// implement
void Transaction::print_transaction() const {
    cout << "User: " << user_name_
         << ", Action: " << transaction_type_
         << ", Asset: " << stock_symbol_
         << ", Price: " << transaction_price_
         << ", Quantity: " << quantity_
         << ", Time: " << ctime(&timestamp_);
}
