class Solution {
public:
    long long minimumSteps(string s)
    {
        long long ans=0, one=0;
        for (int i=0; i<s.length(); i++)
        {
            if (s[i]=='1') one++;
            else ans+=one;
        }
        return ans;
    }
};