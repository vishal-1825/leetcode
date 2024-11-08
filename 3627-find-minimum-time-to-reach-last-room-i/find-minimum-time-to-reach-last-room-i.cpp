class Solution {
public:
    // dijkstra
    // int minTimeToReach(vector<vector<int>>& moveTime)
    // {
    //     int n=moveTime.size(), m=moveTime[0].size();
    //     vector<vector<int>> minTime(n, vector<int>(m, INT_MAX));
    //     minTime[0][0]=0;
    //     vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    //     priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    //     pq.push({0, {0, 0}});
    //     while (!pq.empty())
    //     {
    //         int timeSoFar=pq.top().first;
    //         int i=pq.top().second.first;
    //         int j=pq.top().second.second;
    //         pq.pop();
    //         for (auto d: dir)
    //         {
    //             int x=i+d[0], y=j+d[1];
    //             if (x>=0 && x<n && y>=0 && y<m)
    //             {
    //                 int time=max(timeSoFar, moveTime[x][y])+1;
    //                 if (time<minTime[x][y])
    //                 {
    //                     minTime[x][y]=time;
    //                     pq.push({time, {x, y}});
    //                 }
    //             }
    //         }
    //     }
    //     return minTime[n-1][m-1];
    // }
    // bfs
    int minTimeToReach(vector<vector<int>>& moveTime)
    {
        int n=moveTime.size(), m=moveTime[0].size();
        vector<vector<int>> minTime(n, vector<int>(m, INT_MAX));
        minTime[0][0]=0;
        vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {0, 0}});
        while (!q.empty())
        {
            int timeSoFar=q.front().first;
            int i=q.front().second.first;
            int j=q.front().second.second;
            q.pop();
            for (auto d: dir)
            {
                int x=i+d[0], y=j+d[1];
                if (x>=0 && x<n && y>=0 && y<m)
                {
                    int time=max(timeSoFar, moveTime[x][y])+1;
                    if (time<minTime[x][y])
                    {
                        minTime[x][y]=time;
                        q.push({time, {x, y}});
                    }
                }
            }
        }
        return minTime[n-1][m-1];
    }
};