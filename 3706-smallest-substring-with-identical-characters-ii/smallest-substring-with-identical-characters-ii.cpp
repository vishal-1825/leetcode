class Solution {
public:
    bool specialCase(string s, char num, int numOps)
    {
        int ops=0;
        for (int i=0; i<s.length(); i++)
        {
            if (i%2==0 && s[i]!=num) ops++;
            else if (i%2==1 && s[i]==num) ops++;
        }
        return (ops<=numOps);
    }
    bool possible(string s, int len, int numOps)
    {
        if (len==1) return (specialCase(s, '0', numOps) || specialCase(s, '1', numOps));
        int i=0, j=0, n=s.length(), ops=0;
        // this is wrong
        // while (i<n)
        // {
        //     while (j<n && j-i<len && s[i]==s[j])
        //         j++;
        //     if (j-i==len && s[i]==s[j])
        //     {
        //         s[j]=(s[j]=='0' ? '1' : '0');
        //         ops++;
        //     }
        //     else i=j;
        // }
        // this is correct
        while (i<n)
        {
            while (j<n && s[i]==s[j])
                j++;
            ops+=(j-i)/(len+1);
            i=j;
        }
        return (ops<=numOps);
    }
    int minLength(string s, int numOps)
    {
        int n=s.length(), left=1, right=n, ans=n;
        while (left<=right)
        {
            int mid=(left+right)/2;
            if (possible(s, mid, numOps))
            {
                ans=mid;
                right=mid-1;
            }
            else left=mid+1;
        }
        return ans;
    }
};