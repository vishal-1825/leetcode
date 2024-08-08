class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart)
    {
        int it=1, r=rStart, c=cStart, count=1;
        vector<vector<int>> ans;
        vector<vector<bool>> vis(rows, vector<bool>(cols, false));
        vis[rStart][cStart]=true;
        ans.push_back({rStart, cStart});
        while (count<rows*cols)
        {
            // right
            for (int i=1; i<=it; i++)
            {
                c++;
                if (r>=0 && r<rows && c>=0 && c<cols && !vis[r][c])
                {
                    ans.push_back({r, c});
                    vis[r][c]=true;
                    count++;
                    if (count>=rows*cols) break;
                }
            }
            // down
            for (int i=1; i<=it; i++)
            {
                r++;
                if (r>=0 && r<rows && c>=0 && c<cols && !vis[r][c])
                {
                    ans.push_back({r, c});
                    vis[r][c]=true;
                    count++;
                    if (count>=rows*cols) break;
                }
            }
            // left
            for (int i=1; i<=it+1; i++)
            {
                c--;
                if (r>=0 && r<rows && c>=0 && c<cols && !vis[r][c])
                {
                    ans.push_back({r, c});
                    vis[r][c]=true;
                    count++;
                    if (count>=rows*cols) break;
                }
            }
            // up
            for (int i=1; i<=it+1; i++)
            {
                r--;
                if (r>=0 && r<rows && c>=0 && c<cols && !vis[r][c])
                {
                    ans.push_back({r, c});
                    vis[r][c]=true;
                    count++;
                    if (count>=rows*cols) break;
                }
            }
            it+=2;
        }
        return ans;
    }
};