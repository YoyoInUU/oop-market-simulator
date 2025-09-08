#ifndef MARKET_H
#define MARKET_H

#include <vector>

#include "Asset.h"
#include "User.h"

using namespace std;

// Traditional Market class with runtime polymorphism
class Market {
  private:
    vector<Asset*> marketAssets;
    vector<User*> marketUsers;

  public:
    void addAsset(Asset* asset);
    void addUser(User* user);

    Asset* findAsset(const string& symbol);
    User* findUser(const string& name);

    void listAssets() const;

    ~Market();
};

#endif