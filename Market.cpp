#include <iostream>

#include "Market.h"

using namespace std;

void Market::add_asset(Asset* asset) {
    cout << "Added asset: " << asset->get_symbol() << endl;
    assets_.push_back(asset);
}

void Market::add_user(User* user) {
    cout << "Added user: " << user->name() << " (" << user->user_type() << ")" << endl;
    users_.push_back(user);
}

Asset* Market::find_asset(const string& symbol) {
    for (auto* a : assets_) {
        if (a->get_symbol() == symbol)
            return a;
    }
    cout << "Asset " << symbol << " not found" << endl;
    return nullptr;
}

User* Market::find_user(const string& name) {
    for (auto* u : users_) {
        if (u->name() == name)
            return u;
    }
    cout << "User " << name << " not found" << endl;
    return nullptr;
}

// polymorphic
void Market::list_assets() const {
    cout << "Market assets:" << endl;
    for (const auto* a : assets_) {
        a->print_info();
    }
}

// destructor
Market::~Market() {
    for (auto* a : assets_) {
        delete a;
    }
    for (auto* u : users_) {
        delete u;
    }
}