//{ Driver Code Starts
#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
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

void printInorder(struct Node *node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    printf("%d ", node->data);
    printInorder(node->right);
}

Node *constructTree(int n, int pre[], char preLN[]);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        Node *root = NULL;
        int n;
        cin >> n;
        int pre[n];
        char preLN[n];
        for (int i = 0; i < n; i++)
            cin >> pre[i];
        for (int i = 0; i < n; i++)
            cin >> preLN[i];
        root = constructTree(n, pre, preLN);
        printInorder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends

/*Structure of the Node of the binary tree is as
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
*/

Node *construct(int &index, int n, int pre[], char preLN[])
{
    // goes out of arr[]
    if (index >= n)
        return NULL;
    // if the index is a leaf node
    if (preLN[index] == 'L')
    {
        Node *temp = new Node(pre[index]);
        return temp;
        n
    }
    // this is to be done everytime irrespective it is leaf or not
    Node *root = new Node(pre[index++]);
    root->left = construct(index, n, pre, preLN);
    index++;
    root->right = construct(index, n, pre, preLN);
    return root;
}

// function should return the root of the new binary tree formed
struct Node *constructTree(int n, int pre[], char preLN[])
{
    // Code here
    int index = 0;
    construct(index, n, pre, preLN);
}