// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
/*
1---2
|   |
4---3
 given this graph and also 1-->3 so we have to tell is it possible to distribute M colors to all the vertices without the adjacent vertice having the same color.Y/N.*/
// } Driver Code Ends
// Function to determine if graph can be coloured with at most M colours such
// that no two adjacent vertices of graph are coloured with same colour.
bool isSafe(bool graph[101][101], int node, int n, int color[], int i) // i for storing current color
{
    for (int k = 0; k < n; k++)
    {
        if (k != node && graph[k][node] == 1 && color[k] == i)
            return false;
    }
    return true;
}
bool solve(bool graph[101][101], int m, int n, int color[], int node)
{
    if (node == n)
        return true;
    for (int i = 1; i <= m; i++)
    {
        if (isSafe(graph, node, n, color, i))
        {
            color[node] = i;
            if (solve(graph, m, n, color, node + 1))
                return true;
            color[node] = 0; // backtrack if false
        }
    }
    return false;
}
bool graphColoring(bool graph[101][101], int m, int n)
{
    // your code here
    int color[n] = {0};
    if (solve(graph, m, n, color, 0))
        return true;
    return false;
}

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++)
        {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++)
        {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
// } Driver Code Ends