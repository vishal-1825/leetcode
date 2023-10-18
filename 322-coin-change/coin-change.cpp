class Solution {
public:
    int coinChange(vector<int>& coins, int amount)
    {
        sort(coins.begin(), coins.end());
        vector<int> dp(amount+1, INT_MAX);
        dp[0]=0;

        for (int i=1; i<amount+1; i++)
        {
            for (int j=0; j<coins.size(); j++)
            {
                if (coins[j]>i) break;
                if (dp[i-coins[j]]!=INT_MAX)
                    dp[i]=min(dp[i], 1+dp[i-coins[j]]);
            }
        }

        return ((dp[amount]==INT_MAX) ? -1 : dp[amount]);
    }
};