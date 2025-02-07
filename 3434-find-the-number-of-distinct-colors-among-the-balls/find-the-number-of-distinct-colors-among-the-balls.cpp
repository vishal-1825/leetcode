class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries)
    {
        unordered_map<int, int> colorFreq, color;
        int n=queries.size(), count=0;
        vector<int> ans;
        for (int i=0; i<n; i++)
        {
            int ball=queries[i][0], col=queries[i][1];
            if (color.find(ball)!=color.end())
            {
                colorFreq[color[ball]]--;
                if (colorFreq[color[ball]]==0)
                    count--;
            }
            color[ball]=col;
            colorFreq[col]++;
            if (colorFreq[col]==1) count++;
            ans.push_back(count);
        }
        return ans;
    }
};