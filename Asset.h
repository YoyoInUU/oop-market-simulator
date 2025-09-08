#ifndef ASSET_H
#define ASSET_H

#include <string>
using namespace std;

// Traditional runtime polymorphism Asset base class
class Asset {
  protected:
    string assetSymbol;
    double assetPrice;

  public:
    Asset(string symbol, double price)
        : assetSymbol(move(symbol)), assetPrice(price) {}

    // virtual function
    virtual ~Asset() = default;
    virtual const string& getSymbol() const;
    virtual double getPrice() const;
    virtual void updatePrice(double newPrice);

    // pure virtual function
    virtual void printInfo() const = 0;
};

// Runtime polymorphism Stock (inheritance + polymorphism)
class Stock : public Asset {
  private:
    string industry;

  public:
    Stock(string symbol, double price, string industryType)
        : Asset(move(symbol), price), industry(move(industryType)) {}
    void printInfo() const override;
};

// Runtime polymorphism Future (inheritance + polymorphism)
class Future : public Asset {
  private:
    string endDate;

  public:
    Future(string symbol, double price, string expiryDate)
        : Asset(move(symbol), price), endDate(move(expiryDate)) {}
    void printInfo() const override;
};

#endif