class Solution {
public:
    int maxScore(vector<int>& values, vector<int>& dp, int n, int leftMax, int i)
    {
        if (i==n) return 0;

        if (dp[i]!=-1) return dp[i];
        int ans=0;
        if (leftMax>-1) ans=max(ans, values[i]-i+leftMax);
        else leftMax=values[i]+i;
        leftMax=max(leftMax, values[i]+i);
        ans=max(ans, maxScore(values, dp, n, max(leftMax, values[i]+i), i+1));
        return dp[i]=ans;
    }
    int maxScoreSightseeingPair(vector<int>& values)
    {
        int n=values.size(), leftMax=-1;
        vector<int> dp(n, -1);
        return maxScore(values, dp, n, leftMax, 0);
    }
};