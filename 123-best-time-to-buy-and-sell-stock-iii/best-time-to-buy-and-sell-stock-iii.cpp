class Solution {
public:
    int maxProfit(vector<int>& prices, int i, int buy, int cap, vector<vector<vector<int>>>& dp)
    {
        if (cap==0 || i==prices.size()) return 0;

        if (dp[i][buy][cap]!=-1) return dp[i][buy][cap];

        if (buy)
        {
            int op1=-prices[i]+maxProfit(prices, i+1, 0, cap, dp);
            int op2=maxProfit(prices, i+1, 1, cap, dp);
            dp[i][buy][cap]=max(op1, op2);
        }
        else
        {
            int op1=prices[i]+maxProfit(prices, i+1, 1, cap-1, dp);
            int op2=maxProfit(prices, i+1, 0, cap, dp);
            dp[i][buy][cap]=max(op1, op2);
        }
        return dp[i][buy][cap];
    }
    int maxProfit(vector<int>& prices)
    {
        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(2, vector<int>(3, -1)));
        return maxProfit(prices, 0, 1, 2, dp);  
    }
};