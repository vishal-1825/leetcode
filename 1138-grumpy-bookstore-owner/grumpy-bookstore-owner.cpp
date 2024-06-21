class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes)
    {
        int n=customers.size(), extra=0, ans=0;
        for (int i=0; i<minutes; i++)
        {
            if (grumpy[i]==1)
                extra+=customers[i];
        }
        ans=extra;
        for (int i=minutes; i<n; i++)
        {
            if (grumpy[i-minutes]==1) extra-=customers[i-minutes];
            if (grumpy[i]==1) extra+=customers[i];
            if (extra>ans) ans=extra;
        }

        for (int i=0; i<n; i++)
        {
            if (grumpy[i]==0)
                ans+=customers[i];
        }
        return ans;
    }
};