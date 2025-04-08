# 🧠 GTK Logic Gate Simulator

![Language](https://img.shields.io/badge/language-C-blue)
![GTK](https://img.shields.io/badge/built%20with-GTK%2B3-green)

This is a C-based GUI logic simulator that computes the Boolean expression **(A ∧ B) ∨ (A ∧ C)** using GTK+3.

---

## 💡 Features

- GUI interface to input values for A, B, and C
- Displays results for:
  - `D = A ∧ B`
  - `E = A ∧ C`
  - `X = D ∨ E`
- Built entirely with GTK+3 in C
- Simple, clean layout for learning logic gate simulation

---

## 🛠️ How to Run

### 1. Install GTK+3 (for macOS via Homebrew)
```bash
brew install gtk+3



gcc logic_simulator.c -o logic_simulator `pkg-config --cflags --libs gtk+-3.0`



./logic_simulator
