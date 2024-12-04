class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries)
    {
        int n=nums.size();
        vector<int> diffArray(n, 0);
        for (auto query: queries)
        {
            diffArray[query[0]]++;
            if (query[1]+1<n) diffArray[query[1]+1]--;
        }
        for (int i=1; i<n; i++)
            diffArray[i]+=diffArray[i-1];
        for (int i=0; i<n; i++)
        {
            if (nums[i]>diffArray[i])
                return false;
        }
        return true;
    }
};