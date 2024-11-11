class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums)
    {
        int n=nums.size(), ans=1;
        vector<int> peaks;
        peaks.push_back(-1);
        vector<int> length(n, 0);
        length[0]=1;
        for (int i=1; i<n; i++)
        {
            if (nums[i]>nums[i-1])
                length[i]=1+length[i-1];
            else length[i]=1;
            if (length[i]==1) peaks.push_back(i-1);
        }
        if (length[n-1]!=1) peaks.push_back(n-1);
        for (int i=0; i<peaks.size()-1; i++)
        {
            int left, right;
            if (peaks[i]==-1) left=0;
            else left=length[peaks[i]];
            right=length[peaks[i+1]];
            int k=max({min(left, right), left/2, right/2});
            if (k>ans) ans=k;
        }
        return ans;
    }
};

// 2 5 7 8 9 2 3 4 3 1
// 1 2 3 4 5 1 2 3 1 2