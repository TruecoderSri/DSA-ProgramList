//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Trienode
{
public:
    Trienode *child[26];
    bool contains(char c)
    {
        return child[c - 'a'] != NULL;
    }
    vector<string> curr;
    void push(string &s)
    {

        curr.push_back(s);
    }
};

class Trie
{
public:
    Trienode *root;
    Trie()
    {
        root = new Trienode();
    }
    void insert(string &word)
    {
        Trienode *node = root;
        //   general insertion of a particular word of the list
        for (auto it : word)
        {
            if (!node->contains(it))
                node->child[it - 'a'] = new Trienode();
            node = node->child[it - 'a'];
            auto fd = find(node->curr.begin(), node->curr.end(), word);
            if (fd == node->curr.end())
                //   add to the vector
                node->push(word);
        }
    }

    vector<vector<string>> search(string &word)
    {
        Trienode *node = root;
        vector<vector<string>> ans;
        for (auto it : word)
        {
            if (node->contains(it) == false)
            {
                return ans;
            }
            node = node->child[it - 'a'];
            ans.push_back(node->curr);
        }
        return ans;
    }
};

class Solution
{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        // code here
        sort(contact, contact + n);

        Trie t;
        for (int i = 0; i < n; i++)
        {
            t.insert(contact[i]);
        }
        // s->the query to be searched
        auto ans = t.search(s);
        for (int i = ans.size(); i < s.size(); i++)
        {
            ans.push_back({"0"});
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
        string contact[n], s;
        for (int i = 0; i < n; i++)
            cin >> contact[i];
        cin >> s;

        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for (int i = 0; i < s.size(); i++)
        {
            for (auto u : ans[i])
                cout << u << " ";
            cout << "\n";
        }
    }
    return 0;
}
// } Driver Code Ends