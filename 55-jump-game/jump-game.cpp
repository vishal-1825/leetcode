class Solution {
public:
    bool canJump(vector<int>& nums)
    {
        int n=nums.size(), i, end=n-1;
        for (i=n-2; i>=0; i--)
        {
            if (i+nums[i]>=end)
                end=i;
        }
        return (end<=0);
    }
};