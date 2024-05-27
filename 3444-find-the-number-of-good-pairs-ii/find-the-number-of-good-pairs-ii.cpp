class Solution {
public:
    // store all nums2[i]*k in map
    // Iterate through nums1[i] and find the factors; add the counts of the factors to the answer
    // Time -> O(m+n*max(nums[i])^0.5)
    // Worst case time -> O(10^5 + 10^5 * (10^6)^0.5) = O(10^5+10^8)
    // Prune cases where nums1[i]%k!=0 to optimize further that's the best solution
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k)
    {
        unordered_map<int, int> mp;
        for (auto n2: nums2)
            mp[n2*k]++;
        
        long long ans=0;
        for (int n1: nums1)
        {
            for (int f=1; f*f<=n1; f++)
            {
                if (n1%f!=0) continue;
                int f1=f, f2=n1/f;
                ans+=mp[f1];
                if (f1!=f2) ans+=mp[f2];
            }
        }
        return ans;
    }
};