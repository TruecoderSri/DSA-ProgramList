#include <iostream>
#include <vector>
using namespace std;
// program to display the max path bw 2 points using backtracking

void Longestpath(int r, int c, vector<vector<int>> matrix, vector<vector<bool>> visited, int crow, int ccol, int dx, int dy, int pathlength, int &ans)
{
    if (crow == dx && ccol == dy)
    {
        if (pathlength > ans) // since maxpath is to be calculated so we do this
            pathlength = ans;
        return;
    }

    if (crow < 0 || ccol < 0 || matrix[crow][ccol] == 0 || visited[crow][ccol] || crow >= r || ccol >= c) // safe condition
        return;

    visited[crow][ccol] = true;
    Longestpath(r, c, matrix, visited, crow, ccol + 1, dx, dy, pathlength + 1, ans);
    Longestpath(r, c, matrix, visited, crow, ccol - 1, dx, dy, pathlength + 1, ans);
    Longestpath(r, c, matrix, visited, crow - 1, ccol, dx, dy, pathlength + 1, ans);
    Longestpath(r, c, matrix, visited, crow + 1, ccol, dx, dy, pathlength + 1, ans);
    visited[crow][ccol] = false; // Backtracking ie erasing the signs of previous path and then carrying another path traversal

    return;
}

int main()
{
    int r, c;
    int sx, sy, dx, dy;
    cin >> r >> c;
    vector<vector<int>> matrix(r, vector<int>(c, 0)); // 2d vector for matrix
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> matrix[i][j];
        }
    }

    cin >> sx >> sy; // SOURCE COORDINATES
    cin >> dx >> dy; // DEST. COORDINATES
    vector<vector<bool>> visited(r, vector<bool>(c, false));
    int ans = INT_MIN;

    if (matrix[sx][sy] == 0)
        cout << "source is a hurdle";

    else
    {
        Longestpath(r, c, matrix, visited, sx, sy, dx, dy, 0, ans);
        cout << "maximum possible distance of the 2 points are";
        cout << ans;
    }
    return 0;
}