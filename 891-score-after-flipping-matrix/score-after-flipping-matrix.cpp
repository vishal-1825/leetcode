class Solution {
public:
    // Greedy approach, take all rows and flip them such that 0th column of each row is 1
    // Take columns 1 to n-1, flip if count of 0s is less than count of 1s
    // T = O(m*n), S = O(1);
    int matrixScore(vector<vector<int>>& grid)
    {
        int m=grid.size(), n=grid[0].size(), ans=0;
        for (int i=0; i<m; i++)
        {
            if (grid[i][0]==0)
            {
                for (int j=0; j<n; j++)
                    grid[i][j]^=1;
            }
        }
        for (int j=1; j<n; j++)
        {
            int ones=0;
            for (int i=0; i<m; i++)
                ones+=grid[i][j];
            if (ones<m-ones)
            {
                for (int i=0; i<m; i++)
                    grid[i][j]^=1;
            }
        }
        for (int i=0; i<m; i++)
        {
            for (int j=0; j<n; j++)
                ans+=(grid[i][j]<<(n-j-1));
        }
        return ans;
    }
};