class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k)
    {
        unordered_map<string, int> mp;
        for (int i=0; i<word.length(); i+=k)
            mp[word.substr(i, k)]++;
        int maxfq=INT_MIN;
        for (auto m: mp)
            maxfq=max(maxfq, m.second);
        return word.length()/k-maxfq;
    }
};