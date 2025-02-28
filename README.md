# Shape List

This project implements a simplified drawing canvas that manages a list of shapes to be "drawn" on the screen. A linked list (via the CanvasList class) maintains a collection of Shape objects, including derived classes such as Circle, Rectangle, and RightTriangle.

## Overview

- **Shape Hierarchy**:

  - **Shape**: The base class providing common functionality (e.g., printing, copying).
  - **Rectangle, Circle, RightTriangle**: Derived classes that implement specific details for each shape type.

- **CanvasList**:  
  A linked list implementation that holds Shape nodes. It supports operations like:
  - Adding shapes to the front or back.
  - Inserting shapes at specific positions.
  - Removing shapes (e.g., pop, remove at index, remove every other node).
  - Drawing shapes (displaying their details).
  - Printing memory addresses for debugging.

## Primary Topics

- Object-Oriented Programming
- Linked Lists and Dynamic Memory Management
- Test-Driven Development (using the Catch framework)

## Functionalities

- **Shape Class and Derived Classes**:  
  Implements constructors, destructors, a copy function, and print methods to display shape details.

- **CanvasList Class**:  
  Manages a linked list of shapes with functions to:
  - Draw the list (output the details of each shape).
  - Print the addresses of the nodes and their associated shapes.
  - Insert and remove shapes at specified positions.
  - Clear the list to free allocated memory.

## Submission Guidelines

Submit the following files to Gradescope:

- `shape.h`
- `canvaslist.h`
- `shape.cpp`
- `canvaslist.cpp`
- `tests.cpp`

**Requirements**:

- Do not change the provided public class declarations.
- Use proper function decomposition and helper functions where needed.
- Ensure your implementation produces a clean valgrind report (no memory leaks or errors).
- Follow the coding style and documentation requirements outlined in the project description.

HappyCoding!
