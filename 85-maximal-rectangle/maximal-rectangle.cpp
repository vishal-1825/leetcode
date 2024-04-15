class Solution {
public:
    int largestRectangleHistogram(vector<int>& heights, int& n)
    {
        int ans=0;
        vector<int> leftsmall(n), rightsmall(n);
        stack<int> lst, rst;

        lst.push(-1);
        for (int i=0; i<n; i++)
        {
            while (lst.size()>1 && heights[lst.top()]>=heights[i])
                lst.pop();
            leftsmall[i]=lst.top();
            lst.push(i);
        }

        rst.push(n);
        for (int i=n-1; i>=0; i--)
        {
            while (rst.size()>1 && heights[rst.top()]>=heights[i])
                rst.pop();
            rightsmall[i]=rst.top();
            rst.push(i);
        }

        for (int i=0; i<n; i++)
            ans=max(ans, (rightsmall[i]-leftsmall[i]-1)*heights[i]);
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix)
    {
        int row=matrix.size(), col=matrix[0].size(), ans=0;
        vector<vector<int>> heights(row, vector<int>(col));
        for (int i=0; i<row; i++)
        {
            for (int j=0; j<col; j++)
                heights[i][j]=(matrix[i][j]-'0');
        }
        for (int r=1; r<row; r++)
        {
            for (int c=0; c<col; c++)
            {
                if (heights[r][c]==1)
                    heights[r][c]=heights[r-1][c]+1;
            }
        }
        for (int r=0; r<row; r++)
            ans=max(ans, largestRectangleHistogram(heights[r], col));
        return ans;
    }
};