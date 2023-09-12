class Solution {
public:
    // int getMinCount(vector<int>& nums, int s, int n, vector<int>& dp)
    // {
    //     if (s>=n-1) return 0;

    //     if (dp[s]!=-1) return dp[s];
    //     int ans=n+1;
    //     for (int i=1; i<=nums[s]; i++)
    //         ans=min(ans, 1+getMinCount(nums, s+i, n, dp));
    //     dp[s]=ans;
    //     return ans;
    // }
    // int jump(vector<int>& nums)
    // {
    //     int n=nums.size();
    //     vector<int> dp(n, -1);
    //     int ans=getMinCount(nums, 0, n, dp);
    //     return ans;
    // }
    int jump(vector<int>& nums)
    {
        int n=nums.size();
        vector<int> dp(n, -1);
        dp[n-1]=0;
        for (int s=n-2; s>=0; s--)
        {
            int ans=n+1;
            for (int i=1; i<=nums[s]; i++)
            {
                if (s+i>=0 && s+i<n)
                    ans=min(ans, 1+dp[s+i]);
            }
            dp[s]=ans;
        }
        return dp[0];
    }
};