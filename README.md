# GTK Logic Gate Simulator

This is a C-based GUI logic gate simulator that computes `(A ∧ B) ∨ (A ∧ C)` using GTK+3.

### 🖥️ Features
- Input A, B, and C
- Computes:
  - D = A ∧ B
  - E = A ∧ C
  - X = D ∨ E
- Built with GTK+3 for GUI

### 🛠️ How to Run

Install GTK+3 via Homebrew:
```bash
brew install gtk+3


2. Compile the program

gcc logic_simulator.c -o logic_simulator `pkg-config --cflags --libs gtk+-3.0`


3. Run the GUI app

./logic_simulator