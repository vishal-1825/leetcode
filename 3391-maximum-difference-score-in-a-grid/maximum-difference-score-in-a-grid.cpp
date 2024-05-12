class Solution {
public:
    // Key observation the distance between any two cells is constant irrespective of the path taken
    // because a-b = (a-x)+(x-b)
    // So if we fix the destination, the problem is to find the smallest possible start value to the left and top of each destination
    // Then calculate maximum difference from all these
    int maxScore(vector<vector<int>>& grid)
    {
        int m=grid.size(), n=grid[0].size(), ans=INT_MIN;
        vector<vector<int>> prevMin(m, vector<int>(n));
        prevMin[0][0]=grid[0][0];
        for (int i=1; i<n; i++)
        {
            prevMin[0][i]=min(prevMin[0][i-1], grid[0][i-1]);
            ans=max(ans, grid[0][i]-prevMin[0][i]);
        }
        for (int i=1; i<m; i++)
        {
            prevMin[i][0]=min(prevMin[i-1][0], grid[i-1][0]);
            ans=max(ans, grid[i][0]-prevMin[i][0]);
        }
        for (int i=1; i<m; i++)
        {
            for (int j=1; j<n; j++)
            {
                prevMin[i][j]=min({prevMin[i-1][j], grid[i-1][j], prevMin[i][j-1], grid[i][j-1]});
                ans=max(ans, grid[i][j]-prevMin[i][j]);
            }
        }
        return ans;
    }
};