class Solution {
public:
    int longestConsecutive(vector<int>& nums)
    {
        int n=nums.size();
        if (n==0) return 0;

        int ans=1;
        unordered_set<int> s(nums.begin(), nums.end());

        for (int n:nums)
        {
            int i=n-1, j=n+1;
            while (s.find(i)!=s.end())
                s.erase(i--);
            while (s.find(j)!=s.end())
                s.erase(j++);
            ans=max(ans, j-i-1);
        }
        return ans;
    }
};