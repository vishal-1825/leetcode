class Solution {
public:
    string decodeString(string s)
    {
        stack<string> st;
        int i=0;
        string ans="";
        while (i<s.length())
        {
            if (s[i]=='[')
            {
                st.push(to_string(s[i]));
                i++;
            }
            else if (isalpha(s[i]))
            {
                string p="";
                while (isalpha(s[i]))
                {
                    p+=s[i];
                    i++;
                }
                if (!st.empty() && st.top()!="[" && !isdigit(st.top()[0]))
                {
                    p=st.top()+p;
                    st.pop();
                }
                st.push(p);
                // cout << p << " ";
            }
            else if (isdigit(s[i]))
            {
                string num="";
                while (isdigit(s[i]))
                {
                    num+=s[i];
                    i++;
                }
                st.push(num);
                // cout << num << " ";
            }
            else
            {
                string p=st.top(), fp=p;
                st.pop();
                st.pop();
                int rep=stoi(st.top());
                st.pop();
                for (int r=1; r<rep; r++)
                    fp+=p;
                if (st.empty() || st.top()=="[" || isdigit(st.top()[0])) st.push(fp);
                else
                {
                    fp=st.top()+fp;
                    st.pop();
                    st.push(fp);
                }
                i++;
                // cout << fp << " ";
            }
        }
        while (!st.empty())
        {
            ans=st.top()+ans;
            st.pop();
        }
        return ans;
    }
};