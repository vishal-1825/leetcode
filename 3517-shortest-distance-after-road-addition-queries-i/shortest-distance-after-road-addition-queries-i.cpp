class Solution {
public:
    // int dijkstra(vector<vector<int>>& graph, int src, int dest, int n)
    // {
    //     vector<int> dist(n, INT_MAX);
    //     dist[src]=0;
    //     priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    //     pq.push({0, src});
    //     while (!pq.empty())
    //     {
    //         int u=pq.top().second;
    //         pq.pop();

    //         for (int v: graph[u])
    //         {
    //             if (dist[v]>dist[u]+1)
    //             {
    //                 dist[v]=dist[u]+1;
    //                 pq.push({dist[v], v});
    //             }
    //         }
    //     }
    //     return dist[dest];
    // }
    // vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries)
    // {
    //     vector<vector<int>> graph(n);
    //     for (int i=0; i<n-1; i++)
    //         graph[i].push_back(i+1);

    //     vector<int> ans;
    //     for (auto q: queries)
    //     {
    //         graph[q[0]].push_back(q[1]);
    //         ans.push_back(dijkstra(graph, 0, n-1, n));
    //     }
    //     return ans;
    // }
    int bfs(vector<vector<int>>& graph, int n)
    {
        int dist=0, node=0;
        vector<bool> visited(n, false);
        visited[node]=true;
        queue<int> pendingNodes;
        pendingNodes.push(node);
        while (!pendingNodes.empty())
        {
            int sz=pendingNodes.size();
            while (sz--)
            {
                node=pendingNodes.front();
                pendingNodes.pop();

                if (node==n-1) return dist;

                for (int nei: graph[node])
                {
                    if (visited[nei]) continue;
                    visited[nei]=true;
                    pendingNodes.push(nei);
                }
            }
            dist++;
        }
        return -1;
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
            int dist=bfs(graph, n);
            ans.push_back(dist);
        }
        return ans;
    }
};