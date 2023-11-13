class Solution {
public:
    // Couldn't solve this yourself obv, try again
    // Topological Sort BFS (Kahn's algorithm)
    vector<int> findOrder(int n, vector<vector<int>>& pre)
    {
        vector<vector<int>> adj(n);
        for (auto& p : pre)
            adj[p[1]].push_back(p[0]);
        
        vector<int> indegree(n);
        for (int i=0; i<n; i++)
        {
            for (auto& a : adj[i])
                indegree[a]++;
        }

        queue<int> order;
        for (int i=0; i<n; i++)
        {
            if (indegree[i]==0)
                order.push(i);
        }

        vector<int> ans;
        while (!order.empty())
        {
            int zero=order.front();
            order.pop();
            ans.push_back(zero);

            for (auto& nei : adj[zero])
            {
                indegree[nei]--;
                if (indegree[nei]==0) order.push(nei);
            }
        }
        if (ans.size()==n) return ans;
        return {};
    }
};