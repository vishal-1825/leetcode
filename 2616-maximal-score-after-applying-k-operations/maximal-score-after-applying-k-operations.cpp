class Solution {
public:
    long long maxKelements(vector<int>& nums, int k)
    {
        priority_queue<int> pq;
        for (int n: nums)
            pq.push(n);

        long long ans=0, count=0;
        while (count<k)
        {
            int val=pq.top();
            pq.pop();
            ans+=val;
            count++;
            if (val%3==0) val/=3;
            else val=val/3+1;
            pq.push(val);
        } 
        return ans;
    }
};