class Solution {
public:
    // int minDistance(string word1, string word2, int e1, int e2, vector<vector<int>>& dp)
    // {
    //     if (e1<0 && e2<0) return 0;
    //     else if (e1<0) return e2+1;
    //     else if (e2<0) return e1+1;

    //     if (dp[e1][e2]!=-1) return dp[e1][e2];

    //     if (word1[e1]==word2[e2]) dp[e1][e2]=minDistance(word1, word2, e1-1, e2-1, dp);
    //     else
    //     {
    //         int op1=1+minDistance(word1, word2, e1, e2-1, dp);
    //         int op2=1+minDistance(word1, word2, e1-1, e2, dp);
    //         int op3=1+minDistance(word1, word2, e1-1, e2-1, dp);
    //         dp[e1][e2]=min({op1, op2, op3});
    //     }
    //     return dp[e1][e2];
    // }
    int minDistance(string word1, string word2)
    {
        int i, j, w1=word1.size(), w2=word2.size();
        vector<vector<int>> dp(w1+1, vector<int>(w2+1, 0));
        for (i=1; i<=w1; i++)
            dp[i][0]=i;
        for (j=1; j<=w2; j++)
            dp[0][j]=j;
        
        for (i=1; i<=w1; i++)
        {
            for (j=1; j<=w2; j++)
            {
                if (word1[i-1]==word2[j-1]) dp[i][j]=dp[i-1][j-1];
                else dp[i][j]=min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]})+1;
            }
        }
        return dp[w1][w2];
    }
};