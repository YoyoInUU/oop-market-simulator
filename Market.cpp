#include <iostream>

#include "Market.h"

void Market::addAsset(std::unique_ptr<Asset> asset) {
    std::cout << "Added asset: " << asset->getSymbol() << '\n';
    marketAssets.push_back(std::move(asset));
}

void Market::addUser(std::unique_ptr<User> user) {
    std::cout << "Added user: " << user->getName() << " (" << user->getUserType() << ")" << '\n';
    marketUsers.push_back(std::move(user));
}

Asset* Market::findAsset(const std::string_view symbol) const {
    for (auto& asset : marketAssets) {
        if (asset->getSymbol() == symbol)
            return asset.get();
    }
    std::cout << "Asset " << symbol << " not found" << '\n';
    return nullptr;
}

User* Market::findUser(const std::string_view name) const {
    for (auto& user : marketUsers) {
        if (user->getName() == name)
            return user.get();
    }
    std::cout << "User " << name << " not found" << '\n';
    return nullptr;
}

// polymorphic
void Market::listAssets() const {
    std::cout << "Market assets:" << '\n';
    for (auto& asset : marketAssets) {
        asset->printInfo();
    }
}
