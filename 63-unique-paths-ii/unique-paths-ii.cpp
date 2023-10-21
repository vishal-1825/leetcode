class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>> grid)
    {
        int r=grid.size(), c=grid[0].size();
        if (grid[0][0]==1 || grid[r-1][c-1]==1) return 0;
        grid[r-1][c-1]=1;
        for (int i=r-2; i>=0; i--)
        {
            if (grid[i][c-1]==1) grid[i][c-1]=0;
            else grid[i][c-1]=grid[i+1][c-1];
        }
        for (int j=c-2; j>=0; j--)
        {
            if (grid[r-1][j]==1) grid[r-1][j]=0;
            else grid[r-1][j]=grid[r-1][j+1];
        }

        for (int i=r-2; i>=0; i--)
        {
            for (int j=c-2; j>=0; j--)
            {
                if (grid[i][j]==1 || (long)grid[i+1][j]+(long)grid[i][j+1]>2*1e9) grid[i][j]=0;
                else grid[i][j]=grid[i+1][j]+grid[i][j+1];
            }
        }
        return (int)grid[0][0];
    }
};