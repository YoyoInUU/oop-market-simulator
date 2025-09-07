# 編譯器
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g

# 目標執行檔
TARGET = main

# 所有的 .cpp 檔案
SRCS = main.cpp Transaction.cpp Asset.cpp User.cpp Market.cpp

# 對應的 .o 檔案（自動把 .cpp 改成 .o）
OBJS = $(SRCS:.cpp=.o)

# 預設目標
all: $(TARGET)

# 連結所有 .o 成執行檔
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# 編譯規則
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# 清除編譯產物
clean:
	rm -f $(OBJS) $(TARGET)