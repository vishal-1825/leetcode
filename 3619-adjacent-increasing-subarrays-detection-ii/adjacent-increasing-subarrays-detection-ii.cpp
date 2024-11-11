class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums)
    {
        int prev=0, cur=1, ans=1;
        for (int i=1; i<nums.size(); i++)
        {
            if (nums[i]>nums[i-1]) cur++;
            else
            {
                prev=cur;
                cur=1;
            }
            ans=max({ans, cur/2, min(prev, cur)});
        }
        return ans;
    }
};

// 2 5 7 8 9 2 3 4 3 1
// 1 2 3 4 5 1 2 3 1 2