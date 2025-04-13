import subprocess
import os

TESTS_DIR = "tests"
OUTPUT_DIR = os.path.join(TESTS_DIR, "output")
EXECUTABLE = "./calcvar.exe" if os.name == "nt" else "./calcvar"

def run_test_and_generate_output(test_file):
    base_name = os.path.splitext(test_file)[0]
    source_path = os.path.join(TESTS_DIR, test_file)
    output_path = os.path.join(OUTPUT_DIR, base_name + ".calc.out")

    try:
        result = subprocess.run(
            [EXECUTABLE, source_path],
            stdout=subprocess.PIPE,
            stderr=subprocess.STDOUT,
            text=True,
            timeout=5
        )
        output = result.stdout.strip()
    except Exception as e:
        output = f"[ERROR] {test_file} -> Failed to execute: {e}"

    # Grava a saída no arquivo .out
    with open(output_path, "w", encoding="utf-8") as f:
        f.write(output)

    print(f"\n📄 {test_file}")
    print("----------- Output -----------")
    print(output)
    print("------------------------------")

def main():
    print("⚙️ Generating and printing test outputs...\n")

    os.makedirs(OUTPUT_DIR, exist_ok=True)

    files = os.listdir(TESTS_DIR)
    for file in files:
        if file.endswith(".calc"):
            run_test_and_generate_output(file)

if __name__ == "__main__":
    main()
