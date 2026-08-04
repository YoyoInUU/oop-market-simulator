#include <iostream>
#include <memory>

#include "Asset.h"
#include "Market.h"
#include "User.h"


int main() {
    std::cout << "=== OOP Market Simulator - Runtime Polymorphism ===" << '\n';
    Market market;

    // Add assets using runtime polymorphism (inheritance + virtual functions)
    market.addAsset(std::make_unique<Stock>("AAPL", 150.0,  "Technology"));
    market.addAsset(std::make_unique<Stock>("GOOG", 2800.0, "Technology"));
    market.addAsset(std::make_unique<Future>("TXO23000A6", 23000, "2026/01/21"));

    market.listAssets();

    std::cout << "--------------------" << '\n';

    // Add users with different fee models using runtime polymorphism
    market.addUser(std::make_unique<VipUser>("Alice", 10000.0));
    market.addUser(std::make_unique<NormalUser>("Bob", 5000.0));

    std::cout << "--------------------" << '\n';

    // Locate users and assets
    User* alice = market.findUser("Alice");
    User* bob = market.findUser("Bob");
    const Asset* apple = market.findAsset("AAPL");
    const Asset* google = market.findAsset("GOOG");

    if (alice && apple) {
        alice->buyAsset(*apple, 10);
    }

    if (bob && google) {
        bob->buyAsset(*google, 2);
    }

    if (alice && apple) {
        alice->sellAsset(*apple, 5);
    }

    if (alice) {
        std::cout << "User Type: " << alice->getUserType() << '\n';
        alice->printTransactions();
    }

    if (bob) {
        std::cout << "User Type: " << bob->getUserType() << '\n';
        bob->printTransactions();
    }

    return 0;
}
