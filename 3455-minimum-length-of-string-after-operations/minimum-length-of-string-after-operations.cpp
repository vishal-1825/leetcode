class Solution {
public:
    int minimumLength(string s)
    {
        vector<int> fq(26, 0);
        for (char c: s)
            fq[c-'a']++;
        
        int ans=0;
        for (int i=0; i<26; i++)
        {
            if (fq[i]<3) ans+=fq[i];
            else if (fq[i]%2==0) ans+=2;
            else ans++;
        }
        return ans;
    }
};