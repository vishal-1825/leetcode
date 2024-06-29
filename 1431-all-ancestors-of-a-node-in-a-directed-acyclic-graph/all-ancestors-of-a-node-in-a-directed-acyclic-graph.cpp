class Solution {
public:
    vector<int> getAncestors(int node, vector<vector<int>>& graph, int n)
    {
        vector<bool> visited(n, false);
        vector<int> ans;
        queue<int> pendingNodes;
        pendingNodes.push(node);
        visited[node]=true;
        while (!pendingNodes.empty())
        {
            int vert=pendingNodes.front();
            pendingNodes.pop();

            for (auto& nei: graph[vert])
            {
                if (visited[nei]) continue;
                visited[nei]=true;
                ans.push_back(nei);
                pendingNodes.push(nei);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges)
    {
        vector<vector<int>> graph(n);
        for (auto& e: edges)
            graph[e[1]].push_back(e[0]);
        
        vector<vector<int>> ans;
        for (int node=0; node<n; node++)
            ans.push_back(getAncestors(node, graph, n));
        return ans;
    }
};