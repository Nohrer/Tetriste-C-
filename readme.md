**Tetriste**
This is a C++ implementation of a game where pieces of different shapes and colors are arranged in a circular linked list. The goal is to remove groups of three or more pieces with the same shape or color.

**Table of Contents**

- Features
- Getting Started
- Game Controls
- Technical Details
- Circular Linked List
- Piece Rotation
- Piece Generation and Removal

  **Features**

- Circular linked list data structure to store the game pieces
- Ability to add, insert, and delete pieces
- Automatic removal of groups of three or more pieces with the same shape or color
- Score tracking
- Piece generation and rotation
  **Getting Started**
  1- Compile the main.cpp file using a C++ compiler.
  2- Run the executable to start the game.

  **Game Controls**

- Q: Place the next piece on the left side of the list
- D: Place the next piece on the right side of the list
- R: Rotate the pieces
- C: Rotate the pieces by color
- S: Rotate the pieces by shape
- Esc: Quit the game

**Technical Details**

- Circular Linked List
  The game uses a circular linked list to store the game pieces. Each piece is represented by a Piece object, which holds the shape and color of the piece. The Node class represents a node in the linked list, and the CircularLinkedList class manages the operations on the list.

- Piece Rotation
  The turnRight and turnLeft functions in the CircularLinkedList class handle the rotation of the pieces. They identify the pieces with the specified shape or color, and then rearrange their order in the list.

- Piece Generation and Removal
  The generatePiece function creates a new random piece, and the check function removes groups of three or more pieces with the same shape or color. The startGame function initializes the game by adding the first piece to the list.
