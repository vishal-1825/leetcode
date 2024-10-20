class Solution {
public:
    bool parseBoolExpr(string expression)
    {
        stack<char> opr, opd;
        int i=0;
        for (int i=0; i<expression.length(); i++)
        {
            if (expression[i]=='!' || expression[i]=='|' || expression[i]=='&') opr.push(expression[i]);
            else if (expression[i]==')')
            {
                char ans, op=opr.top(); opr.pop();
                if (op=='!')
                {
                    ans = (opd.top()=='f' ? 't' : 'f');
                    opd.pop();
                }
                else if (op=='|')
                {
                    int flag=0;
                    while (opd.top()!='(')
                    {
                        if (opd.top()=='t') flag=1;
                        opd.pop();
                    }
                    ans = (flag==1 ? 't' : 'f');
                }
                else
                {
                    int flag=1;
                    while (opd.top()!='(')
                    {
                        if (opd.top()=='f') flag=0;
                        opd.pop();
                    }
                    ans = (flag==1 ? 't' : 'f');
                }
                opd.pop();
                opd.push(ans);
            }
            else if (expression[i]==',') continue;
            else opd.push(expression[i]);
        }
        return (opd.top()=='t'? true : false);
    }
};