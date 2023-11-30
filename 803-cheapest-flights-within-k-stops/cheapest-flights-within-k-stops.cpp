class Solution {
public:
    // 'visited' is not necessary here since infinite loop is not possible here as we are restricting the number of steps to k
    int findPrice(unordered_map<int, unordered_map<int, int>>& graph, int src, int& dst, int k, vector<vector<int>>& dp, unordered_set<int>& visited)
    {
        if (src==dst) return 0;
        if (k==-1) return INT_MAX;

        if (dp[src][k]!=-1) return dp[src][k];

        int price=INT_MAX;
        visited.insert(src);
        for (auto& nei : graph[src])
        {
            if (visited.find(nei.first)!=visited.end()) continue;
            int p=findPrice(graph, nei.first, dst, k-1, dp, visited);
            if (p<INT_MAX) p+=nei.second;
            if (p<price) price=p;
        }
        visited.erase(src);
        return dp[src][k]=price;
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k)
    {
        unordered_map<int, unordered_map<int, int>> graph;
        unordered_set<int> visited;
        for (auto& f : flights)
            graph[f[0]][f[1]]=f[2];

        vector<vector<int>> dp(n, vector<int>(k+1, -1));
        int ans=findPrice(graph, src, dst, k, dp, visited);
        return (ans==INT_MAX ? -1 : ans);  
    }
};