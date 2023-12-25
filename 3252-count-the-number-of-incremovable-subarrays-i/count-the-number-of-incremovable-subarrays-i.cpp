class Solution {
public:
    bool incremovable(vector<int>& nums, int i, int j, int n)
    {
        for (int x=i-1; x>=1; x--)
        {
            if (nums[x-1]>=nums[x])
                return false;
        }
        for (int x=j+1; x<n-1; x++)
        {
            if (nums[x]>=nums[x+1])
                return false;
        }
        if (i-1>=0 && j+1<n && nums[i-1]>=nums[j+1])
            return false;
        return true;
    }
    int incremovableSubarrayCount(vector<int>& nums)
    {
        int n=nums.size(), ans=0;
        for (int i=0; i<n; i++)
        {
            for (int j=i; j<n; j++)
            {
                if (incremovable(nums, i, j, n))
                    ans++;
            }
        }
        return ans;
    }
};