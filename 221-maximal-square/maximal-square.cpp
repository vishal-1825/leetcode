class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix)
    {
        int r=matrix.size(), c=matrix[0].size(), ans=0, f=0;
        vector<vector<int>> dp(r, vector<int>(c, 0));

        for (int i=0; i<r; i++)
        {
            for (int j=0; j<c; j++)
            {
                if (matrix[i][j]!='1') continue;
                f=1;
                dp[i][j]=1;
                if (i-1>=0 && j-1>=0 && dp[i-1][j-1])
                {
                    int n=dp[i-1][j-1], flag=1;
                    for (int k=1; k<=n; k++)
                    {
                        if (matrix[i-k][j]!='1' || matrix[i][j-k]!='1')
                        {
                            flag=0;
                            break;
                        }
                        dp[i][j]++;
                    }
                    if (flag) ans=max(ans, dp[i][j]);
                }

            }
        }
        return (f ? max(1, ans*ans): 0);
    }
};