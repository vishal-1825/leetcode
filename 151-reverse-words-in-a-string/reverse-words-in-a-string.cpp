class Solution {
public:
    string reverseWords(string s)
    {
        s+=' ';
        vector<string> words;
        string ss="", ans="";
        for (int i=0; i<s.length(); i++)
        {
            if (s[i]==' ')
            {
                if (ss.length()>0) words.push_back(ss);
                ss="";
            }
            else ss+=s[i];
        }
        for (int i=words.size()-1; i>=0; i--)
            ans+=words[i]+' ';
        ans.pop_back();
        return ans;
    }
};