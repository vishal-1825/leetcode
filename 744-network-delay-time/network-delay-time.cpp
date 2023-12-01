class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k)
    {
        vector<vector<pair<int, int>>> graph(n+1);
        for (auto& t : times)
            graph[t[0]].push_back({t[1], t[2]});
        
        vector<int> time(n+1, INT_MAX);
        time[k]=0;
        queue<int> received;
        received.push(k);
        while (!received.empty())
        {
            int node=received.front();
            received.pop();
            
            for (auto& g : graph[node])
            {
                if (time[node]+g.second<time[g.first])
                {
                    time[g.first]=time[node]+g.second;
                    received.push(g.first);
                }
            }
        }
        
        int ans=0;
        for (int i=1; i<=n; i++)
        {
            if (time[i]==INT_MAX) return -1;
            ans=max(ans, time[i]);
        }
        return ans;
    }
};