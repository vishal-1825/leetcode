class Solution {
public:
    void mark(vector<vector<char>>& board, int i, int j, int r, int c)
    {
        if (i<0 || i>=r || j<0 || j>=c) return;

        if (board[i][j]=='O')
        {
            board[i][j]='Y';
            mark(board, i+1, j, r, c);
            mark(board, i-1, j, r, c);
            mark(board, i, j+1, r, c);
            mark(board, i, j-1, r, c);
        }
    }
    void solve(vector<vector<char>>& board)
    {
        int r=board.size(), c=board[0].size();
        for (int i=0; i<r; i++)
        {
            if (board[i][0]=='O') mark(board, i, 0, r, c);
            if (board[i][c-1]=='O') mark(board, i, c-1, r, c);
        }
        for (int i=0; i<c; i++)
        {
            if (board[0][i]=='O') mark(board, 0, i, r, c);
            if (board[r-1][i]=='O') mark(board, r-1, i, r, c);
        }

        for (int i=0; i<r; i++)
        {
            for (int j=0; j<c; j++)
            {
                if (board[i][j]=='O') board[i][j]='X';
                else if (board[i][j]=='Y') board[i][j]='O';
            }
        }
    }
};