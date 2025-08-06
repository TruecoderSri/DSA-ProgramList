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
    bool check(TreeNode *root, long long l, long long r)
    {

        if (!root)
            return true;
        // JUST CHECK THE RANGE OF THE 2 SUB-TREES TO VALIDATE
        if (root->val >= r || root->val <= l)
            return false;
        return check(root->left, l, root->val) && check(root->right, root->val, r);
    }

    bool isValidBST(TreeNode *root)
    {

        long long l = LONG_MIN;
        long long r = LONG_MAX;

        return check(root, l, r);
    }
};