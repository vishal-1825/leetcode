class Solution {
public:
    void cs(vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int>& comb, int i)
    {
        if (target==0)
        {
            ans.push_back(comb);
            return;
        }

        for (int j=i; j<candidates.size(); j++)
        {
            if (j>i && candidates[j]==candidates[j-1]) continue;
            if (target<candidates[i]) break;
            comb.push_back(candidates[j]);
            cs(candidates, target-candidates[j], ans, comb, j+1);
            comb.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> comb;
        cs(candidates, target, ans, comb, 0);
        return ans;
    }
};