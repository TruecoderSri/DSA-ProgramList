#include <iostream>
#include <vector>
using namespace std;
#define col 5
#define row 5
void fillwithNewchar(char matrix[][col], int i, int j, char prevc, char newc)
{
    if (i < 0 || i > row || j < 0 || j > col) // boundary conditions
        return;
    if (matrix[i][j] != prevc)
        matrix[i][j] = newc; // mark 2 to ensure it is visited

    // recursive call to check the size of the island
    fillwithNewchar(matrix, i, j - 1, prevc, newc); // TOP
    fillwithNewchar(matrix, i + 1, j, prevc, newc); // RIGHT
    fillwithNewchar(matrix, i, j + 1, prevc, newc); // DOWN
    fillwithNewchar(matrix, i - 1, j, prevc, newc); // LEFT
}
void replacesurr(char grid[][col])
{

    int i, j;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            if (grid[i][j] == 'O')
            {
                grid[i][j] = '-'; // replace every O with '-'
            }
        }
    }

    // check for every boundary conditions and replace with the new char
    for (int i = 0; i < row; i++)
        if (grid[i][0] == '-')
            fillwithNewchar(grid, i, 0, '-', 'O');
    for (int j = 0; j < col; j++)
        if (grid[0][j] == '-')
            fillwithNewchar(grid, 0, j, '-', 'O');
    for (int i = 0; i < row; i++)
        if (grid[i][col - 1] == '-')
            fillwithNewchar(grid, i, col - 1, '-', 'O');
    for (int j = 0; j < col; j++)
        if (grid[row - 1][j] == '-')
            fillwithNewchar(grid, row - 1, j, '-', 'O');
    // whichever char is found
    for (i = 0; i < row; i++)
        for (j = 0; j < col; j++)
            if (grid[i][j] == '-')
                grid[i][j] = 'X';
}
int main()
{
    char mat[][col] = {
        {'X', 'O', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X', 'O'},
        {'X', 'X', 'X', 'O', 'X'},
        {'O', 'X', 'X', 'X', 'X'},
        {'X', 'X', 'X', 'O', 'X'}

    };
    replacesurr(mat);
    int i, j;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            cout << mat[i][j] << " ";
        }
    }
    return 0;
}
