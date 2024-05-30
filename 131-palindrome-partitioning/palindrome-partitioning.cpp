class Solution {
public:
    // Time -> O(n*2^n), Space -> O(n)
    bool isPalindrome(string s)
    {
        int i=0, j=s.length()-1;
        while (i<j)
        {
            if (s[i]!=s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    void partition(string& s, int i, vector<string> combination, vector<vector<string>>& ans)
    {
        if (i==s.length())
        {
            ans.push_back(combination);
            return;
        }

        string sub="";
        for (int ind=i; ind<s.length(); ind++)
        {
            sub+=s[ind];
            if (isPalindrome(sub))
            {
                combination.push_back(sub);
                partition(s, ind+1, combination, ans);
                combination.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> ans;
        vector<string> combination;
        partition(s, 0, combination, ans);
        return ans;
    }
};