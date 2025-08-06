//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

void insert(Node **tree, int val)
{
    Node *temp = NULL;
    if (!(*tree))
    {
        temp = new Node(val);
        *tree = temp;
        return;
    }

    if (val < (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if (val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }
}

int getCountOfNode(Node *root, int l, int h)
{

    if (!root)
        return 0;

    if (root->data == h && root->data == l)
        return 1;

    if (root->data <= h && root->data >= l)
        return 1 + getCountOfNode(root->left, l, h) +
               getCountOfNode(root->right, l, h);

    else if (root->data < l)
        return getCountOfNode(root->right, l, h);

    else
        return getCountOfNode(root->left, l, h);
}

bool isDeadEnd(Node *root);
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        Node *root;
        Node *tmp;
        // int i;

        root = NULL;

        int N;
        cin >> N;
        for (int i = 0; i < N; i++)
        {
            int k;
            cin >> k;
            insert(&root, k);
        }

        cout << isDeadEnd(root);
        cout << endl;
    }
}

// } Driver Code Ends

// check deadEnd of Binary Search Tree

/*The Node structure is
struct Node {
int data;
Node * right, * left;
};*/

void checkdeadEnd(Node *root, int l, int r, bool &flag)
{
    if (!root)
        return;
    if (flag)
        return;
    if (!root->left && !root->right)
    {
        if (l == r)
            flag = true;
        return;
    }
    checkdeadEnd(root->left, l, root->data - 1, flag);
    checkdeadEnd(root->right, root->data + 1, r, flag);
}

/*You are required to complete below method */
bool isDeadEnd(Node *root)
{
    // Your code here
    bool flag = false;
    int l = 1;
    int r = INT_MAX; // specified for defining the left and right range of the left and right subtree respectively
    checkdeadEnd(root, l, r, flag);
    if (flag)
        return 1;
    return 0;
}