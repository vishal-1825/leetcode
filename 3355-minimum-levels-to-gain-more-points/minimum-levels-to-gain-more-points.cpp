class Solution {
public:
    int minimumLevels(vector<int>& possible)
    {
        int tot=0;
        for (int i=0; i<possible.size(); i++)
            tot+=(possible[i]==0 ? -1 : 1);

        int p1=0;
        for (int i=0; i<possible.size()-1; i++)
        {
            p1+=(possible[i]==0 ? -1 : 1);
            tot-=(possible[i]==0 ? -1 : 1);
            if (p1>tot) return i+1;
        }
        return -1;
    }
};