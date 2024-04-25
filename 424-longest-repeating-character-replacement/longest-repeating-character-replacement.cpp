class Solution {
public:
    // Time -> O(2*n), Space -> O(26)
    int characterReplacement(string s, int k)
    {
        vector<int> fq(26, 0);
        int n=s.length(), i=0, j=0, maxfq=0, ans=0;
        while (j<n)
        {
            fq[s[j]-'A']++;
            maxfq=max(maxfq, fq[s[j]-'A']);
            while ((j-i+1)-maxfq>k)
            {
                fq[s[i]-'A']--;
                i++;
                // here you don't have to update maxfq because you already
                // have an answer with maxfq, you just need to check if you get a
                // better answer
                // Otherwise you would have to scan through 26 elements of hash map
                // which is unnecessaery here
            }
            ans=max(ans, j-i+1);
            j++;
        }
        return ans;
    }
};