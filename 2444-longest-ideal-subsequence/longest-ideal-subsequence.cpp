class Solution {
public:
    // int lis(string s, int& k, int cur, int prev, vector<vector<int>>& dp)
    // {
    //     if (cur==s.length()) return 0;

    //     if (dp[cur][prev+1]!=-1) return dp[cur][prev+1];

    //     int op1=0, op2;
    //     if (prev==-1 || abs(s[prev]-s[cur])<=k) op1=1+lis(s, k, cur+1, cur, dp);
    //     op2=lis(s, k, cur+1, prev, dp);
    //     return dp[cur][prev+1]=max(op1, op2);
    // }
    int longestIdealString(string s, int k)
    {
        int n=s.length(), ans=1;
        vector<int> dp(n, 1);
        unordered_map<char, int> lastpos;
        lastpos[s[0]]=0;
        for (int i=1; i<n; i++)
        {
            char low='a', high='z';
            if (s[i]-k>low) low=s[i]-k;
            if (s[i]+k<high) high=s[i]+k;
            for (char c=s[i]; c<=high; c++)
            {
                if (lastpos.find(c)!=lastpos.end())
                    dp[i]=max(dp[i], 1+dp[lastpos[c]]);
            }
            for (char c=s[i]; c>=low; c--)
            {
                if (lastpos.find(c)!=lastpos.end())
                    dp[i]=max(dp[i], 1+dp[lastpos[c]]);
            }
            ans=max(ans, dp[i]);
            lastpos[s[i]]=i;
        }
        return ans;
    }
};