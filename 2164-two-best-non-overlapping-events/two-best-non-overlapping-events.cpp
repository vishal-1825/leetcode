class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events, int cur, int count, vector<vector<int>>& dp)
    {
        if (count==2 || cur==events.size()) return 0;
        
        if (dp[cur][count]!=-1) return dp[cur][count];
        int left=cur+1, right=events.size()-1, next=cur+1;
        while (left<=right)
        {
            int mid=(left+right)/2;
            if (events[mid][0]>events[cur][1])
            {
                next=mid;
                right=mid-1;
            }
            else left=mid+1;
        }
        int include=events[cur][2]+(next<events.size() && events[next][0]>events[cur][1] ? maxTwoEvents(events, next, count+1, dp) : 0);
        int exclude=maxTwoEvents(events, cur+1, count, dp);
        return dp[cur][count]=max(include, exclude);
    }
    int maxTwoEvents(vector<vector<int>>& events)
    {
        sort(events.begin(), events.end());
        vector<vector<int>> dp(events.size(), vector<int>(3, -1));
        return maxTwoEvents(events, 0, 0, dp); 
    }
};