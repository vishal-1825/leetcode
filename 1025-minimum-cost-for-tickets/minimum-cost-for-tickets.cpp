class Solution {
public:
    int minCost(vector<int>& days, vector<int>& costs, vector<int>& dp, int cur)
    {
        if (cur==days.size()) return 0;

        if (dp[cur]!=-1) return dp[cur];

        int oneDay=costs[0]+minCost(days, costs, dp, cur+1);
        
        int left=cur+1, right=days.size()-1, sevenIndex=days.size();
        while (left<=right)
        {
            int mid=(left+right)/2;
            if (days[mid]>=days[cur]+7)
            {
                sevenIndex=mid;
                right=mid-1;
            }
            else left=mid+1;
        }
        int sevenDays=costs[1]+minCost(days, costs, dp, sevenIndex);
        
        left=cur+1, right=days.size()-1;
        int thirtyIndex=days.size();
        while (left<=right)
        {
            int mid=(left+right)/2;
            if (days[mid]>=days[cur]+30)
            {
                thirtyIndex=mid;
                right=mid-1;
            }
            else left=mid+1;
        }
        int thirtyDays=costs[2]+minCost(days, costs, dp, thirtyIndex);

        return dp[cur]=min({oneDay, sevenDays, thirtyDays});
    }
    int mincostTickets(vector<int>& days, vector<int>& costs)
    {
        vector<int> dp(days.size(), -1);
        return minCost(days, costs, dp, 0);
    }
};