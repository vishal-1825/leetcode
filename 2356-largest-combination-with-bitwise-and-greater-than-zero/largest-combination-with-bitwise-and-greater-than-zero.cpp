class Solution {
public:
    int largestCombination(vector<int>& candidates)
    {
        int ans=0;
        vector<int> count(32, 0);
        for (int c: candidates)
        {
            for (int i=0; i<=31; i++)
            {
                if ((c>>i) & 1)
                    count[i]++;
                ans=max(ans, count[i]);
            }
        }
        return ans;
    }
};