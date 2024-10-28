class Solution {
public:
    int longestSquareStreak(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        int n=nums.size(), ans=1;
        unordered_map<long long, int> hash;
        for (int n: nums)
            hash[n]++;
        for (int i=0; i<n; i++)
        {
            int streak=0;
            long long num=nums[i];
            while (hash.find(num)!=hash.end() && hash[num]>0)
            {
                streak++;
                hash[num]--;
                num*=num;
            }
            ans=max(ans, streak);
        }
        return (ans==1 ? -1 : ans);
    }
};