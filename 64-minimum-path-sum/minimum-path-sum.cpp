class Solution {
public:
    int minPathSum(vector<vector<int>>& grid)
    {
        int r=grid.size(), c=grid[0].size();
        for (int i=c-2; i>=0; i--)
            grid[r-1][i]=grid[r-1][i+1]+grid[r-1][i];
        for (int i=r-2; i>=0; i--)
            grid[i][c-1]=grid[i+1][c-1]+grid[i][c-1];
        
        for (int i=r-2; i>=0; i--)
        {
            for (int j=c-2; j>=0; j--)
                grid[i][j]=grid[i][j]+min(grid[i+1][j], grid[i][j+1]);
        }
        return grid[0][0];
    }
};