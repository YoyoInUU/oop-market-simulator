#include <iostream>

#include "Asset.h"
#include "Transaction.h"
#include "User.h"

using namespace std;

// ---------- User base class ----------
const string& User::getName() const {
    return userName;
}

double User::getBalance() const {
    return userBalance;
}

string User::getUserType() const {
    return "User";
}

bool User::buyAsset(Asset& asset, int quantity) {
    if (quantity <= 0) {
        cout << userName << ": invalid quantity." << endl;
        return false;
    }

    double price = asset.getPrice();
    double cost = price * quantity;
    double fee = cost * getFeeRate();
    double total = cost + fee;

    if (userBalance < total) {
        cout << userName << " does not have enough balance to buy " << quantity
             << " of " << asset.getSymbol() << " (need " << total
             << ", have " << userBalance << ")" << endl;
        return false;
    }

    userBalance -= total;
    transactions.emplace_back(userName, asset.getSymbol(), "BUY", price, quantity);
    cout << userName << " (" << getUserType() << ") bought " << quantity << " of "
         << asset.getSymbol() << " at " << price << " (fee " << fee << ")" << endl;
    onTrade(transactions.back());
    return true;
}

bool User::sellAsset(Asset& asset, int quantity) {
    if (quantity <= 0) {
        cout << userName << ": invalid quantity." << endl;
        return false;
    }

    double price = asset.getPrice();
    double revenue = price * quantity;
    double fee = revenue * getFeeRate();
    double net = revenue - fee;

    userBalance += net;
    transactions.emplace_back(userName, asset.getSymbol(), "SELL", price, quantity);
    cout << userName << " (" << getUserType() << ") sold " << quantity << " of "
         << asset.getSymbol() << " at " << price << " (fee " << fee << ")" << endl;
    onTrade(transactions.back());
    return true;
}

void User::printTransactions() const {
    cout << "Transactions of " << userName << ":" << endl;
    for (const auto& t : transactions) {
        t.printTransaction();
    }
}

// ---------- VipUser with lower fees ----------
double VipUser::getFeeRate() const {
    return 0.0001;
}

string VipUser::getUserType() const {
    return "VIP";
}

string VipUser::onTrade(const Transaction&) {
    return "VIP Trading";
}

// ---------- NormalUser with higher fees ----------
double NormalUser::getFeeRate() const {
    return 0.002;
}

string NormalUser::getUserType() const {
    return "Normal";
}