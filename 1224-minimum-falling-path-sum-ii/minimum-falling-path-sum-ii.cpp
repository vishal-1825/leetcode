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
    // T: O(n^3), S: O(n^2)
    // int minFallingPathSum(vector<vector<int>>& grid)
    // {
    //     int row=grid.size(), col=grid[0].size();
    //     vector<vector<int>> dp = grid;
    //     int ans=INT_MAX;
    //     for (int r=0; r<row; r++)
    //     {
    //         for (int c=0; c<col; c++)
    //         {
    //             int minval=INT_MAX;
    //             for (int prevCol=0; r-1>=0 && prevCol<col; prevCol++)
    //             {
    //                 if (prevCol==c) continue;
    //                 minval=min(minval, dp[r-1][prevCol]);
    //             }
    //             if (minval!=INT_MAX) dp[r][c]+=minval;
    //             if (r==row-1) ans=min(ans, dp[r][c]);
    //         }
    //     }
    //     return ans;
    // }
    // T: O(n^2), S: O(n^2)
    int minFallingPathSum(vector<vector<int>>& grid)
    {
        int row=grid.size(), col=grid[0].size(), ans=INT_MAX;
        vector<vector<int>> dp = grid;
        for (int i=0; i<row; i++)
        {
            pair<int, int> smallestAbove = {INT_MAX, -1}, secondAbove = {INT_MAX, -1};
            for (int j=0; i-1>=0 && j<col; j++)
            {
                if (dp[i-1][j]<smallestAbove.first)
                {
                    secondAbove=smallestAbove;
                    smallestAbove={dp[i-1][j], j};
                }
                else if (dp[i-1][j]<secondAbove.first) secondAbove={dp[i-1][j], j};
            }

            for (int j=0; j<col; j++)
            {
                if (i>0 && smallestAbove.second==j) dp[i][j]+=secondAbove.first;
                else if (i>0) dp[i][j]+=smallestAbove.first;
                if (i==row-1) ans=min(ans, dp[i][j]);
            }
        }
        return ans;
    }
};