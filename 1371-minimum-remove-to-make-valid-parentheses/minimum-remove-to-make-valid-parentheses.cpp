class Solution {
public:
    string minRemoveToMakeValid(string s)
    {
        stack<int> open, close, skip;
        string ans="";
        for (int i=0; i<s.length(); i++)
        {
            if (s[i]=='(') open.push(i);
            else if (s[i]==')')
            {
                if (open.empty()) close.push(i);
                else open.pop();
            }
        }
        while (!open.empty())
        {
            skip.push(open.top());
            open.pop();
        }
        while (!close.empty())
        {
            skip.push(close.top());
            close.pop();
        }
        for (int i=0; i<s.length(); i++)
        {
            if (!skip.empty() && i==skip.top())
            {
                skip.pop();
                continue;
            }
            ans+=s[i];
        }
        return ans;
    }
};