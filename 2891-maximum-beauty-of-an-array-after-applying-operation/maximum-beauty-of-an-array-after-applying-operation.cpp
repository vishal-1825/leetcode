class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k)
    {
        sort(nums.begin(), nums.end());
        int n=nums.size(), left=1, right=n, ans=0;
        while (left<=right)
        {
            int mid=(left+right)/2, flag=0;
            for (int i=0; i+mid-1<n; i++)
            {
                if (nums[i+mid-1]-nums[i]<=2*k)
                {
                    flag=1;
                    break;
                }
            }
            if (flag==1)
            {
                ans=mid;
                left=mid+1;
            }
            else right=mid-1;
        }
        return ans;
    }
};