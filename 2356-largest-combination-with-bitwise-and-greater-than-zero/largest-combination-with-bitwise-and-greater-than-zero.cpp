class Solution {
public:
    int largestCombination(vector<int>& candidates)
    {
        int ans=0;
        for (int i=0; i<=23; i++)
        {
            int count=0;
            for (int c: candidates)
            {
                if ((c>>i) & 1)
                    count++;
            }
            ans=max(ans, count);
        }
        return ans;
    }
};