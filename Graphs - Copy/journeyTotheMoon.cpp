#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> &vis, vector<int> adj[], int &count)
{
    vis[node] = 1;
    count++;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            dfs(it, vis, adj, count);
        }
    }
}

int main()
{
    int v, e;
    cin >> v >> e;
    vector<int> adj[v];
    for (int i = 0; i < e; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<int> vis(v, 0);
    vector<int> solution;
    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
        {
            int count = 0;
            dfs(i, vis, adj, count);
            solution.push_back(count);
        }
    }

    int val = (v * (v - 1)) / 2;
    for (int i = 0; i < solution.size(); i++)
    {
        int x = (solution[i] * (solution[i] - 1)) / 2;
        val -= x;
    }
    cout << val << endl;
}