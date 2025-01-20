class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat)
    {
        int m=mat.size(), n=mat[0].size(), a=arr.size();
        vector<int> rowCount(m), colCount(n);
        vector<pair<int, int>> coord(m*n+1);
        for (int i=0; i<m; i++)
        {
            for (int j=0; j<n; j++)
                coord[mat[i][j]]={i, j};
        }
        for (int i=0; i<a; i++)
        {
            rowCount[coord[arr[i]].first]++;
            if (rowCount[coord[arr[i]].first]==n) return i; 
            colCount[coord[arr[i]].second]++;
            if (colCount[coord[arr[i]].second]==m) return i;
        }
        return -1;
    }
};