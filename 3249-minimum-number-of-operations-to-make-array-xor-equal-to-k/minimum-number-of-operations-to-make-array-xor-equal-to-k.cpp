class Solution {
public:
    int minOperations(vector<int>& nums, int k)
    {
        int val=0, ans=0;
        for (int n: nums)
            val=val^n;
        for (int i=0; i<=31; i++)
        {
            if ((val>>i & 1) != (k>>i & 1))
                ans++;
        }
        return ans;
    }
};