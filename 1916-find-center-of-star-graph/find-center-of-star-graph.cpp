class Solution {
public:
    int findCenter(vector<vector<int>>& edges)
    {
        int ans;
        if (edges[0][0]==edges[1][0] || edges[0][0]==edges[1][1]) return edges[0][0];
        else if (edges[0][1]==edges[1][0] || edges[0][1]==edges[1][1]) return edges[0][1];
        return -1;
    }
};