#include <bits/stdc++.h>
bool cmp(vector<int> &a, vector<int> &b)
{
    return a[2] < b[2];
}

void makeSet(vector<int> &parent, vector<int> &rank, int n)
{
    for (int i = 0; i < n; i++)
    {
        rank[i] = 0;
        parent[i] = i;
    }
}
int findPar(vector<int> &parent, int node)
{
    if (parent[node] == node)
        return node;
    return parent[node] = findPar(parent, parent[node]);
}
void unionset(vector<int> &parent, int u, int v, vector<int> &rank)
{
    u = findPar(parent, u);
    v = findPar(parent, v);

    if (rank[u] < rank[v])
    {
        parent[u] = v;
    }
    if (rank[v] < rank[u])
    {
        parent[v] = u;
    }
    else
    {
        parent[v] = u;
        rank[u]++;
    }
}
int minimumSpanningTree(vector<vector<int>> &edges, int n)
{
    sort(edges.begin(), edges.end(), cmp);
    vector<int> parent(n);
    vector<int> rank(n);
    makeSet(parent, rank, n);

    int t_weight = 0;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = findPar(parent, edges[i][0]);
        int v = findPar(parent, edges[i][1]);
        int wt = findPar(parent, edges[i][2]);
        if (u != v)
        {
            t_weight += wt;
            ;
            unionset(parent, u, v, rank);
        }
    }
    return t_weight;
}