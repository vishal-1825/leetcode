class Solution {
public:
    // vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    // int minObst(int i, int j, int& m, int& n, vector<vector<int>>& grid, vector<vector<bool>>& vis)
    // {
    //     if (i==m-1 && j==n-1) return 0;
    //     vis[i][j]=true;
    //     int ans=m*n;
    //     for (auto d: dir)
    //     {
    //         int x=i+d[0], y=j+d[1];
    //         if (x>=0 && x<m && y>=0 && y<n && !vis[x][y])
    //         {
    //             int removal=minObst(x, y, m, n, grid, vis);
    //             if (grid[x][y]==1) removal++;
    //             ans=min(ans, removal);
    //         } 
    //     }
    //     vis[i][j]=false;
    //     return dp[i][j]=ans;
    // }
    int minimumObstacles(vector<vector<int>>& grid)
    {
        // vector<vector<bool>> vis(m, vector<bool>(n, false));
        // return minObst(0, 0, m, n, grid, vis);
        int m=grid.size(), n=grid[0].size();
        vector<vector<int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        vector<vector<int>> minObstacles(m, vector<int>(n, INT_MAX));
        minObstacles[0][0]=0;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, 0, 0});
        while (!pq.empty())
        {
            int obstacles=pq.top()[0], i=pq.top()[1], j=pq.top()[2];
            pq.pop();
            if (i==m-1 && j==n-1) return obstacles;
            for (auto d: dir)
            {
                int x=i+d[0], y=j+d[1];
                if (x>=0 && x<m && y>=0 && y<n)
                {
                    int totalObstacles=obstacles+grid[x][y];
                    if (totalObstacles<minObstacles[x][y])
                    {
                        pq.push({totalObstacles, x, y});
                        minObstacles[x][y]=totalObstacles;
                    }
                }
            }
        }
        return -1;
    }
};
