class Solution {
public:
    vector<int> minOperations(string boxes)
    {
        queue<int> leftOnes, rightOnes;
        int n=boxes.length();
        for (int i=1; i<n; i++)
        {
            if (boxes[i]=='1')
                rightOnes.push(i);
        }

        vector<int> ans(n);
        for (int i=0; i<n; i++)
        {
            if (!rightOnes.empty() && rightOnes.front()==i) rightOnes.pop();
            int leftSum=0, rightSum=0;
            if (!leftOnes.empty())
            {
                int sz=leftOnes.size();
                while (sz--)
                {
                    int leftIndex=leftOnes.front();
                    leftOnes.pop();
                    leftSum+=(i-leftIndex);
                    leftOnes.push(leftIndex);
                }
            }
            if (!rightOnes.empty())
            {
                int sz=rightOnes.size();
                while (sz--)
                {
                    int rightIndex=rightOnes.front();
                    rightOnes.pop();
                    rightSum+=(rightIndex-i);
                    rightOnes.push(rightIndex);
                }
            }
            ans[i]=leftSum+rightSum;
            if (boxes[i]=='1') leftOnes.push(i);
        }
        return ans;
    }
};