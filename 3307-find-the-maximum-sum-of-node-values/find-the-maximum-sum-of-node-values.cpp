typedef long long ll;
class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges)
    {
        ll ans=0, minNode=INT_MAX, count=0;
        for (int i=0; i<nums.size(); i++)
        {
            if ((nums[i]^k) > nums[i])
            {
                ans+=nums[i]^k;
                minNode=min(minNode, ll(nums[i]^k)-ll(nums[i]));
                count++;
            }
            else
            {
                ans+=nums[i];
                minNode=min(minNode, ll(nums[i])-ll(nums[i]^k));
            }
        }

        if (count%2==0) return ans;
        return ans-minNode;
    }

};