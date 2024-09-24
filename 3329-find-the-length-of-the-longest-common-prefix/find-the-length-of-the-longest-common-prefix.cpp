class Solution {
public:
    int size(int num)
    {
        if (num==0) return 1;
        int ans=0;
        while (num!=0)
        {
            ans++;
            num/=10;
        }
        return ans;
    }
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2)
    {
        int ans=0;
        unordered_set<int> prefix1;
        for (int a1: arr1)
        {
            while (a1!=0)
            {
                prefix1.insert(a1);
                a1/=10;
            }
        }
        for (int a2: arr2)
        {
            while (a2!=0)
            {
                if (prefix1.find(a2)!=prefix1.end())
                {
                    ans=max(ans, size(a2));
                    break;
                }
                a2/=10;
            }
        }
        return ans;
    }
};