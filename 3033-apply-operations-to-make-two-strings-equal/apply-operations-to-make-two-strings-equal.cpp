class Solution {
public:
    int getMinCost(int l, int r, vector<int>& fault, int x, vector<vector<int>>& dp)
    {
        if (l>=r) return 0;

        if (dp[l][r]!=-1) return dp[l][r];

        int c1=min(x, fault[l+1]-fault[l])+getMinCost(l+2, r, fault, x, dp);
        int c2=min(x, fault[r]-fault[l])+getMinCost(l+1, r-1, fault, x, dp);
        int c3=min(x, fault[r]-fault[r-1])+getMinCost(l, r-2, fault, x, dp);
        return dp[l][r]=min({c1, c2, c3});
    }
    int minOperations(string s1, string s2, int x)
    {
        int size=s1.length(), i, n=0;
        vector<int> fault;

        for (i=0; i<size; i++)
        {
            if (s1[i]!=s2[i])
            {
                fault.push_back(i);
                n++;
            }
        }

        if (n%2==1) return -1;
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return getMinCost(0, n-1, fault, x, dp);
    }
};