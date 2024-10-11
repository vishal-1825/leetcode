class Solution {
public:
    // No idea
    int smallestChair(vector<vector<int>>& times, int targetFriend)
    {
        int n=times.size();
        vector<pair<int, int>> events;
        for (int i=0; i<n; i++)
        {
            // enter/exit time, friendIndex
            events.push_back({times[i][0], i}); // +ve -> enter time
            events.push_back({times[i][1], -i}); // -ve -> exit time
        }
        sort(events.begin(), events.end());

        // occupied -> exit time, chair number
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> occupied;
        priority_queue<int, vector<int>, greater<int>> available;
        for (int i=0; i<n; i++)
            available.push(i); // free chairs
        
        for (auto event: events)
        {
            int time=event.first;
            int friendIndex=event.second;
            while (!occupied.empty() && occupied.top().first<=time)
            {
                available.push(occupied.top().second);
                occupied.pop();
            }
            if (friendIndex>=0)
            {
                int chair=available.top();
                available.pop();
                if (friendIndex==targetFriend) return chair;
                occupied.push({times[friendIndex][1], chair});
            }
        }
        return -1;
    }
};