class Solution {
public:
    int maxChunksToSorted(vector<int>& arr)
    {
        int n=arr.size(), i=0, j=0, minval=n+1, maxval=0, ans=0;
        while (j<n)
        {
            maxval=max(maxval, arr[j]);
            minval=min(minval, arr[j]);

            if (minval==i && maxval==j)
            {
                ans++;
                j++;
                i=j;
                minval=n+1;
                maxval=0;
            }
            else j++;
        }
        return ans;
    }
};