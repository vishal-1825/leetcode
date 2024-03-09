class Solution {
public:
    // Used editorial, still confusing
    string shortestPalindrome(string s)
    {
        int n=s.length();
        int i=0;
        for (int j=n-1; j>=0; j--)
        {
            if (s[i]==s[j])
                i++;
        }
        if (i==n) return s;
        string prefix=s.substr(i), suffix=s.substr(i);
        reverse(prefix.begin(), prefix.end());
        return prefix+shortestPalindrome(s.substr(0, i))+suffix;
    }
};