class Solution {
public:
    int minOperations(int k)
    {
        if (k==1) return 0;

        int ans=INT_MAX;
        for (int i=1; i<k; i++)
        {
            int op=(i-1)+(k-i)/i;
            if ((k-i)%i!=0) op++;
            ans=min(ans, op);
        }
        return ans;
    }
};