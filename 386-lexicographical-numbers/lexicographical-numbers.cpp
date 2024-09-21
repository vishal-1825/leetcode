class Solution {
public:
    void lexicalOrder(int num, int& count, int& n, vector<int>& ans)
    {
        if (count==n || num>n) return;
        if (num>0)
        {
            ans.push_back(num);
            count++;
            if (count==n) return;
        }

        for (int i=0; i<=9; i++)
        {
            if (num==0 && i==0) continue;
            lexicalOrder(num*10+i, count, n, ans);
        }
    }
    vector<int> lexicalOrder(int n)
    {
        vector<int> ans;
        int num=0, count=0;
        lexicalOrder(num, count, n, ans);
        return ans;
    }
};