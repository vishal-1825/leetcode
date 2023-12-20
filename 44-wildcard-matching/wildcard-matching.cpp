class Solution {
public:
    // bool isMatch(string s, string p, int i, int j, vector<vector<int>>& dp)
    // {
    //     if (i==s.length() && j==p.length()) return true;
    //     if (j==p.length()) return false;
    //     if (i==s.length())
    //     {
    //         for (int k=j; k<p.length(); k++)
    //         {
    //             if (p[k]!='*')
    //                 return false;
    //         }
    //         return true;
    //     }

    //     if (dp[i][j]!=-1) return dp[i][j];

    //     if (s[i]==p[j] || p[j]=='?') return dp[i][j] = isMatch(s, p, i+1, j+1, dp);
    //     if (p[j]=='*') return dp[i][j] = (isMatch(s, p, i+1, j, dp) || isMatch(s, p, i, j+1, dp));
    //     return dp[i][j] = false;
    // }
    bool isMatch(string s, string p)
    {
        vector<vector<int>> dp(s.length()+1, vector<int>(p.length()+1, false));
        // return isMatch(s, p, 0, 0, dp);
        dp[s.length()][p.length()] = true;
        for (int k=p.length()-1; k>=0; k--)
        {
            if (p[k]!='*') dp[s.length()][k] = false;
            else dp[s.length()][k] = dp[s.length()][k+1];
        }
        for (int i=s.length()-1; i>=0; i--)
        {
            for (int j=p.length()-1; j>=0; j--)
            {
                if (s[i]==p[j] || p[j]=='?') dp[i][j] = dp[i+1][j+1];
                else if (p[j]=='*') dp[i][j] = (dp[i+1][j] || dp[i][j+1]);
                else dp[i][j] = false;
            }
            // dp1 = dp0;
        }
        return dp[0][0];
    }
};