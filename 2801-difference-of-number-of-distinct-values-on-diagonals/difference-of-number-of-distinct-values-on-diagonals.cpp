class Solution {
public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid)
    {
        int rows=grid.size(), cols=grid[0].size();
        vector<vector<int>> topLeft(rows, vector<int>(cols, 0));
        vector<vector<int>> bottomRight(rows, vector<int>(cols, 0));
        for (int col=0; col<cols; col++)
        {
            int i=0, j=col;
            unordered_set<int> hash;
            while (i<rows && j<cols)
            {
                if (i-1>=0 && j-1>=0) topLeft[i][j]=hash.size();
                hash.insert(grid[i][j]);
                i++;
                j++;
            }
        }
        for (int row=0; row<rows; row++)
        {
            int i=row, j=0;
            unordered_set<int> hash;
            while (i<rows && j<cols)
            {
                if (i-1>=0 && j-1>=0) topLeft[i][j]=hash.size();
                hash.insert(grid[i][j]);
                i++;
                j++;
            }
        }

        for (int col=cols-1; col>=0; col--)
        {
            int i=rows-1, j=col;
            unordered_set<int> hash;
            while (i>=0 && j>=0)
            {
                if (i+1<rows || j+1<cols) bottomRight[i][j]=hash.size();
                hash.insert(grid[i][j]);
                i--;
                j--;
            }
        }
        for (int row=rows-1; row>=0; row--)
        {
            int i=row, j=cols-1;
            unordered_set<int> hash;
            while (i>=0 && j>=0)
            {
                if (i+1<rows || j+1<cols) bottomRight[i][j]=hash.size();
                hash.insert(grid[i][j]);
                i--;
                j--;
            }
        }

        vector<vector<int>> ans(rows, vector<int>(cols));
        for (int i=0; i<rows; i++)
        {
            for (int j=0; j<cols; j++)
                ans[i][j]=abs(topLeft[i][j]-bottomRight[i][j]);
        }
        return ans;
    }
};