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
                if (x >= 0 && x < n && y >= 0 && y < m) {
                  dfs(nrow, ncol, grid);
                }
               
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

// 2nd Approach

class Solution {
public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    void dfs(int i, int j, vector<vector<char>>& grid,
             vector<vector<bool>>& vis, int m, int n) {

        vis[i][j] = true;

        for (int k = 0; k < 4; k++) {
            int newx = i + dx[k];
            int newy = j + dy[k];

            if (newx >= 0 && newx < m && newy >= 0 && newy < n &&
                !vis[newx][newy] && grid[newx][newy] == '1') {
                dfs(newx, newy, grid, vis, m, n);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int cnt = 0;
        vector<vector<bool>> vis(m, vector<bool>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1' && !vis[i][j]) {
                    cnt++;
                    dfs(i, j, grid, vis, m, n);
                }
            }
        }
        return cnt;
    }
};
