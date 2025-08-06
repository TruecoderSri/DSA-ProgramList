class Solution
{
public:
    // Function to return a list of indexes denoting the required
    // combinations whose sum is equal to given number.
    vector<vector<int>> combinationSum(vector<int> &A, int B)
    {
        // Your code here
        vector<vector<int>> ans;
        vector<int> path;
        sort(A.begin(), A.end());
        backtracking(A, B, 0, path, ans);
        return ans;
    }
    void backtracking(vector<int> &A, int B, int pos, vector<int> &path, vector<vector<int>> &ans)
    {
        if (pos == A.size())
        {
            if (B == 0)
            {
                ans.push_back(path);
            }
            return;
        }

        if (A[pos] <= B)
        {
            path.push_back(A[pos]);
            backtracking(A, B - A[pos], pos, path, ans);
            path.pop_back();
        }
        backtracking(A, B, pos + 1, path, ans);
    }