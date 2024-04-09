class Solution {
public:
    int orval(vector<int> contribution)
    {
        int val=0;
        for (int k=0; k<=31; k++)
            val+=(contribution[k] ? 1 : 0)*(1<<k);
        return val;
    }

    void addContribution(int val, vector<int>& contribution, bool isadd)
    {
        int k=0;
        while (val>0)
        {
            contribution[k]=contribution[k]+(isadd ? 1 : -1)*val%2;
            val/=2;
            k++;
        }
    }

    int minimumSubarrayLength(vector<int>& nums, int k)
    {
        if (k==0) return 1;

        int n=nums.size(), i=0, j=0, ans=INT_MAX;
        vector<int> contribution(32, 0);
        while (j<n)
        {
            addContribution(nums[j], contribution, true);
            while (orval(contribution)>=k && i<=j)
            {
                ans=min(ans, j-i+1);
                addContribution(nums[i], contribution, false);
                i++;
            }
            j++;
        }
        return (ans==INT_MAX ? -1 : ans);
    }
};