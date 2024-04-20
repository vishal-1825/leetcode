class Solution {
public:
    string reorganizeString(string s)
    {
        int n=s.length();
        vector<int> fq(26, 0);
        for (char c: s)
            fq[c-'a']++;
        
        priority_queue<pair<int, char>> pq;
        for (int i=0; i<26; i++)
        {
            if (fq[i]>0)
                pq.push({fq[i], char(i+'a')});
        }

        string ans="";
        while (pq.size()>1)
        {
            char c1=pq.top().second;
            int f1=pq.top().first;
            pq.pop();
            char c2=pq.top().second;
            int f2=pq.top().first;
            pq.pop();

            ans+=c1;
            ans+=c2;
            f1--;
            f2--;

            if (f1>0) pq.push({f1, c1});
            if (f2>0) pq.push({f2, c2});
        }
        if (!pq.empty())
        {
            char c=pq.top().second;
            int f=pq.top().first;
            pq.pop();
            
            if (f>1)
                return "";
            ans+=c;
        }
        return ans;
    }
};