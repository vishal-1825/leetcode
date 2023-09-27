class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp)
    {
        int n=temp.size();
        vector<int> answer(n, 0);
        stack<int> index;
        index.push(n-1);
        for (int i=n-2; i>=0; i--)
        {
            while (!index.empty() && temp[i]>=temp[index.top()]) index.pop();
            if (!index.empty()) answer[i]=index.top()-i;
            index.push(i);
        }
        return answer;
    }
};