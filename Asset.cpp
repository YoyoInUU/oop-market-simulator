#include <iostream>

#include "Asset.h"


// ---------- Asset base class ----------
const std::string& Asset::getSymbol() const {
    return assetSymbol;
}

double Asset::getPrice() const {
    return assetPrice;
}

void Asset::updatePrice(const double newPrice) {
    assetPrice = newPrice;
}

// ---------- Stock ----------
void Stock::printInfo() const {
    std::cout << "Runtime Stock: " << assetSymbol << ", Industry: " << industry
         << ", Current Price: " << assetPrice << '\n';
}

// ---------- Future ----------
void Future::printInfo() const {
    std::cout << "Runtime Future: " << assetSymbol << ", End Date: " << endDate
         << ", Current Price: " << assetPrice << '\n';
}
