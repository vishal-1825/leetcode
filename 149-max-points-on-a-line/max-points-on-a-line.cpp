class Solution {
public:
    // time -> O(n^2), space O(n)
    int maxPoints(vector<vector<int>>& points)
    {
        if (points.size()==1) return 1;

        int n=points.size(), ans=2;
        for (int i=0; i<n; i++)
        {
            unordered_map<double, int> slope;
            for (int j=i+1; j<n; j++)
            {
                double num=double(points[j][1]-points[i][1]);
                double den=double(points[j][0]-points[i][0]);
                double slp = ((den==0) ? INT_MAX : num/den);
                if (slope.find(slp)==slope.end()) slope[slp]=2;
                else
                {
                    slope[slp]++;
                    ans=max(ans, slope[slp]);
                }
            }
        }
        return ans;
    }
};