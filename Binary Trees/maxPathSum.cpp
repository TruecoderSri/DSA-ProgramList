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
class Solution {
public:
    
    int maxpath(TreeNode *root,int &maxi){
        if(!root )
            return 0;
        //DFS Traversal
        int leftsum=max(0,maxpath(root->left,maxi));
        int rightsum=max(0,maxpath(root->right,maxi));
        //update the maxi after each call
        maxi=max(maxi,root->val+leftsum+rightsum);
        //return the max of the nodes's value
        return root->val+max(leftsum,rightsum);
        
    }
    
    int maxi=INT_MIN;
    int maxPathSum(TreeNode* root) {
    
        maxpath(root,maxi);
        return maxi;
        
    }
};