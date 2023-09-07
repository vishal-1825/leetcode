typedef long long ll;
class Solution {
public:
    
    int minOperations(vector<int>& nums, int target)
    {
        ll total_sum=0, op=0, i=nums.size()-1;
        
        for (auto n: nums)
            total_sum+=n;
        if (total_sum<target)
            return -1;
        
        sort(nums.begin(), nums.end());
        while (i>=0 && total_sum)
        {
            int largest=nums.back();
            nums.pop_back();
            if (total_sum-largest>=target) total_sum-=largest;
            else if (largest<=target)
            {
                total_sum-=largest;
                target-=largest;
            }
            else
            {
                nums.push_back(largest/2);
                nums.push_back(largest/2);
                op++;
            }
        }
        return op;
    }
};