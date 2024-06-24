class Solution {
public:
    // T -> O(2n), S -> O(2n)
    // long long maxCost(vector<int>& nums, int i, bool positive, vector<vector<long long>>& dp)
    // {
    //     if (i==nums.size()) return 0;

    //     if (dp[i][positive]!=-1) return dp[i][positive];

    //     long long thisGroup = (positive ? nums[i] : -nums[i]) + maxCost(nums, i+1, !positive, dp);
    //     long long newGroup = (positive ? nums[i] : -nums[i]) + maxCost(nums, i+1, true, dp);
    //     return dp[i][positive]=max(thisGroup, newGroup);
    // }
    long long maximumTotalCost(vector<int>& nums)
    {
        vector<vector<long long>> dp(nums.size()+1, vector<long long>(2, 0));
        // return maxCost(nums, 0, true, dp);
        for (int i=nums.size()-1; i>=0; i--)
        {
            dp[i][1]=nums[i]+max(dp[i+1][0], dp[i+1][1]);
            dp[i][0]=-nums[i]+dp[i+1][1];
        }
        return dp[0][1];
    }
};