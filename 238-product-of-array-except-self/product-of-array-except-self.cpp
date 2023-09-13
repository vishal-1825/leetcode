class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        int n=nums.size(), i, lp=1, rp=1;
        vector<int> l(n), r(n), ans(n);
        for (i=0; i<n; i++)
        {
            l[i]=lp;
            lp*=nums[i];

            r[n-i-1]=rp;
            rp*=nums[n-i-1];
        }
        for (i=0; i<n; i++)
            ans[i]=l[i]*r[i];
        return ans;
    }
};