class Solution {
public:
    void markComponent(int node, vector<vector<int>>& graph, vector<bool>& visited)
    {
        if (visited[node]) return;

        visited[node]=true;
        for (auto& nei: graph[node])
            markComponent(nei, graph, visited);
    }
    int makeConnected(int n, vector<vector<int>>& connections)
    {
        if (connections.size()<n-1) return -1;

        vector<vector<int>> graph(n);
        for (auto& c: connections)
        {
            graph[c[0]].push_back(c[1]);
            graph[c[1]].push_back(c[0]);
        }

        int ans=0;
        vector<bool> visited(n, false);
        for (int node=0; node<n; node++)
        {
            if (!visited[node])
            {
                markComponent(node, graph, visited);
                ans++;
            }
        }
        return --ans;
    }
};