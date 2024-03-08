class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix)
    {
        int r=matrix.size(), c=matrix[0].size();
        vector<vector<bool>> vis(r, vector<bool>(c, false));
        int x=0, y=0, count=0;
        vector<int> ans;
        while (count<r*c)
        {
            // l-r, t-b, r-l, b-t
            while (y<c && !vis[x][y])
            {
                ans.push_back(matrix[x][y]);
                vis[x][y]=true;
                y++;
                count++;
            }
            y--;
            x++;
            while (x<r && !vis[x][y])
            {
                ans.push_back(matrix[x][y]);
                vis[x][y]=true;
                x++;
                count++;
            }
            x--;
            y--;
            while (y>=0 && !vis[x][y])
            {
                ans.push_back(matrix[x][y]);
                vis[x][y]=true;
                y--;
                count++;
            }
            y++;
            x--;
            while (x>=0 && !vis[x][y])
            {
                ans.push_back(matrix[x][y]);
                vis[x][y]=true;
                x--;
                count++;
            }
            x++;
            y++;
        }
        return ans;
    }
};