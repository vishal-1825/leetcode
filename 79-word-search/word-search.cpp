class Solution {
public:
    bool found(vector<vector<char>>& board, string& word, vector<vector<bool>>& visited, int x, int y, int& r, int& c, int i)
    {
        if (i==word.length()) return true;
        if (x<0 || x>=r || y<0 || y>=c || visited[x][y]) return false;

        if (board[x][y]!=word[i]) return false;
        visited[x][y]=true;
        bool up=found(board, word, visited, x-1, y, r, c, i+1);
        bool down=found(board, word, visited, x+1, y, r, c, i+1);
        bool left=found(board, word, visited, x, y-1, r, c, i+1);
        bool right=found(board, word, visited, x, y+1, r, c, i+1);
        visited[x][y]=false;
        return (up || down || left || right);
    }

    bool exist(vector<vector<char>>& board, string word)
    {
        int r=board.size(), c=board[0].size();
        vector<vector<bool>> visited(r, vector<bool>(c, false));
        for (int x=0; x<r; x++)
        {
            for (int y=0; y<c; y++)
            {
                if (found(board, word, visited, x, y, r, c, 0))
                    return true;
            }
        }
        return false;   
    }
};