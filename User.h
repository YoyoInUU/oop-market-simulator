#ifndef USER_H
#define USER_H

#include <string>
#include <vector>

#include "Asset.h"
#include "Transaction.h"


// Runtime polymorphism User base class
class User {
  protected:
    std::string userName;
    double userBalance;
    std::vector<Transaction> transactions;

  public:
    User(std::string name, const double balance)
        : userName(std::move(name)), userBalance(balance) {}

    [[nodiscard]] const std::string& getName() const;
    [[nodiscard]] double getBalance() const;

    // pure virtual function
    [[nodiscard]] virtual double getFeeRate() const = 0;

    // virtual function
    virtual ~User() = default;
    [[nodiscard]] virtual std::string getUserType() const;
    virtual std::string onTrade(const Transaction&) {
        return "Trading";
    }

    bool buyAsset(const Asset& asset, int quantity);
    bool sellAsset(const Asset& asset, int quantity);

    void printTransactions() const;
};

// Runtime polymorphism VipUser with lower fees
class VipUser : public User {
  public:
    VipUser(std::string name, const double balance)
        : User(std::move(name), balance) {}

    [[nodiscard]] double getFeeRate() const override;
    [[nodiscard]] std::string getUserType() const override;

    std::string onTrade(const Transaction&) override;
};

// Runtime polymorphism NormalUser with higher fees
class NormalUser : public User {
  public:
    NormalUser(std::string name, const double balance)
        : User(std::move(name), balance) {}

    [[nodiscard]] double getFeeRate() const override;
    [[nodiscard]] std::string getUserType() const override;
};

#endif
