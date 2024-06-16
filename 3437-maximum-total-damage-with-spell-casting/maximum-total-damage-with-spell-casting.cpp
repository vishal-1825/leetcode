class Solution {
public:
    unordered_map<int, int> fq;
    long long maxDamage(vector<int>& nums, int i, vector<long long>& dp)
    {
        if (i>=nums.size()) return 0;

        if (dp[i]!=-1) return dp[i];

        int index;
        for (index=i; index<nums.size(); index++)
        {
            if (nums[index]>nums[i]+2)
                break;
        }
        long long include = (long long)nums[i]*(long long)fq[nums[i]] + maxDamage(nums, index, dp);
        long long exclude = maxDamage(nums, i+1, dp);
        
        return dp[i]=max(include, exclude); 
    }
    long long maximumTotalDamage(vector<int>& power)
    {
        for (int p: power)
            fq[p]++;
        vector<int> nums;
        for (auto f: fq)
            nums.push_back(f.first);
        sort(nums.begin(), nums.end());
        vector<long long> dp(nums.size(), -1);
        return maxDamage(nums, 0, dp);
    }
};