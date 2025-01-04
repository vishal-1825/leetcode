class Solution {
public:
    int countPalindromicSubsequence(string s)
    {
        int ans=0;
        for (int i=0; i<26; i++)
        {
            int first=-1, last=-1, sub=0;
            unordered_set<char> hash;
            for (int j=0; j<s.length(); j++)
            {
                if (first==-1 && s[j]==char(i+'a')) first=j;
                else if (first!=-1 && s[j]!=char(i+'a')) hash.insert(s[j]);
                else if (s[j]==char(i+'a'))
                {
                    sub=hash.size();
                    last=j;
                    hash.insert(s[j]);
                }
            }
            ans+=sub;
        }
        return ans;
    }
};