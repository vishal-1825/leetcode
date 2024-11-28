class Solution {
public:
    // int minimumObstacles(vector<vector<int>>& grid)
    // {
    //     int m=grid.size(), n=grid[0].size();
    //     vector<vector<int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    //     vector<vector<int>> minObstacles(m, vector<int>(n, INT_MAX));
    //     minObstacles[0][0]=0;
    //     priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
    //     pq.push({0, 0, 0});
    //     while (!pq.empty())
    //     {
    //         int obstacles=pq.top()[0], i=pq.top()[1], j=pq.top()[2];
    //         pq.pop();
    //         if (i==m-1 && j==n-1) return obstacles;
    //         for (auto d: dir)
    //         {
    //             int x=i+d[0], y=j+d[1];
    //             if (x>=0 && x<m && y>=0 && y<n)
    //             {
    //                 int totalObstacles=obstacles+grid[x][y];
    //                 if (totalObstacles<minObstacles[x][y])
    //                 {
    //                     pq.push({totalObstacles, x, y});
    //                     minObstacles[x][y]=totalObstacles;
    //                 }
    //             }
    //         }
    //     }
    //     return -1;
    // }
    int minimumObstacles(vector<vector<int>>& grid)
    {
        int m=grid.size(), n=grid[0].size();
        vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        vector<vector<int>> minObstacles(m, vector<int>(n, INT_MAX));
        minObstacles[0][0]=0;
        deque<vector<int>> dq;
        dq.push_back({0, 0, 0});
        while (!dq.empty())
        {
            int obstacles=dq.front()[0], i=dq.front()[1], j=dq.front()[2];
            dq.pop_front();
            if (i==m-1 && j==n-1) return obstacles;
            for (auto d: dir)
            {
                int x=i+d[0], y=j+d[1];
                if (x>=0 && x<m && y>=0 && y<n && minObstacles[x][y]==INT_MAX)
                {
                    if (grid[x][y]==1)
                    {
                        minObstacles[x][y]=obstacles+1;
                        dq.push_back({obstacles+1, x, y});
                    }
                    else
                    {
                        minObstacles[x][y]=obstacles;
                        dq.push_front({obstacles, x, y});
                    }
                }
            }
        }
        return -1;
        // return minObstacles[m-1][n-1];
    }
};
