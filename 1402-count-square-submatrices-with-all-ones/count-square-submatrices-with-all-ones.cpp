class Solution {
public:
    int countSquares(vector<vector<int>>& matrix)
    {
        int r=matrix.size(), c=matrix[0].size(), ans=0;
        vector<vector<int>> dp(r, vector<int>(c, 0));
        for (int i=0; i<r; i++)
            dp[i][0]=matrix[i][0], ans+=dp[i][0];
        for (int j=1; j<c; j++)
            dp[0][j]=matrix[0][j], ans+=dp[0][j];
        for (int i=1; i<r; i++)
        {
            for (int j=1; j<c; j++)
            {
                if (matrix[i][j]==0) continue;
                dp[i][j]=1+min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
                ans+=dp[i][j];
            }
        }
        return ans;
    }
};