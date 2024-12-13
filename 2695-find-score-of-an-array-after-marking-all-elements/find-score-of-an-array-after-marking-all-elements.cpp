class Solution {
public:
    struct compare
    {
        static bool operator()(pair<int, int>& a, pair<int, int>& b)
        {
            if (a.first>b.first) return true;
            if (a.first==b.first) return (a.second>b.second);
            return false;
        }
    };
    long long findScore(vector<int>& nums)
    {
        int n=nums.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
        for (int i=0; i<n; i++)
            pq.push({nums[i], i});
        
        long long ans=0;
        vector<bool> marked(n, false);
        while (!pq.empty())
        {
            int num=pq.top().first;
            int index=pq.top().second;
            pq.pop();
            
            if (marked[index]) continue;
            ans+=nums[index];
            
            marked[index]=true;
            if (index-1>=0) marked[index-1]=true;
            if (index+1<n) marked[index+1]=true;
        }
        return ans;
    }
};