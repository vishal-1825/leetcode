class Solution {
public:
    int SD(int n1, int n2)
    {
        for (int i=2; i<=n2; i++)
        {
            if (n1%i==0)
                return i;
        }
        return -1;
    }
    int minOperations(vector<int>& nums)
    {
        int n=nums.size(), ans=0;
        for (int i=n-2; i>=0; i--)
        {
            if (nums[i]>nums[i+1])
            {
                ans++;
                nums[i]=SD(nums[i], nums[i+1]);
                if (nums[i]==-1) return -1;
            }
        }
        return ans;
    }
};