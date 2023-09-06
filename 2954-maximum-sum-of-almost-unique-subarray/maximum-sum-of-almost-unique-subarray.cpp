typedef long long ll;
class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k)
    {
        map<ll, int> fq;
        ll sum=0, ans=0;
        int i=0, distinct=0, n=nums.size();

        for (i=0; i<n; i++)
        {
            fq[nums[i]]++;
            if (fq[nums[i]]==1) distinct++;
            sum+=nums[i];

            if (i<k-1) continue;

            if (distinct>=m && sum>ans) ans=sum;

            fq[nums[i-k+1]]--;
            if (fq[nums[i-k+1]]==0) distinct--;
            sum-=nums[i-k+1];
        }
        return ans;
    }
};