class Solution {
public:
    bool isOk(vector<vector<char>>& board, int x, int y, int num)
    {
        for (int i=0; i<9; i++)
        {
            if (board[x][i]==char(num+'0') || board[i][y]==char(num+'0'))
                return false;
        }

        int r=x-x%3, c=y-y%3;
        for (int i=0; i<3; i++)
        {
            for (int j=0; j<3; j++)
            {
                if (board[i+r][j+c]==char(num+'0'))
                    return false;
            }
        }

        return true;
    }
    bool filled(vector<vector<char>>& board, int& x, int& y)
    {
        for (int i=0; i<9; i++)
        {
            for (int j=0; j<9; j++)
            {
                if (board[i][j]=='.')
                {
                    x=i, y=j;
                    return false;
                }
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board)
    {
        int x, y;
        if (filled(board, x, y)) return true;

        for (int i=1; i<=9; i++)
        {
            if (isOk(board, x, y, i))
            {
                board[x][y]=char(i+'0');
                if (solve(board)) return true;
                board[x][y]='.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board)
    {
        solve(board);    
    }
};