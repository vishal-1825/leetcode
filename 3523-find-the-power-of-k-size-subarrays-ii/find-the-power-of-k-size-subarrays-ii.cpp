class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k)
    {
        int n=nums.size(), consec=0;
        vector<int> ans;
        for (int i=0; i<n; i++)
        {
            if (i==0 || nums[i-1]+1==nums[i]) consec++;
            else consec=1;
            if (i>=k-1)
            {
                if (consec>=k) ans.push_back(nums[i]);
                else ans.push_back(-1);
            }
        }
        return ans;    
    }
};