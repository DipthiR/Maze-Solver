# Maze-Solver

## Maze Solver (C++)

A Maze Solver program written in C++ that finds the shortest path between a start (S) and end (E) point in a maze using Breadth-First Search (BFS).

## Features

 Solves any rectangular maze with walls #, open paths ., start S, and end E.

 Uses BFS to guarantee the shortest path.

 Prints the maze with the solution path marked using *.

 Simple and efficient implementation.

## Tech Stack

Language: C++

Algorithm: BFS (Breadth-First Search)

## How to Run

Clone this repository:

git clone https://github.com/your-username/maze-solver.git
cd maze-solver


Compile the program:

g++ maze_solver.cpp -o maze_solver


Run the program:

./maze_solver

## Example Maze
##########
#S...#...#
#.#.#.#..#
#.#...#..#
#.#####..#
#.....#..#
###.#.####
#...#....#
#.###.##E#
##########

## Example Output
Solved Maze:
##########
#S***#...#
#*#*#.#..#
#*#***#..#
#*#####..#
#*****#..#
###*#.####
#***#....#
#*###.##E#
##########


(* marks the path taken)
