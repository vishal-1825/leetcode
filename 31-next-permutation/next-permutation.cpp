class Solution {
public:
    // T -> O(3n), S -> O(1)
    void nextPermutation(vector<int>& nums)
    {
        int n=nums.size(), index=-1;
        for (int i=n-2; i>=0; i--)
        {
            if (nums[i]<nums[i+1])
            {
                index=i;
                break;
            }
        }
        
        for (int i=n-1; index>=0 && i>index; i--)
        {
            if (nums[i]>nums[index])
            {
                swap(nums[i], nums[index]);
                break;
            }
        }
        // Note that from 'index+1' the array nums is sorted in descending order
        // so instead of sorting you can reverse
        reverse(nums.begin()+index+1, nums.end());
    }
};