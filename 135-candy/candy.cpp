class Solution {
public:
    int candy(vector<int>& rating)
    {
        int i, n=rating.size(), ans;
        vector<int> v(n, 1);
        for (i=1; i<n; i++)
        {
            if (rating[i]>rating[i-1])
                v[i]=v[i-1]+1;
        }
        ans=v[n-1];
        for (i=n-2; i>=0; i--)
        {
            if (rating[i]>rating[i+1])
                v[i]=max(v[i], v[i+1]+1);
            ans+=v[i];
        }
        return ans;
    }
};