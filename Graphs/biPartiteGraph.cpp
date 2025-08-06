//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
private:
    // TC:O(N)
    // SC:O(N^2)

    bool solve(int src, int V, vector<int> adj[], int color[])
    {
        queue<int> q;
        q.push(src);

        color[src] = 0;
        while (!q.empty())
        {
            int top = q.front();
            q.pop();

            for (auto it : adj[top])
            {
                // when the adjoint node is not coloured
                if (color[it] == -1)
                {
                    color[it] = !color[top];
                    q.push(it);
                }
                // when the 2 adjacent nodes have the same color
                else if (color[it] == color[top])
                {
                    return false;
                }
            }
        }
        return true;
    }

public:
    bool isBipartite(int V, vector<int> adj[])
    {
        // Code here

        int color[V];
        for (int i = 0; i < V; i++)
        {
            color[i] = -1;
        }
        for (int i = 0; i < V; i++)
        {
            if (color[i] == -1)
            {
                if (solve(i, V, adj, color) == false)
                    return false;
            }
        }
        return true;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isBipartite(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends