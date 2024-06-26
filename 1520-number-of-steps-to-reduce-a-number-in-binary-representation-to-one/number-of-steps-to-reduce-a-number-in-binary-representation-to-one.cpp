class Solution {
public:
    int numSteps(string s)
    {
        int n=s.length(), ans=0;
        while (s.length()>1)
        {
            n=s.length(); 
            if (s[n-1]=='0') s.pop_back();
            else
            {
                int i=n-1;
                while (i>=0 && s[i]=='1')
                {
                    s[i]='0';
                    i--;
                }
                if (i<0) s='1'+s;
                else s[i]='1';
            }
            ans++;
        }
        return ans;
    }
};