class Solution {
public:
    // Brute Force O(m^2*n^2)
    int maxGold(vector<vector<int>>& grid, int i, int j, int& m, int& n)
    {
        if (i<0 || j<0 || i>=m || j>=n || grid[i][j]==0) return 0;

        int val=grid[i][j];
        grid[i][j]=0;
        int top=val+maxGold(grid, i-1, j, m, n);
        int bottom=val+maxGold(grid, i+1, j, m, n);
        int left=val+maxGold(grid, i, j-1, m, n);
        int right=val+maxGold(grid, i, j+1, m, n);
        grid[i][j]=val;
        return max({top, bottom, left, right});
    }
    int getMaximumGold(vector<vector<int>>& grid)
    {
        int m=grid.size(), n=grid[0].size(), ans=0;
        for (int i=0; i<m; i++)
        {
            for (int j=0; j<n; j++)
                ans=max(ans, maxGold(grid, i, j, m, n));
        }
        return ans;
    }
};