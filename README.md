# Snakes and Ladders

## 📖 Overview
This repository contains a C++ implementation of the classic Snakes and Ladders game, designed with a focus on **Low-Level Design (LLD)** principles. The system is modular, uses efficient data structures for board navigation, and implements advanced gameplay rules often required in technical machine coding interviews.

## 🚀 Key Features
* **Modular Architecture**: The project maintains a clean separation of concerns between game logic (`Game`), player entities (`Player`), and board components (`Element`).
* **Recursive Jump Logic**: The engine automatically handles chained jumps (e.g., landing on a ladder that leads directly to a snake's mouth) using a loop-based lookup in the `GetPosition` function.
* **Fair Dice Simulation**: Utilizes the `std::mt19937` Mersenne Twister engine combined with a high-resolution clock seed to ensure high-quality randomness for every roll.
* **O(1) Board Navigation**: The board layout is pre-calculated into a `Game_Grid` vector during initialization, allowing the system to determine the result of any move in constant time.

## 🎮 Gameplay Mechanics
The implementation includes specific rules that add complexity and robustness to the simulation:
* **Recursive Movement Resolution**: If a player lands on a ladder or snake that leads directly to another board element, the system uses a `while` loop to resolve the final position.
* **The "Triple Six" Penalty**: If a player rolls a 6 three times in a row, the `Play` function voids the entire turn, and the player remains at their starting position.
* **Bonus Rolls**: Players earn an additional roll for every 6 rolled, up to a maximum of two extra rolls per turn, provided the "Triple Six" rule is not triggered.
* **Exact Finish Constraint**: The `GetPosition` function returns `-1` if a move exceeds square 100; the engine then ensures the player stays at their current position.
* **Fair Dice Logic**: Uses the Mersenne Twister engine (`mt19937`) with a high-resolution clock seed to provide a uniform distribution for all dice rolls.

## 🛠️ Build, Execution, and Initialization

### File Structure
The project is organized into a modular directory structure to maintain a clean separation between headers and source logic:
* **`headers/`**: Contains the class definitions for `Game`, `Player`, and `Element`.
* **`src/`**: Contains the core implementation logic for the game engine (`Game.cpp`).
* **`main.cpp`**: The entry point that handles file stream initialization and starts the game loop.
* **`Makefile`**: Automates the compilation process using `g++`.

### Build Instructions
The included `Makefile` defines variables for the compiler and flags to streamline the build process:
```bash
# Compile the project and generate the 'snake_and_ladder' executable
make all

# Run the simulation using the sample input file
make run

# Clean up object files and the executable
make clean
```


## 🕹️ Gameplay Demo

### ⚙️ Initial Setup
* **Board Size**: 100 squares (Indices 1-100).
* **Participants**: Amit, Anand, Priyanshi, Aditi, Gaurav, and Sagar.
* **Environment**: 9 Snakes (e.g., 62 → 5) and 8 Ladders (e.g., 2 → 37) are mapped onto the grid.

### 🔄 Execution Trace Example
1.  **Standard Movement**: If **Amit** rolls a 4, the engine updates his position from 0 to 4.
2.  **Ladder Climb**: If **Anand** rolls a 2, he lands on square 2. The `GetPosition` function detects the ladder and immediately moves him to **37**.
3.  **Bonus Turns**: If **Priyanshi** rolls a 6, she moves forward and is granted an immediate extra roll.
4.  **The "Triple Six" Rule**: If **Aditi** rolls three 6s in a row, the `Play` function triggers the `steps == 3` condition, resetting her to her original position for that turn.
5.  **Snake Bite**: If **Gaurav** lands on square 62, the grid logic automatically slides him down to square **5**.
6.  **Exact Finish**: If **Sagar** is at square 98 and rolls a 5, the `GetPosition` function returns `-1`, and he remains at **98** because the roll exceeds the target of 100.
7.  **Victory**: The first player to land exactly on square **100** triggers the win condition, and the game terminates.

### 🖥️ Example Console Output
```text
Game Setup Complete ! Proceeding to Playground

Amit rolled a 2, and moved from 0 to 37

Anand rolled a 6, 4, and moved from 0 to 10

Aditi rolled a 6, 6, 6, and remained at 0

...

Amit rolled a 3, and moved from 97 to 100

Amit Wins !

Game Over !
```
![istockphoto-531466314-1024x1024](https://github.com/user-attachments/assets/0eab3627-330d-44a4-ada7-e59908ce0a49)
