class Solution {
public:
    int getPermutations(unordered_set<int>& visited, int i, int n)
    {
        if (i>n) return 1;

        int ans=0;
        for (int num=1; num<=n; num++)
        {
            if (visited.find(num)==visited.end() && (i%num==0 || num%i==0))
            {
                visited.insert(num);
                ans+=getPermutations(visited, i+1, n);
                visited.erase(num);
            }
        }
        return ans;
    }
    int countArrangement(int n)
    {
        unordered_set<int> visited;
        int ans=getPermutations(visited, 1, n);
        return ans;
    }
};