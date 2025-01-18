class Solution {
public:
    // long long minCost(vector<vector<int>>& grid, vector<vector<bool>>& vis, int r, int c, int i, int j)
    // {
    //     if (i==r-1 && j==c-1) return 0;
    //     vis[i][j]=true;

    //     long long noChange=INT_MAX;
    //     if (j+1<c && grid[i][j]==1 && !vis[i][j+1]) noChange=minCost(grid, vis, r, c, i, j+1);
    //     else if (j-1>=0 && grid[i][j]==2 && !vis[i][j-1]) noChange=minCost(grid, vis, r, c, i, j-1);
    //     else if (i+1<r && grid[i][j]==3 && !vis[i+1][j]) noChange=minCost(grid, vis, r, c, i+1, j);
    //     else if (i-1>=0 && grid[i][j]==4 && !vis[i-1][j]) noChange=minCost(grid, vis, r, c, i-1, j);

    //     long long change1=INT_MAX, change2=INT_MAX, change3=INT_MAX, change4=INT_MAX;
    //     if (j+1<c && grid[i][j]!=1 && !vis[i][j+1]) change1=1+minCost(grid, vis, r, c, i, j+1);
    //     if (j-1>=0 && grid[i][j]!=2 && !vis[i][j-1]) change2=1+minCost(grid, vis, r, c, i, j-1);
    //     if (i+1<r && grid[i][j]!=3 && !vis[i+1][j]) change3=1+minCost(grid, vis, r, c, i+1, j);
    //     if (i-1>=0 && grid[i][j]!=4 && !vis[i-1][j]) change4=1+minCost(grid, vis, r, c, i-1, j);

    //     vis[i][j]=false;
    //     return min({noChange, change1, change2, change3, change4});
    // }
    int minCost(vector<vector<int>>& grid)
    {
        int r=grid.size(), c=grid[0].size();
        vector<vector<int>> direction = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        vector<vector<int>> pathCost(r, vector<int>(c, INT_MAX));
        pathCost[0][0]=0;
        deque<pair<int, int>> pendingNodes;
        pendingNodes.push_back({0, 0});
        while (!pendingNodes.empty())
        {
            int i=pendingNodes.front().first, j=pendingNodes.front().second;
            pendingNodes.pop_front();

            for (int dir=0; dir<=3; dir++)
            {
                int x=i+direction[dir][0], y=j+direction[dir][1];
                int cost=((grid[i][j]==1+dir) ? 0 : 1);
                if (x>=0 && x<r && y>=0 && y<c && pathCost[i][j]+cost<pathCost[x][y])
                {
                    if (cost==0) pendingNodes.push_front({x, y});
                    else pendingNodes.push_back({x, y});
                    pathCost[x][y]=pathCost[i][j]+cost;
                }
            }
        }
        return pathCost[r-1][c-1];
    }
};