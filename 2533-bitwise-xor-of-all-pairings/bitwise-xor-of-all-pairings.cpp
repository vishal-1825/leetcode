class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2)
    {
        int xorNums=0;
        if (nums1.size()%2==1)
        {
            for (int num: nums2)
                xorNums^=num;
        }
        if (nums2.size()%2==1)
        {
            for (int num: nums1)
                xorNums^=num;
        }
        return xorNums;
    }
};