/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    void solve(TreeNode *root, vector<long long int> path, int k, int &count)
    {
        if (!root)
            return;
        path.push_back(root->val);
        solve(root->left, path, k, count); // push the elements in the vector
        solve(root->right, path, k, count);

        long long int sum = 0;
        // iterate the vector to check the given sum
        for (int i = path.size() - 1; i >= 0; i--)
        {
            sum += path[i];
            if (sum == k)
            {
                count++;
            }
        }
    }

    int pathSum(TreeNode *root, int targetSum)
    {
        vector<long long int> path;
        int c = 0;
        solve(root, path, targetSum, c);
        return c;
    }
};