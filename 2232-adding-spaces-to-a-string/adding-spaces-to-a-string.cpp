class Solution {
public:
    string addSpaces(string s, vector<int>& spaces)
    {
        int j=0;
        string ans="";
        for (int i=0; i<s.length(); i++)
        {
            if (j<spaces.size() && i==spaces[j])
            {
                ans+=' ';
                j++;
            }
            ans+=s[i];
        }
        return ans;
    }
};