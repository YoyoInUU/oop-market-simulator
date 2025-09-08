# OOP Market Simulator

A comprehensive C++ project demonstrating both **Runtime Polymorphism** and **Compile-time Polymorphism** in a market trading simulation environment.

## 🎯 Project Overview

This project showcases advanced Object-Oriented Programming concepts and template metaprogramming in C++, implementing a market simulator that supports:

- **Runtime Polymorphism** via virtual functions and inheritance
- **Compile-time Polymorphism** via templates
- **Performance comparison** between both approaches
- **Multiple data type support** through template specialization

## 🏗️ Architecture

### Runtime Polymorphism Classes
- **Asset** (base class) → **Stock**, **Future** (derived classes)
- **User** (base class) → **VipUser**, **NormalUser** (derived classes)
- **Market** (manages collections of assets and users)
- **Transaction** (encapsulates trading operations)

### Compile-time Polymorphism Classes
- `template <typename PriceType>` in **Transaction**

## 🚀 Key Features

### 1. CamelCase Coding Style
All code follows standard C++ camelCase conventions:
```cpp
// Variables and functions
userName, getUserType(), buyAsset()

// Classes  
StockTemplate, VipUserTemplate, MarketTemplate
```

### 2. Template-based Compile-time Polymorphism
Supports multiple numeric types for enhanced flexibility:
```cpp
// Price updates with different numeric types
template <typename PriceType>
Transaction(string user, string symbol, string type, PriceType price, int qty)
    : userName(move(user)), stockSymbol(move(symbol)), transactionType(move(type)),
      transactionPrice(static_cast<double>(price)), quantity(qty), timestamp(time(nullptr)) {
    static_assert(std::is_arithmetic_v<PriceType>, "Price must be a numeric type");
}
```

## 📊 Polymorphism Comparison

### Runtime Polymorphism (Virtual Functions)

**✅ PROS:**
- Dynamic behavior selection at runtime
- Easy to extend with new types without changing client code
- Clean, intuitive inheritance hierarchy
- Supports heterogeneous collections

**❌ CONS:**
- Virtual function call overhead (vtable lookup)
- Slightly larger memory footprint (vtable pointers)
- Cannot be fully optimized by compiler (no inlining)
- Runtime type checking needed for downcasting

### Compile-time Polymorphism (Templates)

**✅ PROS:**
- Zero runtime overhead (all resolved at compile time)
- Full compiler optimization potential (inlining)
- Type safety enforced at compile time
- Support for multiple parameter types

**❌ CONS:**
- Code bloat (separate code generated for each type)
- Longer compilation times
- Cannot store different template types in same container
- Complex error messages when template instantiation fails
- Less intuitive for traditional OOP hierarchies

## 🛠️ Build Instructions

### Prerequisites
- C++17 or later compiler (GCC, Clang, MSVC)
- Make (optional, for using Makefile)

### Compilation

**Using Make:**
```bash
make all
./main
```

**Manual Compilation:**
```bash
g++ -std=c++17 -Wall -Wextra -O2 *.cpp -o main
./main
```

**Windows (MSVC):**
```cmd
cl /EHsc /std:c++17 *.cpp /Fe:main.exe
main.exe
```

## 📁 File Structure

```
oop-market-simulator-main/
├── Asset.h              # Asset classes (runtime + template)
├── Asset.cpp            # Asset implementations
├── User.h               # User classes (runtime + template)
├── User.cpp             # User implementations
├── Market.h             # Market classes (runtime + template)
├── Market.cpp           # Market implementations
├── Transaction.h        # Transaction class with template support
├── Transaction.cpp      # Transaction implementation
├── main.cpp             # Demo program with performance analysis
├── Makefile             # Build configuration
└── README.md            # This file
```

## 🔬 Performance Insights

Based on typical runs, you'll observe:

1. **Compile-time polymorphism** generally performs faster due to:
   - No virtual function call overhead
   - Full compiler optimizations (inlining)
   - Direct function calls

2. **Runtime polymorphism** offers flexibility at the cost of:
   - Virtual table lookups
   - Reduced optimization opportunities
   - Dynamic dispatch overhead

## 📈 Learning Objectives

This project demonstrates:

1. **OOP Design Patterns**: Inheritance, Encapsulation, Polymorphism
2. **Template Metaprogramming**: CRTP, SFINAE, Type Traits
3. **Performance Analysis**: Microbenchmarking, Compiler Optimizations
4. **Modern C++**: Smart pointers, Move semantics, Auto type deduction
5. **Software Engineering**: Clean code, Documentation, Testing

## 🤝 Contributing

Feel free to fork this project and submit pull requests for:
- Additional template specializations
- Performance optimizations
- New asset/user types
- Enhanced documentation

## 📄 License

This project is for educational purposes. Feel free to use and modify as needed.

---

**Author**: Yoyo Chang
**Last Updated**: September 2025  
**C++ Standard**: C++17
