# Circle the Cat

**Circle the Cat** is a strategic game where the objective is to trap a virtual cat on a hexagonal grid by blocking its potential moves. The game is structured into three main parts, focusing on data structures, game logic, and graphical display. Written in **C++** (CMake)

---

## Game Overview

The game consists of the following key components:

### 1. **Data Structures**
- **Node:**  
  Represents a vertex in the graph, forming the foundation of the game's grid.
  
- **Graph Class:**  
  A generic class for handling a graph of nodes. Key features include:  
  - **Efficient Pathfinding:** Implements a fast search for a path from a source to a target using a BFS-based algorithm.  
  - **Versatility:** Designed to support the game's dynamic requirements with a focus on performance.  

---

### 2. **Game Logic**
- **circleTheCat:**  
  This class manages the game flow and logic, including:
  - Queuing and processing each player's move.
  - Validating the game's rules at every step.
  - Supporting the **Undo** functionality, allowing players to backtrack their moves.  

---

### 3. **Graphical Display**
- **Display Module:**  
  - Handles all visual rendering for the game.  
  - Fully isolated from the game's data structures (`Node`, `Graph`).  
  - Designed to be modular and somewhat generic for potential reuse in other applications.  

---

## How to Play

1. **Start the Game:**  
   Launch the game through the game manager, which initializes the grid and places the cat.  

2. **Objective:**  
   The goal is to strategically block the cat's potential moves and prevent it from escaping the grid.  

3. **Controls:**  
   - Place a block by clicking on a tile.  
   - Use the **Undo** button to revert a move.  

4. **Winning:**  
   The player wins if the cat is completely surrounded and cannot move.  

---

## Technical Details

### Algorithms and Efficiency
- The **Graph Class** employs a Breadth-First Search (BFS) algorithm to quickly calculate paths and validate potential moves.  
- The separation of logic, data structures, and display ensures clean and maintainable code.  

---
