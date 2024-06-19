class Solution {
public:
    int bouquet(vector<int>& bloomDay, int days, int k)
    {
        int count=0, c=0;
        for (int i=0; i<bloomDay.size(); i++)
        {
            if (bloomDay[i]<=days) c++;
            else c=0;
            if (c==k)
            {
                count++;
                c=0;
            }
        }
        return count;
    }
    int minDays(vector<int>& bloomDay, int m, int k)
    {
        int l=0, r=bloomDay[0];
        for (int i=1; i<bloomDay.size(); i++)
            r=max(r, bloomDay[i]);
        
        int ans=-1;
        while (l<=r)
        {
            int mid=(l+r)/2;
            if (bouquet(bloomDay, mid, k)>=m)
            {
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};