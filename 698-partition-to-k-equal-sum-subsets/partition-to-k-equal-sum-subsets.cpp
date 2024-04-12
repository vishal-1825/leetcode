class Solution {
public:
    bool canPartition(vector<int>& nums, int sum, int k, vector<int>& ans, int index) // index is for number
    {
        if (index==nums.size())
        {
            for (int i=0; i<k; i++)
            {
                if (ans[i]!=sum)
                    return false;
            }
            return true;
        }

        for (int i=0; i<k; i++) // i is for set
        {
            if (ans[i]+nums[index]<=sum)
            {
                ans[i]+=nums[index];
                bool isPossible=canPartition(nums, sum, k, ans, index+1);
                ans[i]-=nums[index];
                if (isPossible)
                    return true;
                if (ans[i]==0 || ans[i]+nums[index]==sum) break;
                // ans[i] can't be zero coz all sets are supposed to non-empty ansof equal sum
                // if ans[i]+nums[index]==sum and doesn't give solution it never will so break
            }
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k)
    {
        int tot=0;
        for (int n: nums)
            tot+=n;
        
        if (tot%k!=0)
            return false;
        
        int sum=tot/k;
        vector<int> ans(k, 0);
        return canPartition(nums, sum, k, ans, 0);
    }
};