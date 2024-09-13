class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries)
    {
        int n=arr.size();
        vector<vector<int>> oneCount(n, vector<int>(32, 0));
        vector<int> ans(queries.size(), 0);
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<=31; j++)
            {
                int bit=((arr[i]>>j)&1);
                if (bit==1)
                    oneCount[i][j]=1;
            }
        }
        for (int i=1; i<n; i++)
        {
            for (int j=0; j<=31; j++)
                oneCount[i][j]+=oneCount[i-1][j];
        }
        for (int i=0; i<queries.size(); i++)
        {
            int l=queries[i][0], r=queries[i][1];
            for (int j=0; j<=31; j++)
            {
                int oc=oneCount[r][j];
                if (l>0) oc-=oneCount[l-1][j];
                if (oc%2==1) ans[i] = (ans[i] | 1<<j);
            }
        }
        return ans;
    }
};