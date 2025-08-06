#include <bits/stdc++.h>
using namespace std;
class Trienode
{
public:
    int freq;
    struct Trienode *child[26];
    Trienode()
    {
        freq = 0;
        for (int i = 0; i < 26; i++)
            child[i] = NULL;
    }
};

class Solution
{
public:
    vector<string> findPrefixes(string arr[], int n)
    {
        // code here
        Trienode *root = new Trienode();
        vector<string> ans;
        for (int i = 0; i < n; i++)
        {
            buildTrie(arr[i], root);
        }
        for (int i = 0; i < n; i++)
        {
            ans.push_back(buildPrefix(arr[i], root));
        }
        return ans;
    }

    void buildTrie(string s, Trienode *root)
    {
        Trienode *node = root;
        for (int i = 0; i < s.size(); i++)
        {
            int index = s[i] - 'a';
            // whenever we add a new node:condition
            if (node->child[index] == NULL)
            {
                node->child[index] = new Trienode();
            }
            // irrespective it is a new node or not we increment the count
            node->child[index]->freq++;
            node = node->child[index];
        }
    }

    string buildPrefix(string s, Trienode *root)
    {
        Trienode *node = root;
        string ans = "";
        for (int i = 0; i < s.size(); i++)
        {
            int index = s[i] - 'a';
            if (node->freq == 1) // denotes the prefix is unique
                break;
            ans += s[i];
            node = node->child[index];
        }
        return ans;
    }
};