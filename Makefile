SRC_DIR := src
BUILD_DIR := build
INCLUDE_DIR := include

CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -I$(SRC_DIR) -I$(INCLUDE_DIR)

SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRCS))

TARGET := calcvar

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@if exist $(BUILD_DIR) del /q $(BUILD_DIR)\*

rebuild: clean all
