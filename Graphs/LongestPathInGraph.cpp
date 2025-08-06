// using toposort
#include <bits/stdc++.h>
using namespace std;
void dfs(int node, vector<vector<int>> &adj, vector<int> &vis, stack<int> &s)
{
    vis[node] = 1;
    for (auto x : adj[node])
    {
        if (!vis[x])
        {
            dfs(x, adj, vis, s);
        }
    }
    s.push(node);
}
vector<int> findMaxDistances(int n, int src, vector<vector<int>> &edges)
{
    vector<int> vis(n, 0);
    stack<int> s;
    vector<int> dist(n, -1);
    vector<vector<pair<int, int>>> g(n);
    vector<vector<int>> gph(n);

    for (auto i : edges)
    {
        gph[i[0]].push_back(i[1]);
    }
    for (auto i : edges)
    {
        g[i[0]].push_back({i[1], i[2]});
    }
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs(i, gph, vis, s);
        }
    }
    dist[src] = 0;
    // stack stores the topo sorted nodes
    while (!s.empty())
    {
        int top = s.top();
        s.pop();
        if (dist[top] != -1)
        {
            for (auto x : g[top])
            {
                int u = dist[top];
                int v = dist[x.first];
                int w = x.second;
                if (w + u > v)
                {
                    dist[x.first] = u + w;
                }
            }
        }
    }
    return dist;
}