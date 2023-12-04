class Solution {
public:
    // No algorithm, recognize the  pattern to solve
    // I had no idea
    typedef long long ll;
    int minimumAddedCoins(vector<int>& coins, int target)
    {
        sort(coins.begin(), coins.end());

        ll covered=0;
        int index=0, ans=0;
        while (covered<target)
        {
            if (index<coins.size() && covered+1>=coins[index]) covered+=coins[index++];
            else
            {
                ans++;
                covered+=(covered+1);
            }
        }
        return ans;
    }
};