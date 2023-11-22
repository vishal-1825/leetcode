class Solution {
public:
    // vector<int> eventualSafeNodes(vector<vector<int>>& graph)
    // {
    //     int n=graph.size();
    //     unordered_map<int, vector<int>> incoming;
    //     vector<bool> terminal(n, false);
    //     queue<int> terminalNodes;

    //     for (int i=0; i<n; i++)
    //     {
    //         if (graph[i].size()==0)
    //         {
    //             terminal[i]=true;
    //             terminalNodes.push(i);
    //         }
    //     }
    //     for (int i=0; i<n; i++)
    //     {
    //         for (auto& g : graph[i])
    //             incoming[g].push_back(i);
    //     }

    //     while (!terminalNodes.empty())
    //     {
    //         int node = terminalNodes.front();
    //         terminalNodes.pop();

    //         for (auto& i : incoming[node])
    //         {
    //             if (terminal[i]) continue;
    //             bool flag=true;
    //             for (auto& o : graph[i])
    //             {
    //                 if (!terminal[o])
    //                 {
    //                     flag=false;
    //                     break;
    //                 }
    //             }
    //             terminal[i]=flag;
    //             if (terminal[i]) terminalNodes.push(i);
    //         }
    //     }

    //     vector<int> ans;
    //     for (int i=0; i<n; i++)
    //     {
    //         if (terminal[i])
    //             ans.push_back(i);
    //     }
    //     return ans;
    // }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph)
    {
        int n=graph.size();
        vector<vector<int>> incoming(n);
        vector<int> outdegree(n), safe(n), ans;
        queue<int> safeNodes;

        for (int i=0; i<n; i++)
        {
            for (int g : graph[i])
                incoming[g].push_back(i);
            outdegree[i]=graph[i].size();
            if (outdegree[i]==0) safeNodes.push(i);
        }

        while (!safeNodes.empty())
        {
            int node = safeNodes.front();
            safeNodes.pop();
            safe[node]=1;
            for (int i : incoming[node])
            {
                outdegree[i]--;
                if (outdegree[i]==0) safeNodes.push(i);
            }
        }

        for (int i=0; i<n; i++)
        {
            if (safe[i])
                ans.push_back(i);
        }
        return ans;
    }
};