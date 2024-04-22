typedef long long ll;
class Solution {
public:
    // Calculate distances of all nodes from source and sitances of all nodes from destination
    // Whenever wt of edge + distFromSrc[node1]+distFrom[node2] = shortest distance include in answer
    // Time complexity of Dijkstra is O((E+V)logV)
    // Time Complexity of this code is O(2*(E+V)logV+E) = O((E+V)logV)
    vector<int> dijkstra(int n, vector<vector<pair<int, int>>>& graph, int src)
    {
        vector<int> dist(n, INT_MAX);
        dist[src]=0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<bool> vis(n, false);
        pq.push({0, src});
        while (!pq.empty())
        {
            int node=pq.top().second;
            int d=pq.top().first;
            pq.pop();

            if (vis[node]) continue;
            vis[node]=true;
            for (pair<int, int> g: graph[node])
            {
                int nei=g.first;
                int wt=g.second;
                if (!vis[nei] && dist[nei]>d+wt)
                {
                    dist[nei]=d+wt;
                    pq.push({dist[nei], nei});
                }
            }
        }
        return dist;
    }
    vector<bool> findAnswer(int n, vector<vector<int>>& edges)
    {
        vector<vector<pair<int, int>>> graph(n);
        for (int i=0; i<edges.size(); i++)
        {
            graph[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            graph[edges[i][1]].push_back({edges[i][0], edges[i][2]});
        }
        
        vector<int> distFromSrc = dijkstra(n, graph, 0);
        vector<int> distFromDest = dijkstra(n, graph, n-1);
        int sd=distFromSrc[n-1];
        vector<bool> ans(edges.size(), false);
        for (int i=0; i<edges.size(); i++)
        {
            int node1=edges[i][0], node2=edges[i][1], wt=edges[i][2];
            if (distFromSrc[node1]!=INT_MAX && distFromDest[node2]!=INT_MAX && distFromSrc[node1]+(ll)wt+distFromDest[node2]==sd)
                ans[i]=true;
            if (distFromSrc[node2]!=INT_MAX && distFromDest[node1]!=INT_MAX && distFromSrc[node2]+(ll)wt+distFromDest[node1]==sd)
                ans[i]=true;
        }
        return ans;
    }
}; 