class Solution {
public:
    int LPS(string s, int l, int r, vector<vector<int>>& dp)
    {
        if (l==r) return 1;
        if (l>r) return 0;

        if (dp[l][r]!=-1) return dp[l][r];
        if (s[l]==s[r]) return dp[l][r] = 2 + LPS(s, l+1, r-1, dp);
        int op1 = LPS(s, l+1, r, dp);
        int op2 = LPS(s, l, r-1, dp);
        return dp[l][r] = max(op1, op2);
    }
    int longestPalindromeSubseq(string s)
    {
        int n=s.length(), l=0, r=n-1;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        // return LPS(s, l, r, dp);

        for (int i=0; i<n; i++)
            dp[i][i]=1;
        for (int l=n-2; l>=0; l--)
        {
            for (int r=1; r<n; r++)
            {
                if (l>=r) continue;
                if (s[l]==s[r]) dp[l][r]=2+dp[l+1][r-1];
                else dp[l][r]=max(dp[l+1][r], dp[l][r-1]);
            }
        }
        return dp[0][n-1];
    }
};