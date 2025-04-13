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
ifeq ($(OS),Windows_NT)
	@if exist build rmdir /S /Q build
	@mkdir build
	@type nul > build\.gitkeep
	
	@if exist tests\output rmdir /S /Q tests\output
	@mkdir tests\output
	@type nul > tests\output\.gitkeep
	
	@if exist calcvar.exe del /Q calcvar.exe
else
	@find $(BUILD_DIR) -mindepth 1 ! -name ".gitkeep" -delete
	@find $(TESTS_OUTPUT_DIR) -mindepth 1 ! -name ".gitkeep" -delete
	@rm -f $(TARGET)
endif

rebuild: clean all
