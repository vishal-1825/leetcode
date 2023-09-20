class Solution {
public:
    string convert(string s, int numRows)
    {
        int i=0, n=s.length(), j;
        bool rev=false;
        vector<string> zigzag(numRows, "");
        string ans="";

        while (i<n)
        {
            if (!rev)
            {
                j=0;
                while (i<n && j<numRows)
                    zigzag[j++]+=s[i++];
            }
            else
            {
                j=numRows-2;
                while (i<n && j>0)
                    zigzag[j--]+=s[i++];
            }
            rev=!rev;
        }

        for (i=0; i<numRows; i++)
            ans+=zigzag[i];
        return ans;
    }
};