class Solution {
public:
    // int minInsertions(string s, int l, int r, vector<vector<int>>& dp)
    // {
    //     if (l>=r) return 0;

    //     if (dp[l][r]!=-1) return dp[l][r];

    //     if (s[l]!=s[r])
    //     {
    //         int op1 = 1 + minInsertions(s, l+1, r, dp);
    //         int op2 = 1 + minInsertions(s, l, r-1, dp);
    //         return dp[l][r]=min(op1, op2);
    //     }
    //     return dp[l][r]=minInsertions(s, l+1, r-1, dp);
    // }
    int minInsertions(string s)
    {
        int n=s.length(); // , l=0, r=n-1;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        // return minInsertions(s, l, r, dp);
        for (int l=n-2; l>=0; l--)
        {
            for (int r=1; r<n; r++)
            {
                if (l>=r) continue;
                if (s[l]!=s[r]) dp[l][r] = min(1+dp[l+1][r], 1+dp[l][r-1]);
                else dp[l][r] = dp[l+1][r-1];
            }
        }
        return dp[0][n-1];
    }
};