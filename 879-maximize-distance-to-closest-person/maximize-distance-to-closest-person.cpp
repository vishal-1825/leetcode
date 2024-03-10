class Solution {
public:
    int maxDistToClosest(vector<int>& seats)
    {
        int n=seats.size();
        vector<int> prev(n), next(n);
        if (seats[0]==1) prev[0]=0;
        else prev[0]=-1;
        for (int i=1; i<n; i++)
        {
            if (seats[i]==1) prev[i]=i;
            else prev[i]=prev[i-1];
        }
        if (seats[n-1]==1) next[n-1]=n-1;
        else next[n-1]=n;
        for (int i=n-2; i>=0; i--)
        {
            if (seats[i]==1) next[i]=i;
            else next[i]=next[i+1];
        }

        int ans=0;
        for (int i=0; i<n; i++)
        {
            if (seats[i]==0)
            {
                if (prev[i]==-1 && next[i]==n) ans=max(ans, n/2);
                else if (prev[i]==-1) ans=max(ans, next[i]-i);
                else if (next[i]==n) ans=max(ans, i-prev[i]);
                else ans=max(ans, min(i-prev[i], next[i]-i));
            }
        }
        return ans;
    }
};