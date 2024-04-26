class Solution {
public:
    int mfps(vector<vector<int>>& grid, int& row, int& col, int r, int prev, vector<vector<int>>& dp)
    {
        if (r==row) return 0;

        if (dp[r][prev+1]!=-1) return dp[r][prev+1];

        int ans=INT_MAX;
        for (int c=prev+1; c<col; c++)
            ans=min(ans, grid[r][c]+mfps(grid, row, col, r+1, c, dp));
        for (int c=prev-1; c>=0; c--)
            ans=min(ans, grid[r][c]+mfps(grid, row, col, r+1, c, dp));
        return dp[r][prev+1]=ans;
    }
    int minFallingPathSum(vector<vector<int>>& grid)
    {
        int row=grid.size(), col=grid[0].size();
        vector<vector<int>> dp(row, vector<int>(row+1, -1));
        return mfps(grid, row, col, 0, -1, dp);
    }
};