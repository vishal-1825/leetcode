class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int cur=0, next=1, profit=0, n=prices.size();
        while (next<n)
        {
            if (prices[next]>prices[cur])
                profit+=prices[next]-prices[cur];
            cur++;
            next++;
        }
        return profit;
    }
};