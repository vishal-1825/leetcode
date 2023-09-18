class Solution {
public:
    int countWays(vector<int>& nums)
    {
        int n=nums.size(), i, ans=0;
        sort(nums.begin(), nums.end());

        if (0<nums[0]) ans++;
        for (i=0; i<n-1; i++)
        {
            if (i+1>nums[i] && i+1<nums[i+1]) ans++;
        }
        if (n>nums[n-1]) ans++;
        return ans;
    }
    // 0 2 3 3 6 6 7 7
};