class Solution {
public:
    bool canArrange(vector<int>& arr, int k)
    {
        unordered_map<int, int> rem;
        for (int a: arr)
        {
            int val=a%k;
            while (val<0)
                val+=k;
            rem[val]++;
        }

        if (rem[0]%2==1) return false;
        for (auto r: rem)
        {
            if (r.first==0 || r.second==0) continue;
            if (rem[k-r.first]==rem[r.first])
            {
                rem[r.first]=0;
                rem[k-r.first]=0;
            }
            else return false;
        }
        return true;
    }
};