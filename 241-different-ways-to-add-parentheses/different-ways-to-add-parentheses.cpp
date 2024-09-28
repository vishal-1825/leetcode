class Solution {
public:
    vector<int> diffWays(string expression, int s, int e, vector<vector<vector<int>>>& dp)
    {
        if (isdigit(expression[s]) && (s==e || e-s==1)) return {stoi(expression.substr(s, e-s+1))};

        if (!dp[s][e].empty()) return dp[s][e]; 
        vector<int> ans;
        for (int i=s; i<=e; i++)
        {
            if (isdigit(expression[i])) continue;
            vector<int> leftWays = diffWays(expression, s, i-1, dp);
            vector<int> rightWays = diffWays(expression, i+1, e, dp);
            for (auto l: leftWays)
            {
                for (auto r: rightWays)
                {
                    switch(expression[i])
                    {
                        case '+':
                            ans.push_back(l+r);
                            break;
                        case '-':
                            ans.push_back(l-r);
                            break;
                        case '*':
                            ans.push_back(l*r);
                            break;
                    }
                }
            }
        }
        return dp[s][e]=ans;
    }
    vector<int> diffWaysToCompute(string expression)
    {
        vector<vector<vector<int>>> dp(expression.length(), vector<vector<int>> (expression.length()));
        return diffWays(expression, 0, expression.length()-1, dp);    
    }
};