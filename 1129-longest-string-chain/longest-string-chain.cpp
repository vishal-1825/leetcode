class Solution {
public:
    static bool cmp(string& s1, string& s2)
    {
        if (s1.length()==s2.length()) return (s1 < s2);
        return (s1.length() <= s2.length());
    }
    bool compare(string wi, string wj)
    {
        int li=wi.length(), lj=wj.length(), i=0, j=0;
        if (lj!=li-1) return false;
        if (wj.substr(1)==wi || wi.substr(0, li-1)==wj) return true;
        
        while (i<li && j<lj)
        {
            if (wi[i]==wj[j])
            {
                i++;
                j++;
            }
            else i++;
        }
        return (i==li && j==lj);
    }
    int longestStrChain(vector<string>& words)
    {
        // similar to LIS
        sort(words.begin(), words.end(), cmp);
        int n=words.size(), ans=1;
        vector<int> dp(n, 1);
        for (int i=1; i<n; i++) //current
        {
            for (int j=0; j<i; j++) // previous
            {
                if (compare(words[i], words[j]) && 1+dp[j]>dp[i])
                    dp[i]=1+dp[j];
            }
            ans=max(ans, dp[i]);
        }
        return ans;
    }
};