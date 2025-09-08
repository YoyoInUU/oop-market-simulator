#ifndef USER_H
#define USER_H

#include <string>
#include <vector>

#include "Asset.h"
#include "Transaction.h"

using namespace std;

// Runtime polymorphism User base class
class User {
  protected:
    string userName;
    double userBalance;
    vector<Transaction> transactions;

  public:
    User(string name, double balance)
        : userName(move(name)), userBalance(balance) {}

    const string& getName() const;
    double getBalance() const;

    // pure virtual function
    virtual double getFeeRate() const = 0;

    // virtual function
    virtual ~User() = default;
    virtual string getUserType() const;
    virtual string onTrade(const Transaction&) {
        return "Trading";
    }

    bool buyAsset(Asset& asset, int quantity);
    bool sellAsset(Asset& asset, int quantity);

    void printTransactions() const;
};

// Runtime polymorphism VipUser with lower fees
class VipUser : public User {
  public:
    VipUser(string name, double balance)
        : User(move(name), balance) {}

    double getFeeRate() const override;
    string getUserType() const override;

    string onTrade(const Transaction&) override;
};

// Runtime polymorphism NormalUser with higher fees
class NormalUser : public User {
  public:
    NormalUser(string name, double balance)
        : User(move(name), balance) {}

    double getFeeRate() const override;
    string getUserType() const override;
};

#endif