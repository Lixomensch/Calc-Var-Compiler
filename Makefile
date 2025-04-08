# Diretórios
SRC_DIR := src
BUILD_DIR := build
INCLUDE_DIR := include

# Compilador e flags
CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -I$(SRC_DIR) -I$(INCLUDE_DIR)

# Arquivos fonte
SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRCS))

# Executável final
TARGET := calcvar

# Regra padrão
all: $(TARGET)

# Criação do executável
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compilação dos objetos
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpar
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

# Recompilar tudo
rebuild: clean all
