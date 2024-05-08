class Solution {
public:
    long long minEnd(int n, int x)
    {
        n--;
        vector<long long> xbit(64, 0), nbit(64, 0);
        for (int i=0; i<32; i++)
        {
            xbit[i] = ((x>>i) & 1);
            nbit[i] = ((n>>i) & 1);
        }

        int i=0, j=0;
        while (i<64)
        {
            if (xbit[i]==0)
            {
                xbit[i]=nbit[j];
                j++;
            }
            i++;
        }

        long long ans=0;
        for (int i=0; i<64; i++)
        {
            if (xbit[i]==1)
                ans|=(1ll<<i);
        }
        return ans;
    }
};