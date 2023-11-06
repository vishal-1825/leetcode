class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges)
    {
        int m=edges.size(), ans, count=0;
        vector<int> pointingCount(n, 0);
        for (int i=0; i<m; i++)
            pointingCount[edges[i][1]]++;
        for (int i=0; i<n; i++)
        {
            if (pointingCount[i]==0)
            {
                if (count==1) return -1;
                count++;
                ans=i;
            }
        }
        return ans;
    }
};