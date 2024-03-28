class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k)
    {
        int i=0, j=0, n=nums.size(), ans=0;
        unordered_map<int, int> fq;
        while (i<n)
        {
            // int flag=0;
            while (j<n)
            {
                fq[nums[j]]++;
                if (fq[nums[j]]>k)
                {
                    // flag=1;
                    fq[nums[j]]--;
                    j--;
                    break;
                }
                j++;
            }
            if (j==n) j--;
            if (i<=j) // size of subarray=0
            {
                ans=max(ans, j-i+1);
                fq[nums[i]]--;
                i++;
                j++;
            }
            else
            {
                i++;
                j=i;
            }
        }    
        return ans;
    }
};