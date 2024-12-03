class Solution {
public:
    // int shortestSubarray(vector<int>& nums, int k)
    // {
    //     int n=nums.size(), ans=n+1;
    //     long long sum=0;
    //     priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    //     for (int i=0; i<n; i++)
    //     {
    //         sum+=nums[i];
    //         if (sum>=k) ans=min(ans, i+1);
    //         while (!pq.empty() && sum-pq.top().first>=k)
    //         {
    //             ans=min(ans, i-pq.top().second);
    //             pq.pop();
    //         }
    //         pq.push({sum, i});
    //     }
    //     return (ans==n+1 ? -1 : ans);
    // }
    int shortestSubarray(vector<int>& nums, int k)
    {
        int n=nums.size(), ans=n+1;
        long long sum=0;
        deque<pair<long long, int>> dq;
        for (int i=0; i<n; i++)
        {
            sum+=nums[i];
            if (sum>=k) ans=min(ans, i+1);
            while (!dq.empty() && sum-dq.front().first>=k)
            {
                ans=min(ans, i-dq.front().second);
                dq.pop_front();
            }
            while (!dq.empty() && sum<dq.back().first)
                dq.pop_back();
            dq.push_back({sum, i});
        }
        return (ans==n+1 ? -1 : ans);
    }
};