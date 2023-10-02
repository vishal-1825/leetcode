class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b)
    {
        return (a[1]<b[1]);
    }
    int findMinArrowShots(vector<vector<int>>& points)
    {
        int n=points.size(), i=0, ans=0;
        sort(points.begin(), points.end(), cmp);

        while (i<n)
        {
            int interval=points[i][1];
            while (i<n && points[i][0]<=interval) i++;
            ans++;
        }
        return ans;  
    }
};