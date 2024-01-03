class Solution {
public:
    // very difficult, i had no idea
    int findNumberOfLIS(vector<int>& nums)
    {
        int n=nums.size(), lenLIS=1;
        vector<int> dp(n, 1), count(n, 1);
        for (int i=1; i<n; i++)
        {
            for (int j=0; j<i; j++)
            {
                if (nums[j]<nums[i] && dp[j]+1==dp[i]) count[i]+=count[j];
                else if (nums[j]<nums[i] && dp[j]+1>dp[i])
                {
                    dp[i]=1+dp[j];
                    count[i]=count[j];
                }
            }
            lenLIS=max(lenLIS, dp[i]);
        }

        int ans=0;
        for (int i=0; i<n; i++)
        {
            if (dp[i]==lenLIS)
                ans+=count[i];
        }
        return ans;
    }
};