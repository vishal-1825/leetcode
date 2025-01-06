class Solution {
public:
    vector<int> minOperations(string boxes)
    {
        int n=boxes.length();
        int leftCount=0, rightCount=0, leftSum=0, rightSum=0;

        for (int i=0; i<n; i++)
        {
            if (boxes[i]=='1')
            {
                rightCount++;
                rightSum+=i;
            }
        }

        vector<int> ans(n);
        for (int i=0; i<n; i++)
        {
            if (boxes[i]=='1')
            {
                rightCount--;
                rightSum-=i;
            }
            ans[i]+=(leftCount*i-leftSum);
            ans[i]+=(rightSum-rightCount*i);
            if (boxes[i]=='1')
            {
                leftCount++;
                leftSum+=i;
            }
        }
        return ans;
    }
};