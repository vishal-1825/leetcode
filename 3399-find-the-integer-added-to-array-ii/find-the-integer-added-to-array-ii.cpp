class Solution {
public:
    bool allSeparatedBy(int diff, int i, vector<int>& nums1, vector<int>& nums2, int count)
    {
        int c=0;
        for (int k=i, j=0; k<nums1.size() && j<nums2.size(); k++)
        {
            if (nums2[j]-nums1[k]!=diff) c++;
            else j++;
        }
        return (c<=count);
    }
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2)
    {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int ans=INT_MAX;
        for (int i=0; i<=2; i++)
        {
            int diff=nums2[0]-nums1[i];
            if (allSeparatedBy(diff, i, nums1, nums2, 2-i))
                ans=min(ans, diff);
        }
        return ans;
    }
};