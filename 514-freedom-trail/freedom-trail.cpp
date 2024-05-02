class Solution {
public:
    int frs(string ring, string key, int ring_index, int key_index, vector<vector<int>>& indices, vector<vector<int>>& dp)
    {
        if (key_index==key.length()) return 0;

        if (dp[ring_index][key_index]!=-1) return dp[ring_index][key_index];

        int ans=INT_MAX;
        for (int i: indices[key[key_index]-'a'])
        {
            int diff;
            if (i>ring_index) diff=min(int(i-ring_index), int(ring_index+ring.length()-i));
            else diff=min(int(ring_index-i), int(i+ring.length()-ring_index));
            ans=min(ans, 1+diff+frs(ring, key, i, key_index+1, indices, dp));
        }
        return dp[ring_index][key_index]=ans;
    }
    int findRotateSteps(string ring, string key)
    {
        vector<vector<int>> indices(26);
        for (int i=0; i<ring.length(); i++)
            indices[ring[i]-'a'].push_back(i);
        vector<vector<int>> dp(ring.length(), vector<int>(key.length(), -1));
        return frs(ring, key, 0, 0, indices, dp);
    }
};