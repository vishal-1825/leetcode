class Solution {
public:
    int dijkstra(vector<vector<int>>& graph, int src, int dest, int n)
    {
        vector<int> dist(n, INT_MAX);
        dist[src]=0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, src});
        while (!pq.empty())
        {
            int u=pq.top().second;
            pq.pop();

            for (int v: graph[u])
            {
                if (dist[v]>dist[u]+1)
                {
                    dist[v]=dist[u]+1;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist[dest];
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries)
    {
        vector<vector<int>> graph(n);
        for (int i=0; i<n-1; i++)
            graph[i].push_back(i+1);

        vector<int> ans;
        for (auto q: queries)
        {
            graph[q[0]].push_back(q[1]);
            ans.push_back(dijkstra(graph, 0, n-1, n));
        }
        return ans;
    }
    // vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries)
    // {
    //     vector<vector<int>> dist(n, vector<int>(n));
    //     for (int i=0; i<n; i++)
    //     {
    //         for (int j=i; j<n; j++)
    //             dist[i][j]=j-i;
    //     }

    //     vector<int> ans;
    //     for (auto q: queries)
    //     {
    //         if (dist[0][n-1]>dist[0][q[0]]+1+dist[q[1]][n-1])
    //         {
    //             for (int i=0; i<=q[0]; i++)
    //             {
    //                 for (int j=q[1]; j<n; j++)
    //                     dist[i][j]=dist[i][q[0]]+1+dist[q[1]][j];
    //             }
    //         }
    //         ans.push_back(dist[0][n-1]);
    //     }
    //     return ans;
    // }
};