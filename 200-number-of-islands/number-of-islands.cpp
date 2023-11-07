class Solution {
public:
    void markIsland(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j, int r, int c)
    {
        if (i<0 || j<0 || i>=r || j>=c) return;

        if (grid[i][j]=='1' && !visited[i][j])
        {
            visited[i][j]=true;
            markIsland(grid, visited, i-1, j, r, c); // up
            markIsland(grid, visited, i+1, j, r, c); // down
            markIsland(grid, visited, i, j-1, r, c); // left
            markIsland(grid, visited, i, j+1, r, c); // right
        }
    }
    int numIslands(vector<vector<char>>& grid)
    {
        int r=grid.size(), c=grid[0].size(), count=0;
        vector<vector<bool>> visited(r, vector<bool>(c, false));
        for (int i=0; i<r; i++)
        {
            for (int j=0; j<c; j++)
            {
                if (visited[i][j]) continue;

                if (grid[i][j]=='1')
                {
                    markIsland(grid, visited, i, j, r, c);
                    count++;
                }
            }
        }
        return count;
    }
};