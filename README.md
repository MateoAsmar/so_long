# so_long
## Grade: 100/100
![solong](https://github.com/user-attachments/assets/e8985ca7-7326-4370-b30e-b719ec2af8bb)

## Overview

**so_long** is a 2D game project developed as part of the 42 curriculum. The goal is to create a minimalistic game using the MiniLibX library, where the player navigates through a map loaded from a `.ber` file. The project emphasizes robust map validation, efficient memory management, and real-time graphical rendering—all while strictly following the 42 Norm.

## Features

### Map Validation
- **Rectangular Map:** Ensures that every row in the map is of the same length.
- **Wall Check:** Verifies that the map is fully enclosed by walls.
- **Item Validation:** Uses a flood fill algorithm to ensure that all key items (exit and collectibles) are accessible from the player’s starting position.

### Graphical Rendering
- **Texture Loading:** Renders various textures (player, exit, collectibles, floor, and wall) using MiniLibX.
- **Window Management:** Creates and manages a game window that adjusts based on the map’s dimensions.
- **Real-time Updates:** Continuously updates the game state and displays the move count on-screen.

### Player Interaction
- **Keyboard Input:** Supports player movement in all four directions with real-time feedback.
- **Collision Detection:** Handles interactions with walls and other map elements to ensure valid movement.
- **Move Logging:** Displays the current move count as the player navigates through the map.

## Project Details

- **Language:** C
- **Compilation:** Use the provided Makefile. The project is compiled with flags `-Wall -Wextra -Werror` along with MiniLibX.
- **Norm Compliance:** All code strictly adheres to the 42 Norm.
- **Testing:** Extensively tested with various map configurations to guarantee robustness and correct behavior.

## Usage

***To compile so_long:***

```bash
make
```

***To run so_long:***
```bash
./so_long path_to_map.ber
```

## File Structure
**so_long.c:**

Entry point of the game. Initializes game resources, validates the map, and starts the game loop.

**so_long.h:**

Header file containing structure definitions, function prototypes, and necessary macros for the project.

**window.c:**

Manages the graphical window and renders game elements by loading textures and drawing the map.

**parsing.c:**

Reads and validates the map file. Processes command-line arguments and prepares the map for the game.

**player.c:**

Handles the player’s position, movement, and interactions with items on the map.

**moves.c:**

Processes keyboard input and updates the player’s position and game state accordingly.

**flood_fill.c:**

Implements the flood fill algorithm to ensure that all critical areas (exit and collectibles) are accessible.

**FandD.c:**

Contains functions to free allocated resources and gracefully exit the game.

**errors.c:**

Provides error handling routines to validate the map and manage game state issues.

**utils.c:**

Utility functions for string manipulation, memory allocation, and other helper operations.

**get_next_line.c:**

Reads files line by line, used for processing the map file.

**Makefile:**

Automates the build process for the project

## What I Learned
**Working on **so_long** allowed me to deepend my understanding of:**

**Graphical Programming:** Learning to work with MiniLibX for window creation and real-time rendering.

**Memory Management:** Implementing robust dynamic memory management and avoiding memory leaks.

**Algorithm Design:** Using flood fill for map validation to ensure accessibility of game elements.

**Error Handling:** Designing and implementing comprehensive error checking and cleanup routines.

**Coding Standards:** Adhering to strict coding norms and best practices as required by the 42 curriculum.

## Conclusion
The so_long project was a challenging yet rewarding experience that expanded my skills in C programming, real-time graphics, and game development. It pushed me to combine algorithmic problem-solving with system-level programming while maintaining high coding standards—a truly invaluable learning journey.
