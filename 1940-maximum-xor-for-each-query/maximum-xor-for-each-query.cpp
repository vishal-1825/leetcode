class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit)
    {
        int n=nums.size(), xxor=0;
        vector<int> ans(n);
        for (int i=0; i<n; i++)
        {
            xxor^=nums[i];
            int k=0;
            for (int j=0; j<maximumBit; j++)
            {
                if ((xxor>>j & 1)==0)
                    k = k | (1<<j);
            }
            ans[n-i-1]=k;
        }
        return ans;
    }
};