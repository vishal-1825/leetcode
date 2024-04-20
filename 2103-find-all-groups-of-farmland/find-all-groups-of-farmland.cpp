class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>> land)
    {
        int r=land.size(), c=land[0].size();
        vector<vector<int>> ans;
        for (int i=0; i<r; i++)
        {
            for (int j=0; j<c; j++)
            {
                if (land[i][j]==1)
                {
                    pair<int, int> start={i, j}, end={i, j};
                    queue<pair<int, int>> nei;
                    nei.push({i, j});
                    land[i][j]=0;
                    while (!nei.empty())
                    {
                        int x=nei.front().first, y=nei.front().second;
                        nei.pop();
                        if (x>end.first) end.first=x;
                        if (y>end.second) end.second=y;
                        if (x+1<r && land[x+1][y]==1)
                        {
                            land[x+1][y]=0;
                            nei.push({x+1, y});
                        }
                        if (y+1<c && land[x][y+1]==1)
                        {
                            land[x][y+1]=0;
                            nei.push({x, y+1});
                        }
                    }
                    ans.push_back({start.first, start.second, end.first, end.second});
                    cout << endl;
                }
            }
        }
        return ans;
    }
};