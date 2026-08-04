#include <iostream>

#include "Transaction.h"

// constructor
Transaction::Transaction(std::string user, std::string symbol, std::string type, const double price, const int qty)
    : userName(std::move(user)),
      stockSymbol(std::move(symbol)),
      transactionType(std::move(type)),
      transactionPrice(price),
      quantity(qty),
      timestamp(time(nullptr)) {}

// implement
void Transaction::printTransaction() const {
    std::cout << "User: " << userName
         << ", Action: " << transactionType
         << ", Asset: " << stockSymbol
         << ", Price: " << transactionPrice
         << ", Quantity: " << quantity
         << ", Time: " << ctime(&timestamp);
}
