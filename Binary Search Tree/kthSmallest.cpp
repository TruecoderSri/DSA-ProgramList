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
    int count = 0;
    int ans;
    // since the count and ans variable is cont. changing
    void solve(TreeNode *root, int &count, int k, int &ans)
    {

        if (!root)
            return;

        // inorder traversal
        kthSmallest(root->left, k);

        count++;
        if (count == k)
            ans = root->val;

        kthSmallest(root->right, k);
    }

    int kthSmallest(TreeNode *root, int k)
    {

        solve(root, count, k, ans);
        return ans;
    }
};