class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater)
    {
        int m=isWater.size(), n=isWater[0].size();
        vector<vector<int>> height(m, vector<int>(n));
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        queue<pair<int, int>> coord;
        for (int i=0; i<m; i++)
        {
            for (int j=0; j<n; j++)
            {
                if (isWater[i][j]==1)
                {
                    coord.push({i, j});
                    vis[i][j]=true;
                }
            }
        }

        vector<vector<int>> dirs={{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while (!coord.empty())
        {
            int x=coord.front().first, y=coord.front().second;
            coord.pop();

            for (auto dir: dirs)
            {
                int i=x+dir[0], j=y+dir[1];
                if (i>=0 && i<m && j>=0 && j<n && !vis[i][j])
                {
                    height[i][j]=1+height[x][y];
                    vis[i][j]=true;
                    coord.push({i, j});
                }
            }
        }
        return height;
    }
};