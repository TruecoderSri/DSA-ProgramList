#include <bits/stdc++.h>
using namespace std;

// TC:O(V+E)
// SC:O(B^M),B->branching factor of search Tree and the M is the max depth of state space
void dfs(int node, int &timer, int parent, vector<int> &disc, vector<int> &low, unordered_map<int, bool> &vis,
         vector<vector<int>> &result, unordered_map<int, list<int>> &adj)
{

    vis[node] = true;
    disc[node] = timer++;
    low[node] = timer++;

    for (auto nbr : adj[node])
    {
        if (parent == nbr)
            continue;

        if (!vis[nbr])
        {

            dfs(nbr, timer, node, disc, low, vis, result, adj);
            low[node] = min(low[node], low[nbr]);

            //   check bridge

            if (low[nbr] > disc[node])
            {
                vector<int> ans;
                ans.push_back(node);
                ans.push_back(nbr);
                result.push_back(ans);
            }
        }
        else
        {
            // back edge
            low[node] = min(low[node], disc[nbr]);
        }
    }
}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e)
{
    // Write your code here
    unordered_map<int, list<int>> adj;

    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int timer = 0;
    vector<int> disc(v, -1);
    vector<int> low(v, -1);
    unordered_map<int, bool> vis;
    int parent = -1;

    // dfs
    vector<vector<int>> result;

    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
        {
            dfs(i, timer, parent, disc, low, vis, result, adj);
        }
    }
    return result;
}