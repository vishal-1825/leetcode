class Solution {
public:
    bool primeSubOperation(vector<int>& nums)
    {
        vector<bool> prime(1001, true);
        prime[0]=false;
        prime[1]=false;
        for (int p=2; p*p<=1000; p++)
        {
            if (prime[p])
            {
                for (int i=p*p; i<=1000; i+=p)
                    prime[i]=false;
            }
        }

        for (int i=nums.size()-2; i>=0; i--)
        {
            if (nums[i]<nums[i+1]) continue;
            int diff=nums[i]-nums[i+1]+1;
            int flag=0;
            while (diff<nums[i])
            {
                if (prime[diff])
                {
                    flag=1;
                    break;
                }
                diff++;
            }
            if (flag==0) return false;
            nums[i]-=diff;
        }
        return true;
    }
};