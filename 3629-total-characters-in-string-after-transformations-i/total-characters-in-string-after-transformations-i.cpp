class Solution {
public:
    int lengthAfterTransformations(string s, int t)
    {
        long long mod=1e9+7, ans=0;
        vector<long long> fq(26, 0);
        for (char c: s)
            fq[c-'a']=(fq[c-'a']+1)%mod;
        for (int i=0; i<t; i++)
        {
            vector<long long> f(26, 0);
            for (int j=0; j<25; j++)
            {
                if (fq[j]==0) continue;
                f[j+1]=fq[j]%mod;
            }
            if (fq[25]>0)
            {
                f[0]=(f[0]+fq[25])%mod;
                f[1]=(f[1]+fq[25])%mod;
            }
            fq=f;
        }
        for (int i=0; i<26; i++)
            ans=(ans+fq[i])%mod;
        return ans;
    }
};