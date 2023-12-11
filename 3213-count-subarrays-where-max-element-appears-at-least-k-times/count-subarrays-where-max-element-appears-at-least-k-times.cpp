class Solution {
public:
    // Couldn't implement without help
    typedef long long ll;
    long long countSubarrays(vector<int>& nums, int k)
    {
        ll ans=0;
        int maximum=0, n=nums.size(), count=0;
        for (int i=0; i<n; i++)
            maximum=max(maximum, nums[i]);
        
        int l=0, r=0;
        for (r=0; r<n; r++)
        {
            if (nums[r]==maximum) count++;
            while (count>=k)
            {
                ans+=(n-r);
                if (nums[l]==maximum) count--;
                l++;
            }
        }
        return ans;
    }
};