class Solution {
public:
/*
    int maxProfit(vector<int>& prices, int i, int buy, int cap, vector<vector<vector<int>>>& dp)
    {
        if (cap==0) return 0;
        if (i==prices.size()) return 0;

        if (dp[i][buy][cap]!=-1) return dp[i][buy][cap];

        if (buy)
        {
            int inc=-prices[i]+maxProfit(prices, i+1, 0, cap, dp);
            int exc=maxProfit(prices, i+1, 1, cap, dp);
            dp[i][buy][cap]=max(inc, exc);
        }
        else
        {
            int inc=prices[i]+maxProfit(prices, i+1, 1, cap-1, dp);
            int exc=maxProfit(prices, i+1, 0, cap, dp);
            dp[i][buy][cap]=max(inc, exc);
        }
        return dp[i][buy][cap];
    }
*/
    int maxProfit(int k, vector<int>& prices)
    {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1, 0)));
        // return maxProfit(prices, 0, 1, k, dp);

        // nase case already filled with 0

        for (int i=n-1; i>=0; i--)
        {
            for (int buy=0; buy<=1; buy++)
            {
                for (int cap=1; cap<=k; cap++)
                {
                    if (buy) dp[i][buy][cap]=max(-prices[i]+dp[i+1][0][cap], dp[i+1][1][cap]);
                    else dp[i][buy][cap]=max(prices[i]+dp[i+1][1][cap-1], dp[i+1][0][cap]);
                }
            }
        }
        return dp[0][1][k];
    }
};