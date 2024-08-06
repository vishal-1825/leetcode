class Solution {
public:
    int minimumPushes(string word)
    {
        vector<int> fq(26, 0);
        for (char w: word)
            fq[w-'a']++;
        
        priority_queue<pair<int, int>> pq;
        for (int i=0; i<26; i++)
        {
            if (fq[i]>0)
                pq.push({fq[i], i});
        }
        
        int count=0, ans=0;
        while (!pq.empty())
        {
            int f=pq.top().first;
            pq.pop();

            if (count<8) ans+=f;
            else if (count<16) ans+=2*f;
            else if (count<24) ans+=3*f;
            else ans+=4*f;
            count++;
        }
        return ans;
    }
};