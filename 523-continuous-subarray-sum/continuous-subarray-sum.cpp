class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k)
    {
        int sum=0, rem;
        unordered_map<int, int> index; // rem, index, count
        index[0]=-1;
        for (int i=0; i<nums.size(); i++)
        {
            sum+=nums[i];
            rem=sum%k;
            if (index.find(rem)!=index.end())
            {
                if (i-index[rem]>1)
                    return true;
            }
            else index[rem]=i;
        }
        return false;
    }
};