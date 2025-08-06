#include <iostream>
#include <vector>
using namespace std;

int largestEqualAreaSubmatrix(vector<vector<int>> &matrix)
{
    int rows = matrix.size();
    int cols = matrix[0].size();

    // Step 1: Create the modified matrix (dp)
    vector<vector<int>> dp(rows, vector<int>(cols));
    dp[0][0] = matrix[0][0] == 0 ? -1 : 1;

    for (int i = 1; i < rows; i++)
    {
        dp[i][0] = dp[i - 1][0] + (matrix[i][0] == 0 ? -1 : 1);
    }

    for (int j = 1; j < cols; j++)
    {
        dp[0][j] = dp[0][j - 1] + (matrix[0][j] == 0 ? -1 : 1);
    }

    for (int i = 1; i < rows; i++)
    {
        for (int j = 1; j < cols; j++)
        {
            int val = (matrix[i][j] == 0) ? -1 : 1;
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + val;
        }
    }

    int maxArea = 0;

    // Step 2: Iterate through all pairs of rows and columns
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            for (int k = i; k < rows; k++)
            {
                for (int l = j; l < cols; l++)
                {
                    int sum = dp[k][l];
                    if (i > 0)
                        sum -= dp[i - 1][l];
                    if (j > 0)
                        sum -= dp[k][j - 1];
                    if (i > 0 && j > 0)
                        sum += dp[i - 1][j - 1];

                    if (sum == 0)
                    {
                        int area = (k - i + 1) * (l - j + 1);
                        maxArea = max(maxArea, area);
                    }
                }
            }
        }
    }

    return maxArea;
}

int main()
{
    // Test the code with an example matrix
    vector<vector<int>> matrix = {
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 1},
        {1, 1, 0, 0, 1},
        {0, 0, 0, 0, 0}};

    int largestArea = largestEqualAreaSubmatrix(matrix);
    cout << "Largest area of a rectangular submatrix with equal number of 1's and 0's: " << largestArea << endl;

    return 0;
}
