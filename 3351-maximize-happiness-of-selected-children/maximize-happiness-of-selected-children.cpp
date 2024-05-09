class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k)
    {
        long long ans=0, minus=0;
        sort(happiness.begin(), happiness.end(), greater<int>());
        for (int i=0; i<happiness.size(); i++)
        {
            if (k==0 || happiness[i]-minus<=0) break;
            ans+=happiness[i]-minus;
            k--;
            minus++;
        }
        return ans;
    }
};