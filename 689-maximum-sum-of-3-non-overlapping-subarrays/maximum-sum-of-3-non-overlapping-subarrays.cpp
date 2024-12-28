class Solution {
public:
    // 17 15 13 8 4 4 4
    // 0  1  2  3 4 5 6
    vector<int> maxSum(vector<int>& ksum, vector<vector<vector<int>>>& dp, int k, int cur, int count)
    {
        if (cur==ksum.size() || count==3) return {};

        if (!dp[cur][count].empty()) return dp[cur][count];
        
        // include
        vector<int> include = {cur};
        vector<int> rem = maxSum(ksum, dp, k, (cur+k>ksum.size() ? (int)ksum.size() : cur+k), count+1);
        if (!rem.empty()) include.insert(include.end(), rem.begin(), rem.end());

        // exclude
        vector<int> exclude = maxSum(ksum, dp, k, cur+1, count);

        int incSum=0, excSum=0;
        for (int i: include)
            incSum+=ksum[i];
        for (int e: exclude)
            excSum+=ksum[e];
        
        return dp[cur][count]=(incSum>=excSum ? include : exclude);
    }
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k)
    {
        int sum=0;
        vector<int> ksum;
        for (int i=0; i<k; i++)
            sum+=nums[i];
        ksum.push_back(sum);
        for (int i=k; i<nums.size(); i++)
        {
            sum=sum+nums[i]-nums[i-k];
            ksum.push_back(sum);
        }

        vector<vector<vector<int>>> dp(ksum.size(), vector<vector<int>>(3));
        return maxSum(ksum, dp, k, 0, 0);
    }
};