class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k)
    {
        int sum=0, rem;
        unordered_map<int, pair<int, int>> count; // rem, index, count
        for (int i=0; i<nums.size(); i++)
        {
            sum+=nums[i];
            rem=sum%k;
            if ((rem==0 && i!=0) || (count.find(rem)!=count.end() && i-count[rem].first>1))
                return true;
            if (count.find(rem)==count.end()) count[rem]={i, 1};
            else count[rem].second++;
        }
        return false;
    }
};