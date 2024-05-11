class Solution {
public:
    // after sorting wage[i]/quality[i] < wage[j]/quality[j] => wage[i] < ratio[j]*quality[i] holds true always
    // Time O(nlogn+nlogk)
    // Space O(n+k)
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k)
    {
        int n=quality.size();
        // ratio, quality
        vector<pair<double, int>> worker(n);
        for (int i=0; i<n; i++)
            worker[i]={double(wage[i])/double(quality[i]), quality[i]};
        sort(worker.begin(), worker.end());

        double ans=numeric_limits<double>::max(), qualitySum=0;
        priority_queue<int> pq;
        for (int i=0; i<n; i++)
        {
            qualitySum+=worker[i].second;
            pq.push(worker[i].second);
            while (pq.size()>k)
            {
                qualitySum-=pq.top();
                pq.pop();
            }
            if (pq.size()==k)
                ans=min(ans, qualitySum*worker[i].first);
        }
        return ans;
    }
};