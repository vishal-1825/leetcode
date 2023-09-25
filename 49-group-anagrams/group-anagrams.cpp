class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        int i;
        unordered_map<string, vector<string>> anagrams;
        vector<vector<string>> ans;
        string s;

        for (i=0; i<strs.size(); i++)
        {
            s=strs[i];
            sort(s.begin(), s.end());
            anagrams[s].push_back(strs[i]);
        }

        for (auto it: anagrams)
            ans.push_back(it.second);
        return ans;
    }
};