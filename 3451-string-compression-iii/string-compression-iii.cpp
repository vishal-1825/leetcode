class Solution {
public:
    string compressedString(string word)
    {
        string ans="";
        int i=0;
        while (i<word.length())
        {
            char c=word[i];
            int count=0;
            while (i<word.length() && count<9 && word[i]==c)
            {
                i++;
                count++;
            }
            ans+=char(count+'0');
            ans+=c;
        }
        return ans;
    }
};