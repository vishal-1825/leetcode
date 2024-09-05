class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n)
    {
        int m=rolls.size(), actual_sum=0, required_sum=mean*(m+n);
        for (int r: rolls)
            actual_sum+=r;

        if (actual_sum+n>required_sum || actual_sum+6*n<required_sum) return {};

        int mean2=(required_sum-actual_sum)/n;
        if (mean2<1) mean2=1;
        else if (mean2>6) mean2=6;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i=0; i<n; i++)
        {
            pq.push(mean2);
            actual_sum+=mean2;
        }
        
        while (actual_sum!=required_sum)
        {
            int p=pq.top();
            pq.pop();
            cout << p << endl;
            p++;
            pq.push(p);
            actual_sum++;
        }

        vector<int> ans;
        while (!pq.empty())
        {
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
    }
};