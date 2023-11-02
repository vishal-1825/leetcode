typedef long long int ll;
class Solution {
public:
    // try this again later
    int singleNumber(vector<int>& nums)
    {
        ll expo=1, ans=0;
        int k=3; // solution applicable for any value of k, here k is given as 3
        for (int i=0; i<=31; i++)
        {
            int c=0;
            for (int j=0; j<nums.size(); j++)
            {
                if (nums[j] & 1) c++;
                nums[j]=nums[j]>>1;
            }
            if (c%k) ans+=expo;
            expo*=2;
        }
        return ans;
    }
};