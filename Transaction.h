#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include <type_traits>
using namespace std;

// Transaction class with template support for compile-time polymorphism
class Transaction {
  private:
    string userName;
    string stockSymbol;
    string transactionType; // "BUY" or "SELL"
    double transactionPrice;
    int quantity;
    time_t timestamp;

  public:
    Transaction(string user, string symbol, string type, double price, int qty);

    // Template method for different price types
    template <typename PriceType>
    Transaction(string user, string symbol, string type, PriceType price, int qty)
        : userName(move(user)), stockSymbol(move(symbol)), transactionType(move(type)),
          transactionPrice(static_cast<double>(price)), quantity(qty), timestamp(time(nullptr)) {
        static_assert(std::is_arithmetic_v<PriceType>, "Price must be a numeric type");
    }

    void printTransaction() const;

    // Getters
    const string& getUserName() const {
        return userName;
    }
    const string& getStockSymbol() const {
        return stockSymbol;
    }
    const string& getTransactionType() const {
        return transactionType;
    }
    double getTransactionPrice() const {
        return transactionPrice;
    }
    int getQuantity() const {
        return quantity;
    }
    time_t getTimestamp() const {
        return timestamp;
    }
};

#endif
