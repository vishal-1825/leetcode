class Solution {
public:
    // All testase passed but gives TLE
    // vector<int> LDS(vector<int>& nums, int prev, int cur, vector<vector<vector<int>>>& dp)
    // {
    //     if (cur==nums.size()) return {};

    //     if (!dp[prev+1][cur].empty()) return dp[prev+1][cur];
        
    //     vector<int> op1, op2;
    //     if (prev==-1 || nums[prev]%nums[cur]==0 || nums[cur]%nums[prev]==0)
    //     {
    //         vector<int> op3 = LDS(nums, cur, cur+1, dp);
    //         op1.push_back(nums[cur]);
    //         op1.insert(op1.end(), op3.begin(), op3.end());
    //     }
    //     op2 = LDS(nums, prev, cur+1, dp);
    //     return dp[prev+1][cur] = ((op1.size() >= op2.size()) ? op1 : op2);
    // }
    vector<int> largestDivisibleSubset(vector<int>& nums)
    {
        // vector<vector<vector<int>>> dp(nums.size()+1, vector<vector<int>>(nums.size()+1, vector<int>()));
        // return LDS(nums, -1, 0, dp);

        // Totally different approach, use tabulation (similar to printing the longest increasing subsequence)
        // This is very important!!!!!!!        
        sort(nums.begin(), nums.end());
        int n=nums.size(), max_ind=0, max_len=1;;
        vector<int> dp(n, 1), prev(n, -1);
        // dp will store the length of longest divisible subset ending at the particular index
        // prev will store the index of the previous element of the divisible subset
        // The length of the longest divisible subset will be the maximum of the length of longest divisible subsets ending at every index
        // Taking that index, we can use the prev array to back track and find the sequence
        for (int cur=1; cur<n; cur++)
        {
            for (int lef=0; lef<cur; lef++)
            {
                if (nums[cur]%nums[lef]==0 && 1+dp[lef]>dp[cur])
                {
                    dp[cur]=1+dp[lef];
                    prev[cur]=lef;
                }
            }
            if (dp[cur]>max_len)
            {
                max_ind=cur;
                max_len=dp[cur];
            }
        }  

        vector<int> ans;
        while (max_ind>=0)
        {
            ans.push_back(nums[max_ind]);
            max_ind=prev[max_ind];
        }
        return ans;
    }
};