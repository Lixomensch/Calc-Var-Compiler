# CalcVar Compiler (C++)

A simple compiler developed from scratch in C++ for the educational language **CalcVar**.  
This project implements a full compilation pipeline, including:

- **Lexical analysis** (tokenization)
- **Syntactic analysis** with a recursive descent parser
- **AST (Abstract Syntax Tree)** construction
- **Semantic analysis**, checking for correct variable usage

## ✨ Features

- ✅ Lexical analyzer (`Lexer`)
- ✅ Syntax parser using recursive descent (`Parser`)
- ✅ Abstract Syntax Tree (`AST`) support
- ✅ Semantic analyzer with variable declaration checks
- ✅ Command-line interface with `.calc` file input
- ✅ Automated testing with Python script

## 🛠️ Build & Run

### 📦 Requirements

- **C++ Compiler:** Compatible with C++17 (e.g., `g++`, `clang++`)
- **Build Tool:** `make` (available via [Git for Windows](https://gitforwindows.org/), WSL, or Unix-based systems)
- **Python 3:** Required to run the automated test script (`tests/test_runner.py`)

### 🔧 Compile the project

```bash
make
```

### ▶️ Run the compiler

```bash
./calcvar example.calc          # Linux / macOS
calcvar.exe example.calc        # Windows
```

### 🧹 Clean build artifacts

```bash
make clean
```

## ✅ Automated Testing

You can run all `.calc` test files from the `tests/` directory and generate their output into `tests/output/`.

### 📄 Example test file: `tests/example.calc`

```c
int x;
x = 5 + 3;
```

### ▶️ Run the test generator

```bash
python3 tests/test_runner.py     # Linux
python tests/test_runner.py      # Windows
```

### ✅ This will:

- Run `calcvar` for each `.calc` file in `tests/`
- Save the output into `tests/output/example.out`
- Print the output in the terminal

Example output:

```
📄 example.calc
----------- Output -----------
Semantic analysis completed successfully.
------------------------------
```

## 📜 License

This project is licensed under the MIT License. See the [LICENSE](./LICENSE) file for details.
