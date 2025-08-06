
// start from the end of the postorder which is bound to be the root then the lefthand side of root in inorder will make up the
// left tree and the right half accounts for the right half of the tree

class Solution
{
public:
    Node *constructTree(int post[], int postStart, int postEnd, int in[], int inStart, int inEnd, unordered_map<int, int> mp)
    {

        if (inStart > inEnd || postStart > postEnd)
            return NULL;

        Node *root = new Node(post[postEnd]);
        int elem = mp[root->data];
        int lLen = elem - inStart;

        root->left = constructTree(post, postStart, postStart + lLen - 1, in, inStart, elem - 1, mp);
        root->right = constructTree(post, postStart + lLen, postEnd - 1, in, elem + 1, inEnd, mp);

        return root;
    }

    // Function to return a tree created from postorder and inoreder traversals.
    Node *buildTree(int in[], int post[], int n)
    {
        // Your code here
        int inStart = 0, inEnd = n - 1;
        int postStart = 0, postEnd = n - 1;

        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++)
            mp[in[i]] = i;

        return constructTree(post, postStart, postEnd, in, inStart, inEnd, mp);
    }
};