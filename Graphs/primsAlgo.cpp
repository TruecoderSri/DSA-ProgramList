#include <bits/stdc++.h>
using namespace std;

int spanningTree(int V, vector<vector<int>> adj[])
{
    // code here
    int parent[V];
    int key[V];
    bool mySet[V];

    for (int i = 0; i < V; i++)
    {

        key[i] = INT_MAX;
        mySet[i] = false;
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    parent[0] = -1;
    key[0] = 0;
    pq.push({0, 0});
    for (int i = 0; i < V - 1; i++)
    {
        int u = pq.top().second;
        pq.pop();
        mySet[u] = true;

        for (auto it : adj[u])
        {
            int node = it.first;
            int weight = it.second;
            if (mySet[node] == false && weight < key[node])
            {
                pq.push({key[node], node});
                key[node] = weight;
                parent[node] = u;
            }
        }
    }
    return parent;
}