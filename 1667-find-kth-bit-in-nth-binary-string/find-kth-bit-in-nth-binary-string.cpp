class Solution {
public:
    string invert(string s)
    {
        string ans="";
        for (char c: s)
            ans+=((c=='0') ? '1' : '0');
        return ans;
    }
    string reverse(string s)
    {
        string ans="";
        for (int i=s.length()-1; i>=0; i--)
            ans+=s[i];
        return ans;
    }
    char findKthBit(int n, int k)
    {
        string s="0";
        for (int i=2; i<=n; i++)
            s=s+"1"+reverse(invert(s));
        return s[k-1];
    }
};