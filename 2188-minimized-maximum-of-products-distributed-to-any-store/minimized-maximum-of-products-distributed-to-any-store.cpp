class Solution {
public:
    bool distributable(vector<int>& quantities, int prod, int n)
    {
        int stores=0;
        for (int quant: quantities)
        {
            if (quant%prod==0) stores+=(quant/prod);
            else stores+=((quant/prod)+1);
            if (stores>n) return false;
        }
        return true;
    }
    int minimizedMaximum(int n, vector<int>& quantities)
    {
        int left=1, right=quantities[0], ans=0;
        for (int i=1; i<quantities.size(); i++)
            right=max(right, quantities[i]);

        while (left<=right)
        {
            int mid=(left+right)/2;

            if (distributable(quantities, mid, n))
            {
                ans=mid;
                right=mid-1;
            }
            else left=mid+1;
        }
        return ans;
    }
};