class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix)
    {
        unordered_map<string, int> patternCount;
        int ans=0;
        for (int row=0; row<matrix.size(); row++)
        {
            string pattern="", complement="";
            for (int cell: matrix[row])
            {
                pattern+=(cell==0 ? '0' : '1');
                complement+=(cell==0 ? '1' : '0');
            }
            patternCount[pattern]++;
            patternCount[complement]++;
            ans=max(ans, patternCount[pattern]);
        }
        return ans;
    }
};