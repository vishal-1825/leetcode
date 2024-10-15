class Solution {
public:
    int minSubarray(vector<int>& nums, int p)
    {
        int n=nums.size(), rem=0, sum=0, ans=n;
        for (int i=0; i<n; i++)
            rem=(rem+nums[i])%p;
        if (rem==0) return 0;
        // remove a subarray whose remainder is rem
        unordered_map<int, int> index;
        index[0]=-1;
        for (int i=0; i<n; i++)
        {
            sum=(sum+nums[i])%p;
            if (index.find((sum-rem+p)%p)!=index.end())
                ans=min(ans, i-index[(sum-rem+p)%p]);
            index[sum]=i;
        }
        return (ans==n ? -1 : ans);
    }
};