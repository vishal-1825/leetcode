class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval)
    {
        int n=intervals.size(), i;
        bool first=true;
        vector<vector<int>> ans;

        for (i=0; i<n; i++)
        {
            if (intervals[i][0]<=newInterval[0]) ans.push_back(intervals[i]);
            else if (first)
            {
                if (i==0) ans.push_back(newInterval);
                else
                {
                    if (ans.back()[1]>=newInterval[0])
                    {
                        ans.back()[0]=min(ans.back()[0], newInterval[0]);
                        ans.back()[1]=max(ans.back()[1], newInterval[1]);
                    }
                    else ans.push_back(newInterval);
                }
                i--;
                first=false;
            }
            else
            {
                if (ans.back()[1]>=intervals[i][0])
                {
                    ans.back()[0]=min(ans.back()[0], intervals[i][0]);
                    ans.back()[1]=max(ans.back()[1], intervals[i][1]);
                }
                else ans.push_back(intervals[i]);
            }
        }
        if (first)
        {
            if (i==0) ans.push_back(newInterval);
            else
            {
                if (ans.back()[1]>=newInterval[0])
                {
                    ans.back()[0]=min(ans.back()[0], newInterval[0]);
                    ans.back()[1]=max(ans.back()[1], newInterval[1]);
                }
                else ans.push_back(newInterval);
            }
        }

        return ans;
    }
};