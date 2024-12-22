class Solution {
public:
    // Had no idea
    // Greedy
    // T -> O(n), S -> O(1)
    int maxDistinctElements(vector<int>& nums, int k)
    {
        sort(nums.begin(), nums.end());
        int prevMax=INT_MIN, distinct=0;
        for (int num: nums)
        {
            if (prevMax<num-k)
            {
                prevMax=num-k;
                distinct++;
            }
            else if (prevMax<num+k)
            {
                distinct++;
                prevMax++;
            }
        }
        return distinct;
    }
};