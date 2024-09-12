class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit)
    {
        int n=nums.size(), l=0, r=0, ans=1;
        multiset<int> s;
        s.insert(nums[0]);
        while (r<n)
        {
            // cout << *s.begin() << " " << *s.rbegin() << " " << l << " " << r << endl;
            while (abs(*s.begin()-*s.rbegin())<=limit)
            {
                ans=max(ans, r-l+1);
                r++;
                if (r==n) break;
                s.insert(nums[r]);
                // cout << *s.begin() << " " << *s.rbegin() << " " << l << " " << r << endl;
            }
            auto e=s.find(nums[l]);
            if (e!=s.end()) s.erase(e);
            l++;
        }
        return ans;
    }
};