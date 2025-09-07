#include <iostream>

#include "Asset.h"

using namespace std;

// ---------- Asset base class ----------
const string& Asset::get_symbol() const {
    return symbol_;
}

double Asset::get_price() const {
    return price_;
}

void Asset::update_price(double new_price) {
    price_ = new_price;
}

// ---------- Stock ----------
void Stock::print_info() const {
    cout << "Stock: " << symbol_ << ", industry: " << industry_ << ", Current Price: " << price_ << endl;
}

// ---------- Future ----------
void Future::print_info() const {
    cout << "Future: " << symbol_ << ", End Date: " << end_date_ << ", Current Price: " << price_ << endl;
}