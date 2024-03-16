class Solution {
public:
    int findMaxLength(vector<int>& nums)
    {
        int c=0, ans=0;
        unordered_map<int, int> countindex;
        if (nums[0]==0) c--;
        else c++;
        countindex[c]=0;
        for (int i=1; i<nums.size(); i++)
        {
            if (nums[i]==0) c--;
            else c++;
            
            if (countindex.find(c)!=countindex.end()) ans=max(ans, i-countindex[c]);
            else countindex[c]=i;
            if (c==0) ans=max(ans, i+1);
        }
        return ans;
    }
};