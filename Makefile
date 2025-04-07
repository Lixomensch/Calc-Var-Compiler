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
TARGET := $(BUILD_DIR)/calcvar

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
	@if exist $(BUILD_DIR) del /q $(BUILD_DIR)\*

# Recompilar tudo
rebuild: clean all
