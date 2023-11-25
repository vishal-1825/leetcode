class Solution {
public:
    // Couldn't implement yourself, read solution
    int clumsy(int n)
    {
        int op=1;
        stack<int> val;
        val.push(n);
        for (int i=n-1; i>=1; i--)
        {
            int t=val.top();
            if (op==1)
            {
                val.pop();
                val.push(t*i);
                op++;
            }
            else if (op==2)
            {
                val.pop();
                val.push(t/i);
                op++;
            }
            else if (op==3)
            {
                val.pop();
                val.push(t+i);
                op++;
            }
            else
            {
                val.push(-i);
                op=1;
            }
        }

        int ans=0;
        while (!val.empty())
        {
            ans+=val.top();
            val.pop();
        }
        return ans;
    }
};