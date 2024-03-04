class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power)
    {
        sort(tokens.begin(), tokens.end());
        int i=0, j=tokens.size()-1, ans=0, score=0;
        while (i<=j)
        {
            if (power<tokens[i])
            {
                if (score>=1)
                {
                    score--;
                    power+=tokens[j];
                    j--;
                }
                else break;
            }
            else
            {
                power-=tokens[i];
                score++;
                i++;
            }
            ans=max(ans, score);
        }
        return ans;
    }
};