//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    //   TC:O(N+E)
    //   SC:O(2N+(ASC:N))

    bool checkCycle(int node, vector<int> adj[], int vis[], int dfsvis[])
    {
        vis[node] = 1;
        dfsvis[node] = 1;
        for (auto it : adj[node])
        {
            //   check the adjacency list for each node
            if (!vis[it])
            {
                if (checkCycle(it, adj, vis, dfsvis))
                    return true;
            }
            //   i.e. the cycle was detected in the current call itself
            else if (dfsvis[it])
                return true;
        }
        //   when the function returns we unmark the dfsvis for next call
        dfsvis[node] = 0;
        return false;
    }

    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[])
    {
        // code here
        int vis[V] = {0};
        int dfsvis[V] = {0};

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (checkCycle(i, adj, vis, dfsvis))
                    return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends