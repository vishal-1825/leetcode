class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums)
    {
        int k=nums.size();
        vector<pair<int, int>> numbers;
        for (int i=0; i<k; i++)
        {
            for (int j=0; j<nums[i].size(); j++)
                numbers.push_back({nums[i][j], i});
        }
        sort(numbers.begin(), numbers.end());

        vector<int> lists(k, 0);
        int count=0, i=0, j=0, n=numbers.size(), low=0, high=INT_MAX;
        while (j<n)
        {
            lists[numbers[j].second]++;
            if (lists[numbers[j].second]==1) count++;
            while (count==k)
            {
                if (numbers[j].first-numbers[i].first<high-low)
                {
                    high=numbers[j].first;
                    low=numbers[i].first;
                }
                lists[numbers[i].second]--;
                if (lists[numbers[i].second]==0) count--;
                i++;
            }
            j++;
        }
        return {low, high};
    }
};