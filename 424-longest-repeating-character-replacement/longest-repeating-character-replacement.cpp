class Solution {
public:
    // Time -> O(26*n), Space -> O(1)
    int characterReplacement(string s, int k)
    {
        int n=s.length(), i, j, count, ans=0;
        for (char c='A'; c<='Z'; c++)
        {
            i=0, j=0, count=0;
            while (j<n)
            {
                if (s[j]!=c) count++;
                while (count>k)
                {
                    if (s[i]!=c) count--;
                    i++;
                }
                if (count<=k) ans=max(ans, j-i+1);
                j++;
            }
        }
        return ans;
    }
};