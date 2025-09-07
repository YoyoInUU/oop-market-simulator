#ifndef USER_H
#define USER_H

#include <string>
#include <vector>

#include "Asset.h"
#include "Transaction.h"

using namespace std;

class User {
  protected:
    string name_;
    double balance_;
    vector<Transaction> transactions_;

  public:
    User(string n, double b)
        : name_(move(n)), balance_(b) {}

    const string& name() const;
    double balance() const;

    // pure virtual function
    virtual double fee_rate() const = 0;

    // virtual function
    virtual ~User() = default;
    virtual string user_type() const;
    virtual string on_trade(const Transaction&) {
        return "Trading";
    }

    bool buy_asset(Asset& asset, int quantity);
    bool sell_asset(Asset& asset, int quantity);

    void print_transactions() const;
};

// Derived user: VipUser with lower fees
class VipUser : public User {
  public:
    VipUser(string n, double b)
        : User(move(n), b) {}

    double fee_rate() const override;
    string user_type() const override;

    string on_trade(const Transaction&) override;
};

// Derived user: NormalUser with higher fees
class NormalUser : public User {
  public:
    NormalUser(string n, double b)
        : User(move(n), b) {}

    double fee_rate() const override;
    string user_type() const override;
};

#endif