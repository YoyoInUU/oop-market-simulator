#include <iostream>

#include "Asset.h"

using namespace std;

// ---------- Asset base class ----------
const string& Asset::getSymbol() const {
    return assetSymbol;
}

double Asset::getPrice() const {
    return assetPrice;
}

void Asset::updatePrice(double newPrice) {
    assetPrice = newPrice;
}

// ---------- Stock ----------
void Stock::printInfo() const {
    cout << "Runtime Stock: " << assetSymbol << ", Industry: " << industry
         << ", Current Price: " << assetPrice << endl;
}

// ---------- Future ----------
void Future::printInfo() const {
    cout << "Runtime Future: " << assetSymbol << ", End Date: " << endDate
         << ", Current Price: " << assetPrice << endl;
}