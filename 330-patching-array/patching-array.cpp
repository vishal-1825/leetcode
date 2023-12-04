class Solution {
public:
    // No algorithm, recognize the  pattern to solve
    // I had no idea
    typedef long long ll;
    int minPatches(vector<int>& nums, int n)
    {
        ll covered=0;
        int index=0, ans=0;
        while (covered<n)
        {
            if (index<nums.size() && covered+1>=nums[index]) covered+=nums[index++];
            else
            {
                ans++;
                covered+=(covered+1);
            }
        }
        return ans;
    }
};