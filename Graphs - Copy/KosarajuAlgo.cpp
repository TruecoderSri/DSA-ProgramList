//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// TC:0(N+E)
// SC:O(1)

// } Driver Code Ends

class Solution
{
    //  1.  sort the graph topologically and store it in the stack.

    //  2.  transpose the given graph

    //  3.   do the dfs(accordig to the top element of the stack you got from topo sort) and count everytime you run the dfs

private:
    void dfs(vector<int> adj[], unordered_map<int, bool> &visited, stack<int> &st, int node)
    {
        visited[node] = true;

        for (auto i : adj[node])
        {
            if (!visited[i])
                dfs(adj, visited, st, i);
        }
        st.push(node);
    }
    void revdfs(unordered_map<int, list<int>> &transpose, int node,
                unordered_map<int, bool> &visited)
    {

        visited[node] = true;

        for (auto i : transpose[node])
        {
            if (!visited[i])
                revdfs(transpose, i, visited);
        }
    }

public:
    // Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
        stack<int> st;
        unordered_map<int, bool> visited;

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
                dfs(adj, visited, st, i);
        }

        unordered_map<int, list<int>> transpose;

        for (int i = 0; i < V; i++)
        {
            visited[i] = 0;
            for (auto nbr : adj[i])
                transpose[nbr].push_back(i);
        }
        int cnt = 0;
        while (!st.empty())
        {
            int top = st.top();
            st.pop();
            if (!visited[top])
                cnt++;
            revdfs(transpose, top, visited);
        }
        return cnt;
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
        cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends