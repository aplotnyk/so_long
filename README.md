# So_long - 2D Collectible Game

> A 2D game built with C and the MLX42 graphics library, featuring custom sprites, map parsing, and real-time rendering.

## 📋 Project Overview

This project is a **2D tile-based game** where the player navigates through a map, collects items, and finds an exit. The game demonstrates fundamental graphics programming concepts, event handling, and game logic implementation in C.

**Key Achievement:** Built a complete game engine from scratch, handling graphics rendering, collision detection, player input, and map validation.

---

## 🎮 Game Mechanics

### Objective
Navigate your character through the map to:
1. **Collect all collectibles** (items scattered across the map)
2. **Reach the exit** after collecting everything
3. **Complete the level** with minimum moves

### Controls

| Key | Action |
|-----|--------|
| `W` or `↑` | Move up |
| `A` or `←` | Move left |
| `S` or `↓` | Move down |
| `D` or `→` | Move right |
| `ESC` | Exit game |

### Game Elements

- **Player (P)** - Your character
- **Collectibles (C)** - Items to collect
- **Exit (E)** - Door to the next level (opens after collecting all items)
- **Walls (1)** - Obstacles that block movement
- **Empty space (0)** - Free to walk on

---

## 🚀 How to Play

### Installation

```bash
# Clone the repository
git clone https://github.com/aplotnyk/so_long.git
cd so_long

# Compile the game
make

# This creates the so_long executable
```

### Running the Game

```bash
# Play with a map file
./so_long map/map1.ber

# Example maps are provided in the map/ directory
./so_long map/medium.ber
./so_long map/hard.ber
```

### Map Format

Maps are `.ber` files with simple text format:

```
1111111111
1P00C0001
100011101
1C00E0C01
1111111111
```

**Map Rules:**
- Must be rectangular
- Must be surrounded by walls (1)
- Must contain exactly 1 player (P), 1 exit (E), and at least 1 collectible (C)
- Must have a valid path to collect all items and reach the exit

---

## 🎨 Features

### Core Features
- ✅ **Real-time rendering** using MLX42 graphics library
- ✅ **Sprite-based graphics** with custom textures
- ✅ **Collision detection** for walls and boundaries
- ✅ **Move counter** displayed in terminal
- ✅ **Map validation** with error handling

### Technical Features
- ✅ **Flood fill algorithm** for path validation
- ✅ **Event-driven input handling** (keyboard events)
- ✅ **Memory management** with proper cleanup
- ✅ **Modular code structure** for maintainability

---

## 🛠️ Technical Implementation

### Project Structure

```
so_long/
├── src/                # Source files
│   ├── main.c          # Entry point
│   ├── map_parser.c    # Map file reading & validation
│   ├── game_logic.c    # Player movement & game rules
│   ├── graphics.c      # Rendering functions
│   └── utils.c         # Helper functions
├── img/                # Game sprites (PNG files)
│   ├── player.png
│   ├── wall.png
│   ├── collectible.png
│   └── exit.png
├── map/                # Map files (.ber format)
│   ├── map1.ber
│   ├── medium.ber
│   └── hard.ber
├── libs/               # MLX42 library
├── Makefile            # Build configuration
└── README.md
```

### Graphics Pipeline

```
Map File (.ber)
      ↓
Parse & Validate → Build Game Map
      ↓
Initialize MLX42 Window
      ↓
Load Textures (PNG → Images)
      ↓
Game Loop:
  - Handle Input Events
  - Update Game State
  - Render Frame (60 FPS)
  - Check Win/Lose Conditions
      ↓
Cleanup & Exit
```

---

## 🎓 Key Learning Outcomes

This project demonstrates:

1. **Graphics Programming** - Using a graphics library (MLX42) to render 2D sprites
2. **Game Development** - Implementing game loops, state management, and win conditions
3. **Event Handling** - Processing keyboard input in real-time
4. **Algorithm Implementation** - Flood fill for map validation
5. **File Parsing** - Reading and validating custom map formats
6. **Memory Management** - Proper allocation/deallocation in a real-time application

---

## 📊 Map Validation

The game validates maps for:

### Structural Rules
- ✅ Rectangular shape (all rows same length)
- ✅ Surrounded by walls (border = all 1s)
- ✅ Valid characters only (0, 1, P, E, C)

### Game Logic Rules
- ✅ Exactly 1 player starting position (P)
- ✅ Exactly 1 exit (E)
- ✅ At least 1 collectible (C)

### Path Validation
- ✅ Player can reach all collectibles
- ✅ Player can reach the exit after collecting all items
- ✅ Uses flood fill algorithm to check reachability

### Error Examples

```bash
$ ./so_long map/invalid.ber
Error: Map not surrounded by walls

$ ./so_long map/no_path.ber
Error: No valid path to collect all items

$ ./so_long map/duplicate_player.ber
Error: Map must contain exactly one player
```

---

## 🔧 Makefile Commands

```bash
make        # Compile the game
make clean  # Remove object files
make fclean # Remove object files and executable
make re     # Recompile everything
```

---

## 🧪 Testing

### Create Custom Maps

Create a `.ber` file with your own layout:

```
111111111
1P00C0001
100000001
1C00E0001
111111111
```

**Tips:**
- Start simple (small maps)
- Test edge cases (no collectibles, blocked paths)
- Make sure there's always a valid path

---

## 📝 Technical Details

- **Language:** C
- **Graphics Library:** MLX42 (OpenGL-based)
- **Compilation Flags:** `-Wall -Wextra -Werror`
- **Platform:** macOS / Linux
- **Dependencies:** MLX42, OpenGL, GLFW
- **Rendering:** 2D sprite-based with texture mapping

---

## 🎮 Gameplay Features

### Move Counter
Every move is counted and displayed in the terminal:
```
Moves: 1
Moves: 2
Moves: 3
...
```

### Win Condition
```
Congratulations! You collected all items in X moves!
```

---

## 🏆 Game Highlights

**Technical Achievements:**
- **Efficient rendering** - Only redraws changed tiles
- **Clean architecture** - Separated game logic from graphics
- **Robust validation** - Comprehensive map error checking
- **Memory safe** - No leaks detected with valgrind

---

## ✅ Project Status

**Completed** - All mandatory features implemented and tested.

---

## 📖 About This Project

Part of the **42 School curriculum**, so_long teaches:
- Graphics programming fundamentals
- Game development basics
- Real-time application design
- User input handling

This project bridges the gap between algorithmic programming and interactive applications, providing hands-on experience with graphics libraries and event-driven programming.
