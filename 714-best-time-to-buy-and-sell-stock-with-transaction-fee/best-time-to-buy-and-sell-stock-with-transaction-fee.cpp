class Solution {
public:
    // int maxProfit(vector<int>& prices, int i, int buy, int fee, vector<vector<int>>& dp)
    // {
    //     if (i==prices.size()) return 0;

    //     if (dp[i][buy]!=-1) return dp[i][buy];

    //     if (buy)
    //     {
    //         int op1 = -prices[i]+maxProfit(prices, i+1, 0, fee, dp);
    //         int op2 = maxProfit(prices, i+1, 1, fee, dp);
    //         return dp[i][buy]=max(op1, op2);
    //     }
        
    //     int op1 = prices[i]+maxProfit(prices, i+1, 1, fee, dp)-fee;
    //     int op2 = maxProfit(prices, i+1, 0, fee, dp);
    //     return dp[i][buy]=max(op1, op2);
    // }
    int maxProfit(vector<int>& prices, int fee)
    {
        vector<vector<int>> dp(prices.size()+1, vector<int>(2, 0));
        // return maxProfit(prices, 0, 1, fee, dp);
        for (int i=prices.size()-1; i>=0; i--)
        {
            dp[i][1]=max(-prices[i]+dp[i+1][0], dp[i+1][1]);
            dp[i][0]=max(prices[i]+dp[i+1][1]-fee, dp[i+1][0]);
        }
        return dp[0][1];
    }
};