class Solution {
public:
    int findKOr(vector<int>& nums, int k)
    {
        int sum=0;
        for (int i=0; i<=31; i++)
        {
            int count=0;
            for (int j=0; j<nums.size(); j++)
            {
                if (nums[j] & (1<<i))
                    count++;
            }
            if (count>=k)
                sum+=(1<<i);
        }
        return sum;
    }
};