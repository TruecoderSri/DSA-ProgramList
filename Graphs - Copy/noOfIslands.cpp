#include <bits/stdc++.h>
using namespace std;
// TC:O(8*N^2)
// SC:O(N^2)

void dfs(int row, int col, vector<vector<char>> &grid)
{

    int n = grid.size();

    int m = grid[0].size();

    if (row >= 0 && col >= 0 && row < n && col < m && grid[row][col] == '1')
    {

        grid[row][col] = '0';
        for (int i = -1; i <= 1; i++)
        {

            for (int j = -1; j <= 1; j++)
            {

                int nrow = row + i;

                int ncol = col + j;

                dfs(nrow, ncol, grid);
            }
        }
    }
}

int numIslands(vector<vector<char>> &grid)
{

    // Code here

    int n = grid.size();

    int m = grid[0].size();

    int count = 0;

    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < m; j++)
        {

            if (grid[i][j] == '1')
            {

                count++;

                dfs(i, j, grid);
            }
        }
    }

    return count;
}
