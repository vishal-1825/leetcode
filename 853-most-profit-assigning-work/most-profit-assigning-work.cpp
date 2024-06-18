class Solution {
public:
    // int maxProfit(vector<int>& difficulty, vector<int>& profit, vector<int>& worker, int i, vector<int>& dp)
    // {
    //     if (i==worker.size()) return 0;

    //     if (dp[i]!=-1) return dp[i];

    //     int ans=0;
    //     for (int j=0; j<profit.size(); j++)
    //     {
    //         int assigned=0;
    //         if (difficulty[j]<=worker[i])
    //             assigned=profit[j]+maxProfit(difficulty, profit, worker, i+1, dp);
    //         if (assigned>ans)
    //             ans=assigned;
    //     }
    //     int not_assigned=maxProfit(difficulty, profit, worker, i+1, dp);
    //     if (not_assigned>ans)
    //         ans=not_assigned;
    //     return dp[i]=ans;
    // }
    // int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker)
    // {
    //     vector<int> dp(worker.size(), -1);
    //     return maxProfit(difficulty, profit, worker, 0, dp);    
    // }
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker)
    {
        int n=difficulty.size(), m=worker.size();
        vector<pair<int, int>> profdif;
        for (int i=0; i<n; i++)
            profdif.push_back({difficulty[i], profit[i]});
        sort(profdif.begin(), profdif.end());
        for (int i=1; i<profdif.size(); i++)
            profdif[i].second=max(profdif[i-1].second, profdif[i].second);

        int ans=0;
        for (int i=0; i<m; i++)
        {
            int prof=0, l=0, r=n-1;
            while (l<=r)
            {
                int m=(l+r)/2;
                if (profdif[m].first<=worker[i])
                {
                    prof=max(prof, profdif[m].second);
                    l=m+1;
                }
                else r=m-1;
            }
            ans+=prof;
        }
        return ans;
    }
};