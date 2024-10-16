class Solution {
public:
    string longestDiverseString(int a, int b, int c)
    {
        string ans="";
        priority_queue<pair<int, char>> pq;
        if (a>0) pq.push({a, 'a'});
        if (b>0) pq.push({b, 'b'});
        if (c>0) pq.push({c, 'c'});
        while (!pq.empty())
        {
            char c1=pq.top().second;
            int f1=pq.top().first;
            pq.pop();
            if (ans.length()<2 || (c1!=ans[ans.length()-2] || c1!=ans[ans.length()-1]))
            {
                ans+=c1;
                cout << ans << endl;
                f1--;
                if (f1>0)
                    pq.push({f1, c1});
            }
            else if (pq.empty()) break;
            else
            {
                char c2=pq.top().second;
                int f2=pq.top().first;
                pq.pop();
                ans+=c2;
                f2--;
                if (f2>0)
                    pq.push({f2, c2});
                pq.push({f1, c1});
            }
        }
        return ans;
    }
};