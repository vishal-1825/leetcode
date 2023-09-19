typedef long long ll;
class Solution {
public:
    bool mWorks(ll m, int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost)
    {
        ll i=0, j=0, req_cost=INT_MAX, req=0;

        for (i=0; i<k; i++)
        {
            req=0;
            for (j=0; j<n; j++)
                req+=max(ll(m*composition[i][j]-stock[j]), ll(0))*cost[j];
            req_cost=min(req_cost, req);
        }
        return (budget>=req_cost);
    }
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost)
    {
        ll s=0, e=1e9, ans=0;
        while (s<=e)
        {
            ll m=(s+e)/2;

            if (mWorks(m, n, k, budget, composition, stock, cost))
            {
                ans=m;
                s=m+1;
            }
            else e=m-1;
        }
        return ans;
    }
};