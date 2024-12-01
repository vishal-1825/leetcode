class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k)
    {
        int n=nums.size();
        vector<long long> prefixSum(nums.begin(), nums.end());
        for (int i=1; i<n; i++)
            prefixSum[i]+=prefixSum[i-1];

        long long ans=0;
        unordered_map<int, int> prevIndex;
        int start=0;
        for (int end=0; end<n; end++)
        {
            if (prevIndex.find(nums[end])==prevIndex.end() || prevIndex[nums[end]]<start)
            {
                if (end-start+1==k)
                {
                    ans=max(ans, prefixSum[end]-prefixSum[end-k+1]+1LL*nums[end-k+1]);
                    start++;
                }
            }
            else start=prevIndex[nums[end]]+1;
            prevIndex[nums[end]]=end;
        }
        return ans;
    }
};