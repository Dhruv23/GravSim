# Gravity Simulator

A fully custom-built C++ gravity simulator with 2D physics logic rendered in 3D using OpenGL. Built from scratch with modular components, this project simulates gravitational interactions between celestial bodies on a 2D plane and visualizes them with depth and lighting in a 3D space.

---

## Features

- Uses Newton's Laws of Gravitation for Physics simulations
- Modular architecture with separate classes for:
  - `Vector2`: Core math for 2D vector operations [FINISHED]
  - `Body`: Represents a physical object with mass, velocity, and position [FINISHED]
  - `Simulation`: [Planned] Governs the gravitational interactions between all bodies
  - `Renderer`: [Planned] Real-time OpenGL-based visualizer
- [Planned] Time-stepped physics with Euler integration
- Force application, collision detection, and motion updates
- Unit tests for each core class (`Vector2Test`, `BodyTest`, etc.)
---

## Coordinate System
All physics is simulated in **2D (X/Y plane)**, but rendered in **3D space** using OpenGL. This allows full use of shaders, lighting, and camera effects while keeping the physics simple and efficient.

