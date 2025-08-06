class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        vector<int> ans;
        int top = 0, down = n - 1;
        int left = 0, right = matrix[0].size() - 1;
        int dir = 0;
        int i, j;
        while (left <= right && top <= down)
        {
            if (dir == 0)
            {
                for (i = left; i <= right; i++)
                    ans.push_back(matrix[top][i]);
                top++;
            }
            else if (dir == 1)
            {
                for (i = top; i <= down; i++)
                    ans.push_back(matrix[i][right]);
                right--;
            }
            else if (dir == 2)
            {
                for (i = right; i >= left; i--)
                    ans.push_back(matrix[down][i]);
                down--;
            }
            else if (dir == 3)
            {
                for (i = down; i >= top; i--)
                {
                    ans.push_back(matrix[i][left]);
                    left++;
                }
            }
            dir = (dir + 1) % 4;
        }
        return ans;
    }
};