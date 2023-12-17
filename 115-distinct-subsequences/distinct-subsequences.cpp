class Solution {
public:
    // int numSeq(string s, string t, int i, int j, vector<vector<int>>& dp)
    // {
    //     if (j==t.size()) return 1;
    //     if (i==s.size()) return 0;

    //     if (dp[i][j]!=-1) return dp[i][j];

    //     if (s[i]==t[j]) return dp[i][j] = numSeq(s, t, i+1, j+1, dp) + numSeq(s, t, i+1, j, dp);
    //     return dp[i][j] = numSeq(s, t, i+1, j, dp);
    // }
    // some weird runtime error keeps coming while trying to optimize space
    typedef long long int ll;
    long long int mod = 1e9+7;
    int numDistinct(string s, string t)
    {
        // vector<vector<ll>> dp(s.size()+1, vector<ll>(t.size()+1, 0));
        vector<ll> dp0(t.size()+1), dp1(t.size()+1);
        dp0[t.size()]=1;
        dp1[t.size()]=1;
        // return numSeq(s, t, 0, 0, dp);
        // for (int i=0; i<=s.size(); i++)
        //     dp[i][t.size()]=1;
        for (int i=s.size()-1; i>=0; i--)
        {
            for (int j=t.size()-1; j>=0; j--)
            {
                if (s[i]==t[j]) dp0[j] = (dp1[j+1] + dp1[j]) % mod;
                else dp0[j] = dp1[j];
            }
            dp1 = dp0;
        }
        return dp0[0];
    }
};