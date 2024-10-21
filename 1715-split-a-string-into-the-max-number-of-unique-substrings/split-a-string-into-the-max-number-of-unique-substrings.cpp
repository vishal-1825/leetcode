class Solution {
public:
    int maxSplit(string s, int start, unordered_set<string>& substrings)
    {
        if (start==s.length()) return 0;
        int ans=0;
        for (int end=start; end<s.length(); end++)
        {
            string substring=s.substr(start, end-start+1);
            if (substrings.find(substring)==substrings.end())
            {
                substrings.insert(substring);
                ans = max(ans, 1 + maxSplit(s, end+1, substrings));
                substrings.erase(substring);
            }
        }
        return ans;
    }
    int maxUniqueSplit(string s)
    {
        unordered_set<string> substrings;
        return maxSplit(s, 0, substrings); 
    }
};