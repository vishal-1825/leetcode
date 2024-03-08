class Solution {
public:
    int numberOfSubstrings(string s)
    {
        int l=0, r=0;
        int af=0, bf=0, cf=0;
        int ans=0;
        while (r<s.length())
        {
            if (s[r]=='a') af++;
            else if (s[r]=='b') bf++;
            else if (s[r]=='c') cf++;

            while (af>0 && bf>0 && cf>0)
            {
                ans+=s.length()-r;
                if (s[l]=='a') af--;
                else if (s[l]=='b') bf--;
                else if (s[l]=='c') cf--;
                l++;
            }
            r++;
        }
        return ans;
    }
};