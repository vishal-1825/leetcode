class Solution {
public:
    // No idea, will have to redo and learn all approaches
    int maxComp(vector<vector<int>>& graph, vector<int>& values, int k, int& components, int parentNode, int curNode)
    {
        int sum=0;
        for (auto nei: graph[curNode])
        {
            if (parentNode==nei) continue;
            sum+=maxComp(graph, values, k, components, curNode, nei);
            sum%=k;
        }

        sum+=values[curNode];
        sum%=k;
        if (sum==0) components++;
        return sum;
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k)
    {
        int components=0;
        vector<vector<int>> graph(n);
        for (auto edge: edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        maxComp(graph, values, k, components, -1, 0);
        return components;
    }
};