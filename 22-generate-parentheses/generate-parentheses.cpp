class Solution {
public:
    void getPar(vector<string>& ans, string res, int open, int close, int n)
    {
        if (open==close && open==n)
        {
            ans.push_back(res);
            return;
        }
        if (open<n) getPar(ans, res+'(', open+1, close, n);
        if (close<open) getPar(ans, res+')', open, close+1, n);
    }
    vector<string> generateParenthesis(int n)
    {
        vector<string> ans;
        getPar(ans, "(", 1, 0, n);
        return ans;
    }
};