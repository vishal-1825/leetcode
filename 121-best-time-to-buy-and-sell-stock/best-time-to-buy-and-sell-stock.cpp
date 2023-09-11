class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
        int n=prices.size(), i, rightMax=0, max_diff=0;

        for (i=n-2; i>=0; i--)
        {
            rightMax=max(rightMax, prices[i+1]);
            max_diff=max(max_diff, rightMax-prices[i]);
        }
        return max_diff;



        // int i=0, n=prices.size(), maxDiff=0;
        // while (i<n-1)
        // {
        //     while (i<n-1 && prices[i]>=prices[i+1])
        //         i++;
            
        //     if (i==n-1) return 0;
            
        //     int buy=prices[i++];
        //     int sell=0;
        //     for (; i<n; i++)
        //         sell=max(sell, prices[i]);
            
        //     int diff=sell-buy;
        //     if (diff<0) continue;
        //     maxDiff=max(maxDiff, diff);
        // }
        // return maxDiff;
    }
};