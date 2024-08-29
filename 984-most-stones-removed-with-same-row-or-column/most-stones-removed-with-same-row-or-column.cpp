class Solution {
public:
    void markComponent(vector<vector<int>>& graph, int node, vector<bool>& vis, int& visited, int& components)
    {
        if (vis[node]) return;
        components++;
        queue<int> pendingNodes;
        pendingNodes.push(node);
        vis[node]=true;
        visited++;
        while (!pendingNodes.empty())
        {
            int node=pendingNodes.front();
            pendingNodes.pop();
            for (int nei: graph[node])
            {
                if (vis[nei]) continue;
                vis[nei]=true;
                visited++;
                pendingNodes.push(nei);
            }
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        vector<vector<int>> graph(n);
        for (int i=0; i<n-1; i++)
        {
            for (int j=i+1; j<n; j++)
            {
                if (stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1])
                {
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }

        int components=0, visited=0;
        vector<bool> vis(n, false);
        for (int i=0; i<n; i++)
        {
            if (visited==n) break;
            markComponent(graph, i, vis, visited, components);
        }
        return n-components;
    }
};