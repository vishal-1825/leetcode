class Solution {
public:
    int waysToSplitArray(vector<int>& nums)
    {
        long long total=0;
        for (int num: nums)
            total+=num;

        long long sum=0, ans=0;
        for (int i=0; i<nums.size()-1; i++)
        {
            sum+=nums[i];
            if (sum>=total-sum)
                ans++;
        }
        return (int)ans;
    }
};