class Solution {
public:
    int findMinDifference(vector<string>& timePoints)
    {
        int n=timePoints.size(), ans=24*60;
        vector<int> times;
        for (string tp: timePoints)
        {
            int h=stoi(tp.substr(0, 2)), m=stoi(tp.substr(3));
            int t=h*60+m;
            times.push_back(t);
        }
        sort(times.begin(), times.end());
        for (int i=0; i<n-1; i++)
        {
            ans=min(ans, abs(times[i]-times[i+1]));
            ans=min(ans, 24*60-abs(times[i]-times[i+1]));
        }
        ans=min(ans, abs(times[0]-times[n-1]));
        ans=min(ans, 24*60-abs(times[0]-times[n-1]));
        return ans;
    }
};