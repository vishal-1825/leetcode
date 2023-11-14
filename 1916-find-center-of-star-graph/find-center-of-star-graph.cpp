class Solution {
public:
    int findCenter(vector<vector<int>>& edges)
    {
        int n=edges.size();
        map<int, vector<int>> gr;
        for (auto& e : edges)
        {
            gr[e[0]].push_back(e[1]);
            gr[e[1]].push_back(e[0]);
        }

        for (auto& g : gr)
        {
            if (g.second.size()==n)
                return g.first;
        }
        return -1;
    }
};