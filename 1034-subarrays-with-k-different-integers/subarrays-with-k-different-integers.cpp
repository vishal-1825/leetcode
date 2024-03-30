class Solution {
public:
    int subarraysWithKAtmost(vector<int>& nums, int k)
    {
        unordered_map<int, int> fq;
        int n=nums.size(), i=0, j=0, ans=0, count=0;
        while (i<n)
        {
            while (j<n && count<=k)
            {
                fq[nums[j]]++;
                if (fq[nums[j]]==1) count++;
                j++;
            }
            if (count==k+1)
            {
                j--;
                fq[nums[j]]--;
                count--;
            }
            ans+=(j-i);
            fq[nums[i]]--;
            if (fq[nums[i]]==0) count--;
            i++;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k)
    {
        return subarraysWithKAtmost(nums, k)-subarraysWithKAtmost(nums, k-1);
    }
};