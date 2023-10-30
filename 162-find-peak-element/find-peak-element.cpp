class Solution {
public:
    int findPeakElement(vector<int>& nums)
    {
        int n=nums.size(), s=0, e=n-1, m;
        while (s<=e)
        {
            m=(s+e)/2;

            if ((m-1>=0 && nums[m-1]<nums[m] || m-1<0) && (m+1<n && nums[m+1]<nums[m] || m+1>=n)) return m;
            else if (m-1<0 || nums[m-1]<nums[m]) s=m+1;
            else e=m-1;
        }
        return -1;
    }
};