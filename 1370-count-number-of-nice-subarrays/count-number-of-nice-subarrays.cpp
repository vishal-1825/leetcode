class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k)
    {
        int n=nums.size();
        vector<int> nextOddIndex(n);
        nextOddIndex[n-1]=n;
        for (int i=n-2; i>=0; i--)
        {
            if (nums[i+1]%2==1) nextOddIndex[i]=i+1;
            else nextOddIndex[i]=nextOddIndex[i+1];
        }

        vector<int> prevOddIndex(n);
        prevOddIndex[0]=-1;
        for (int i=1; i<n; i++)
        {
            if (nums[i-1]%2==1) prevOddIndex[i]=i-1;
            else prevOddIndex[i]=prevOddIndex[i-1];
        }

        int i=0, j=0, count=0, ans=0;
        while (j<n)
        {
            if (nums[j]%2==1) count++;
            if (count==k)
            {
                while (nums[i]%2==0)
                    i++;
                ans=ans+(i-prevOddIndex[i]-1)+(nextOddIndex[j]-j-1)+(i-prevOddIndex[i]-1)*(nextOddIndex[j]-j-1)+1;
                i++;
                count--;
            }
            j++;
        }
        return ans;
    }
};
//  0  1  2  3 4 5 6 7 8 9 indices
//  2  2  2  1 2 2 1 2 2 2 
// -1 -1 -1 -1 3 3 3 6 6 6 prevOddIndex
//  3  3  3  6 6 6 10 10 10 10 nextOddIndex