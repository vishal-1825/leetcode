class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat)
    {
        int r=mat.size(), c=mat[0].size();
        vector<vector<int>> closest(r, vector<int>(c, -1));
        queue<pair<int, int>> one;

        for (int i=0; i<r; i++)
        {
            for (int j=0; j<c; j++)
            {
                if (mat[i][j]==0)
                {
                    closest[i][j]=0;
                    one.push({i, j});
                }
            }
        }

        vector<vector<int>> dir={{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while (!one.empty())
        {
            pair<int, int> p = one.front();
            one.pop();

            for (auto& d : dir)
            {
                int x=p.first+d[0];
                int y=p.second+d[1];

                if (x>=0 && x<r && y>=0 && y<c && closest[x][y]==-1)
                {
                    closest[x][y]=1+closest[p.first][p.second];
                    one.push({x, y});
                }
            }
        }
        return closest;
    }
};