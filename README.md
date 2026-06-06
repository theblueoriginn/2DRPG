# 2D TURN BASED RPG GAME WITH SFML ENGINE

A proof of concept 2D RPG game engine built from scratch using Modern C++ and SFML.This project focuses on turned based rpg combat system, sound and animation and simple physics systems.

## Milestones

### State-Driven Scene Management
Implemented a custom state machine utilizing strongly typed enums (`enum class scene`) to decouple game logic. The engine dynamically switches core loops between `Map Rendering` (exploration mode) and `Fight Infrastructure` (turn-based combat state) based on runtime events.

### Vector Based Collision Detection
* Custom delta-time (`dt`) dependent movement algorithm ensures frame-rate independent physics execution.
* Utilizes vector mathematics to handle distance checking (`.length()`) between entities, dynamically triggering scene transitions when within a specific interaction radius (`INTERACTION_DISTANCE`).

### Audio & Animation Pipeline
* Integrated asynchronous sound buffer management (`sf::SoundBuffer`) to fire spatial sound effects dynamically during entity movement.
* Mathematical sprite-sheet indexing using modulus operations (`currentIndex % frames`) to cycle walking and idle animations with automatic ayna (mirror) scaling for bidirectional movement.

### Tiled Map System
* tinytmx library 


## Core Stack
* **Language:** C++17 
* **Graphics & Audio :** SFML (Simple and Fast Multimedia Library)
* **Build System:** MSBuild / Visual Studio 

Used Libraries/APIS:
tinytmx: https://github.com/KaseyJenkins/tinytmx
