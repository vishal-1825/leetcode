class Solution {
public:
/*
    int getMaxProfit(vector<int>& prices, int i, int buy, int n, vector<vector<int>>& dp)
    {
        if (i==n) return 0;

        if (dp[i][buy]!=-1) return dp[i][buy];
        int profit;
        if (buy) profit=max(getMaxProfit(prices, i+1, 1, n, dp), -prices[i]+getMaxProfit(prices, i+1, 0, n, dp));
        else profit=max(getMaxProfit(prices, i+1, 0, n, dp), prices[i]+getMaxProfit(prices, i+1, 1, n, dp));
        return dp[i][buy]=profit;
    }

    int maxProfit(vector<int>& prices)
    {
        int n=prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        int ans=getMaxProfit(prices, 0, 1, n, dp);
        return ans;
    }
*/

    int maxProfit(vector<int>& prices)
    {
        int n=prices.size(), i, buy;
        vector<vector<int>> dp(2, vector<int>(2, 0));

        for (i=n-1; i>=0; i--)
        {
            for (buy=0; buy<=1; buy++)
            {
                int profit;
                if (buy) profit=max(dp[1][1], -prices[i]+dp[1][0]);
                else profit=max(dp[1][0], prices[i]+dp[1][1]);
                dp[0][buy]=profit;
            }
            dp[1][0]=dp[0][0];
            dp[1][1]=dp[0][1];
        }
        return dp[0][1];
    }

/*
    int maxProfit(vector<int>& prices)
    {
        // this is called greedy approach - whenever next day's price is greater than today, you immediately buy today and sell the next day
        int cur=0, next=1, profit=0, n=prices.size();
        while (next<n)
        {
            if (prices[next]>prices[cur])
                profit+=prices[next]-prices[cur];
            cur++;
            next++;
        }
        return profit;
    }
*/
};