class Solution {
public:
    int countMaxOr(vector<int>& nums, int& maxOr, int curOr, int i, vector<vector<int>>& dp)
    {
        if (i==nums.size()) return ((curOr==maxOr) ? 1 : 0);

        if (dp[curOr][i]!=-1) return dp[curOr][i];
        int exc = countMaxOr(nums, maxOr, curOr, i+1, dp);
        int inc = countMaxOr(nums, maxOr, curOr | nums[i], i+1, dp);
        return dp[curOr][i] = inc + exc;
    }
    int countMaxOrSubsets(vector<int>& nums)
    {
        int maxOr = 0;
        for (int n: nums)
            maxOr = maxOr | n;
        vector<vector<int>> dp(maxOr+1, vector<int>(nums.size(), -1));
        int ans = countMaxOr(nums, maxOr, 0, 0, dp);
        return ans;
    }
};