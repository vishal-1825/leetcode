class Solution {
public:
    typedef long long ll;
    // No idea, had to refer solution :(
    // 2 options take element or skip to form subsequence
    // whenever you take switch the sign from 1 to 0 (+ to - alternating sum) and use same sign when you skip
    /*
    ll maxSum(vector<int>& nums, int i, int sign, vector<vector<ll>>& dp)
    {
        if (i==nums.size()) return 0;

        if (dp[i][sign]!=-1) return dp[i][sign];

        if (sign==1) // odd position, so add
        {
            ll include=nums[i]+maxSum(nums, i+1, 0, dp);
            ll exclude=maxSum(nums, i+1, 1, dp);
            return dp[i][sign]=max(include, exclude);
        }
        // else if sign==0 even position, so subtract
        ll include=-nums[i]+maxSum(nums, i+1, 1, dp);
        ll exclude=maxSum(nums, i+1, 0, dp);
        return dp[i][sign]=max(include, exclude);
    }
    long long maxAlternatingSum(vector<int>& nums)
    {
        int sign=1;
        vector<vector<ll>> dp(nums.size()+1, vector<ll>(2, -1));
        ll ans=maxSum(nums, 0, sign, dp);
        return ans;
    }
    */
    long long maxAlternatingSum(vector<int>& nums)
    {
        int n=nums.size();
        vector<vector<ll>> dp(n+1, vector<ll>(2, 0));
        dp[n][0]=0;
        dp[n][1]=0;
        for (int i=n-1; i>=0; i--)
        {
            dp[i][1]=max(nums[i]+dp[i+1][0], dp[i+1][1]);
            dp[i][0]=max(-nums[i]+dp[i+1][1], dp[i+1][0]);
        }

        return max(dp[0][0], dp[0][1]);
    }
};