class Solution {
public:
    // Recursion -> Memoization -> 2D DP -> two 1D DP
    // int LCS(string& text1, string& text2, int l1, int l2, vector<vector<int>>& dp)
    // {
    //     if (l1==0 || l2==0) return 0;

    //     if (dp[l1][l2]!=-1) return dp[l1][l2];
        
    //     if (text1[l1-1]==text2[l2-1]) dp[l1][l2] = 1 + LCS(text1, text2, l1-1, l2-1, dp);
    //     else
    //     {
    //         int op1 = LCS(text1, text2, l1-1, l2, dp);
    //         int op2 = LCS(text1, text2, l1, l2-1, dp);
    //         dp[l1][l2] = max(op1, op2);
    //     }
    //     return dp[l1][l2];
    // }
    int longestCommonSubsequence(string text1, string text2)
    {
        int l1=text1.length(), l2=text2.length();
        // vector<vector<int>> dp(l1+1, vector<int>(l2+1, -1));
        // return LCS(text1, text2, l1, l2, dp);
        vector<int> dp0(l2+1, 0), dp1(l2+1, 0);

        for (int i=1; i<=l1; i++)
        {
            for (int j=1; j<=l2; j++)
            {
                int op1=0;
                if (text1[i-1]==text2[j-1]) dp1[j]=1+dp0[j-1];
                else
                {
                    int op1=dp0[j];//dp[i-1][j];
                    int op2=dp1[j-1];//dp[i][j-1];
                    // dp[i][j]=max({op1, op2, op3});
                    dp1[j]=max(op1, op2);
                }
            }
            dp0=dp1;
        }
        return dp1[l2];
    }
};