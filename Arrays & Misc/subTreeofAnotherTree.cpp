/**
 * Definition for a binary tree node.
 * structhttps://assets.leetcode.com/uploads/2021/04/28/subtree1-tree.jpg TreeNode {
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
    bool checksubTree(TreeNode *root, TreeNode *subroot)
    {
        if (!root && !subroot)
            return true;
        if (!root || !subroot)
            return false;
        if (root->val != subroot->val)
            return false;

        return checksubTree(root->left, subroot->left) && checksubTree(root->right, subroot->right);
    }

    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {

        if (!root || !subRoot)
            return false;
        if (checksubTree(root, subRoot))
            return true;
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};