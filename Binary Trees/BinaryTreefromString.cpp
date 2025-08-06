//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left
child and a pointer to right child */
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};

/* This function is to print the inorder of the tree  */
void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    // function to construct tree from string
    Node *treeFromString(string str)
    {
        // code here
        int n = str.size();
        stack<Node *> st;
        for (int i = 0; i < n; i++)
        {
            if (str[i] != '(' && str[i] != ')')
            {

                int num = 0;

                while (i < n && isdigit(str[i]))
                {
                    num = num * 10 + int(str[i] - 48);
                    i++;
                }
                Node *root = new Node(num);
                st.push(root);
                i--;
            }
            else if (str[i] == ')')
            {
                Node *l = st.top();
                st.pop();
                Node *r = st.top();
                if (!r->left)
                    r->left = l;
                else
                    r->right = l;
            }
        }
        return st.top();
    }
};

//{ Driver Code Starts.

// Driver Code
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        Solution obj;
        Node *root = obj.treeFromString(str);
        inorder(root);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends