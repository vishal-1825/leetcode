class Solution {
public:
    // int getMinSum(int x, int y, vector<vector<int>>& matrix, int n, vector<vector<int>>& dp)
    // {
    //     if (x<0 || x>=n) return INT_MAX; // edge case
    //     if (x==n-1) return matrix[x][y]; // base case

    //     if (dp[x][y]!=-1) return dp[x][y];

    //     int op1 = INT_MAX, op2 = INT_MAX, op3 = INT_MAX;
    //     if (x+1<n)
    //     {
    //         if (y-1>=0) op1 = getMinSum(x+1, y-1, matrix, n, dp);
    //         op2 = getMinSum(x+1, y, matrix, n, dp);
    //         if (y+1<n) op3 = getMinSum(x+1, y+1, matrix, n, dp);
    //     }
    //     return dp[x][y] = matrix[x][y] + min({op1, op2, op3});
    // }
    int minFallingPathSum(vector<vector<int>>& matrix)
    {
        int n=matrix.size(), ans=INT_MAX;
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        // for (int i=0; i<n; i++)
        // {
        //     int sum = getMinSum(0, i, matrix, n, dp);
        //     ans=min(ans, sum);
        // }
        // return ans;
        for (int i=0; i<n; i++)
            dp[n-1][i]=matrix[n-1][i];
        
        for (int x=n-2; x>=0; x--)
        {
            for (int y=0; y<n; y++)
            {
                int op1 = INT_MAX, op2 = INT_MAX, op3 = INT_MAX;
                if (y-1>=0) op1 = dp[x+1][y-1]; // getMinSum(x+1, y-1, matrix, n, dp);
                op2 = dp[x+1][y]; // getMinSum(x+1, y, matrix, n, dp);
                if (y+1<n) op3 = dp[x+1][y+1]; // getMinSum(x+1, y+1, matrix, n, dp);
                dp[x][y] = matrix[x][y] + min({op1, op2, op3});
            }
        }

        for (int i=0; i<n; i++)
            ans=min(ans, dp[0][i]);
        return ans;
    }
};