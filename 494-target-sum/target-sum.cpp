class Solution {
public:
    int findWays(vector<int>& nums, int& target, int i, int sum, int& tot, vector<vector<int>>& dp)
    {
        if (i==nums.size())
        {
            if (sum-(tot-sum)==target) return 1;
            return 0;
        }

        if (dp[sum][i]!=-1) return dp[sum][i];

        int op1 = findWays(nums, target, i+1, sum+nums[i], tot, dp);
        int op2 = findWays(nums, target, i+1, sum, tot, dp);
        return dp[sum][i]=op1+op2;
    }
    int findTargetSumWays(vector<int>& nums, int target)
    {
        int tot=0;
        for (int i=0; i<nums.size(); i++)
            tot+=nums[i];
        
        vector<vector<int>> dp(tot+1, vector<int>(nums.size()+1, -1));
        int ans = findWays(nums, target, 0, 0, tot, dp);
        return ans;
    }
};