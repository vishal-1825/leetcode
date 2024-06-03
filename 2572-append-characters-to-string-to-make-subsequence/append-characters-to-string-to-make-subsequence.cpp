class Solution {
public:
    int appendCharacters(string s, string t)
    {
        int i=0, j=0;
        while (j<t.length() && i<s.length())
        {
            while (i<s.length() && s[i]!=t[j])
                i++;
            if (i<s.length())
            {
                i++;
                j++;
            }
        }
        return (t.length()-j);
    }
};