# 🏓 Project Pong

A modern recreation of the classic **Pong** game built in **C++** using **raylib**.

This project started as a way to learn raylib by following Programming With Nick's tutorials, but quickly grew into something much bigger. Instead of stopping at a simple ball-and-paddle demo, I expanded it into a complete local multiplayer game with menus, settings, music, sound effects, pause functionality, and customizable gameplay.

It's a small project, but it taught me a lot about game loops, collision detection, audio management, state machines, and organizing game logic in C++.

---

## 🎮 Features

### Gameplay
- 🏓 Local 2-player Pong
- ⚡ Ball speed increases after every paddle hit to keep matches exciting
- 🏆 Choose the winning score before the match:
  - 5 Points
  - 10 Points
  - 15 Points

### Menus
- Main Menu
- Settings Menu
- Pause Menu
- Game Over Screen
- Play Again / Return to Main Menu

### Audio
- 🎵 Choose from 5 different background music tracks
- 🔇 Option to turn background music off
- 🔊 Toggle sound effects on or off independently

### Game Over
- Displays the winner
- Shows the final score
- Restart the game instantly or return to the main menu

---

## 🎮 Controls

| Player | Controls |
|---|---|
| Left Paddle | **W** (Up) / **S** (Down) |
| Right Paddle | **↑** / **↓** Arrow Keys |
| Pause / Resume | **ESC** |

---

## 🛠 Built With

- C++17
- raylib

---

## 📂 Project Structure

```
Project-Pong/
│
├── main.cpp
├── *.mp3
├── README.md
└── ...
```

### Files

| File | Description |
|---|---|
| `main.cpp` | Contains the complete game logic |
| `*.mp3` | Background music and sound effects |

---

## 🚀 How to Run

### 1. Install raylib

Install raylib for your operating system.

### 2. Compile

```bash
g++ -std=c++17 main.cpp -o main -lraylib
```

### 3. Run

```bash
./main
```

### macOS / Linux Notes

Depending on your operating system, raylib may require additional linker flags. For example:

- macOS requires frameworks such as Cocoa and OpenGL.
- Linux often requires X11, pthread, GL, dl, and rt libraries.

If compilation fails during linking, refer to the raylib installation guide for your operating system.

---

## 🎵 Audio Files

The game loads all music and sound effects using relative file paths. Make sure all `.mp3` files remain in the same directory as the executable (or update the paths in the source code). Missing audio files may prevent sounds from loading correctly.

---

## 📚 What I Learned

Building this project helped me gain practical experience with:

- Game loops
- Collision detection
- Game state management
- Input handling
- Audio playback
- Menu systems
- Object-oriented programming in C++
- Working with the raylib game framework

---

## 🔮 Future Improvements

- Single-player mode with an AI opponent
- Save high scores
- Online multiplayer
- Improved graphics and animations
- Better sound effects (the current paddle hit is a fart sound... it gets the job done 😄)
- Split the project into multiple source/header files instead of keeping everything in `main.cpp`

---

## 🙏 Credits

This project was originally inspired by the excellent **Programming With Nick** raylib tutorials.

After completing the tutorial, I expanded the project with my own features including:

- Main menu
- Settings menu
- Pause system
- Multiple music tracks
- Audio toggles
- Game over screen
- Winning score selection
- Increasing ball speed
- General gameplay improvements

---

## ℹ️ About

This project was built as part of my journey learning C++ and raylib. It may be a simple game, but every feature added was an opportunity to learn something new. I'll continue improving it whenever I have time and use it as a foundation for building larger game projects in the future.

If you have suggestions or feedback, feel free to open an issue or fork the project.

Thanks for checking it out!
