class Solution {
public:
    // Couldn't solve without hint
    typedef long long ll;
    bool isPal(ll num)
    {
        ll forw=num, rev=0;
        while (num)
        {
            rev = rev*10 + num%10;
            num/=10;
        }
        return (forw==rev);
    }

    long long minimumCost(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());

        int n=nums.size();
        ll median = ((n % 2) ? nums[n/2] : (nums[n/2-1] + nums[n/2]) / 2);
        ll leftCost=0, rightCost=0, leftPal=median, rightPal=median;
        
        while (!isPal(leftPal))
            leftPal--;
        while (!isPal(rightPal))
            rightPal++;
        
        for (int i=0; i<n; i++)
        {
            leftCost+=abs(nums[i]-leftPal);
            rightCost+=abs(nums[i]-rightPal);
        }

        return min(leftCost, rightCost);
    }
};