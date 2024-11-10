class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k)
    {
        int bor=0, left=0, ans=INT_MAX;
        vector<int> ones(32, 0);
        for (int right=0; right<nums.size(); right++)
        {
            bor|=nums[right];
            for (int i=0; i<=31; i++)
                ones[i]+=(nums[right]>>i & 1);
            while (left<=right && bor>=k)
            {
                ans=min(ans, right-left+1);
                for (int i=0; i<=31; i++)
                {
                    if (nums[left]>>i & 1)
                    {
                        ones[i]--;
                        if (ones[i]==0)
                            bor^=(1<<i);
                    }
                }
                left++;
            }
        }
        return (ans==INT_MAX ? -1 : ans);
    }
};