#include <iostream>
#include <vector>
using namespace std;
#define col 5
#define row 5
// program to print the no of clusters of 1(islands) with restricted diagonal movement
//  time complexity O(row.col) ,space complexity O(row.col)
void currentisland(int matrix[][col], int i, int j, int r, int c)
{
    if (i < 0 || i > r || j < 0 || j > c || matrix[i][j] != 1) // boundary conditions
        return;
    matrix[i][j] = 2; // mark 2 to ensure it is visited

    // recursive call to check the size of the island
    currentisland(matrix, i, j - 1, r, c); // TOP
    currentisland(matrix, i + 1, j, r, c); // RIGHT
    currentisland(matrix, i, j + 1, r, c); // DOWN
    currentisland(matrix, i - 1, j, r, c); // LEFT
}
int numIslands(int grid[][col])
{

    int i, j, island = 0; // variable to store the no of islands
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            if (grid[i][j] == 1)
            {
                currentisland(grid, i, j, row, col); // we check in all the directions
                island++;
            }
        }
    }
    return island;
}
int main()
{
    int M[][col] = {{1, 1, 0, 0, 0},
                    {0, 1, 0, 0, 1},
                    {1, 0, 0, 1, 1},
                    {0, 0, 0, 0, 0},
                    {1, 0, 1, 0, 1}};
    cout << "the no of islands:" << numIslands(M);
    return 0;
}
