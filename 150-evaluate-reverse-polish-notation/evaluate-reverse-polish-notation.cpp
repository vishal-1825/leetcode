class Solution {
public:
    int integer(string s)
    {
        
        int num=0;
        for (char c:s)
            if (c>='0' && c<='9')
                num=num*10+(c-'0');
        if (s[0]=='-') return -num;
        return num;
    }
    int eval(int op1, int op2, string t)
    {
        if (t=="+") return op1+op2;
        if (t=="-") return op1-op2;
        if (t=="*") return op1*op2;
        return op1/op2;
    }
    int evalRPN(vector<string>& tokens)
    {
        stack<int> st;
        int op1, op2, res=0;
        for (string t:tokens)
        {
            if (t=="+" || t=="-" || t=="*" || t=="/")
            {
                op2=st.top();
                st.pop();
                op1=st.top();
                st.pop();
                st.push(eval(op1, op2, t)); 
            }
            else st.push(integer(t));
        }
        return st.top();
    }
};