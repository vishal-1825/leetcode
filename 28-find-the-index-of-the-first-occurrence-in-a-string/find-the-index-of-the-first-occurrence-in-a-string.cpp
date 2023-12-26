class Solution {
public:
    int strStr(string haystack, string needle)
    {
        int n=needle.length(), h=haystack.length();
        for (int i=0; i<h-n+1; i++)
        {
            if (haystack.substr(i, n)==needle)
                return i;
        }
        return -1;
    }
};