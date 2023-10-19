class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict)
    {
        int n=s.length();
        unordered_set<string> wordict;
        for (auto& wd: wordDict)
            wordict.insert(wd);
        
        vector<bool> dp(n+1, false);
        dp[0]=true;

        // got the approach right but the implementation wrong
        for (int i=1; i<=n; i++)
        {
            for (int j=i-1; j>=0; j--)
            {
                if (dp[j] && wordict.find(s.substr(j, i-j))!=wordict.end())
                {
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[n];
    }
};