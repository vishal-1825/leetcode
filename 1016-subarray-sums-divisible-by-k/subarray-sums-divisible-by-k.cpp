class Solution {
public:
    // refer editorial
    int subarraysDivByK(vector<int>& nums, int k)
    {
        int sum=0, ans=0;
        unordered_map<int, int> count;
        for (int n: nums)
        {
            sum+=n;
            int rem=sum%k;
            while (rem<0)
                rem+=k;
            if (rem==0) ans++;
            if (count.find(rem)!=count.end()) ans+=count[rem];
            count[rem]++;
        }
        return ans;
    }
};