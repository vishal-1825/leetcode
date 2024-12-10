class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2)
    {
        long long xor1=0, xor2=0;
        for (int a: arr1)
            xor1^=a;
        for (int a: arr2)
            xor2^=a;
        return int(xor1 & xor2);
    }
};