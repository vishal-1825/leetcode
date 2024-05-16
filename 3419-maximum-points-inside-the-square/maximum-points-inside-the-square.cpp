class Solution {
public:
    int maxPointsInsideSquare(vector<vector<int>>& points, string s)
    {
        int l=0, r=0, ans=0;
        for (int i=0; i<points.size(); i++)
            r=max(r, max(abs(points[i][0]), abs(points[i][1])));
        while (l<=r)
        {
            int m=(l+r)/2;
            int high=m, low=-m, count=0;
            unordered_set<char> tag;
            for (int i=0; i<points.size(); i++)
            {
                if (points[i][0]<=high && points[i][0]>=low && points[i][1]<=high && points[i][1]>=low)
                {
                    if (tag.find(s[i])!=tag.end())
                    {
                        count=-1;
                        break;
                    }
                    tag.insert(s[i]);
                    count++;
                }
            }
            if (count>=ans)
            {
                l=m+1;
                ans=count;
            }
            else r=m-1;
        }
        return ans;
    }
};