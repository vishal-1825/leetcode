class Solution {
public:
    int majorityElement(vector<int>& nums)
    {
        map<int, int> fq;
        int i, n=nums.size();

        for (i=0; i<n; i++)
        {
            fq[nums[i]]++;
            if (fq[nums[i]]>n/2)
                return nums[i];
        }
        return 0;
    }
};