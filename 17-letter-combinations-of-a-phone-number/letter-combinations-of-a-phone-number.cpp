class Solution {
public:
    void mapping(int i, string& digits, vector<string>& dict, string comb, vector<string>& ans)
    {
        if (i==digits.size())
        {
            if (comb.size()>0)
                ans.push_back(comb);
            return;
        }

        for (auto d: dict[digits[i]-'0'])
            mapping(i+1, digits, dict, comb+d, ans);
    }
    vector<string> letterCombinations(string digits)
    {
        vector<string> dict = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans;
        string comb="";
        mapping(0, digits, dict, comb, ans);
        return ans;  
    }
};