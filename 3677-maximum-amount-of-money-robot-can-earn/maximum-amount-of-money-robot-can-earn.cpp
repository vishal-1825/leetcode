class Solution {
public:
    int maxAmt(vector<vector<int>>& coins, vector<vector<vector<int>>>& dp, int& m, int& n, int i, int j, int rob)
    {
        if (i==m-1 && j==n-1) return ((coins[i][j]<0 && rob>0) ? 0 : coins[i][j]);

        if (dp[i][j][rob]!=INT_MIN) return dp[i][j][rob];

        int right=INT_MIN, down=INT_MIN, rightNeutral=INT_MIN, downNeutral=INT_MIN;
        if (coins[i][j]<0 && rob>0)
        {
            if (j+1<n) rightNeutral=maxAmt(coins, dp, m, n, i, j+1, rob-1);
            if (i+1<m) downNeutral=maxAmt(coins, dp, m, n, i+1, j, rob-1);
        }
        if (j+1<n) right=coins[i][j]+maxAmt(coins, dp, m, n, i, j+1, rob);
        if (i+1<m) down=coins[i][j]+maxAmt(coins, dp, m, n, i+1, j, rob);
        return dp[i][j][rob]=max({right, down, rightNeutral, downNeutral});
    }
    int maximumAmount(vector<vector<int>>& coins)
    {
        int m=coins.size(), n=coins[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(3, INT_MIN)));
        return maxAmt(coins, dp, m, n, 0, 0, 2);
    }
};


// -16   4   1   -1
//  11   9   3    3
//  -6  17  -19   9
//  14 -17  -19  -13