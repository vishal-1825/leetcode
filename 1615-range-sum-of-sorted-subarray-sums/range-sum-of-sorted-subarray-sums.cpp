class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right)
    {
        vector<long long> prefixSum(n);
        prefixSum[0]=nums[0];
        for (int i=1; i<n; i++)
            prefixSum[i]=prefixSum[i-1]+nums[i];

        vector<long long> sums;
        for (int i=-1; i<n; i++)
        {
            for (int j=i+1; j<n; j++)
            {
                if (i==-1) sums.push_back(prefixSum[j]);
                else sums.push_back(prefixSum[j]-prefixSum[i]);
            }
        }

        sort(sums.begin(), sums.end());

        long long ans=0, mod=1e9+7;
        for (int i=left-1; i<=right-1; i++)
            ans=(ans+sums[i])%mod;
        return ans;
    }
};