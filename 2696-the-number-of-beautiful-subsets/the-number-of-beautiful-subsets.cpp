class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int& k, int i, int mask)
    {
        if (i==nums.size())
        {
            if (mask!=0) return 1;
            return 0;
        }

        int exclude = beautifulSubsets(nums, k, i+1, mask);
        bool isBeautiful=true;
        for (int ind=i; ind>=0; ind--)
        {
            if ((mask >> ind) & 1)
            {
                if (nums[ind]==nums[i]+k || nums[ind]==nums[i]-k)
                {
                    isBeautiful=false;
                    break;
                }
            }
        }
        int include=0;
        if (isBeautiful) include = beautifulSubsets(nums, k, i+1, (mask|(1<<i)));
        return include+exclude;
    }
    int beautifulSubsets(vector<int>& nums, int k)
    {
        return beautifulSubsets(nums, k, 0, 0);
    }
};