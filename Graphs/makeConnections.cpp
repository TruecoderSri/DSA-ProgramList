class Solution
{
public:
    void dfs(int src, vector<int> edges[], vector<int> &vis)
    {
        vis[src] = 1;
        for (auto it : edges[src])
        {
            if (!vis[it])
            {
                dfs(it, edges, vis);
            }
        }
    }

    int makeConnected(int n, vector<vector<int>> &connections)
    {

        vector<int> edges[n];
        int m = connections.size();
        if (m < n - 1)
            return -1;
        for (int i = 0; i < m; i++)
        {
            edges[connections[i][0]].push_back(connections[i][1]);
            edges[connections[i][1]].push_back(connections[i][0]);
        }
        vector<int> vis(n, 0);
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                count++;
                dfs(i, edges, vis);
            }
        }
        return count - 1;
    }
};