class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid)
    {
        int ans=0;
        for (int i=1; i<grid.size()-1; i++)
        {
            for (int j=1; j<grid[0].size()-1; j++)
            {
                // unique
                int flag=1;
                vector<bool> vis(10, false);
                for (int k=i-1; k<=i+1; k++)
                {
                    for (int l=j-1; l<=j+1; l++)
                    {
                        if (vis[grid[k][l]] || grid[k][l]<1 || grid[k][l]>9)
                        {
                            flag=0;
                            break;
                        }
                        vis[grid[k][l]]=true;
                    }
                }
                
                // row
                int sum1=grid[i-1][j-1]+grid[i-1][j]+grid[i-1][j+1];
                int sum2=grid[i][j-1]+grid[i][j]+grid[i][j+1];
                int sum3=grid[i+1][j-1]+grid[i+1][j]+grid[i+1][j+1];
                
                // diagonal
                int sum4=grid[i-1][j-1]+grid[i][j]+grid[i+1][j+1];
                int sum5=grid[i+1][j-1]+grid[i][j]+grid[i-1][j+1];

                // column
                int sum6=grid[i-1][j-1]+grid[i][j-1]+grid[i+1][j-1];
                int sum7=grid[i-1][j]+grid[i][j]+grid[i+1][j];
                int sum8=grid[i-1][j+1]+grid[i][j+1]+grid[i+1][j+1];

                if (flag==1 && sum1==sum2 && sum2==sum3 && sum3==sum4 && sum4==sum5 &&
                    sum5==sum6 && sum6==sum7 && sum7==sum8)
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};