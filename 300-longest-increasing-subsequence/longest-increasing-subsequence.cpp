#include <climits>
class Solution {
public:
/*
    int getLIS(vector<int>& nums, int cur, int prev, int size, vector<vector<int>>& dp)
    {
        if (cur==size || size==0) return 0;

        if (dp[cur][prev+1]!=-1) return dp[cur][prev+1];
        int a=getLIS(nums, cur+1, prev, size, dp);
        if (prev==-1 || nums[prev]<nums[cur])
            a=max(a, 1+getLIS(nums, cur+1, cur, size, dp));
        dp[cur][prev+1]=a;
        return dp[cur][prev+1];
    }

    int lengthOfLIS(vector<int>& nums)
    {
        int n=nums.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int ans=getLIS(nums, 0, -1, n, dp);
        return ans;
    }
*/
    int lengthOfLIS(vector<int>& nums)
    {
        int n=nums.size(), ans=1;
        vector<int> dp(n);
        dp[n-1]=1;

        for (int i=n-2; i>=0; i--)
        {
            int right_max=0;
            for (int j=i+1; j<n; j++)
            {
                if (nums[j]>nums[i])
                    right_max=max(right_max, dp[j]);
            }
            dp[i]=1+right_max;
            ans=max(ans, dp[i]);
        }
        return ans;
    }
};