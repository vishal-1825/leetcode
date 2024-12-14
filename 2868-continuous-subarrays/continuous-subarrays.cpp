class Solution {
public:
    long long continuousSubarrays(vector<int>& nums)
    {
        long long ans=0;
        int i=0, j=0;
        int n=nums.size(), minval=nums[j], maxval=nums[j];
        for (j=0; j<n; j++)
        {
            minval=min(minval, nums[j]);
            maxval=max(maxval, nums[j]);

            if (maxval-minval>2)
            {
                ans+=(1LL*(j-i)*(j-i+1)/2);
                i=j;
                maxval=minval=nums[j];
                while (i>=0 && abs(nums[i]-maxval)<=2 && abs(nums[i]-minval)<=2)
                {
                    minval=min(minval, nums[i]);
                    maxval=max(maxval, nums[i]);
                    i--;
                }
                i++;
                if (i<j) ans-=(1LL*(j-i)*(j-i+1)/2);
            }
        }
        ans+=(1LL*(j-i)*(j-i+1)/2);
        return ans;
    }
};