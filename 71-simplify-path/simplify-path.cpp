class Solution {
public:
    string simplifyPath(string path)
    {
        int n=path.length(), i=1;
        stack<string> st;
        string s, ans="";

        while (i<n)
        {
            while (i<n && path[i]=='/')
                i++;
            s="";
            while (i<n && path[i]!='/')
                s+=path[i++];
            if (s==".." && !st.empty()) st.pop();
            else if (s!=".." && s!="." && s!="") st.push(s);
            i++;
        }
        
        if (st.empty()) return "/";
        while (!st.empty())
        {
            ans=("/"+st.top())+ans;
            st.pop();
        }
        return ans;
    }
};