class Solution {
public:
    int hIndex(vector<int>& citations)
    {
        int n=citations.size(), ans=n;
        if (n==0) return 0;

        sort(citations.begin(), citations.end());

        for (int i=0; i<n; i++)
        {
            if (citations[i]>=n-i) break;
            ans--;
        }
        return ans; 
    }
};