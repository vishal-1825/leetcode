class Solution {
public:
    // Had to refer 2097. Valid Arrangement of Pairs
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> graph;
    void EulerianPath(string node, vector<string>& ans)
    {
        while (!graph[node].empty())
        {
            string neighbor=graph[node].top();
            graph[node].pop();
            EulerianPath(neighbor, ans);
        }
        ans.push_back(node);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets)
    {
        for (auto ticket: tickets)
            graph[ticket[0]].push(ticket[1]);
        string startNode="JFK";
        vector<string> ans;
        EulerianPath(startNode, ans);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};