class Solution {
public:
    void markPossible(vector<vector<int>>& grid, int i, int j, int& r, int& c)
    {
        if (i<0 || i>=r || j<0 || j>=c || grid[i][j]!=1) return;

        grid[i][j]=-1;
        markPossible(grid, i-1, j, r, c);
        markPossible(grid, i+1, j, r, c);
        markPossible(grid, i, j-1, r, c);
        markPossible(grid, i, j+1, r, c);
    }
    int numEnclaves(vector<vector<int>>& grid)
    {
        int r=grid.size(), c=grid[0].size(), ans=0;
        for (int i=0; i<r; i++)
        {
            if (grid[i][0]==1) markPossible(grid, i, 0, r, c);
            if (grid[i][c-1]==1) markPossible(grid, i, c-1, r, c);
        }
        for (int i=0; i<c; i++)
        {
            if (grid[0][i]==1) markPossible(grid, 0, i, r, c);
            if (grid[r-1][i]==1) markPossible(grid, r-1, i, r, c);
        }

        for (int i=0; i<r; i++)
        {
            for (int j=0; j<c; j++)
            {
                if (grid[i][j]==1) ans++;
                else if (grid[i][j]==-1) grid[i][j]==1;
            }
        }
        return ans;
    }
};