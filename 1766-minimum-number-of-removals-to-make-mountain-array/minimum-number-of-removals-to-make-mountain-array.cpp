class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums)
    {
        // total length - (length of longest mountain subsequence)
        /* To find the longest mountain subsequence, find Longest increasing subsequence from 0 to i 
        and longest decreasing subsequence from i to n-1 i.e longest increasing subsequence from n-1 to i
        */ 
        int n=nums.size(), ans=1;
        vector<int> dp1(n, 1), dp2(n, 1);
        for (int cur=0; cur<n; cur++)
        {
            for (int prev=0; prev<cur; prev++)
            {
                if (nums[prev]<nums[cur])
                    dp1[cur]=max(dp1[cur], 1+dp1[prev]);
            }
        }
        for (int cur=n-1; cur>=0; cur--)
        {
            for (int prev=n-1; prev>cur; prev--)
            {
                if (nums[prev]<nums[cur])
                    dp2[cur]=max(dp2[cur], 1+dp2[prev]);
            }
        }
        for (int i=1; i<n-1; i++)
        {
            if (dp1[i]>1 && dp2[i]>1)
                ans=max(ans, dp1[i]+dp2[i]-1);
        }
        ans=n-ans;
        return ans;
    }
};