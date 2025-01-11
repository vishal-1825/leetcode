class Solution {
public:
    bool canConstruct(string s, int k)
    {
        if (s.length()<k) return false;

        vector<int> fq(26, 0);
        for (char c: s)
            fq[c-'a']++;

        int oddCount=0;
        for (int i=0; i<26; i++)
            oddCount+=(fq[i]%2==1 ? 1 : 0);
        return (oddCount<=k);
    }
};