class Solution {
public:
    int equalSubstring(string s, string t, int maxCost)
    {
        int n=s.length(), i=0, j=0, ans=0, c=maxCost;
        while (j<n)
        {
            while (abs(s[j]-t[j])>c)
            {
                c+=abs(s[i]-t[i]);
                i++;
            }
            c-=abs(s[j]-t[j]);
            ans=max(ans, j-i+1);
            j++;
        }
        return ans;
    }
};