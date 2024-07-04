class Solution {
public:
    /*
    vector<vector<vector<int>>> dp;
    int maxLength(vector<int>& nums, int& k, int cur, int prev, int prevrem)
    {
        if (cur==nums.size()) return 0;
        
        if (dp[cur+1][prev+1][prevrem+1]!=-1) return dp[cur+1][prev+1][prevrem+1];
        
        int inc=0, exc=0;
        if (prev==-1)
        {
            inc=1+maxLength(nums, k, cur+1, cur, prevrem);
            exc=maxLength(nums, k, cur+1, prev, prevrem);
        }
        else if (prevrem==-1)
        {
            inc=1+maxLength(nums, k, cur+1, cur, (nums[prev]+nums[cur])%k);
            exc=maxLength(nums, k, cur+1, prev, prevrem);
        }
        else
        {
            if (prevrem==(nums[prev]+nums[cur])%k) inc=1+maxLength(nums, k, cur+1, cur, (nums[prev]+nums[cur])%k);
            exc=maxLength(nums, k, cur+1, prev, prevrem);
        }
        return dp[cur+1][prev+1][prevrem+1]=max(inc, exc);
    }
    int maximumLength(vector<int>& nums, int k)
    {
        int n=nums.size();
        dp.resize(n+1, vector<vector<int>>(n+1, vector<int>(k+1, -1)));
        return maxLength(nums, k, 0, -1, -1);
    }
    */
    int maximumLength(vector<int>& nums, int k)
    {
        int n=nums.size(), ans=1;
        vector<vector<int>> dp(n, vector<int>(k, 1));
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<i; j++)
            {
                int mod=(nums[i]+nums[j])%k;
                dp[i][mod]=max(dp[i][mod], 1+dp[j][mod]);
                ans=max(ans, dp[i][mod]);
            }
        }
        return ans;
    }
};