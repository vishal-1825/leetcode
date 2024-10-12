class Solution {
public:
    // Had no idea
    // int minGroups(vector<vector<int>>& intervals)
    // {
    //     if (intervals.size()==0 || intervals.size()==1) return intervals.size();
    //     // start -> +1, end -> -1
    //     vector<pair<int, int>> events;
    //     for (auto interval: intervals)
    //     {
    //         events.push_back({interval[0], 1});
    //         events.push_back({interval[1]+1, -1});
    //         // we give +1 so that when an enter event and exit event happend simultaneously we first add find max value and then subtract
    //         // If we subtract first we would ge the wrong answer
    //     }
    //     sort(events.begin(), events.end());
    //     int intersecting=0, maxIntersecting=0;
    //     for (auto e: events)
    //     {
    //         // if event is entry add 1, if event is exit subtract 1
    //         // this way at every point we know how many events are concurrent
    //         intersecting+=e.second;
    //         maxIntersecting=max(maxIntersecting, intersecting);
    //     }
    //     return maxIntersecting;
    // }
    int minGroups(vector<vector<int>>& intervals)
    {
        if (intervals.size()==0 || intervals.size()==1) return intervals.size();
        
        int start=INT_MAX, end=INT_MIN;
        for (auto interval: intervals)
        {
            start=min(start, interval[0]);
            end=max(end, interval[1]);
        }

        vector<int> events(end-start+2, 0);
        for (auto interval: intervals)
        {
            events[interval[0]-start]++;
            events[interval[1]-start+1]--;
        }

        int maxIntersecting=0, intersecting=0;
        for (int i=start; i<=end; i++)
        {
            intersecting+=events[i-start];
            maxIntersecting=max(maxIntersecting, intersecting);
        }
        return maxIntersecting;
    }
};