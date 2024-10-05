class Solution {
public:
    bool equal(vector<int>& f1, vector<int>& f2)
    {
        for (int i=0; i<26; i++)
        {
            if (f1[i]!=f2[i])
                return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2)
    {
        if (s2.length()<s1.length()) return false;

        vector<int> f1(26, 0), f2(26, 0);
        for (char s: s1)
            f1[s-'a']++;
        for (int i=0; i<s1.length(); i++)
            f2[s2[i]-'a']++;
        
        if (equal(f1, f2)) return true;
        for (int i=s1.length(); i<s2.length(); i++)
        {
            f2[s2[i]-'a']++;
            f2[s2[i-s1.length()]-'a']--;
            if (equal(f1, f2)) return true;
        }
        return false;
    }
};