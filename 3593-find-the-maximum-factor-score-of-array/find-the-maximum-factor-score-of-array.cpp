class Solution {
public:
    long long calculateFactor(vector<int>& arr)
    {
        long long gcdval=arr[0], lcmval=arr[0];
        for (int i=1; i<arr.size(); i++)
        {
            gcdval=gcd(gcdval, arr[i]);
            lcmval=(lcmval*arr[i])/gcd(lcmval, arr[i]);
        }
        return lcmval*gcdval;
    }
    long long maxScore(vector<int>& nums)
    {
        long long ans = calculateFactor(nums);
        for (int i=0; i<nums.size(); i++)
        {
            vector<int> removed;
            for (int j=0; j<nums.size(); j++)
            {
                if (i!=j)
                    removed.push_back(nums[j]);
            }
            if (!removed.empty())
            {
                long long factor = calculateFactor(removed);
                ans=max(ans, factor);
            }
        }
        return ans;
    }
};