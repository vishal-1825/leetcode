class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix)
    {
        int n=matrix.size(), minPosVal=INT_MAX, maxNegVal=INT_MIN, negCount=0;
        long long ans=0;
        for (int i=0; i<n; i++)
        {
            for (int j=0; j<n; j++)
            {
                ans+=abs(matrix[i][j]);
                if (matrix[i][j]>=0) minPosVal=min(minPosVal, matrix[i][j]);
                else
                {
                    maxNegVal=max(maxNegVal, matrix[i][j]);
                    negCount++;
                }
            }
        }
        if (minPosVal!=0 && negCount%2==1) ans=max(ans-1LL*2*minPosVal, ans+1LL*2*maxNegVal);
        return ans;
    }
};
