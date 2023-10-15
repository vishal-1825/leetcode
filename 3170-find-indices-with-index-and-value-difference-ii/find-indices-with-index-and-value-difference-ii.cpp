class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference)
    {
        vector<int> ans(2, -1);
        int i=0, j=indexDifference, n=nums.size(), leftMin=nums[0], leftMinIndex=0, leftMax=nums[0], leftMaxIndex=0;
        
        while (j<n)
        {
            if (abs(nums[j]-leftMin)>=valueDifference)
            {
                ans[0]=leftMinIndex;
                ans[1]=j;
                break;
            }
            if (abs(nums[j]-leftMax)>=valueDifference)
            {
                ans[0]=leftMaxIndex;
                ans[1]=j;
                break;
            }
            j++;
            i++;
            if (i<n && nums[i]<leftMin)
            {
                leftMin=nums[i];
                leftMinIndex=i;
            }
            if (i<n && nums[i]>leftMax)
            {
                leftMax=nums[i];
                leftMaxIndex=i;
            }
        }
        
        return ans;
    }
};