//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // TC:O(M*N)
    // SC:O(N+1)

    int isNegativeWeightCycle(int n, vector<vector<int>> edges)
    {
        // Code here
        vector<int> dist(n + 1, 1e9);
        // first dist is always 0
        dist[0] = 0;
        for (int i = 1; i <= n; i++)
        {

            for (int j = 0; j < edges.size(); j++)
            {
                int u = edges[j][0];
                int v = edges[j][1];
                int wt = edges[j][2];
                // Bellman-Ford Algorithm
                if (dist[u] != 1e9 && (dist[u] + wt < dist[v]))
                {
                    dist[v] = wt + dist[u];
                }
            }
        }

        int flag = 0;
        for (int i = 1; i <= n; i++)
        {

            for (int j = 0; j < edges.size(); j++)
            {
                int u = edges[j][0];
                int v = edges[j][1];
                int wt = edges[j][2];
                // if the if part runs if means that the graph contains neg part
                if (dist[u] != 1e9 && (dist[u] + wt < dist[v]))
                {
                    dist[v] = wt + dist[u];
                    flag = 1;
                }
            }
        }
        if (flag)
            return 1;
        return 0;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; i++)
        {
            int x, y, z;
            cin >> x >> y >> z;
            edges.push_back({x, y, z});
        }
        Solution obj;
        int ans = obj.isNegativeWeightCycle(n, edges);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends