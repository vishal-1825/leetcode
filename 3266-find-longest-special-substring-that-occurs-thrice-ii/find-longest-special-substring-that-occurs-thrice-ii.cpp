class Solution {
public:
    // O(26nlogn)
    // bool specialCheck(string s, int le, int& ans)
    // {
    //     for (char c='a'; c<='z'; c++)
    //     {
    //         unordered_map<char, int> fc;
    //         int fq=0;
    //         for (int i=0; i<le; i++)
    //             fc[s[i]]++;
    //         if (fc[c]==le) fq++;
    //         for (int i=1; i+le-1<s.length(); i++)
    //         {
    //             fc[s[i-1]]--;
    //             fc[s[i+le-1]]++;
    //             if (fc[c]==le) fq++;
    //             if (fq==3)
    //             {
    //                 ans=le;
    //                 return true;
    //             }
    //         }
    //     }
    //     return false;
    // }
    // int maximumLength(string s)
    // {
    //     int l=1, r=s.length(), m, ans=-1;
    //     while (l<=r)
    //     {
    //         m=(l+r)/2;
    //         if (specialCheck(s, m, ans)) l=m+1;
    //         else r=m-1;
    //     }
    //     return ans;
    // }
    // O(n) time, O(n) space
    int maximumLength(string s)
    {
        unordered_map<string, int> fq;
        int i=0, n=s.length();
        while (i<n)
        {
            string sub="";
            while (i<n-1 && s[i+1]==s[i])
            {
                sub+=s[i];
                i++;
            }
            sub+=s[i];
            i++;
            if (fq[sub]<3) fq[sub]++;
        }

        int ans=-1;
        for (auto& [sub, freq]: fq)
        {
            if (fq.find(sub+sub[0])!=fq.end() || freq==3) ans=max(ans, (int)sub.length());
            else if (freq==2) ans=max(ans, (int)sub.length()-1);
            else if (freq==1) ans=max(ans, (int)sub.length()-2); 
        }

        return (ans ? ans : -1);
    }
};