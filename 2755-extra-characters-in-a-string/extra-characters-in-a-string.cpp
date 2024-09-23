class Solution {
public:
    int minChar(int i, int& n, string& s, vector<string>& dictionary, vector<int>& dp)
    {
        if (i==n) return 0;
        if (dp[i]!=-1) return dp[i];
        int ans=n;
        for (string d: dictionary)
        {
            int inc=n;
            if (i+d.length()<=n && d==s.substr(i, d.length()))
                inc=minChar(i+d.length(), n, s, dictionary, dp);
            int exc=1+minChar(i+1, n, s, dictionary, dp);
            ans=min(ans, min(inc, exc));
        }
        return dp[i]=ans;
    }
    int minExtraChar(string s, vector<string>& dictionary)
    {
        int n=s.length();
        vector<int> dp(n, -1);
        return minChar(0, n, s, dictionary, dp);
    }
};