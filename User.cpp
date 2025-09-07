#include <iostream>

#include "Asset.h"
#include "Transaction.h"
#include "User.h"

using namespace std;

// ---------- User base class ----------
const string& User::name() const {
    return name_;
}

double User::balance() const {
    return balance_;
}

string User::user_type() const {
    return "User";
}

bool User::buy_asset(Asset& asset, int quantity) {
    if (quantity <= 0) {
        cout << name_ << ": invalid quantity." << endl;
        return false;
    }

    double price = asset.get_price();
    double cost = price * quantity;
    double fee = cost * fee_rate();
    double total = cost + fee;

    if (balance_ < total) {
        cout << name_ << " does not have enough balance to buy " << quantity
             << " of " << asset.get_symbol() << " (need " << total
             << ", have " << balance_ << ")" << endl;
        return false;
    }

    balance_ -= total;
    transactions_.emplace_back(name_, asset.get_symbol(), "BUY", price, quantity);
    cout << name_ << " (" << user_type() << ") bought " << quantity << " of "
         << asset.get_symbol() << " at " << price << " (fee " << fee << ")" << endl;
    on_trade(transactions_.back());
    return true;
}

bool User::sell_asset(Asset& asset, int quantity) {
    if (quantity <= 0) {
        cout << name_ << ": invalid quantity." << endl;
        return false;
    }

    double price = asset.get_price();
    double revenue = price * quantity;
    double fee = revenue * fee_rate();
    double net = revenue - fee;

    balance_ += net;
    transactions_.emplace_back(name_, asset.get_symbol(), "SELL", price, quantity);
    cout << name_ << " (" << user_type() << ") sold " << quantity << " of "
         << asset.get_symbol() << " at " << price << " (fee " << fee << ")" << endl;
    on_trade(transactions_.back());
    return true;
}

void User::print_transactions() const {
    cout << "Transactions of " << name_ << ":" << endl;
    for (const auto& t : transactions_) {
        t.print_transaction();
    }
}

// ---------- VipUser with lower fees ----------
double VipUser::fee_rate() const {
    return 0.0001;
}

string VipUser::user_type() const {
    return "VIP";
}

string VipUser::on_trade(const Transaction&) {
    return "VIP Trading";
}

// ---------- NormalUser with higher fees ----------
double NormalUser::fee_rate() const {
    return 0.002;
}

string NormalUser::user_type() const {
    return "Normal";
}