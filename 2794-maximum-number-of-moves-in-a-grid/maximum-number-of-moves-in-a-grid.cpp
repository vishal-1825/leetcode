class Solution {
public:
    int maxMoves(vector<vector<int>>& grid)
    {
        int row=grid.size(), col=grid[0].size(), ans=0;
        vector<vector<int>> dp(row, vector<int>(col, 0));
        for (int r=0; r<row; r++)
            dp[r][0]=1;
        for (int c=1; c<col; c++)
        {
            for (int r=0; r<row; r++)
            {
                int one=0, two=0, three=0;
                if (r-1>=0 && dp[r-1][c-1]>0 && grid[r-1][c-1]<grid[r][c]) one=1+dp[r-1][c-1];
                if (dp[r][c-1]>0 && grid[r][c-1]<grid[r][c]) two=1+dp[r][c-1];
                if (r+1<row && dp[r+1][c-1]>0 && grid[r+1][c-1]<grid[r][c]) three=1+dp[r+1][c-1];
                dp[r][c]=max({one, two, three});
                ans=max(ans, dp[r][c]-1);
            }
        }
        for (int r=0; r<row; r++)
        {
            for (int c=0; c<col; c++)
                cout << dp[r][c] << " ";
            cout << endl;
        }
        return ans;
    }
};