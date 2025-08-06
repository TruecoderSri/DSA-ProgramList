#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

// we need to find the min time required to start the last course on offer

/*
 the algo works as:

 1) we find he indeg of each node
 2) the one with 0 indeg is inserted in a queue and conseidred
 3) take its neighbours one by one and update the time for the last coure in a maxarray
 4) at last we return the max ele from te max aray */

class Solution
{
public:
    int minimumTime(int n, std::vector<std::vector<int>> &relations, std::vector<int> &time)
    {
        std::unordered_map<int, std::vector<int>> graph;
        for (int i = 0; i < n; i++)
        {
            graph[i] = std::vector<int>();
        }

        std::vector<int> indegree(n, 0);
        for (std::vector<int> edge : relations)
        {
            graph[edge[0] - 1].push_back(edge[1] - 1);
            indegree[edge[1] - 1]++;
        }

        std::queue<int> queue;
        std::vector<int> maxTime(n);

        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0)
            {
                queue.push(i);
            }
            maxTime[i] = time[i];
        }
        int node;
        while (!queue.empty())
        {
            node = queue.front();
            queue.pop();
            for (int neighbor : graph[node])
            {
                maxTime[neighbor] = std::max(maxTime[neighbor], maxTime[node] + time[neighbor]);
                indegree[neighbor]--;
                if (indegree[neighbor] == 0)
                {
                    queue.push(neighbor);
                }
            }
        }

        int ans = 0;
        for (node = 0; node < n; node++)
        {
            ans = std::max(ans, maxTime[node]);
        }

        return ans;
    }
};
