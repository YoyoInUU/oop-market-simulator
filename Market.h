#ifndef MARKET_H
#define MARKET_H

#include <vector>

#include "Asset.h"
#include "User.h"

using namespace std;

// Market class: polymorphically
class Market {
  private:
    vector<Asset*> assets_;
    vector<User*> users_;

  public:
    void add_asset(Asset* asset);
    void add_user(User* user);

    Asset* find_asset(const string& symbol);
    User* find_user(const string& name);

    void list_assets() const;

    ~Market();
};

#endif