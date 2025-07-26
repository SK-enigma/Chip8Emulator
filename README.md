# Chip-8 Emulator (C++ / SDL2)

This is a Chip-8 emulator built in C++ using SDL2. The project was developed as a learning exercise to understand the basics of old CPUs and emulation.

Chip-8 is a virtual machine from the 1970s, often used as a first project for emulator development. It helped me explore core systems-level concepts like instruction decoding, memory layout, and low-level graphics.

---

## 🔧 Features

- 🕹 Loads and runs `.ch8` ROM files  
- ⏱ Full CPU cycle implementation with 60Hz timers  
- ⌨ Keypad input handling via SDL2  
- 🖥 Monochrome 64x32 pixel display output  
- 💾 Instruction decoding and execution loop  
- 🗂 ROM selection at runtime or via hardcoded path  

---

## 📦 Requirements

- C++17+
- SDL2
- CMake

---

## 🚀 How to Run

```bash
# Clone the repo
git clone https://github.com/YOUR-USERNAME/chip8-emulator.git
cd chip8-emulator

# Place any `.ch8` ROM files in the project directory

# Build and run
mkdir build && cd build
cmake ..
make
./chip8
