**Maze Path Finder**

You are given a maze as N × M binary matrix of blocks and there is a rabbit initially at
(0, 0) and the rabbit wants to eat carrot which is present at some given block (fx, fy) in the
maze. In a maze matrix, 0 means that the block is a dead end and 1 means that the block
can be used in the path. The rabbit can move in any non-diagonal direction to the blocks
that are not dead end.

This maze will check if there exists any path so that the rabbit can reach the carrot or not.
It is not needed to print the path. You must use the built-in stack class to solve this
question.

Input and output
The program takes several inputs.
1. Number of rows (N) and columns (M) of the maze
2. 2D array representing the maze
3. Position of the carrot (row, column)

If there is a path from rabbit to carrot the program should print “Path Found”, Otherwise
it should print “No Path Found”.
