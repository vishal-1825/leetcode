class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k)
    {
        if (k<=1) return 0;

        int n=nums.size(), ans=0, p=1;
        int i=0, j=0;
        for (int i=0; i<n; i++)
        {
            while (j<n && p<k)
                p*=nums[j++];
            if (p>=k)
            {
                j--;
                p/=nums[j];
            }

            if(j-i>=1)
            {
                ans+=(j-i);
                p/=nums[i];
            }
            else j=i+1;
        }
        return ans;
        // for (int i=0; i<n; i++)
        // {
        //     int p=1;
        //     for (int j=i; j<n; j++)
        //     {
        //         p*=nums[j];
        //         if (p>=k) break;
        //         ans++;
        //     }
        // }
        // return ans;
    }
};