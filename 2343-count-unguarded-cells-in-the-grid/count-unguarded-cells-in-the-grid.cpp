class Solution {
public:
    // 1 guard, -1 wall, 2 guarded, 0 not guarded
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls)
    {
        vector<vector<int>> grid(m, vector<int>(n, 0));
        for (auto g: guards)
            grid[g[0]][g[1]]=1;
        for (auto w: walls)
            grid[w[0]][w[1]]=-1;
        for (int i=0; i<m; i++)
        {
            for (int j=0; j<n; j++)
            {
                if (grid[i][j]==1)
                {
                    int l=j-1, r=j+1, t=i-1, b=i+1;
                    while (l>=0 && (grid[i][l]==0 || grid[i][l]==2))
                    {
                        grid[i][l]=2;
                        l--;
                    }
                    while (r<n && (grid[i][r]==0 || grid[i][r]==2))
                    {
                        grid[i][r]=2;
                        r++;
                    }
                    while (t>=0 && (grid[t][j]==0 || grid[t][j]==2))
                    {
                        grid[t][j]=2;
                        t--;
                    }
                    while (b<m && (grid[b][j]==0 || grid[b][j]==2))
                    {
                        grid[b][j]=2;
                        b++;
                    }
                }
            }
        }
        int ans=0;
        for (int i=0; i<m; i++)
        {
            for (int j=0; j<n; j++)
                ans+=(grid[i][j]==0 ? 1 : 0);
        }
        return ans;
    }
};