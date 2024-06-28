class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads)
    {
        vector<long long> indegree(n, 0);
        for (vector<int>& r: roads)
        {
            indegree[r[0]]++;
            indegree[r[1]]++;
        }
        sort(indegree.begin(), indegree.end());

        long long ans=0, val=1;
        for (long i: indegree)
        {
            ans+=(i*val);
            val++;
        }
        return ans;
    }
};