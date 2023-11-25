class Solution {
public:
    bool isValid(string s)
    {
        stack<char> brackets;

        for (auto& b : s)
        {
            if (b=='(' || b=='{' || b=='[') brackets.push(b);
            else if (brackets.empty()) return false;
            else
            {
                if (b==')' && brackets.top()!='(') return false;
                if (b=='}' && brackets.top()!='{') return false;
                if (b==']' && brackets.top()!='[') return false;
                brackets.pop();
            }
        }
        return brackets.empty();
    }
};