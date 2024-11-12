class Solution {
public:
    int binarySearch(int maxPrice, vector<vector<int>>& items)
    {
        int l=0, r=items.size()-1, maxBeauty=0;
        while (l<=r)
        {
            int m=(l+r)/2;
            if (items[m][0]<=maxPrice)
            {
                maxBeauty=max(maxBeauty, items[m][1]);
                l=m+1;
            }
            else r=m-1;
        }
        return maxBeauty;
    }
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries)
    {
        sort(items.begin(), items.end());
        int maxBeauty=items[0][1];
        for (int i=0; i<items.size(); i++)
        {
            maxBeauty=max(maxBeauty, items[i][1]);
            items[i][1]=maxBeauty;
        }
        vector<int> ans;
        for (int i=0; i<queries.size(); i++)
            ans.push_back(binarySearch(queries[i], items));
        return ans;
    }
    // vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries)
    // {
    //     sort(items.begin(), items.end());
    //     map<int, int> q;
    //     for (int i=0; i<queries.size(); i++)
    //         q[queries[i]]=0;
    //     int i=0, maxBeauty=0;
    //     for (auto query: q)
    //     {
    //         int price=query.first;
    //         while (i<items.size() && items[i][0]<=price)
    //         {
    //             maxBeauty=max(maxBeauty, items[i][1]);
    //             i++;
    //         }
    //         q[price]=maxBeauty;
    //     }
    //     vector<int> ans;
    //     for (int i=0; i<queries.size(); i++)
    //         ans.push_back(q[queries[i]]);
    //     return ans;
    // }
};