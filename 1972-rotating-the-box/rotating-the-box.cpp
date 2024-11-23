class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box)
    {
        int m=box.size(), n=box[0].size();
        vector<vector<char>> rotatedBox(n, vector<char>(m));
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<m; j++)
                rotatedBox[i][j]=box[j][i];
        }
        for (int i=0; i<n; i++)
            reverse(rotatedBox[i].begin(), rotatedBox[i].end());

        for (int j=0; j<m; j++)
        {
            int lowestEmpty=n-1;
            for (int i=n-1; i>=0; i--)
            {
                if (rotatedBox[i][j]=='#')
                {
                    rotatedBox[i][j]='.';
                    rotatedBox[lowestEmpty][j]='#';
                    lowestEmpty--;
                }
                if (rotatedBox[i][j]=='*')
                    lowestEmpty=i-1;
            }
        }
        return rotatedBox;
    }
};