class Solution {
public:
    int dijkstra(int n, int src, vector<vector<pair<int, int>>>& graph, int distanceThreshold)
    {
        vector<int> distance(n, INT_MAX);
        distance[src]=0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> nodes;
        nodes.push({0, src});
        while (!nodes.empty())
        {
            int node = nodes.top().second;
            int dist = nodes.top().first;
            nodes.pop();

            for (auto& g : graph[node])
            {
                if (distance[node]+g.second < distance[g.first])
                {
                    distance[g.first] = distance[node]+g.second;
                    nodes.push({distance[g.first], g.first});
                }
            }
        }

        int ans=0;
        for (int node=0; node<n; node++)
        {
            if (distance[node]<=distanceThreshold)
                ans++;
        }
        return ans;
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold)
    {
        vector<vector<pair<int, int>>> graph(n);
        for (auto& e : edges)
        {
            graph[e[0]].push_back({e[1], e[2]});
            graph[e[1]].push_back({e[0], e[2]});
        }

        int minNode, minCities=INT_MAX;
        for (int node=0; node<n; node++)
        {
            int cities = dijkstra(n, node, graph, distanceThreshold);
            if (cities<=minCities)
            {
                minNode=node;
                minCities=cities;
            }
        }

        return minNode;
    }
};