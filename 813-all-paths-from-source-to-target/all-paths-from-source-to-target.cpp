class Solution {
public:
    void getPaths(int node, int end, vector<vector<int>>& ans, vector<int> path, vector<vector<int>>& graph)
    {
        if (node==end)
        {
            if (!path.empty()) ans.push_back(path);
            return;
        }

        for (auto& n : graph[node])
        {
            path.push_back(n);
            getPaths(n, end, ans, path, graph);
            path.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph)
    {
        vector<vector<int>> ans;
        vector<int> path;
        path.push_back(0);
        getPaths(0, graph.size()-1, ans, path, graph);
        return ans;
    }
};