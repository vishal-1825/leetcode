class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid)
    {
        int n=grid.size();
        if (grid[0][0]==1 || grid[n-1][n-1]==1) return -1;
        grid[n-1][n-1]=1;
       
        int ans=0;
        vector<pair<int, int>> dir={{1, 1}, {1, 0}, {0, 1}, {1, -1}, {-1, 1}, {0, -1}, {-1, 0}, {-1, -1}};
        queue<pair<int, int>> adjNodes;
        adjNodes.push({n-1, n-1});
        
        while (!adjNodes.empty())
        {
            int sz=adjNodes.size();
            ans++;
            while (sz--)
            {
                pair<int, int> index = adjNodes.front();
                adjNodes.pop();
                if (index.first==0 && index.second==0) return ans;

                for (auto& d : dir)
                {
                    int x=index.first+d.first;
                    int y=index.second+d.second;
                    
                    if (x<0 || y<0 || x>=n || y>=n || grid[x][y]==1) continue;
                    grid[x][y]=1;
                    adjNodes.push({x, y});
                }
            }
        }
        return -1;
    }
};