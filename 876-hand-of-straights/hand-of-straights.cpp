class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize)
    {
        if (hand.size()%groupSize!=0) return false;

        unordered_map<int, int> fq;
        for (int i: hand)
            fq[i]++;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (auto f: fq)
            pq.push({f.first, f.second});
        
        while (!pq.empty())
        {
            int c=0, prev=-1;
            vector<pair<int, int>> pairs;
            while (!pq.empty() && c<groupSize)
            {
                int val=pq.top().first;
                int f=pq.top().second;
                pq.pop();
                if (prev!=-1 && prev!=val-1) return false;
                if (--f>0) pairs.push_back({val, f});
                c++;
                prev=val;
            }
            cout << endl;
            if (c!=groupSize) return false;
            for (auto p: pairs)
                pq.push({p.first, p.second});
        }
        return true;
    }
};

// 1: 1
// 2: 2
// 3: 2
// 6: 1
// 7: 1
// 8: 1