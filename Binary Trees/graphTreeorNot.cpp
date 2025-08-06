#include <bits/stdc++.h>

bool iscyclic(int src, int parent, vector<vector<int>> &v, vector<bool> &visited)
{

    visited[src] = true;
    for (auto i : v[src])
    {
        if (!visited[i])
        {
            if (iscyclic(i, src, v, visited))
                return true;
        }
        else if (i != parent)
            return true;
    }
    return false;
}
bool isGraphTree(int n, vector<vector<int>> &edgeList)
{
    // Write your code here
    vector<bool> visited(n, false);

    int start = 0;
    if (iscyclic(start, -1, edgeList, visited))
        return false;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            return false;
    }
    return true;
}