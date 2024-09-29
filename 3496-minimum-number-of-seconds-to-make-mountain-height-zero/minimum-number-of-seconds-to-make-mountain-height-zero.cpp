class Solution {
public:
    bool canMakeZero(int mountainHeight, vector<int>& workerTimes, long long time)
    {
        for (int w: workerTimes)
        {
            long long s=0, e=mountainHeight, h=1;
            while (s<=e)
            {
                long long x=(s+e)/2;
                if ((w*x*(x+1))/2 <= time)
                {
                    s=x+1;
                    h=x;
                }
                else e=x-1; 
            }
            mountainHeight-=h;
            if (mountainHeight<=0) break;
        }
        return (mountainHeight<=0);
    }
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes)
    {
        long long s=0, e=1e18, ans=0;
        while (s<=e)
        {
            long long m=(s+e)/2;
            if (canMakeZero(mountainHeight, workerTimes, m))
            {
                ans=m;
                e=m-1;
            }
            else s=m+1;
        }
        return ans;
    }
};