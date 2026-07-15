# 🐾 Pixel Pet: Console Companion

An interactive **virtual pet simulation game built in C++** featuring real-time status tracking, ASCII animations, save/load functionality, and an engaging console-based experience.

---

# 📋 Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Gameplay Mechanics](#gameplay-mechanics)
- [Installation & Setup](#installation--setup)
- [How to Play](#how-to-play)
- [Game States](#game-states)
- [Visual Design](#visual-design)
- [File Structure](#file-structure)
- [Technical Details](#technical-details)
- [Future Improvements](#future-improvements)
- [Contributing](#contributing)
- [License](#license)
- [Author](#author)

---

# 🎮 Overview

**Pixel Pet** is a console-based virtual pet simulator where players take care of their own digital companion by managing three main statistics:

- Hunger
- Happiness
- Energy

The game includes dynamic ASCII art, animated interactions, colorful console feedback, and a persistent save system that allows players to continue their progress.

This project was created to practice core C++ programming concepts including structures, functions, file handling, and program logic.

---

# ✨ Features

## 🐕 Core Gameplay

- Create and name your own virtual pet
- Feed your pet
- Play with your pet
- Let your pet sleep
- Monitor real-time statistics
- Save and load game progress

---

## 📊 Status System

The pet has three main attributes:

| Stat | Description |
|---|---|
| 🍖 Hunger | How much food your pet needs |
| 🎾 Happiness | Your pet's mood |
| ⚡ Energy | Your pet's ability to play and act |

All statistics range from:

```
0 - 100
```

---

## 🎨 Visual Feedback

Features include:

- Dynamic ASCII pet expressions
- Animated actions
- Console colors
- Status bars
- Different reactions depending on pet condition

Pet expressions:

| State | Face | Condition |
|---|---|---|
| Happy | `o o` | All stats are high |
| Sad | `T T` | One or more stats are low |
| Dead | `x x` | Any stat reaches 0 |

---

# 🎯 Gameplay Mechanics

## 📈 Stat Changes

Statistics naturally decrease over time:

- Hunger decreases
- Happiness decreases
- Energy decreases

The player must maintain balance between all three values.

---

# 💀 Game Over Conditions

The pet dies if any statistic reaches:

```
0
```

Possible causes:

- Starvation
- Depression
- Exhaustion

---

# 🚀 Installation & Setup

## Requirements

- C++ Compiler (C++11 or later)
- Windows Operating System
- Standard C++ Library Support

---

# 🔨 Compilation

Using g++:

```bash
g++ -std=c++11 -o pixelpet main.cpp pet.cpp
```

Run:

```bash
./pixelpet.exe
```

---

# 🎮 How to Play

## Main Menu

```
1. BESLE (Feed)
2. OYNA (Play)
3. UYUT (Sleep)
4. KAYDET (Save)
5. CIKIS (Exit)
```

---

## First Time Playing

1. Start the program
2. Choose the option for a new game
3. Enter your pet's name
4. Start taking care of your companion

---

## Continue Saved Game

1. Start the program
2. Select load saved game
3. Your previous progress will be restored

---


# 📁 File Structure

```text
PixelPet/

├── main.cpp          # Main game loop and user interaction
├── pet.cpp           # Pet mechanics, animations, and display
├── pet.h             # Struct definitions and function declarations
├── README.md         # Project documentation
└── LICENSE           # MIT License
```

---

# 💾 Save System

The game automatically creates a local:

```
pet.dat
```

file to store player progress.

The save file contains:

- Pet name
- Hunger value
- Happiness value
- Energy value
- Days survived

The file is generated automatically when the player saves the game.

---


---

# 🧠 Concepts Practiced

This project demonstrates:

- C++ structures
- Functions
- References
- File handling
- Random number generation
- Console programming
- User interaction
- State management

---

# 🔮 Future Improvements

Possible upgrades:

- Multiple pet types
- Pet evolution system
- Mini-games
- Accessories and customization
- Sound effects
- Achievement system
- Graphical User Interface
- Cross-platform support

---

# 🤝 Contributing

Contributions are welcome.

Steps:

1. Fork the repository
2. Create a feature branch

```bash
git checkout -b feature/NewFeature
```

3. Commit changes

```bash
git commit -m "Added new feature"
```

4. Push changes

```bash
git push origin feature/NewFeature
```

5. Open a Pull Request

---

# 📄 License

This project is licensed under the MIT License.

---

# 👤 Author

**Arian Nabil**

Information Systems Engineering Student

GitHub:

https://github.com/herrpo

---

Features included:

- ✅ Virtual pet system
- ✅ Save/load functionality
- ✅ ASCII animations
- ✅ Status tracking
- ✅ Console interaction
- ✅ Multiple game actions

---

**Enjoy your new virtual companion! 🐾**

*Remember: A happy pet is a healthy pet!*
