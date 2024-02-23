# A Q-Learning Implementation for Travelling Salesman Problem

This project aims to solve the Travelling Salesman Problem (TSP) using two algorithms, including a greedy approach and a reinforcement learning (RL)-like implementation.

## Overview

The project consists of several C++ source files organized into different modules:

- **Main.cpp**: Entry point of the program. Reads data from a file and invokes the RL-based algorithm.
- **RL.cpp**: Contains the implementation of the RL-like algorithm for solving the TSP.
- **Travel.cpp**: Implements an old version of the TSP solver using a greedy approach.
- **Helpers.cpp**: Provides helper functions used by the main algorithms.
- **ReadFile.cpp**: Reads input data from a CSV file.
- **Headers**: Header files containing function declarations and necessary includes.

## Algorithm Implementations

### Reinforcement Learning (RL)

The RL algorithm employs a Q-learning-like approach to learn an optimal policy for visiting cities in the TSP. It utilizes a Q-table to estimate the value of taking a particular action (visiting a city) in a given state (current city).

### Greedy Approach

The greedy algorithm iteratively selects the next city to visit based on the closest available neighbor, aiming to minimize the total distance travelled.

## Usage

To compile and run the program, follow these steps:

1. Ensure you have a C++ compiler installed (e.g., g++).

2. Clone the repository to your local machine.

3. Navigate to the project directory in your terminal.

4. The program will read data from the "DistancesBetweenCities.csv" file (adjust path if necessary), apply the RL algorithm, and output the results.

5. Compile the source files using the provided Makefile:
    ```
    make all
    ```

6. Run the executable:
    ```
    ./main
    ```
    
