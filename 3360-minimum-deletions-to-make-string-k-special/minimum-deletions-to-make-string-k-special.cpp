class Solution {
public:
    int minimumDeletions(string word, int k)
    {
        vector<int> fq(26);
        for (int i=0; i<word.length(); i++)
            fq[word[i]-'a']++;
        
        sort(fq.begin(), fq.end());

        int ans=INT_MAX, deleted=0;
        for (int i=0; i<26; i++)
        {
            if (fq[i]==0) continue;
            int possibleAns=deleted;
            for (int j=i+1; j<26; j++)
            {
                if (fq[j]-fq[i]>k)
                    possibleAns+=fq[j]-(fq[i]+k);
            }
            ans=min(ans, possibleAns);
            deleted+=fq[i];
        }
        return ans;
    }
};