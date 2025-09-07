#ifndef ASSET_H
#define ASSET_H

#include <string>
using namespace std;

// Abstract base class: Asset (encapsulation + polymorphism)
class Asset {
  protected:
    string symbol_;
    double price_;

  public:
    Asset(string symbol, double price)
        : symbol_(symbol), price_(price){};

    // virtual function
    virtual ~Asset() = default;
    virtual const string& get_symbol() const;
    virtual double get_price() const;
    virtual void update_price(double new_price);

    // pure virtual function
    virtual void print_info() const = 0;
};

// Derived class: Stock (inheritance  + polymorphism)
class Stock : public Asset {
  private:
    string industry_;

  public:
    Stock(string symbol, double price, string industry)
        : Asset(move(symbol), price), industry_(move(industry)) {}
    void print_info() const override;
};

// Derived class: Future (inheritance + polymorphism)
class Future : public Asset {
  private:
    string end_date_;

  public:
    Future(string symbol, double price, string end_date)
        : Asset(move(symbol), price), end_date_(move(end_date)) {}
    void print_info() const override;
};

#endif