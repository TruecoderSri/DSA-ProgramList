#include <bits/stdc++.h>

bool solve(int src, vector<pair<int, int>> adj[], int k, vector<bool> &vis)
{
    vis[src] = true;
    if (k <= 0)
        return true;
    for (auto it : adj[src])
    {
        int adjN = it.first;
        int weight = it.second;
        //         to eliminate any cycle
        if (vis[adjN] == true)
            continue;
        if (weight >= k)
            return true;
        if (solve(adjN, adj, k - weight, vis))
            return true;
    }
    vis[src] = false;
    return false;
}

string pathMoreThanK(int n, int m, int k, vector<vector<int>> &edges)
{
    // Write your code here.
    vector<pair<int, int>> adj[n];
    for (int i = 0; i < m; i++)
    {
        adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        adj[edges[i][1]].push_back({edges[i][0], edges[i][2]});
    }
    vector<bool> vis(n, false);

    if (solve(0, adj, k, vis) == true)
    {
        return "YES";
    }
    return "NO";
}