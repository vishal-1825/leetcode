class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum)
    {
        unordered_set<int> hash;
        for (auto ban: banned)
            hash.insert(ban);
        int sum=0, count=0;
        for (int i=1; i<=n; i++)
        {
            if (hash.find(i)==hash.end())
            {
                if (sum+i<=maxSum)
                {
                    sum+=i;
                    count++;
                }
                else break; 
            }
        }
        return count;
    }
};