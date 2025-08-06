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
    TreeNode *deleteNode(TreeNode *root, int key)
    {

        if (!root)
            return NULL;
        if (root->val == key)
        {
            return helper(root);
        }
        TreeNode *temp = root;
        while (root != NULL)
        // perform the search of the key in the tree
        {
            if (root->val > key) // searching in BST
            {
                if (root->left != NULL && root->left->val == key)
                {
                    root->left = helper(root->left); // link the node with the lower part of the deleted Node
                    break;
                }
                else
                {
                    root = root->left;
                }
            }
            else
            {
                if (root->right != NULL && root->right->val == key)
                {
                    root->right = helper(root->right); // link the node with the lower part of the deleted Node
                    break;
                }
                else
                {
                    root = root->right; // else just traverse the tree until the node is found
                }
            }
        }
        return temp;
    }

    TreeNode *helper(TreeNode *root)
    {
        // if anyone of them doesn't exist pass the other one
        if (!root->left)
        {
            return root->right;
        }
        if (!root->right)
        {
            return root->left;
        }
        // link the first left element of left part with the smallest val i.e leftmost part of the right portion.
        TreeNode *leftchild = root->left;
        TreeNode *lastleft = lastChild(root->right);
        lastleft->left = leftchild;

        return root->right;
    }
    // func to access the leftmost element in the right portion of tree
    TreeNode *lastChild(TreeNode *root)
    {
        if (root->left == NULL)
        {
            return root;
        }
        lastChild(root->left);
    }
};