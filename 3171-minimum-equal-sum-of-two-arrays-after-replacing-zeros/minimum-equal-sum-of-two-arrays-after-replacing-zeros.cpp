typedef long long ll;
class Solution {
public:
    long long minSum(vector<int>& num1, vector<int>& num2)
    {
        ll sum1=0, sum2=0;
        int n1=num1.size(), n2=num2.size(), c1=0, c2=0;

        for (int i=0; i<n1; i++)
        {
            sum1+=num1[i];
            if (num1[i]==0) c1++;
        }
        for (int i=0; i<n2; i++)
        {
            sum2+=num2[i];
            if (num2[i]==0) c2++;
        }

        if ((c1==0 && sum1<sum2+c2) || (c2==0 && sum2<sum1+c1)) return -1;
        return max(sum1+c1, sum2+c2);
    }
};