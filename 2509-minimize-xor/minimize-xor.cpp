class Solution {
public:
    int minimizeXor(int num1, int num2)
    {
        int setbits=0;
        for (int i=0; i<=31; i++)
            setbits+=((num2>>i & 1)==1 ? 1 : 0);
        
        int ans=0;
        for (int i=31; i>=0 && setbits>0; i--)
        {
            if ((num1>>i & 1)==1)
            {
                ans = ans | (1<<i);
                setbits--;
            }
        }
        for (int i=0; i<=31 && setbits>0; i++)
        {
            if ((num1>>i & 1)==0)
            {
                ans = ans | (1<<i);
                setbits--;
            }
        }
        return ans;
    }
};