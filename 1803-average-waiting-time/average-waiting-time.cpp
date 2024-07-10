class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers)
    {
        int n=customers.size(), curtime=0;
        double ans=0;
        for (int i=0; i<n; i++)
        {
            ans+=customers[i][1];
            if (curtime<=customers[i][0]) curtime=customers[i][0]+customers[i][1];
            else
            {
                ans+=curtime-customers[i][0];
                curtime+=customers[i][1];
            }
        }
        ans/=n;
        return ans;
    }
};