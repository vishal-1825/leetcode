class Solution {
public:
    int change(int amount, vector<int>& coins)
    {
        int ans=0;
        // vector<vector<int>> dp(coins.size()+1, vector<int>(amount+1, 0));
        // vector<int> d1(amount+1, 0), d2(amount+1, 0);
        // d1[0]=1;
        // d2[0]=1;
        vector<int> d(amount+1, 0);
        d[0]=1;
        // for (int c=0; c<=coins.size(); c++)
        //     dp[c][0]=1;
        
        for (int c=coins.size()-1; c>=0; c--)
        {
            for (int a=1; a<=amount; a++)
            {
                // d1[a]=d2[a];
                if (coins[c]<=a) d[a]+=d[a-coins[c]];// d1[a]+=d1[a-coins[c]];
            }
            // d2=d1;
        }
        return d[amount];
        // return d1[amount];
    }
    // int change(int amount, vector<int>& coins, int i, vector<vector<int>>& dp)
    // {
    //     if (amount==0) return 1;
    //     if (i==coins.size()) return 0;

    //     if (dp[amount][i]!=-1) return dp[amount][i];

    //     int op1=0;
    //     if (coins[i]<=amount) op1 = change(amount-coins[i], coins, i, dp);
    //     int op2 = change(amount, coins, i+1, dp);

    //     return dp[amount][i]=(op1+op2);
    // }
    // int change(int amount, vector<int>& coins)
    // {
    //     vector<vector<int>> dp(amount+1, vector<int>(coins.size()+1, -1));
    //     return change(amount, coins, 0, dp); // reverse -> i from coins.size() to 0, j from 0 to amount
    // }
};