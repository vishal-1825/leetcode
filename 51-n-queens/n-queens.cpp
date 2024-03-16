class Solution {
public:
    bool canPlace(vector<string>& singleAns, int row, int col, int& n)
    {
        for (int i=row, j=col; i>=0 && j>=0; i--, j--)
        {
            if (singleAns[i][j]=='Q')
                return false;
        }
        for (int i=row, j=col; i<n && j>=0; i++, j--)
        {
            if (singleAns[i][j]=='Q')
                return false;
        }
        for (int j=col; j>=0; j--)
        {
            if (singleAns[row][j]=='Q')
                return false;
        }
        return true;
    }
    void nqueens(vector<vector<string>>& ans, vector<string>& singleAns, int& n, int col)
    {
        if (col==n)
        {
            ans.push_back(singleAns);
            return;
        }

        for (int row=0; row<n; row++)
        {
            if (canPlace(singleAns, row, col, n))
            {
                singleAns[row][col]='Q';
                nqueens(ans, singleAns, n, col+1);
                singleAns[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;
        vector<string> singleAns(n);
        string empty="";
        for (int i=0; i<n; i++)
            empty+='.';
        for (int i=0; i<n; i++)
            singleAns[i]=empty;
        nqueens(ans, singleAns, n, 0);
        return ans;
    }
};