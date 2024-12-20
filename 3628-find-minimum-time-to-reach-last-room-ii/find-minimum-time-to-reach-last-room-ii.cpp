class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime)
    {
        int n=moveTime.size(), m=moveTime[0].size();
        vector<vector<int>> minTime(n, vector<int>(m, INT_MAX));
        minTime[0][0]=0;
        vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        priority_queue<pair<pair<int, int>, pair<int, int>>, vector<pair<pair<int, int>, pair<int, int>>>, greater<pair<pair<int, int>, pair<int, int>>>> pq;
        pq.push({{0, 1}, {0, 0}});
        while (!pq.empty())
        {
            int timeSoFar=pq.top().first.first;
            int oddEven=pq.top().first.second;
            int i=pq.top().second.first;
            int j=pq.top().second.second;
            pq.pop();
            for (auto d: dir)
            {
                int x=i+d[0], y=j+d[1];
                if (x>=0 && x<n && y>=0 && y<m)
                {
                    int time=max(timeSoFar, moveTime[x][y])+oddEven;
                    if (time<minTime[x][y])
                    {
                        minTime[x][y]=time;
                        pq.push({{time, oddEven%2+1}, {x, y}});
                    }
                }
            }
        }
        return minTime[n-1][m-1];    
    }
};