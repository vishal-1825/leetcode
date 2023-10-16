typedef long long ll;
class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid)
    {
        int r=grid.size(), c=grid[0].size(), i, j;
        ll pre=1, suf=1, mod=12345;
        vector<vector<int>> p(r, vector<int>(c, 1));

        for (i=0; i<r; i++)
        {
            for (j=0; j<c; j++)
            {
                p[i][j]=(pre*p[i][j])%mod;
                p[r-i-1][c-j-1]=(p[r-i-1][c-j-1]*suf)%mod;

                pre=(pre*grid[i][j])%mod;
                suf=(suf*grid[r-i-1][c-j-1])%mod;
            }
        }

        return p;
    }
};