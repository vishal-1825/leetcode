class Solution {
public:
    // I can never think like this
    // For each r, we are calculating all p/q ratios such that q=r-2 and p<q-1
    // only q=r-2 is enough because already for the previous r, the ratios with q < current r-2 have been calculated
    // Then we take all possible s values for s/r ratios and adding frequencies of them to the answer
    long long numberOfSubsequences(vector<int>& nums)
    {
        int n=nums.size();
        long long ans=0;
        unordered_map<double, long long> fq;
        for (int r=4; r<n; r++)
        {
            for (int q=r-2, p=0; p<q-1; p++)
            {
                double ratio=double(nums[p])/double(nums[q]);
                fq[ratio]++;
            }
            for (int s=r+2; s<n; s++)
            {
                double ratio=double(nums[s])/double(nums[r]);
                ans+=fq[ratio];
            }
        }
        return ans;
    }
};