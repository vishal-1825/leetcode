typedef long long ll;
class Solution {
public:
    // TLE
    // int maxFrequencyScore(vector<int>& nums, long long k)
    // {
    //     sort(nums.begin(), nums.end());

    //     unordered_map<ll, ll> freq, index;
    //     for (int i=0; i<nums.size(); i++)
    //     {
    //         freq[nums[i]]++;
    //         index[nums[i]]=i; // last occurence
    //     }

    //     priority_queue<pair<ll, ll>> pq;
    //     for (auto& f : freq)
    //         pq.push({f.second, f.first});
        
    //     ll ans=0;
    //     while (!pq.empty())
    //     {
    //         ll el = pq.top().second;
    //         ll fq = pq.top().first;
    //         pq.pop();
            
    //         ll right = index[el]+1, left = index[el]-fq, count=k;
            
    //         while (count!=0 && left>=0 && right<nums.size() && el-nums[left]<=count && nums[right]-el<=count)
    //         {
    //             if (el-nums[left] <= nums[right]-el) count-=(el-nums[left--]);
    //             else count-=(nums[right++]-el);
    //             fq++;
    //         }
    //         while (count!=0 && left>=0 && el-nums[left]<=count)
    //         {
    //             count-=(el-nums[left--]);
    //             fq++;
    //         }
    //         while (count!=0 && right<nums.size() && nums[right]-el<=count)
    //         {
    //             count-=(nums[right++]-el);
    //             fq++;
    //         }

    //         ans=max(ans, fq);
    //     }

    //     return ans;
    // }
    // O(nlogn + n + nlogn)
    bool findFreq(ll len, vector<int>& nums, ll k, vector<ll>& preSum){
        for(int i = 0 ; i <= nums.size() - len ; i++)
        {
            int j = i + len - 1;
            int median = (len % 2 == 1) ? nums[(i + j) / 2] : (nums[(i + j) / 2] + nums[(i + j + 2) / 2]) / 2;
            int mid = (i + j) / 2;
            ll leftK = (ll)median * (mid - i + 1) - (preSum[mid] - ((i - 1 >= 0) ? preSum[i - 1] : 0));
            ll rightK = (preSum[j] - preSum[mid]) - ((ll)median * (j - mid));
            if(leftK + rightK <= k) return true;
        }
        return false;
    }
    // bool findFreq(ll freq, vector<int>& nums, ll k, vector<ll>& prefix){
    //     int n=nums.size();
    //     for(int i = 0 ; i <= n - freq ; i++){
    //         int j = i + freq - 1;
    //         int median = (freq & 1) ? nums[(i + j) / 2] : (nums[(i + j) / 2] + nums[(i + j + 2) / 2]) / 2;
    //         int ind = (i + j) / 2;
    //         long lft_sum = (long)median * (ind - i + 1) - (prefix[ind] - ((i - 1 >= 0) ? prefix[i - 1] : 0));
    //         long rgt_sum = (prefix[j] - prefix[ind]) - ((long)median * (j - ind));
    //         if(lft_sum + rgt_sum <= k)
    //             return true;
    //     }
    //     return false;
    // }
    int maxFrequencyScore(vector<int>& nums, long long k)
    {
        sort(nums.begin(), nums.end());

        vector<ll> preSum(nums.size(), 0);
        preSum[0] = nums[0];
        for (ll i=1; i<nums.size(); i++)
            preSum[i] = preSum[i-1] + nums[i];

        ll l=1, r=nums.size(), mid=0, ans=0;
        while (l<=r)
        {
            mid = (l+r)/2; // mid = length of subarray we consider
            bool isLengthOk = findFreq(mid, nums, k, preSum);
            if (isLengthOk)
            {
                ans=mid;
                l=mid+1;
            }
            else r=mid-1;
        }
        return ans;
    }
};