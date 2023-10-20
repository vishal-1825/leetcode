class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle)
    {
        int r=triangle.size(), ans=INT_MAX;
        if (r==0) return 0;
        if (r==1) return triangle[0][0];

        vector<vector<int>> dp(r, vector<int>(r, 0));
        dp[0][0]=triangle[0][0];
        for (int i=1; i<r; i++)
        {
            for (int j=0; j<=i; j++)
            {
                if (j==0) dp[i][0]=triangle[i][0]+dp[i-1][0];
                else if (j==i) dp[i][i]=triangle[i][i]+dp[i-1][i-1];
                else dp[i][j]=triangle[i][j]+min(dp[i-1][j], dp[i-1][j-1]);
                
                if (i==r-1) ans=min(ans, dp[r-1][j]);
            }
        }
    
        return ans;
    }
};