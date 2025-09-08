#include <ctime>
#include <iostream>

#include "Transaction.h"

using namespace std;

// constructor
Transaction::Transaction(string user, string symbol, string type, double price, int qty)
    : userName(move(user)),
      stockSymbol(move(symbol)),
      transactionType(move(type)),
      transactionPrice(price),
      quantity(qty),
      timestamp(time(nullptr)) {}

// implement
void Transaction::printTransaction() const {
    cout << "User: " << userName
         << ", Action: " << transactionType
         << ", Asset: " << stockSymbol
         << ", Price: " << transactionPrice
         << ", Quantity: " << quantity
         << ", Time: " << ctime(&timestamp);
}
