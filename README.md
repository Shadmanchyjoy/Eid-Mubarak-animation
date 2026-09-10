# 🌙 Eid-ul-Azha Terminal Animation
> A lightweight, animated C++ console application celebrating Eid-ul-Azha with vibrant ANSI color art, twinkling stars, fireworks, and frame-by-frame ASCII animations.
![C++](https://img.shields.io/badge/C%2B%2B-11%2B-blue.svg)
![Platform](https://img.shields.io/badge/Platform-Linux%20%7C%20macOS%20%7C%20WSL-brightgreen.svg)
![License](https://img.shields.io/badge/License-MIT-yellow.svg)
---
## ✨ Features
- 🌙 **Crescent Moon & Mosque Silhouette**: Beautifully rendered ASCII night sky backdrop.
- ✨ **Dynamic Starfield**: Procedural twinkling effect across randomly scattered stars.
- 🎆 **Animated Fireworks**: Alternating colors and burst patterns.
- 🐑 **Walking Animal Animation**: Frame-by-frame walking sheep/cow moving across the screen.
- 🎨 **Color-Shifting Banner**: Multi-color cycling text display reading *"EID-UL-AZHA MUBARAK!"*.
- 🖥️ **Smooth Terminal Control**: Uses ANSI escape codes for flicker-free frame updates and hidden cursor management.
---
## 📸 Preview
```text
      _.._                      \ | /                  d
    .' .-'                     - -* -                 / \
   /  /                         / | \                /   \
  |  |                                              /_____\
   \  \                   +-------------------------+      |   _l_
    '. '._.               | EID-UL-AZHA MUBARAK! |   |  ___  |  |   |
      ''                  +-------------------------+   | |   | |  |   |
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
                          ,(__),
                      ____(oo)
                     /(    (__)
                      \\--//
         May Allah accept your sacrifices and bless your family.
```
---
## 🚀 Getting Started
### Prerequisites
- A C++ compiler supporting **C++11 or higher** (`g++`, `clang++`).
- A **POSIX-compliant system** (Linux, macOS, WSL) for `<unistd.h>`.
- A terminal emulator supporting **ANSI escape codes** and 24x80 text grid.
---
### 🛠️ Build & Run
1. **Clone the repository**
   ```bash
   git clone https://github.com/Shadmanchyjoy/eid-animation.git
   cd eid-animation
   ```
2. **Compile the C++ code**
   ```bash
   g++ -O2 main.cpp -o eid_animation
   ```
3. **Run the executable**
   ```bash
   ./eid_animation
   ```
> 💡 **Windows Users**: Run the executable inside **WSL (Windows Subsystem for Linux)**, **Git Bash**, or **MSYS2** to ensure terminal ANSI escape codes and POSIX timers display properly.
---
## ⚙️ Customization
You can tweak the performance and aesthetics by editing parameters in `main.cpp`:

| Variable / Function | Code snippet | Description |
| :--- | :--- | :--- |
| **Animation Duration** | `f < 70` | Total frame count before ending the animation. |
| **Frame Speed** | `usleep(200000)` | Frame delay in microseconds (lower = faster). |
| **Star Density** | `i < 35` in `initStars()` | Increase/decrease the number of stars generated. |
| **Canvas Size** | `const int W = 80;` | Adjust grid dimensions to match larger screens. |

---
## 📜 License
Distributed under the MIT License. See `LICENSE` for details.