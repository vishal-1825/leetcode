class Solution {
public:
    int nthUglyNumber(int n)
    {
        set<long long> nums;
        nums.insert(1);
        for (int i=1; i<n; i++)
        {
            long long num=*nums.begin();
            nums.erase(nums.begin());
            nums.insert(num*2);
            nums.insert(num*3);
            nums.insert(num*5);
        }
        return int(*nums.begin());
    }
};