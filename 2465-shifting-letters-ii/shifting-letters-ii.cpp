class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts)
    {
        int n=s.length();
        vector<int> diffArray(n);
        for (auto shift: shifts)
        {
            int start=shift[0], end=shift[1], direction=shift[2];
            diffArray[start]+=(direction==1 ? 1 : -1);
            if (end+1<n) diffArray[end+1]+=(direction==1 ? -1 : 1);
        }
        for (int i=1; i<n; i++)
            diffArray[i]+=diffArray[i-1];

        string ans(n, ' ');
        for (int i=0; i<n; i++)
        {
            int netShift=(diffArray[i]%26+26)%26;
            ans[i]='a'+(s[i]-'a'+netShift)%26;
        }
        return ans;
    }
};