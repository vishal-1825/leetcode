class Solution {
public:
    vector<vector<int>> generate(int numRows)
    {
        int i, j;
        vector<vector<int>> ans;
        if (numRows==0) return ans;
        ans.push_back({1});
        if (numRows==1) return ans;
        ans.push_back({1, 1});
        
        for (i=2; i<numRows; i++)
        {
            int s=ans[i-1].size();
            vector<int> row;
            row.push_back(1);
            for (j=0; j<s-1; j++)
                row.push_back(ans[i-1][j]+ans[i-1][j+1]);
            row.push_back(1);
            ans.push_back(row);
        }
        return ans;
    }
};