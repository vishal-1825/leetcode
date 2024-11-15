class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr)
    {
        int n=arr.size(), ans=n-1;
        vector<int> left(n, 1), right(n, 1);
        for (int i=1; i<n; i++)
        {
            if (arr[i-1]<=arr[i])
                left[i]+=left[i-1];
        }
        for (int i=n-2; i>=0; i--)
        {
            if (arr[i]<=arr[i+1])
                right[i]+=right[i+1];
        }

        int l=0, r=n-1;
        while (l<=r)
        {
            int m=(l+r)/2, flag=0;
            if (right[m]==n-m) flag=1;
            else if (left[n-m-1]==n-m) flag=1;
            for (int i=1; i<=n-m-1 && flag==0; i++)
            {
                if (arr[i-1]<=arr[i+m] && left[i-1]==i && right[i+m]==n-i-m)
                {
                    flag=1;
                    break;
                }
            }

            if (flag==1)
            {
                ans=m;
                r=m-1;
            }
            else l=m+1;
        }
        return ans;
    }
};