class Solution {
public:
    long long dp[201][201][201];
    long long mod=1e9+7;
    long long subCount(vector<int>& nums, int gcd1, int gcd2, int i)
    {
        if (i==nums.size()) return (gcd1==gcd2 && gcd1!=0);
        if (dp[gcd1][gcd2][i]!=-1) return dp[gcd1][gcd2][i]%mod;
        long long op1=subCount(nums, __gcd(gcd1, nums[i]), gcd2, i+1)%mod;
        long long op2=subCount(nums, gcd1, __gcd(gcd2, nums[i]), i+1)%mod;
        long long op3=subCount(nums, gcd1, gcd2, i+1)%mod;
        return dp[gcd1][gcd2][i]=(op1+op2+op3)%mod;
    }
    int subsequencePairCount(vector<int>& nums)
    {
        memset(dp, -1, sizeof(dp));
        return (int)(subCount(nums, 0, 0, 0)%mod);
    }
};