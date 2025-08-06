//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// Back-end complete function Template for C++

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
Node *insert(Node *node, int data, Node *&succ)
{
    if (node == NULL)
        return new Node(data);

    if (data < node->data)
    {
        succ = node;
        node->left = insert(node->left, data, succ);
    }
    else if (data >= node->data)
        node->right = insert(node->right, data, succ);
    return node;
}

class Solution
{
public:
    vector<int> findLeastGreater(vector<int> &arr, int n)
    {

        Node *root = NULL;
        vector<int> ans(n, 0);
        for (int i = n - 1; i >= 0; i--)
        {
            Node *succ = NULL;
            root = insert(root, arr[i], succ);
            if (succ)
                ans[i] = succ->data;
            else
                ans[i] = -1;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.findLeastGreater(arr, n);
        for (auto it : ans)
        {
            cout << it << " ";
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends