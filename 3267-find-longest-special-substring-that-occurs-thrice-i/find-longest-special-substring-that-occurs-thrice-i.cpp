class Solution {
public:
    // bool check(string s, int i, int j, int n, int& ans)
    // {
    //     int le=j-i+1, count=1;
    //     if (le<=ans) return false;
    //     for (int k=i+1; k<=n-le+1; k++)
    //     {
    //         if (s.substr(k, le)==s.substr(i, le))
    //             count++;
    //         if (count==3)
    //         {
    //             ans=le;
    //             return true;
    //         }
    //     }
    //     return false;
    // }
    // int maximumLength(string s)
    // {
    //     int i=0, j=0, n=s.length(), ans=-1;
    //     while (i<n)
    //     {
    //         while (j<n && s[i]==s[j]) j++;
    //         j--;
    //         while (j>=i)
    //         {
    //             if (!check(s, i, j, n, ans)) j--;
    //             else break;
    //         }
    //         i++;
    //         j=i;
    //     }
    //     return ans;
    // }
    bool specialCheck(string s, int le, int& ans)
    {
        for (char c='a'; c<='z'; c++)
        {
            unordered_map<char, int> fc;
            int fq=0;
            for (int i=0; i<le; i++)
                fc[s[i]]++;
            if (fc[c]==le) fq++;
            for (int i=1; i+le-1<s.length(); i++)
            {
                fc[s[i-1]]--;
                fc[s[i+le-1]]++;
                if (fc[c]==le) fq++;
                if (fq==3)
                {
                    ans=le;
                    return true;
                }
            }
        }
        return false;
    }
    int maximumLength(string s)
    {
        int l=1, r=s.length(), m, ans=-1;
        while (l<=r)
        {
            m=(l+r)/2;
            if (specialCheck(s, m, ans)) l=m+1;
            else r=m-1;
        }
        return ans;
    }
};