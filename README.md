# DFS-in-Graphs
## Depth First Search Operation in Graphs
## SUBJECT: Maze Problem with Graph
## PROBLEM: 
In this work, an algorithm will be designed to find out whether there is a path from the starting cell (1,1) to the ending cell (N, N) by DFS (Depth First Search) method for a given N number and a given NxN maze. Perform DFS with a recursive approach. The semi-code for the recursive DFS operation is as follows:
***DFS (to visit a vertex v)
{
Mark v as visited
Recursively visit all unmarked vertices w adjacent to v
}***
## METHOD
  * For NxN matrix, [N+1]x[N+1] is defined in the main function.
  * For the target path, NxN matrix is defined and all cells assigned as 0 value.
  * All cells are scanned until [N-1]x[N-1] is reached.
  * Neighboring cells of each cell, east, west, north, and south, are looked at in turn.
  * The neighbor with a value of 1 is selected and the same operations are repeated recursively.
  * When the dead end is reached, return the previous cell and make it 0.
  * When reach the last cell, if the cell value is 1, the return value from the function is 1 and the target path matrix is printed on the screen.
## FLOW CHART

![image](https://user-images.githubusercontent.com/27871676/126899123-86f644a9-04ef-46ff-92ad-b4ddb2cdf6ad.png)
## PROGRAM CODE
Functions that perform the application:
* **main():**
When the program is run, the user is prompted to enter paths. Outer frame defined as 0 because it will form walls. So, for NxN matrix, user enters [N-2]x[N-2] value.
* **drawPath():**
At first, the target path matrix defined as 0. If the target path that reach the destination is found, the last cell will be 1. In other cases all cells of the matrix will remain 0.
* **findPath():**
This function works recursively. For the current cell, check all 4 neighbors in turn, and the cell in that direction becomes active and the function calls itself in whichever direction there is a road. If the PATH_FIND function returns 0, the cell value becomes zero and returns to the previous cell. Since that cell has already been visited, look the cells that are not visited.
For example, if the cell being looked at is west and there is no way out, return the previous cell, if there are any unvisited cells other than the west, look them. If there is no cell that is not looked at, that cell also resets itself and the process is repeated until it reaches the starting cell.
* **checkWay():**
The values of the matrix are checked and based on the values that have marked as:
Walls : '-' and '|'
Rooms : ' '
Corners of rooms: '+',
Start : 'x'
Finish : 'X'
Followed Path: 'I'
Finally; If the last cell is reached, we draw the path and show it on the screen as output. If there is no path, the matrix with all cells 0.
## OUTPUTS
![image](https://user-images.githubusercontent.com/27871676/126899387-e698d8b6-21dc-4ade-b998-a6d4b1d1a014.png)

## CONCLUSION
* In order to find the target path in the [N][N] maze matrix, X element starts scanning from [N+1][N+1].
* The same operations are repeated for the subproblems x[0]-x[j-1] and x[j+1]-x[n-1]. 
* As a result, the data group is sorted.
* If we are lucky, there is a path to the result for each first neighbor chosen (i.e. the matrix has a value of 1) and log2n iterations will be = O(nlog2n).
* In the worst case, that is, when all neighbors are visited and the right path is found for the last neighbor, complexity is 4xO[N2].
