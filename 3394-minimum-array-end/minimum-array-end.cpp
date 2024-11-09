class Solution {
public:
    long long minEnd(int n, int x)
    {
        vector<long long> xbit(64, 0), nbit(64, 0);
        for (int i=0; i<=31; i++)
        {
            xbit[i] = (x>>i) & 1;
            nbit[i] = ((n-1)>>i) & 1;
        }

        int i=0, j=0;
        for (i=0; i<=63; i++)
        {
            if (xbit[i]==0)
                xbit[i] = nbit[j++];
        }

        long long ans=0;
        for (int i=0; i<=63; i++)
        {
            if (xbit[i]==1)
                ans = ans | (1ll<<i);
        }
        return ans;
    }
};