class Solution {
public:
    int pow(int x, int y, int mod)
    {
        if (y==0) return 1;

        int part = pow(x, y/2, mod);
        if (y%2==0) return (part * part) % mod;
        return (((part * part) % mod) * x) % mod;
    }
    vector<int> getGoodIndices(vector<vector<int>>& variables, int target)
    {
        vector<int> ans;
        int n=variables.size();
        for (int i=0; i<n; i++)
        {
            int a=variables[i][0], b=variables[i][1], c=variables[i][2], m=variables[i][3];
            if (pow(pow(a, b, 10), c, m) == target) ans.push_back(i);
        }
        return ans;
    }
};