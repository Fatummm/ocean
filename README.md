# Living Ocean
There is a **Living ocean** realization on C++

---

## Navigation
- [Game description](#game-descrption)
- [How to install and run](#how-to-install-and-run)
- [Game realization](#game-realization)
- [Technologies stack](#technologies-stack)

## Game Description
__Living ocean__ is a simulation of a real ocean

There you can watch how algaes grow, fish-herbivores eat them and reproduce, and how fish-predators hunt herbivores.


## How to Install and Run
:bangbang:This projects works __ONLY on Linux__:bangbang:

1. Firstly, install SFML for C++:
    ```
    sudo apt-get install libsfml-dev
    ```
    If this command __doesn't work__, visit [official SFML site](https://www.sfml-dev.org/tutorials/3.0/getting-started/linux/#installing-sfml).

2. Then install CMake:
    ```
    sudo apt install cmake
    ```
3. Clone this repository and open it
4. Create `build` directory and open it:
    ```
    mkdir build
    cd build
    ```
5. Open `/build` and run:
    ```
    cmake ..
    make
    ```
6. To Run the app, leave build and run the app file:
    ```
    ./Ocean
    ```

## Game Realization
1. OOP, with inheritance and polymorphism
2. PIMPL & unique_ptr
3. Rule Of Five
4. Templates for fish
5. Exceptions
6. RAII: live cycle of an object - constructors, destructors
7. Realization via SFML - Speed and Fast Multimedia Library
8. Logs in "output.log"


## Technologies Stack
- CMake for creating project
- SFML for GUI
- Pure C++
- Aseprite for creating sprites' images
