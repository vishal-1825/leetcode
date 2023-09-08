class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix)
    {
        int m=matrix[0].size(), n=matrix.size(), i, j;
        vector<int> row0(m, 1);
        vector<int> col0(n, 1);
        // m=row size, n=column size
        for (i=0; i<m; i++)
        {
            for (j=0; j<n; j++)
            {
                if (matrix[j][i]==0)
                {
                    row0[i]=0;
                    col0[j]=0;
                }
            }
        }

        for (i=0; i<m; i++)
        {
            for (j=0; j<n; j++)
            {
                if (row0[i]==0 || col0[j]==0)
                    matrix[j][i]=0;
            }
        }
    }
};