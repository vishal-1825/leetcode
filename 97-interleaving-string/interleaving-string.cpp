class Solution {
public:
    bool isInterleave(string s1, string s2, string s3, int i, int j, int k, vector<vector<int>>& dp)
    {
        if (k==s3.size() && i==s1.size() && j==s2.size()) return true;
        if (i>s1.size() || j>s2.size()) return false;
        if (dp[i][j]!=-1) return dp[i][j];

        if (s1[i]==s3[k] && s2[j]==s3[k])
            dp[i][j]=(isInterleave(s1, s2, s3, i+1, j, k+1, dp) 
            || isInterleave(s1, s2, s3, i, j+1, k+1, dp));
        else if (s1[i]==s3[k]) dp[i][j]=isInterleave(s1, s2, s3, i+1, j, k+1, dp);
        else if (s2[j]==s3[k]) dp[i][j]=isInterleave(s1, s2, s3, i, j+1, k+1, dp);
        else dp[i][j]=false;
        return dp[i][j];
    }
    bool isInterleave(string s1, string s2, string s3)
    {
        int i=0, j=0, k=0;
        vector<vector<int>> dp(s1.size()+1, vector<int>(s2.size()+1, -1));
        return isInterleave(s1, s2, s3, i, j, k, dp);
    }
};