#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
BinaryTreeNode<int> *helper(BinaryTreeNode<int> *root,int val,int &k){
    if(!root)
        return NULL;
    BinaryTreeNode<int>*temp=NULL;
    
    if((root->data==val)||(temp=helper(root->left,val,k))
        ||(temp=helper(root->right,val,k))){
        if(k==0){
            k=INT_MAX;
            return root;
        }
        k--;
        return temp?temp:root;
    }
    return NULL;
}

int findKthAncestor(BinaryTreeNode<int> *root, int targetNodeVal, int k) {
    // Write your code here.
    BinaryTreeNode<int>* ans=helper(root,targetNodeVal,k);
    int a=ans->data;
    if(!a||a==targetNodeVal)
           return -1;
    return a;
}












