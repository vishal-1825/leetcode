class Solution {
public:
    int maxProfit(vector<int>& nums, int ind, int prev, int first, vector<vector<vector<int>>>& dp)
    {
        if (ind==nums.size()) return 0;

        if (dp[ind][prev][first]!=-1) return dp[ind][prev][first];

        if (ind==0)
        {
            int op1=nums[ind]+maxProfit(nums, ind+1, ind+1, 1, dp);
            int op2=maxProfit(nums, ind+1, prev, first, dp);
            dp[ind][prev][first]=max(op1, op2);
        }
        else if (prev==ind || (first && ind==nums.size()-1))
            dp[ind][prev][first]=maxProfit(nums, ind+1, prev, first, dp);
        else
        {
            int op1=nums[ind]+maxProfit(nums, ind+1, ind+1, first, dp);
            int op2=maxProfit(nums, ind+1, prev, first, dp);
            dp[ind][prev][first]=max(op1, op2);
        }
        return dp[ind][prev][first];
    }
    int rob(vector<int>& nums)
    {
        int n=nums.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(n+1, vector<int>(2, -1)));
        return maxProfit(nums, 0, 0, 0, dp);    
    }
};