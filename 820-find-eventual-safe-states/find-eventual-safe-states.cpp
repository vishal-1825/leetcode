class Solution {
public:
    bool dfs(vector<vector<int>>& graph, vector<bool>& vis, vector<bool>& safe, int node)
    {
        if (safe[node]) return true; // safe
        if (vis[node]) return false; // unsafe
        // unvisited
        vis[node]=true;
        bool flag=true;
        for (int nei: graph[node])
        {
            bool check=dfs(graph, vis, safe, nei);
            if (!check) flag=false;
        }
        return safe[node]=flag;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph)
    {
        int n=graph.size();
        vector<bool> vis(n), safe(n, false);
        
        for (int node=0; node<n; node++)
            dfs(graph, vis, safe, node);
        
        vector<int> ans;
        for (int node=0; node<n; node++)
        {
            if (safe[node])
                ans.push_back(node);
        }
        return ans;
    }
};