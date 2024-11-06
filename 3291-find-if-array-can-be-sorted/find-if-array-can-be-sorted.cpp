class Solution {
public:
    bool canSortArray(vector<int>& nums)
    {
        vector<int> setbit;
        for (int n: nums)
        {
            int count=0;
            for (int i=0; i<=31; i++)
                count += ((n>>i & 1)==1 ? 1 : 0);
            setbit.push_back(count);
        }
        int i=0, j=0;
        while (i<nums.size())
        {
            while (j<nums.size() && setbit[j]==setbit[i])
                j++;
            sort(nums.begin()+i, nums.begin()+j);
            i=j;
        }
        for (int i=0; i<nums.size()-1; i++)
        {
            if (nums[i]>nums[i+1])
                return false;
        }
        return true;
    }
};