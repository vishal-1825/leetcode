class Solution {
public:
    int countServers(vector<vector<int>>& grid)
    {
        int rows=grid.size(), cols=grid[0].size();
        vector<int> rowCount(rows), colCount(cols);
        for (int row=0; row<rows; row++)
        {
            int count=0;
            for (int col=0; col<cols; col++)
                count+=(grid[row][col]==1 ? 1 : 0);
            rowCount[row]=count;
        }
        for (int col=0; col<cols; col++)
        {
            int count=0;
            for (int row=0; row<rows; row++)
                count+=(grid[row][col]==1 ? 1 : 0);
            colCount[col]=count;
        }

        int ans=0;
        for (int row=0; row<rows; row++)
        {
            for (int col=0; col<cols; col++)
                ans+=((grid[row][col]==1 && (rowCount[row]>1 || colCount[col]>1)) ? 1 : 0);
        }
        return ans;
    }
};