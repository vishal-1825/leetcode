class Solution {
public:
    vector<int> partitionLabels(string s)
    {
        int n=s.length();
        unordered_map<char, int> last;
        for (int i=0; i<n; i++)
            last[s[i]]=i;
        
        vector<int> ans;
        int limit=0, i=0;
        while (i<n)
        {
            limit=last[s[i]];
            int j=i+1;
            while (j<=limit && limit<n)
            {
                if (last[s[j]]>limit) limit=last[s[j]];
                j++;
            }
            ans.push_back(j-i);
            i=j;
        }
        return ans;
    }
};