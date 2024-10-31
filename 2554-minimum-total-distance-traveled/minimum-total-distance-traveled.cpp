class Solution {
public:
    // long long minDist(vector<int>& robot, vector<int>& factories, int i, int j, vector<vector<long long>>& dp)
    // {
    //     if (i==robot.size()) return 0;
    //     if (j==factories.size()) return LLONG_MAX;

    //     if (dp[i][j]!=-1) return dp[i][j];

    //     long long inc = minDist(robot, factories, i+1, j+1, dp);
    //     if (inc!=LLONG_MAX) inc+=abs(robot[i]-factories[j]);
    //     long long exc = minDist(robot, factories, i, j+1, dp);
    //     return dp[i][j] = min(inc, exc);
    // }
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory)
    {
        vector<int> factories;
        for (auto f: factory)
        {
            for (int i=0; i<f[1]; i++)
                factories.push_back(f[0]);
        }
        sort(robot.begin(), robot.end());
        sort(factories.begin(), factories.end());
        vector<vector<long long>> dp(robot.size()+1, vector<long long>(factories.size()+1, 0));
        // return minDist(robot, factories, 0, 0, dp);
        for (int i=0; i<robot.size(); i++)
            dp[i][factories.size()]=LLONG_MAX;
        for (int i=robot.size()-1; i>=0; i--)
        {
            for (int j=factories.size()-1; j>=0; j--)
            {
                long long inc = dp[i+1][j+1];
                if (inc!=LLONG_MAX) inc+=abs(robot[i]-factories[j]);
                long long exc = dp[i][j+1];
                dp[i][j] = min(inc, exc);
            }
        }
        return dp[0][0];
    }
};