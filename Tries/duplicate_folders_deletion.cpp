#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    struct trieNode
    {

        string folder;
        bool remove = false;
        map<string, trieNode *> child;
        trieNode(string folder)
        {
            this->folder = folder;
        }
    };

    // Construct the trieNode

    void insert(trieNode *root, vector<string> &path)
    {

        for (auto it : path)
        {

            if (!root->child.count(it))
            {
                root->child[it] = new trieNode(it);
            }
            root = root->child[it];
        }
    }

    string markDuplicate(trieNode *root, unordered_map<string, trieNode *> &vis)
    {

        // carry out DFS with map check for duplicacy(make bool pointer true);

        string subfolder;

        for (auto [childfolder, childNode] : root->child)
        {

            subfolder += markDuplicate(childNode, vis);
        }

        if (!subfolder.empty())
        {

            if (vis.count(subfolder))
            {
                vis[subfolder]->remove = true; // Mark the 1st Occurence true
                root->remove = true;           // Mark the Current Occurence true
            }
            else
            {
                vis[subfolder] = root;
            }
        }

        return "[" + root->folder + subfolder + "]";
    }

    void clearedPath(trieNode *root, vector<string> &curr_path, vector<vector<string>> &ans)
    {
        if (root->remove)
            return;

        if (root->folder != "/") // skip adding dummy root
            curr_path.push_back(root->folder);

        if (!curr_path.empty())
            ans.push_back(curr_path);

        for (auto &[_, child] : root->child)
        {
            clearedPath(child, curr_path, ans);
        }

        if (root->folder != "/")
            curr_path.pop_back(); // to remove current in order to discover the next depth from root
    }

    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>> &paths)
    {

        trieNode *root = new trieNode("/");

        for (auto path : paths)
        {
            insert(root, path);
        }

        unordered_map<string, trieNode *> vis;
        markDuplicate(root, vis);

        vector<vector<string>> ans;
        vector<string> curr_path;

        for (auto [subfolder, childNode] : root->child)
        {
            clearedPath(childNode, curr_path, ans);
        }

        return ans;
    }
};