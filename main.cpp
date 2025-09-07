#include <iostream>

#include "Asset.h"
#include "Market.h"
#include "Transaction.h"
#include "User.h"

using namespace std;

int main() {
    Market market;

    // Add assets (inheritance + polymorphism)
    market.add_asset(new Stock("AAPL", 150.0, "Technology"));
    market.add_asset(new Stock("GOOG", 2800.0, "Technology"));
    market.add_asset(new Future("TXO23000A6", 23000, "2026/01/21"));

    market.list_assets();

    cout << "--------------------" << endl;

    // Add users with different fee models (inheritance + polymorphism)
    market.add_user(new VipUser("Alice", 10000.0));
    market.add_user(new NormalUser("Bob", 5000.0));

    cout << "--------------------" << endl;

    // Locate users and assets
    User* alice = market.find_user("Alice");
    User* bob = market.find_user("Bob");
    Asset* apple = market.find_asset("AAPL");
    Asset* google = market.find_asset("GOOG");

    if (alice && apple) {
        alice->buy_asset(*apple, 10);
    }

    if (bob && google) {
        bob->buy_asset(*google, 2);
    }

    if (alice && apple) {
        alice->sell_asset(*apple, 5);
    }

    if (alice) {
        alice->user_type();
        alice->print_transactions();
    }

    if (bob) {
        bob->user_type();
        bob->print_transactions();
    }

    return 0;
}