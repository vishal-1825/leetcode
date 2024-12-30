class Solution {
public:
    long long mod=1e9+7;
    // long long countGoodStrings(vector<long long>& dp, int zero, int one, int low, int high, int count)
    // {
    //     if (count>high) return 0;
    //     if (dp[count]!=-1) return dp[count];
    //     long long addOne=countGoodStrings(dp, zero, one, low, high, count+one);
    //     long long addZero=countGoodStrings(dp, zero, one, low, high, count+zero);
    //     long long addNothing=((count>=low && count<=high) ? 1 : 0);
    //     return dp[count]=(addOne+addZero+addNothing)%mod;
    // }
    int countGoodStrings(int low, int high, int zero, int one)
    {
        // vector<long long> dp(high+1, -1);
        // return (int)(countGoodStrings(dp, zero, one, low, high, 0)%mod);
        vector<long long> dp(high+1);
        dp[0]=1;
        for (int i=1; i<=high; i++)
        {
            if (i>=zero) dp[i]=(dp[i]+dp[i-zero])%mod;
            if (i>=one) dp[i]=(dp[i]+dp[i-one])%mod;
        }

        long long ans=0;
        for (int i=low; i<=high; i++)
            ans=(ans+dp[i])%mod;
        return ans;
    }
};