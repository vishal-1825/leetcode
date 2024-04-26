class Solution {
public:
    // T: O(n^3), S: O(n^2)
    // int mfps(vector<vector<int>>& grid, int& row, int& col, int r, int prev, vector<vector<int>>& dp)
    // {
    //     if (r==row) return 0;

    //     if (dp[r][prev+1]!=-1) return dp[r][prev+1];

    //     int ans=INT_MAX;
    //     for (int c=prev+1; c<col; c++)
    //         ans=min(ans, grid[r][c]+mfps(grid, row, col, r+1, c, dp));
    //     for (int c=prev-1; c>=0; c--)
    //         ans=min(ans, grid[r][c]+mfps(grid, row, col, r+1, c, dp));
    //     return dp[r][prev+1]=ans;
    // }
    // int minFallingPathSum(vector<vector<int>>& grid)
    // {
    //     int row=grid.size(), col=grid[0].size();
    //     vector<vector<int>> dp(row, vector<int>(row+1, -1));
    //     return mfps(grid, row, col, 0, -1, dp);
    // }
    int minFallingPathSum(vector<vector<int>>& grid)
    {
        int row=grid.size(), col=grid[0].size();
        vector<vector<int>> dp = grid;
        int ans=INT_MAX;
        for (int r=0; r<row; r++)
        {
            for (int c=0; c<col; c++)
            {
                int minval=INT_MAX;
                for (int prevCol=0; r-1>=0 && prevCol<col; prevCol++)
                {
                    if (prevCol==c) continue;
                    minval=min(minval, dp[r-1][prevCol]);
                }
                if (minval!=INT_MAX) dp[r][c]=grid[r][c]+minval;
                if (r==row-1) ans=min(ans, dp[r][c]);
            }
        }
        return ans;
    }
};