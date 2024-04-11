class Solution {
public:
    string removeKdigits(string num, int k)
    {
        stack<char> prev;
        for (int i=0; i<num.length(); i++)
        {
            while (!prev.empty() && prev.top()>num[i] && k>0)
            {
                prev.pop();
                k--;
            }
            prev.push(num[i]);
        }
        while (num.length()>0 && k>0)
        {
            prev.pop();
            k--;
        }

        string ans="";
        while (!prev.empty())
        {
            ans+=prev.top();
            prev.pop();
        }
        reverse(ans.begin(), ans.end());

        int start=ans.length();
        for (int i=0; i<ans.length(); i++)
        {
            if (ans[i]!='0')
            {
                start=i;
                break;
            }
        }
        if (start==ans.length()) ans="0";
        else if (start>0) ans=ans.substr(start);
        return ans;
    }
};