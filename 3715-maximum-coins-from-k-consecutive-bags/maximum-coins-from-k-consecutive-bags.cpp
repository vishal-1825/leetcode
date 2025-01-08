class Solution {
public:
    // had no idea, copied from solution
    long long maximumCoins(vector<vector<int>>& coins, int k)
    {
        int n=coins.size();
        sort(coins.begin(), coins.end());
        
        long long ans=0, sum=0;
        for (int left=0, right=0; left<n; left++)
        {
            while (right<n && coins[left][0]+k-1>=coins[right][1])
            {
                sum+=1LL*(coins[right][1]-coins[right][0]+1)*coins[right][2];
                right++;
            }
            if (right<n)
            {
                long long partialSum=1LL*max(0, coins[left][0]+k-1-coins[right][0]+1)*coins[right][2];
                ans=max(ans, sum+partialSum);
            }
            sum-=1LL*(coins[left][1]-coins[left][0]+1)*coins[left][2];
        }
        sum=0;
        for (int right=0, left=0; right<n; right++)
        {
            sum+=1LL*(coins[right][1]-coins[right][0]+1)*coins[right][2];
            while (coins[left][1]<coins[right][1]-k+1)
            {
                sum-=1LL*(coins[left][1]-coins[left][0]+1)*coins[left][2];
                left++;
            }
            long long partialSum=1LL*max(0, coins[right][1]-k-coins[left][0]+1)*coins[left][2];
            ans=max(ans, sum-partialSum);
        }
        return ans;
    }
};