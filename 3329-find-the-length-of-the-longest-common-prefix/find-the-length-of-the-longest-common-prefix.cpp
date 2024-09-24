class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2)
    {
        int ans=0;
        unordered_set<string> prefix1;
        for (int a1: arr1)
        {
            string a=to_string(a1);
            for (int i=1; i<=a.length(); i++)
                prefix1.insert(a.substr(0, i));
        }
        for (int a2: arr2)
        {
            string a=to_string(a2);
            for (int i=1; i<=a.length(); i++)
            {
                if (prefix1.find(a.substr(0, i))!=prefix1.end())
                    ans=max(ans, i);
            }
        }
        return ans;
    }
};