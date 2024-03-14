class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal)
    {
        unordered_map<int, int> fq;
        int cursum=0, ans=0;
        for (int i=0; i<nums.size(); i++)
        {
            cursum+=nums[i];
            if (cursum==goal) ans++;
            if (fq.find(cursum-goal)!=fq.end()) ans+=fq[cursum-goal];
            fq[cursum]++;
        }
        return ans;
    }
};