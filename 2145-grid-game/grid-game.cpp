class Solution {
public:
    long long gridGame(vector<vector<int>>& grid)
    {
        int n=grid[0].size();
        vector<long long> topLeft(n), bottomRight(n);
        topLeft[0]=1LL*grid[0][0];
        for (int i=1; i<n; i++)
            topLeft[i]=1LL*(grid[0][i]+topLeft[i-1]);
        bottomRight[n-1]=1LL*grid[1][n-1];
        for (int i=n-2; i>=0; i--)
            bottomRight[i]=1LL*grid[1][i]+bottomRight[i+1];
        
        // minimize sum of second robot
        int minIndex=0;
        long long minSum=topLeft[n-1]-topLeft[0];
        for (int i=1; i<n; i++)
        {
            long long topSum=topLeft[n-1]-topLeft[i];
            long long bottomSum=bottomRight[0]-bottomRight[i];
            if (max(topSum, bottomSum)<minSum)
            {
                minIndex=i;
                minSum=max(topSum, bottomSum);
            }
        }

        for (int i=0; i<=minIndex; i++)
            grid[0][i]=0;
        for (int i=minIndex; i<n; i++)
            grid[1][i]=0;
        
        topLeft[0]=grid[0][0];
        for (int i=1; i<n; i++)
            topLeft[i]=1LL*grid[0][i]+topLeft[i-1];
        bottomRight[n-1]=1LL*grid[1][n-1];
        for (int i=n-2; i>=0; i--)
            bottomRight[i]=1LL*grid[1][i]+bottomRight[i+1];
        
        int maxIndex=0;
        long long maxSum=topLeft[0]+bottomRight[0];
        for (int i=1; i<n; i++)
        {
            if (topLeft[i]+bottomRight[i]>maxSum)
            {
                maxIndex=i;
                maxSum=topLeft[i]+bottomRight[i];
            }
        }
        return maxSum;
    }
};

// [20,3,20,17,2,12,15,17,4,15]
// 20  23  43  60  62  74  89  106 110 125
// 99  79  69  56  42  27  22  20   17  3

// 119 102 112 116 104 101 111 126 127 128
// [20,10,13,14,15,5,2,3,14,3]


// [0, 0, 0, 0, 0, 0,0,0,0,0]
// [20,10,13,14,15,5,2,3,14,0]
