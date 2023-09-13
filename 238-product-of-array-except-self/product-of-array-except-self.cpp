class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        int n=nums.size(), i, r=1;
        vector<int> ans(n);
        ans[0]=1;
        for (i=1; i<n; i++)
            ans[i]=ans[i-1]*nums[i-1];
        for (i=n-1; i>=0; i--)
        {
            ans[i]=ans[i]*r;
            r*=nums[i];
        }
        return ans;
    }
};