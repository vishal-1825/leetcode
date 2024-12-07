class Solution {
public:
    bool numOperationsMatch(vector<int>& nums, int maxOperations, int maxBalls)
    {
        int operations=0;
        for (int balls: nums)
        {
            if (balls<=maxBalls) continue;
            if (balls%maxBalls==0) operations+=(balls/maxBalls-1);
            else operations+=balls/maxBalls;
            if (operations>maxOperations) return false;
        }
        return true;
    }
    int minimumSize(vector<int>& nums, int maxOperations)
    {
        int left=1, right=1, ans=INT_MAX;
        for (int num: nums)
            right=max(right, num);
        while (left<=right)
        {
            int mid=(left+right)/2;
            if (numOperationsMatch(nums, maxOperations, mid))
            {
                ans=mid;
                right=mid-1;
            }
            else left=mid+1;
        }
        return ans;
    }
};