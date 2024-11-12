class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries)
    {
        sort(items.begin(), items.end());
        map<int, int> q;
        for (int i=0; i<queries.size(); i++)
            q[queries[i]]=0;
        int i=0, maxBeauty=0;
        for (auto query: q)
        {
            int price=query.first;
            while (i<items.size() && items[i][0]<=price)
            {
                maxBeauty=max(maxBeauty, items[i][1]);
                i++;
            }
            q[price]=maxBeauty;
        }
        vector<int> ans;
        for (int i=0; i<queries.size(); i++)
            ans.push_back(q[queries[i]]);
        return ans;
    }
};