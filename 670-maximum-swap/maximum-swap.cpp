class Solution {
public:
    int maximumSwap(int num)
    {
        string number=to_string(num);
        int n=number.length(), maxi=n-1;
        char maxval=number.back();
        vector<int> rightMax(n);
        for (int i=n-2; i>=0; i--)
        {
            rightMax[i]=maxi;
            if (number[i]>maxval)
            {
                maxval=number[i];
                maxi=i;
            }
        }
        for (int i=0; i<n-1; i++)
        {
            if (number[i]<number[rightMax[i]])
            {
                swap(number[i], number[rightMax[i]]);
                break;
            }
        }
        return stoi(number);
    }
};