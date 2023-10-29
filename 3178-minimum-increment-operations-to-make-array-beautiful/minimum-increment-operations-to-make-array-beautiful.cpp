typedef long long ll;
class Solution {
public:
/*
    ll minOps(vector<int>& nums, int k, int i, vector<int>& dp)
    {
        if (i>=nums.size()-2) return 0;

        if (dp[i]!=-1) return dp[i];
        
        if (nums[i]>=k || nums[i+1]>=k || nums[i+2]>=k) dp[i]=minOps(nums, k, i+1, dp);
        else
        {
            int op1=k-nums[i]+minOps(nums, k, i+1, dp);
            int op2=k-nums[i+1]+minOps(nums, k, i+2, dp);
            int op3=k-nums[i+2]+minOps(nums, k, i+3, dp);
            dp[i]=min({op1, op2, op3});
        }
        return dp[i];
    }
*/
    long long minIncrementOperations(vector<int>& nums, int k)
    {
        int n=nums.size();
        vector<ll> dp(n+1, 0);
        // return minOps(nums, k, 0, dp);
        for (int i=n-3; i>=0; i--)
        {
            if (nums[i]>=k || nums[i+1]>=k || nums[i+2]>=k) dp[i]=dp[i+1];
            else dp[i]=min({k-nums[i]+dp[i+1], k-nums[i+1]+dp[i+2], k-nums[i+2]+dp[i+3]});
        }
        return dp[0];
    }
};