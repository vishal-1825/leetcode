class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
        int n=nums.size(), i=0, j=0, e, c;

        while (i<n)
        {
            e=nums[i];
            c=0;
            while (i<n && nums[i]==e)
            {
                c++;
                if (c<=2)
                {
                    nums[j]=nums[i];
                    j++;
                }
                i++;
            }
        }
        return j;
    }
};