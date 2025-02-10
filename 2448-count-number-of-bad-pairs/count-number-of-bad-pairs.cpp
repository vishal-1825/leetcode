class Solution {
public:
    long long countBadPairs(vector<int>& nums)
    {
        // j-i != nums[j]-nums[i]
        // nums[i]-i != nums[j]-j
        unordered_map<int, int> diff;
        int n=nums.size();
        long long count=(1LL*n*(n-1))/2;
        for (int i=0; i<n; i++)
            diff[nums[i]-i]++;
        for (auto pair: diff)
            count-=(1LL*pair.second*(pair.second-1))/2;
        return count;
    }
};