class Solution {
public:
    vector<int> constructLPS(vector<int>& pattern, int m)
    {
        vector<int> lps(m);
        lps[0]=0;
        int i=0, j=1;
        while (j<m)
        {
            if (pattern[i]==pattern[j])
            {
                lps[j]=i+1;
                i++;
                j++;
            }
            else if (i!=0) i=lps[i-1];
            else
            {
                lps[j]=0;
                j++;
            }
        }
        return lps;
    }
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern)
    {
        int n=nums.size()-1;
        vector<int> value(n);
        for (int i=0; i<n; i++)
        {
            if (nums[i+1]>nums[i]) value[i]=1;
            else if (nums[i+1]==nums[i]) value[i]=0;
            else value[i]=-1;
        }

        int m=pattern.size();
        vector<int> lps=constructLPS(pattern, m);

        int i=0, j=0, ans=0;
        while (i<n)
        {
            if (value[i]==pattern[j])
            {
                i++;
                j++;
            }

            if (j==m)
            {
                ans++;
                j=lps[j-1];
            }
            else if (i<n && value[i]!=pattern[j])
            {
                if (j!=0) j=lps[j-1];
                else i++;
            }
        }
        return ans;
    }
};