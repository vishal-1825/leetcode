class Solution {
public:
    string longestPalindrome(string s)
    {
        int n=s.length();
        if (n==0) return s;

        string ans="";
        ans+=s[0];
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int i=0; i<n; i++)
            dp[i][i]=true;
        for (int i=n-1; i>=0; i--)
        {
            for (int j=i+1; j<n; j++)
            {
                if (s[i]==s[j] && (j-i==1 || dp[i+1][j-1]))
                {
                    dp[i][j]=true;
                    if (j-i+1 > ans.length()) ans=s.substr(i, j-i+1); 
                }
            }
        }
        return ans;
    }
};