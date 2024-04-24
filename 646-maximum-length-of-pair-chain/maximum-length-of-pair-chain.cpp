class Solution {
public:
    static bool compare(vector<int>& a, vector<int>& b)
    {
        return (a[1]<b[1]);
    }
    int findLongestChain(vector<vector<int>>& pairs)
    {
        int n=pairs.size();
        sort(pairs.begin(), pairs.end(), compare); // O(nlogn) 
        // O(n)
        int prev=0, cur=1, ans=1;
        while (cur<n)
        {
            if (pairs[prev][1]<pairs[cur][0])
            {
                cout << pairs[prev][1] << " " << pairs[cur][0] << endl;
                ans++;
                prev=cur;
            }
            cur++;
        }
        return ans;
    }
};