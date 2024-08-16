class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays)
    {
        int minSoFar=arrays[0][0], maxSoFar=arrays[0].back(), ans=0;
        for (int i=1; i<arrays.size(); i++)
        {
            ans=max(ans, arrays[i].back()-minSoFar);
            ans=max(ans, maxSoFar-arrays[i][0]);
            maxSoFar=max(maxSoFar, arrays[i].back());
            minSoFar=min(minSoFar, arrays[i][0]);
        }
        return ans;
    }
};