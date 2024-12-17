class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit)
    {
        vector<int> fq(26, 0);
        for (auto c: s)
            fq[c-'a']++;
        
        stack<pair<int, int>> st;
        for (int i=0; i<26; i++)
        {
            if (fq[i]>0)
                st.push({i, fq[i]});
        }

        // stack<pair<int, int>> st;
        string ans="";
        while (!st.empty())
        {
            char c=char(st.top().first+'a');
            int f=st.top().second;
            st.pop();

            int rep=0;
            if (f>repeatLimit) rep=repeatLimit;
            else rep=f;
            for (int i=0; i<rep; i++)
                ans+=c;
            f-=rep;
            
            if (f==0) continue;
            if (st.empty()) break;
            
            char c1=char(st.top().first+'a');
            int f1=st.top().second;
            st.pop();

            ans+=c1;
            f1--;
            if (f1>0) st.push({c1-'a', f1});
            st.push({c-'a', f});
        }

        return ans;
    }
};