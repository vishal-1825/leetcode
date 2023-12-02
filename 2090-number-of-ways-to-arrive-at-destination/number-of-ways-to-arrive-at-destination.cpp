class Solution {
public:
    // No clue, just learnt how to implement dijkstra the right way
    // time, node
    typedef long long ll;
    int countPaths(int n, vector<vector<int>>& roads)
    {
        ll mod=1e9+7;
        vector<vector<pair<ll, ll>>> adj(n);
        for (auto& r : roads)
        {
            adj[r[0]].push_back({r[1], r[2]});
            adj[r[1]].push_back({r[0], r[2]});
        }
        
        vector<ll> times(n, LONG_MAX);
        times[0]=0;
        vector<ll> count(n);
        count[0]=1;
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
        pq.push({0, 0});
        while (!pq.empty())
        {
            ll time = pq.top().first;
            ll node = pq.top().second;
            pq.pop();

            for (auto& nei : adj[node])
            {
                ll adjNode=nei.first;
                ll t=nei.second;
                if (time+t < times[adjNode])
                {
                    times[adjNode]=time+t;
                    count[adjNode]=count[node];
                    pq.push({time+t, adjNode});
                }
                else if (time+t == times[adjNode]) count[adjNode]=(count[adjNode]+count[node])%mod;
            }
        }
        return count[n-1];
    }
};