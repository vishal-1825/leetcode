typedef long long int ll;
class Solution {
public:
    // try this again later
    int singleNumber(vector<int>& nums)
    {
        ll ans=0;
        int k=3; // solution applicable for any value of k, here k is given as 3
        for (int i=0; i<=31; i++)
        {
            int c=0;
            for (int j=0; j<nums.size(); j++)
            {
                if (nums[j] & 1) c++;
                nums[j]>>=1;
            }
            if (c%k) ans+=(1<<i);
        }
        return ans;
    }
};