class Solution {
public:
    double maxAmount(string initialCurrency, vector<vector<string>>& pairs1, vector<double>& rates1, vector<vector<string>>& pairs2, vector<double>& rates2)
    {
        unordered_map<string, double> maxDistance; // max distance from initialCurrency
        maxDistance[initialCurrency]=1.0;

        unordered_set<string> nodes;
        for (auto pair: pairs1)
        {
            nodes.insert(pair[0]);
            nodes.insert(pair[1]);
        }
        for (auto pair: pairs2)
        {
            nodes.insert(pair[0]);
            nodes.insert(pair[1]);
        }

        int n=nodes.size();
        for (int i=0; i<n-1; i++)
        {
            for (int j=0; j<pairs1.size(); j++)
            {
                maxDistance[pairs1[j][1]]=max(maxDistance[pairs1[j][1]], maxDistance[pairs1[j][0]]*rates1[j]);
                maxDistance[pairs1[j][0]]=max(maxDistance[pairs1[j][0]], maxDistance[pairs1[j][1]]/rates1[j]);
            }
        }
        for (int i=0; i<n-1; i++)
        {
            for (int j=0; j<pairs2.size(); j++)
            {
                maxDistance[pairs2[j][1]]=max(maxDistance[pairs2[j][1]], maxDistance[pairs2[j][0]]*rates2[j]);
                maxDistance[pairs2[j][0]]=max(maxDistance[pairs2[j][0]], maxDistance[pairs2[j][1]]/rates2[j]);
            }
        }
        return maxDistance[initialCurrency];
    }
};