#include <bits/stdc++.h>
class Solution
{
public:
    // TC:O(N*M)
    // SC:0(N*M)

    void DFS(vector<vector<int>> &ans, vector<vector<int>> &image, int sr, int sc, int initColor, int color, int rowC[], int colC[])
    {
        ans[sr][sc] = color;
        int n = image.size();
        int m = image[0].size();
        for (int i = 0; i < 4; i++)
        {
            int newR = sr + rowC[i];
            int newC = sc + colC[i];
            // check the value is within limits and the color is not visited before and it is same as starting color
            if (newR >= 0 && newR < n && newC >= 0 && newC < m && ans[newR][newC] != color && image[newR][newC] == initColor)
            {
                DFS(ans, image, newR, newC, initColor, color, rowC, colC);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        int initColor = image[sr][sc];
        vector<vector<int>> ans = image;
        //    to cover all 4 directions in a matrix
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        DFS(ans, image, sr, sc, initColor, color, delRow, delCol);
        return ans;
    }
};